CC=gcc
DEPS = print.h readInFile.h variables.h

interpreter: interpreter.o print.o readInFile.o variable.o
	gcc interpreter.o print.o readInFile.o variable.o -o interpreter

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $<