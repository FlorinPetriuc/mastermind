CFLAGS = -c -Werror

OFILES = ./build/obj/main.o ./build/obj/itf.o ./build/obj/game.o

all:$(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) -o ./build/bin/mastermind

./build/obj/main.o: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -o ./build/obj/main.o

./build/obj/game.o: ./src/game/game.c
	$(CC) $(CFLAGS) ./src/game/game.c -o ./build/obj/game.o

./build/obj/itf.o: ./src/itf/console/console.c
	$(CC) $(CFLAGS) ./src/itf/console/console.c -o ./build/obj/itf.o

clean:
	rm ./build/obj/*
	rm ./build/bin/*