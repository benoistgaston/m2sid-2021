# Makefile 

OPTOMP = -fopenmp
OPTSEQ = 
EXELIST = fib fibseq
CC = gcc


all : fib fibseq
fib : fib.c
	  $(CC) $(OPTOMP) $@.c -o $@

fibseq : fib.c
	  $(CC) $(OPTSEQ) fib.c -o $@

clean :
	rm -f core.* $(EXELIST)
