// src/modules_db.c
#include "levels.h"
#include "modules.h"
#include "shared.h"
#include "status_events.h"

void delete_modules_by_ids(Database *db, const int *ids, int count) {
    printf("Modules ");
    for (int i = 0; i < count; i++) {
        StatusEvent se = {ids[i], 0};
        insert(db, "status_events", &se);
        printf("%d%s", ids[i], (i < count - 1) ? ", " : "");
    }
    printf(" marked as deleted\n");
}

void set_protected_mode(Database *db, int id) {
    Module m;
    if (select(db, "modules", id, &m)) {
        m.protected = 1;
        update(db, "modules", id, &m);
    }
}

void move_module(Database *db, int id, int level, int cell) {
    Module m;
    if (select(db, "modules", id, &m)) {
        m.level = level;
        m.cell = cell;
        update(db, "modules", id, &m);
    }
}

void set_level_protection(Database *db, int id) {
    Level l;
    if (select(db, "levels", id, &l)) {
        l.protected = 1;
        update(db, "levels", id, &l);
    }
}

void check_main_module(Database *db) {
    Module m;
    if (select(db, "modules", 0, &m) && m.level == 1 && strcmp(m.name, "Main module") == 0) {
        printf("First cell of first level contains only main AI module: %s\n", m.name);
    } else {
        printf("Warning: Main module not found on first level!\n");
    }
}

int main() {
    Database db;
    init_db(&db);

    // Initial data
    Module m1 = {0, "Main module", 4, 3, 0};
    Module m2 = {1, "Text module", 2, 3, 0};
    Level l1 = {1, 0};
    StatusEvent se1 = {0, 1};
    StatusEvent se2 = {1, 1};
    insert(&db, "modules", &m1);
    insert(&db, "modules", &m2);
    insert(&db, "levels", &l1);
    insert(&db, "status_events", &se1);
    insert(&db, "status_events", &se2);

    int choice, sub_choice, limit, ids[10], id, level, cell;
    while (1) {
        printf(
            "\nPlease choose one operation:\n"
            "1. SELECT\n2. INSERT\n3. UPDATE\n4. DELETE\n"
            "5. Get all active additional modules (last module status is 1)\n"
            "6. Delete modules by ids\n7. Set protected mode for module by id\n"
            "8. Move module by id to specified memory level and cell\n"
            "9. Set protection flag of the specified memory level\n10. Check main module\n> ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Please choose a table:\n1. Modules\n2. Levels\n3. Status events\n> ");
                scanf("%d", &sub_choice);
                printf("Insert the number of records or leave empty to output all of them: ");
                scanf("%d", &limit);
                if (sub_choice == 1)
                    print_modules(&db, limit);
                else if (sub_choice == 2)
                    print_levels(&db, limit);
                else if (sub_choice == 3)
                    print_status_events(&db, limit);
                break;
            case 2:
                printf("Table (1=Modules, 2=Levels, 3=Status): ");
                scanf("%d", &sub_choice);
                if (sub_choice == 1) {
                    Module m;
                    printf("ID Name Level Cell Protected: ");
                    scanf("%d %49s %d %d %d", &m.id, m.name, &m.level, &m.cell, &m.protected);
                    insert(&db, "modules", &m);
                    StatusEvent se = {m.id, 1};
                    insert(&db, "status_events", &se);
                } else if (sub_choice == 2) {
                    Level l;
                    printf("ID Protected: ");
                    scanf("%d %d", &l.id, &l.protected);
                    insert(&db, "levels", &l);
                } else if (sub_choice == 3) {
                    StatusEvent se;
                    printf("Module_ID Status: ");
                    scanf("%d %d", &se.module_id, &se.status);
                    insert(&db, "status_events", &se);
                }
                break;
            case 3:
                printf("Table (1=Modules, 2=Levels): ");
                scanf("%d", &sub_choice);
                if (sub_choice == 1) {
                    Module m;
                    printf("ID Name Level Cell Protected: ");
                    scanf("%d %49s %d %d %d", &m.id, m.name, &m.level, &m.cell, &m.protected);
                    update(&db, "modules", m.id, &m);
                } else if (sub_choice == 2) {
                    Level l;
                    printf("ID Protected: ");
                    scanf("%d %d", &l.id, &l.protected);
                    update(&db, "levels", l.id, &l);
                }
                break;
            case 4:
                printf("Table (1=Modules, 2=Levels): ");
                scanf("%d", &sub_choice);
                printf("ID: ");
                scanf("%d", &id);
                delete (&db, sub_choice == 1 ? "modules" : "levels", id);
                break;
            case 5:
                Module active[MAX_ROWS];
                int count;
                get_all_active_additional_modules(&db, active, &count);
                for (int i = 0; i < count; i++) {
                    printf("%d %s %d %d %d\n", active[i].id, active[i].name, active[i].level, active[i].cell,
                           active[i].protected);
                }
                break;
            case 6:
                printf("Please input the ids of the deleting modules: ");
                count = 0;
                while (count < 10 && scanf("%d", &ids[count]) == 1) count++;
                delete_modules_by_ids(&db, ids, count);
                break;
            case 7:
                printf("Module ID: ");
                scanf("%d", &id);
                set_protected_mode(&db, id);
                break;
            case 8:
                printf("Module ID, Level, Cell: ");
                scanf("%d %d %d", &id, &level, &cell);
                move_module(&db, id, level, cell);
                break;
            case 9:
                printf("Level ID: ");
                scanf("%d", &id);
                set_level_protection(&db, id);
                break;
            case 10:
                check_main_module(&db);
                break;
            default:
                save_indexes(&db);
                free(db.modules);
                free(db.levels);
                free(db.status_events);
                free(db.module_idx);
                free(db.level_idx);
                free(db.se_idx);
                return 0;
        }
    }
}