CFLAGS = -c -Werror

OFILES = ./build/obj/main.o

all:$(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) -o ./build/bin/mastermind

./build/obj/main.o: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -o ./build/obj/main.o

clean:
	rm ./build/obj/*
	rm ./build/bin/*