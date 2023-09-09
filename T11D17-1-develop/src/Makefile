CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clang cppcheck dmanager_module.o door_struct.o door_struct list_test.o list.o list_test stack_test.o stack.o stack_test
 
clang: 
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem ./


dmanager_module.o:
	$(CC) -c $(CFLAGS) dmanager_module.c -o dmanager_module.o

door_struct.o:
	$(CC) -c $(CFLAGS) door_struct.c -o door_struct.o


door_struct: dmanager_module.o door_struct.o
	$(CC) $(CFLAGS) dmanager_module.o door_struct.o -o ../build/Quest_1

leaks_door_struct: door_struct
	leaks -atExit -- ../build/Quest_1



list_test.o:
	$(CC) -c $(CFLAGS) list_test.c -o list_test.o

list.o:
	$(CC) -c $(CFLAGS) list.c -o list.o

list_test: list.o list_test.o
	$(CC) $(CFLAGS) list_test.o list.o -o ../build/Quest_2

leaks_list_test: list_test
	leaks -atExit -- ../build/Quest_2



stack.o:
	$(CC) -c $(CFLAGS) stack.c -o stack.o

stack_test.o:
	$(CC) -c $(CFLAGS) stack_test.c -o stack_test.o

stack_test: stack.o stack_test.o
	$(CC) $(CFLAGS) stack_test.o stack.o -o ../build/Quest_3

leaks_stack_test: stack_test
	leaks -atExit -- ../build/Quest_3



clean: all
	rm -rf *.o ../build/* .clang-format

rebuild: clean clang all 