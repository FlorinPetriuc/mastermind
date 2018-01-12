#
# Copyright (C) 2018 Florin Petriuc. All rights reserved.
# Initial release: Florin Petriuc <petriuc.florin@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License version
# 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
#

CFLAGS = -c -Werror

OFILES = ./build/obj/main.o ./build/obj/itf.o ./build/obj/game.o
TFILES = ./build/obj/testmain.o ./build/obj/itf.o ./build/obj/game.o

all:$(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) -o ./build/bin/mastermind

tests:$(TFILES)
	$(CC) $(LDFLAGS) $(TFILES) -o ./build/bin/mastermind_tests

./build/obj/main.o: ./src/main.c
	$(CC) $(CFLAGS) ./src/main.c -o ./build/obj/main.o

./build/obj/testmain.o: ./src/test/test.c
	$(CC) $(CFLAGS) ./src/test/test.c -o ./build/obj/testmain.o

./build/obj/game.o: ./src/game/game.c
	$(CC) $(CFLAGS) ./src/game/game.c -o ./build/obj/game.o

./build/obj/itf.o: ./src/itf/console/console.c
	$(CC) $(CFLAGS) ./src/itf/console/console.c -o ./build/obj/itf.o

clean:
	rm ./build/obj/*
	rm ./build/bin/*