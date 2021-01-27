TARGETS = test_ordered_list.exe test_find.exe test_vector.exe \
test_list.exe demo_double_linked_list_node.exe list_demo.exe \
Mean_And_Stdev.exe single_linked_list.exe
CC = cl
CCFLAGS = /Zi /EHsc /GR /GZ

all:	$(TARGETS)

test_ordered_list.exe:	test_ordered_list.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_find.exe:	test_find.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_vector.exe:	test_vector.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_list.exe:	test_list.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

demo_double_linked_list_node.exe:	demo_double_linked_list_node.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

list_demo.exe:	list_demo.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

Mean_And_Stdev.exe:	Mean_And_Stdev.obj
	$(CC) $(CCFLAFS) /Fe$@ $**

single_linked_list.exe:	single_linked_list.obj
	$(CC) $(CCFLAGS) /Fe$@ $**

test_vector_validating_iterator.obj:	test_vector.cpp
	$(CC) $(CCFLAGS) /DVALIDATING_ITERATOR /Fe$@ /c $**


demo_double_linked_list_node.obj:	demo_double_linked_list_node.cpp DNode.h
	$(CC) $(CCFLAGS) /c demo_double_linked_list_node.cpp

find.obj:	find.cpp
	$(CC) $(CCFLAGS) /c find.cpp

list_demo.obj:	list_demo.cpp
	$(CC) $(CCFLAGS) /c list_demo.cpp

Mean_And_Stdev.obj:	Mean_And_Stdev.cpp
	$(CC) $(CCFLAGS) /c Mean_And_Stdev.cpp

remove_divisible_by.obj:	remove_divisible_by.cpp
	$(CC) $(CCFLAGS) /c remove_divisible_by.cpp

single_linked_list.obj:	single_linked_list.cpp Node.h
	$(CC) $(CCFLAGS) /c single_linked_list.cpp

swap_middle_with_end.obj:	swap_middle_with_end.cpp
	$(CC) $(CCFLAGS) /c swap_middle_with_end.cpp

test_find.obj:	test_find.cpp find.h
	$(CC) $(CCFLAGS) /c test_find.cpp

test_list.obj:	test_list.cpp list.h DNode.h list_iterator.h \
list_const_iterator.h
	$(CC) $(CCFLAGS) /c test_list.cpp

test_ordered_list.obj:	test_ordered_list.cpp Ordered_List.h
	$(CC) $(CCFLAGS) /c test_ordered_list.cpp

test_vector.obj:	test_vector.cpp vector.h
	$(CC) $(CCFLAGS) /c test_vector.cpp

.PHONY:	clean

clean:
	del *.exe
	del *.obj
	del *.ilk
	del *.pdb
