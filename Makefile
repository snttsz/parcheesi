CC = gcc
CFLAGS = -Wall -Wextra -Isrc/game -Iutils -Isrc
OBJDIR = obj

all: Parcheesi

Parcheesi: $(OBJDIR)/parcheesi.o $(OBJDIR)/game.o $(OBJDIR)/board.o $(OBJDIR)/gameLogic.o $(OBJDIR)/gameStruct.o $(OBJDIR)/string_util.o $(OBJDIR)/socket.o
	$(CC) $(CFLAGS) -o Parcheesi $(OBJDIR)/parcheesi.o $(OBJDIR)/game.o $(OBJDIR)/board.o $(OBJDIR)/gameLogic.o $(OBJDIR)/gameStruct.o $(OBJDIR)/string_util.o $(OBJDIR)/socket.o

$(OBJDIR)/game.o: src/game.c src/game.h src/game/gameLogic.h src/game/board.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game.c -o $(OBJDIR)/game.o

$(OBJDIR)/board.o: src/game/board.c src/game/board.h utils/String_utils.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/board.c -o $(OBJDIR)/board.o

$(OBJDIR)/gameLogic.o: src/game/gameLogic.c src/game/gameLogic.h src/game/gameStructure.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/gameLogic.c -o $(OBJDIR)/gameLogic.o

$(OBJDIR)/gameStruct.o: src/game/gameStructure.c src/game/gameStructure.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/gameStructure.c -o $(OBJDIR)/gameStruct.o

$(OBJDIR)/string_util.o: utils/String_utils.c utils/String_utils.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c utils/String_utils.c -o $(OBJDIR)/string_util.o

$(OBJDIR)/socket.o: src/comm/socket.c src/comm/socket.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/comm/socket.c -o $(OBJDIR)/socket.o

$(OBJDIR)/parcheesi.o: Parcheesi.c src/game.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c Parcheesi.c -o $(OBJDIR)/parcheesi.o

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm $(OBJDIR)/* Parcheesi