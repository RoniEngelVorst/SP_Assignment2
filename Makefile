

FLAGS= -Wall -g
CC=gcc
AR=ar
OBJECTS_MAIN_graph = my_graph.o my_mat.o
OBJECT_MAIN_KNAP = my_Knapsack.o
OBJECTS_graph= my_mat.o my_mat.h

all: my_graph my_Knapsack

my_graph: $(OBJECTS_MAIN_graph) lib_graph.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_graph) my_graph.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

my_Knapsack: $(OBJECT_MAIN_KNAP) my_Knapsack.h
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECT_MAIN_KNAP) my_Knapsack.h
my_Knapsack.o: my_Knapsack.c my_Knapsack.h
	$(CC) $(FLAGS) -C my_Knapsack.c
my_graph.o:my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

lib_graph.a: $(OBJECTS_graph)
	$(AR) -rcs lib_graph.a $(OBJECTS_graph)

.PHONY: clean all

clean:
	rm -f *.o my_Knapsack my_graph lib_graph.a 