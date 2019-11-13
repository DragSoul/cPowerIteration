CC=gcc
CFLAGS=
LDFLAGS=
EXEC=cIMatrice

all: $(EXEC)

cIMatrice: main.o display.o testMatrice.o iterative.o
	$(CC) -o $@ $^ $(LDFLAGS) -lm

main.o: display.o testMatrice.o iterative.o

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -lm

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)