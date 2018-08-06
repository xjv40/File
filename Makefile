CC      = gcc
CFLAGS  = -W -Wall -Wextra -Werror -Wformat=2 -Wwrite-strings -std=c11 -Wpedantic
LDFLAGS =
EXEC    = file
SRC     = $(wildcard *.c)
OBJ     = $(SRC: .c = .o)


all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

cleaner: clean
	rm -rf $(EXEC)
