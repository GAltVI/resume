CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: s21_string_test.o s21_string.o quest1 quest2 quest3 quest4 quest5 quest6 quest7
 
clang: 
	clang-format -i *.c *.h

s21_string_test.o1:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST1

s21_string_test.o2:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST2

s21_string_test.o3:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST3

s21_string_test.o4:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST4

s21_string_test.o5:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST5      

s21_string_test.o6:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST6  

s21_string_test.o7:
	$(CC) -c $(CFLAGS) s21_string_test.c -o s21_string_test.o -DQUEST7  

s21_string.o: 
	$(CC) -c $(CFLAGS) s21_string.c -o s21_string.o

rebuild: clean clang all 

clean: all
	rm -rf *.o ../build/Quest*

quest1: s21_string_test.o1 s21_string.o
	$(CC) $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_1

quest2: s21_string_test.o2 s21_string.o
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_2

quest3: s21_string_test.o3 s21_string.o
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_3

quest4: s21_string_test.o4 s21_string.o 
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_4

quest5: s21_string_test.o5 s21_string.o
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_5

quest6: s21_string_test.o6 s21_string.o
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_6

quest7: s21_string_test.o7 s21_string.o
	$(CC)  $(CFLAGS) s21_string_test.o s21_string.o -o ../build/Quest_7