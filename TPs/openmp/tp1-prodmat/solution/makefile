# Makefile 

OPTOMP =  -fopenmp
OPTSEQ = 
EXELIST = prodmat prodmatseq
CC = gcc


all : prodmat prodmatseq
prodmat : prodmat.c
	  $(CC) $(OPTOMP) $@.c -o $@

prodmatseq : prodmat.c
	  $(CC) $(OPTSEQ) prodmat.c -o prodmatseq

clean :
	rm -f core.* $(EXELIST)
