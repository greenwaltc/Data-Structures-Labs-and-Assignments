TARGETS = test_ordered_list.exe test_find.exe test_vector.exe \
test_list.exe demo_double_linked_list_node.exe list_demo.exe \
Mean_And_Stdev.exe single_linked_list.exe 

CC = g++
CCFLAGS = -g -Wall -pedantic

all:	$(TARGETS)

test_ordered_list.exe:	test_ordered_list.o
	$(CC) $(CCFLAGS) -o $@ $^

test_find.exe:	test_find.o
	$(CC) $(CCFLAGS) -o $@ $^

test_vector.exe:	test_vector.o
	$(CC) $(CCFLAGS) -o $@ $^

test_list.exe:	test_list.o
	$(CC) $(CCFLAGS) -o $@ $^

demo_double_linked_list_node.exe:	demo_double_linked_list_node.o
	$(CC) $(CCFLAGS) -o $@ $^

list_demo.exe:	list_demo.o
	$(CC) $(CCFLAGS) -o $@ $^

Mean_And_Stdev.exe:	Mean_And_Stdev.o
	$(CC) $(CCFLAFS) -o $@ $^

single_linked_list.exe:	single_linked_list.o
	$(CC) $(CCFLAGS) -o $@ $^

test_vector_validating_iterator.o:	test_vector.cpp
	$(CC) $(CCFLAGS) -DVALIDATING_ITERATOR -o $@ -c $^

%.o:	%.cpp
	$(CC) $(CCFLAGS) -c $<

demo_double_linked_list_node.o:	demo_double_linked_list_node.cpp DNode.h

find.o:	find.cpp

list_demo.o:	list_demo.cpp

Mean_And_Stdev.o:	Mean_And_Stdev.cpp

remove_divisible_by.o:	remove_divisible_by.cpp

single_linked_list.o:	single_linked_list.cpp Node.h

swap_middle_with_end.o:	swap_middle_with_end.cpp

test_find.o:	test_find.cpp find.h

test_list.o:	test_list.cpp list.h DNode.h list_iterator.h \
list_const_iterator.h

test_ordered_list.o:	test_ordered_list.cpp Ordered_List.h

test_vector.o:	test_vector.cpp vector.h

.PHONY:	clean

clean:	
	rm -f *.o
	rm -f $(TARGETS)
