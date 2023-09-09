CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clean clang cppcheck cipher.o logger.o cipher logging_cipher 
 
clang: 
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

cipher.o: 
	$(CC) -c $(CFLAGS) cipher.c -o cipher.o -DCOMMON

cipher: cipher.o 
	$(CC) $(CFLAGS) cipher.o -o ../build/cipher  


logger.o:
	$(CC) -c $(CFLAGS) logger.c -o logger.o 

cipher_l.o: 
	$(CC) -c $(CFLAGS) cipher.c -o cipher.o -DLOG

logging_cipher: cipher_l.o logger.o
	$(CC) $(CFLAGS) cipher.o logger.o -o ../build/logging_cipher

clean:
	rm -rf *.o ../build/*