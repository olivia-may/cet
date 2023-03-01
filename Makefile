CC=gcc

# what im calling this i guess haha
PROGRAM_NAME=cet

# name of the C-o Esperanta files
FILE_EXTENSION=.ce

$(PROGRAM_NAME):
	$(CC) main.c -o $(PROGRAM_NAME).o

esperanta-programo: $(PROGRAM_NAME)
	./$(PROGRAM_NAME).o esperanta-programo$(FILE_EXTENSION) > translated.c
	$(CC) translated.c
	./a.out

clean:
	rm -f *.out *.o translated.c

run:
	./$(PROGRAM_NAME).o
