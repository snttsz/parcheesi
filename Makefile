CC = gcc
CFLAGS = -Wall -Wextra -Isrc/game -Iutils -Isrc

all: Parcheesi

Parcheesi: parcheesi.o game.o board.o gameLogic.o gameStruct.o string_util.o socket.o
	$(CC) $(CFLAGS) -o Parcheesi parcheesi.o game.o board.o gameLogic.o gameStruct.o string_util.o socket.o

game.o: src/game.c src/game.h src/game/board.h src/game/gameStructure.h
	$(CC) $(CFLAGS) -c src/game.c -o game.o

board.o: src/game/board.c src/game/board.h utils/String_utils.h
	$(CC) $(CFLAGS) -c src/game/board.c -o board.o

gameLogic.o: src/game/gameLogic.c src/game/gameLogic.h src/game/gameStructure.h src/game/board.h
	$(CC) $(CFLAGS) -c src/game/gameLogic.c -o gameLogic.o

gameStruct.o: src/game/gameStructure.c src/game/gameStructure.h
	$(CC) $(CFLAGS) -c src/game/gameStructure.c -o gameStruct.o

string_util.o: utils/String_utils.c utils/String_utils.h
	$(CC) $(CFLAGS) -c utils/String_utils.c -o string_util.o

socket.o: src/comm/socket.c src/comm/socket.h
	$(CC) $(CFLAGS) -c src/comm/socket.c -o socket.o

parcheesi.o: Parcheesi.c src/game.h
	$(CC) $(CFLAGS) -c Parcheesi.c -o parcheesi.o

clean:
	rm -f *.o board_game