CC = gcc
CFLAGS = -Wall -Wextra -Isrc/game -Iutils -Isrc

all: board_game

board_game: main.o gameConstructor.o board.o gameLogic.o gameStruct.o string_util.o socket.o
	$(CC) $(CFLAGS) -o board_game main.o gameConstructor.o board.o gameLogic.o gameStruct.o string_util.o socket.o

gameConstructor.o: src/gameConstructor.c src/gameConstructor.h src/game/gameLogic.h
	$(CC) $(CFLAGS) -c src/gameConstructor.c -o gameConstructor.o

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

main.o: main.c src/gameConstructor.h
	$(CC) $(CFLAGS) -c main.c -o main.o

clean:
	rm -f *.o board_game