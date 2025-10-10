#include "modules.h"

void print_modules(Database *db, int limit) {
    printf("\n");
    int count = (limit == -1 || limit > db->module_count) ? db->module_count : limit;
    for (int i = 0; i < count; i++) {
        printf("%d %s %d %d %d\n", db->modules[i].id, db->modules[i].name, db->modules[i].level,
               db->modules[i].cell, db->modules[i].protected);
    }
}