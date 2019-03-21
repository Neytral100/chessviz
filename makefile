WAYB = build/
WAYSC = src/c/
WAYSH = src/h/
WAYBIN = bin/
WAYR = results/

all: build bin results $(WAYBIN)chess

clean:
	-rm -f $(WAYBIN)chess* $(WAYB)*.o $(WAYR)*

#include $(WAYSH)board_init.h/td
#include $(WAYSH)output.h/td
#include $(WAYSH)board_read.h/td
#include $(WAYSH)coordinates.h/td
#include $(WAYSH)move.h/td

$(WAYBIN)chess: $(WAYB)main.o $(WAYB)board_output.o $(WAYB)board_init.o $(WAYB)board_read.o $(WAYB)move.o
	gcc -o $(WAYBIN)chess -Wall -Werror -O0 $(WAYB)main.o $(WAYB)board_output.o $(WAYB)board_init.o $(WAYB)board_read.o $(WAYB)move.o

$(WAYB)move.o: $(WAYSC)move.c
	gcc -c $(WAYSC)move.c -g -o $(WAYB)move.o

$(WAYB)board_read.o: $(WAYSC)board_read.c
	gcc -c $(WAYSC)board_read.c -g -o $(WAYB)board_read.o

$(WAYB)board_init.o: $(WAYSC)board_init.c
	gcc -c $(WAYSC)board_init.c -g -o $(WAYB)board_init.o

$(WAYB)board_output.o: $(WAYSC)board_output.c
	gcc -c $(WAYSC)board_output.c -g -o $(WAYB)board_output.o

$(WAYB)main.o: $(WAYSC)main.c
	gcc -c $(WAYSC)main.c -g -o $(WAYB)main.o

build:
	mkdir build

bin:
	mkdir bin
	
results:
	mkdir results

.PHONY: clean