CC=gcc
WFLAGS=-Wall -Wextra -Werror
SOFLAGS=-Wl,-rpath,
OFILES=*.o
CFILES=*.c

clangi: 
	cp ../../materials/linters/.clang-format ./
	clang-format -i ../data_libs/*.c ../data_libs/*.h ../data_module/*.c ../data_module/*.h ../yet_another_decision_module/*.c ../yet_another_decision_module/*.h ../main_executable_module/*.c
	rm -Rf .clang-format 

clean: all
	rm -Rf *.o *.a
	
all: rebuild Quest_3

rebuild: data_stat.o data_io.o data_sort.o data_process.o decision.o main_executable_module.o

data_stat.o:
	$(CC) $(WFLAGS) -c ../data_libs/data_stat.c

data_io.o:
	$(CC) $(WFLAGS) -c ../data_libs/data_io.c

data_sort.o:
	$(CC) $(WFLAGS) -c ../data_libs/data_sort.c

data_process.o:
	$(CC) $(WFLAGS) -c ../data_module/data_process.c

decision.o:
	$(CC) $(WFLAGS) -c ../yet_another_decision_module/decision.c

main_executable_module.o:
	$(CC) $(WFLAGS) -c ../main_executable_module/main_executable_module.c

Quest_3: rebuild
	$(CC) $(WFLAGS) data_io.o data_sort.o data_process.o data_stat.o decision.o main_executable_module.o -o ../../build/Quest_3


data_stat.a: data_stat.o
	ar cr data_stat.a data_stat.o

build_with_static: rebuild data_stat.a
	$(CC) $(WFLAGS) data_io.o data_sort.o data_process.o data_stat.a decision.o main_executable_module.o -o ../../build/Quest_5


data_process_D.o:
	$(CC) $(WFLAGS) -c -fPIC ../data_module/data_process.c ../data_libs/data_stat.c

data_process.so: data_process_D.o
	$(CC) $(WFLAGS) -shared -o data_process.so data_process.o data_stat.o 

build_with_dynamic: rebuild data_process.so
	$(CC) $(WFLAGS) -L./ $(SOFLAGS)./ data_process.so data_io.o data_sort.o decision.o main_executable_module.o -o ../../build/Quest_6
