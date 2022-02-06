CREATOR =  gcc -Wall -ansi -pedantic

# Creating the final executable - mycomp.
mycomp: mycomp.o complex.o utils.o
	$(CREATOR) -g mycomp.o complex.o utils.o -o mycomp -lm


# Creating mycomp.o file.
mycomp.o: mycomp.c complex.h
	$(CREATOR) -g -c mycomp.c -o mycomp.o

# Creating complex.o file.
complex.o: complex.c complex.h
	$(CREATOR) -g -c complex.c -o complex.o

# Creating utils.o file.
utils.o: utils.c complex.h
	$(CREATOR) -g -c utils.c -o utils.o	
