# Check the OS environment variable to determine the appropriate commands and file extensions
ifeq ($(OS),Windows_NT)
    RM = del /q
    MKDIR = mkdir
    OBJEXT = obj
else
    RM = rm -f
    MKDIR = mkdir -p
    OBJEXT = o
endif

CC = gcc
CFLAGS = -Wall -Wextra -Isrc/game -Iutils -Isrc
OBJDIR = obj

all: Parcheesi

Parcheesi: $(OBJDIR)/parcheesi.$(OBJEXT) $(OBJDIR)/game.$(OBJEXT) $(OBJDIR)/board.$(OBJEXT) $(OBJDIR)/gameLogic.$(OBJEXT) $(OBJDIR)/player.$(OBJEXT) $(OBJDIR)/string_util.$(OBJEXT) $(OBJDIR)/socket.$(OBJEXT)
	$(CC) $(CFLAGS) -o Parcheesi $(OBJDIR)/parcheesi.$(OBJEXT) $(OBJDIR)/game.$(OBJEXT) $(OBJDIR)/board.$(OBJEXT) $(OBJDIR)/gameLogic.$(OBJEXT) $(OBJDIR)/player.$(OBJEXT) $(OBJDIR)/string_util.$(OBJEXT) $(OBJDIR)/socket.$(OBJEXT)

$(OBJDIR)/game.$(OBJEXT): src/game.c src/game.h src/game/gameLogic.h src/game/board.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game.c -o $(OBJDIR)/game.$(OBJEXT)

$(OBJDIR)/board.$(OBJEXT): src/game/board.c src/game/board.h utils/String_utils.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/board.c -o $(OBJDIR)/board.$(OBJEXT)

$(OBJDIR)/gameLogic.$(OBJEXT): src/game/gameLogic.c src/game/gameLogic.h src/game/player.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/gameLogic.c -o $(OBJDIR)/gameLogic.$(OBJEXT)

$(OBJDIR)/player.$(OBJEXT): src/game/player.c src/game/player.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/game/player.c -o $(OBJDIR)/player.$(OBJEXT)

$(OBJDIR)/string_util.$(OBJEXT): utils/String_utils.c utils/String_utils.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c utils/String_utils.c -o $(OBJDIR)/string_util.$(OBJEXT)

$(OBJDIR)/socket.$(OBJEXT): src/comm/socket.c src/comm/socket.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/comm/socket.c -o $(OBJDIR)/socket.$(OBJEXT)

$(OBJDIR)/parcheesi.$(OBJEXT): Parcheesi.c src/game.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c Parcheesi.c -o $(OBJDIR)/parcheesi.$(OBJEXT)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR)/*.$(OBJEXT) Parcheesi