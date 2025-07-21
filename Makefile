CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format
TARGET = printf_testing

all:

$(TARGET): *.c
	$(CC) $(CFLAGS) -o $(TARGET) $@ $
