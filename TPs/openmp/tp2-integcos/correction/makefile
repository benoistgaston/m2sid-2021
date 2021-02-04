# Makefile 

OPTOMP = -fopenmp# a renseigner 
OPTSEQ = 
EXELIST = integcos integcosseq
CC = gcc

all : integcos integcosseq
 
integcos : integcos.c
	  $(CC) $(OPTOMP) $@.c -o $@ -lm

integcosseq : integcos.c
	  $(CC) $(OPTSEQ) integcos.c -o integcosseq -lm

clean :
	rm -f core.* $(EXELIST)
