// src/shared.h
#ifndef SHARED_H
#define SHARED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_NAME 50

typedef struct {
    int id;
    char name[MAX_NAME];
    int level;
    int cell;
    int protected;
} Module;

typedef struct {
    int id;
    int protected;
} Level;

typedef struct {
    int module_id;
    int status;
} StatusEvent;

typedef struct {
    int key;     // ID or module_id
    int offset;  // Index in the main array
} IndexEntry;

typedef struct {
    Module *modules;
    Level *levels;
    StatusEvent *status_events;
    IndexEntry *module_idx;
    IndexEntry *level_idx;
    IndexEntry *se_idx;
    int module_count;
    int level_count;
    int se_count;
} Database;

void init_db(Database *db);
void save_indexes(const Database *db);  // Updated to const
void *select(Database *db, const char *table, int id, void *result);
void insert(Database *db, const char *table, void *data);
void update(Database *db, const char *table, int id, void *data);
void delete(Database *db, const char *table, int id);
void get_all_active_additional_modules(Database *db, Module *result, int *count);

#endif