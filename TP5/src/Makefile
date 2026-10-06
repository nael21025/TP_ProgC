CC ?= gcc
CFLAGS = -Wall -Wextra -g

ifeq ($(OS),Windows_NT)
    EXE = .exe
    LIBS = -lws2_32
else
    EXE =
    LIBS =
endif

all: serveur$(EXE) client$(EXE) repertoire$(EXE)

serveur$(EXE): serveur.c serveur.h
	$(CC) $(CFLAGS) serveur.c -o serveur$(EXE) $(LIBS)

client$(EXE): client.c client.h
	$(CC) $(CFLAGS) client.c -o client$(EXE) $(LIBS)

repertoire$(EXE): repertoire.c repertoire.h
	$(CC) $(CFLAGS) repertoire.c -o repertoire$(EXE)

clean:
	rm -f serveur serveur.exe client client.exe repertoire repertoire.exe