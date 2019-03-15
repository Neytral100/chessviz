WAYB = build/
WAYS = src/
WAYBIN = bin/
WAYR = results/

all: build bin results $(WAYBIN)chess

clean:
	-rm -f $(WAYBIN)chess* $(WAYB)*.o $(WAYR)*

#include $(WAYS)chess.h/td

$(WAYBIN)chess: $(WAYB)chess.o
	gcc -o $(WAYBIN)chess -Wall -Werror -O0 $(WAYB)chess.o

$(WAYB)chess.o: $(WAYS)chess.c
	gcc -c $(WAYS)chess.c -g -o $(WAYB)chess.o

build:
	mkdir build

bin:
	mkdir bin
	
results:
	mkdir results

.PHONY: clean