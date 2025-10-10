// src/shared.c
#include "shared.h"

static int compare_index(const void *a, const void *b) {
    return ((IndexEntry *)a)->key - ((IndexEntry *)b)->key;
}

void init_db(Database *db) {
    db->modules = malloc(MAX_ROWS * sizeof(Module));
    db->levels = malloc(MAX_ROWS * sizeof(Level));
    db->status_events = malloc(MAX_ROWS * sizeof(StatusEvent));
    db->module_idx = malloc(MAX_ROWS * sizeof(IndexEntry));
    db->level_idx = malloc(MAX_ROWS * sizeof(IndexEntry));
    db->se_idx = malloc(MAX_ROWS * sizeof(IndexEntry));
    db->module_count = db->level_count = db->se_count = 0;

    FILE *f;
    if ((f = fopen("../materials/modules.idx", "rb")) != NULL) {
        fread(db->module_idx, sizeof(IndexEntry), MAX_ROWS, f);
        fclose(f);
    }
    if ((f = fopen("../materials/levels.idx", "rb")) != NULL) {
        fread(db->level_idx, sizeof(IndexEntry), MAX_ROWS, f);
        fclose(f);
    }
    if ((f = fopen("../materials/status_events.idx", "rb")) != NULL) {
        fread(db->se_idx, sizeof(IndexEntry), MAX_ROWS, f);
        fclose(f);
    }
}

void save_indexes(const Database *db) {
    FILE *f;
    if ((f = fopen("../materials/modules.idx", "wb")) != NULL) {
        fwrite(db->module_idx, sizeof(IndexEntry), db->module_count, f);
        fclose(f);
    }
    if ((f = fopen("../materials/levels.idx", "wb")) != NULL) {
        fwrite(db->level_idx, sizeof(IndexEntry), db->level_count, f);
        fclose(f);
    }
    if ((f = fopen("../materials/status_events.idx", "wb")) != NULL) {
        fwrite(db->se_idx, sizeof(IndexEntry), db->se_count, f);
        fclose(f);
    }
}

void *select(Database *db, const char *table, int id, void *result) {
    IndexEntry *idx;
    int count;
    if (strcmp(table, "modules") == 0) {
        idx = db->module_idx;
        count = db->module_count;
    } else if (strcmp(table, "levels") == 0) {
        idx = db->level_idx;
        count = db->level_count;
    } else if (strcmp(table, "status_events") == 0) {
        idx = db->se_idx;
        count = db->se_count;
    } else {
        return NULL;
    }

    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (idx[mid].key == id) {
            int offset = idx[mid].offset;
            if (strcmp(table, "modules") == 0) {
                *(Module *)result = db->modules[offset];
            } else if (strcmp(table, "levels") == 0) {
                *(Level *)result = db->levels[offset];
            } else {
                *(StatusEvent *)result = db->status_events[offset];
            }
            return result;
        } else if (idx[mid].key < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return NULL;
}

void insert(Database *db, const char *table, void *data) {
    if (strcmp(table, "modules") == 0) {
        int idx = db->module_count;
        db->modules[idx] = *(Module *)data;
        db->module_idx[idx].key = db->modules[idx].id;
        db->module_idx[idx].offset = idx;
        db->module_count++;
        qsort(db->module_idx, db->module_count, sizeof(IndexEntry), compare_index);
    } else if (strcmp(table, "levels") == 0) {
        int idx = db->level_count;
        db->levels[idx] = *(Level *)data;
        db->level_idx[idx].key = db->levels[idx].id;
        db->level_idx[idx].offset = idx;
        db->level_count++;
        qsort(db->level_idx, db->level_count, sizeof(IndexEntry), compare_index);
    } else if (strcmp(table, "status_events") == 0) {
        int idx = db->se_count;
        db->status_events[idx] = *(StatusEvent *)data;
        db->se_idx[idx].key = db->status_events[idx].module_id;
        db->se_idx[idx].offset = idx;
        db->se_count++;
        qsort(db->se_idx, db->se_count, sizeof(IndexEntry), compare_index);
    }
}

void update(Database *db, const char *table, int id, void *data) {
    Module m;
    Level l;
    if (strcmp(table, "modules") == 0 && select(db, "modules", id, &m)) {
        db->modules[db->module_idx[id].offset] = *(Module *)data;
    } else if (strcmp(table, "levels") == 0 && select(db, "levels", id, &l)) {
        db->levels[db->level_idx[id].offset] = *(Level *)data;
    }
}

void delete(Database *db, const char *table, int id) {
    if (strcmp(table, "modules") == 0) {
        for (int i = 0; i < db->module_count; i++) {
            if (db->module_idx[i].key == id) {
                int offset = db->module_idx[i].offset;
                db->modules[offset] = db->modules[--db->module_count];
                db->module_idx[i] = db->module_idx[db->module_count];
                qsort(db->module_idx, db->module_count, sizeof(IndexEntry), compare_index);
                return;
            }
        }
    } else if (strcmp(table, "levels") == 0) {
        for (int i = 0; i < db->level_count; i++) {
            if (db->level_idx[i].key == id) {
                int offset = db->level_idx[i].offset;
                db->levels[offset] = db->levels[--db->level_count];
                db->level_idx[i] = db->level_idx[db->level_count];
                qsort(db->level_idx, db->level_count, sizeof(IndexEntry), compare_index);
                return;
            }
        }
    }
}

void get_all_active_additional_modules(Database *db, Module *result, int *count) {
    *count = 0;
    for (int i = 0; i < db->se_count; i++) {
        if (db->status_events[i].status == 1) {
            Module m;
            if (select(db, "modules", db->status_events[i].module_id, &m) &&
                strcmp(m.name, "Main module") != 0) {
                result[(*count)++] = m;
            }
        }
    }
}