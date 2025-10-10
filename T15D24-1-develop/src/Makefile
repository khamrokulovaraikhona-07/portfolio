# src/Makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = modules_db.c shared.c modules.c levels.c status_events.c
OUT = ../build/modules_db

all: build_db

build_db: $(SRC)
	@mkdir -p ../build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf ../build

.PHONY: all build_db clean