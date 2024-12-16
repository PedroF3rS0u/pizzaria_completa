CC = gcc
CFLAGS = -Wall -Wextra
OBJ = main.o pizza.o ingrediente.o
EXEC = pizzaria

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(EXEC)

run: all
	./$(EXEC)
