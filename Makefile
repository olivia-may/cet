CC = gcc

# what im calling this i guess haha
PROGRAM_NAME = c-esperanta-tradukisto

$(PROGRAM_NAME):
	$(CC) main.c -o $(PROGRAM_NAME).o

esperanta-programo: $(PROGRAM_NAME)
	./$(PROGRAM_NAME).o esperanta-programo.c > translated.c
	$(CC) translated.c
	./a.out

clean:
	rm -f *.out *.o translated.c
