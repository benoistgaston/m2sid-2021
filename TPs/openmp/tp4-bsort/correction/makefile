# Makefile 

OPTOMP = -fopenmp # a renseigner 
OPTSEQ = 
EXELIST = bsort bsortseq
CC = gcc


all : bsort bsortseq
bsort : bsort.c
	  $(CC) $(OPTOMP) $@.c -o $@

bsortseq : bsort.c
	  $(CC) $(OPTSEQ) bsort.c -o $@

clean :
	rm -f core.* $(EXELIST)
