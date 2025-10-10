#include "levels.h"

void print_levels(Database *db, int limit) {
    printf("\n");
    int count = (limit == -1 || limit > db->level_count) ? db->level_count : limit;
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", db->levels[i].id, db->levels[i].protected);
    }
}