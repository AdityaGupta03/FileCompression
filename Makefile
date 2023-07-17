CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = FileCompression
SRCS = FileCompression.c
OBJS = $(SRCS:.c=.o)
HEADERS = FileCompression.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)