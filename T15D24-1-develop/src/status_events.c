#include "status_events.h"

void print_status_events(Database *db, int limit) {
    printf("\n");
    int count = (limit == -1 || limit > db->se_count) ? db->se_count : limit;
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", db->status_events[i].module_id, db->status_events[i].status);
    }
}