CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

TARGET = benchMark
OBJS = sort_benchMark.o sort.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

sort_benchMark.o: sort_benchMark.c sort.h
	$(CC) $(CFLAGS) -c sort_benchMark.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean: 
	rm -f $(OBJS)