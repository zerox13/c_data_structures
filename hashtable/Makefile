CC=gcc
CFLAGS=-g -std=gnu11 -Wall
LDFLAGS=-lm -pthread
OBJ=$(patsubst %.c,%.o,$(wildcard *.c))
RM=rm
OUT=hashtable

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	$(RM) -f $(OBJ) $(OUT)

