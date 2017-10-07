EXE = linked_list
LFLAGS = -lm
CC = gcc
CFLAGS= -Iinclude -g -ggdb -Wall -Wextra -O0
default: $(EXE)

#first target
$(EXE): linked_list.o
	$(CC) $^ -o $(EXE) -lm $(LFLAGS) 
%.o:%.c
	$(CC) -c $< -o $@  $(CFLAGS)

linked_list.o: linked_list.c 

