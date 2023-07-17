CC = gcc
CFLAGS = -Wall -Werror -g

TARGET = FileCompression
SRC_DIR = src
INCLUDE_DIR = includes

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=%.o)
HEADERS = $(wildcard $(INCLUDE_DIR)/*.h)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
