WAYB = build/
WAYSC = src/c/
WAYSH = src/h/
WAYBIN = bin/
WAYR = results/

all: build bin results $(WAYBIN)chess

clean:
	-rm -f $(WAYBIN)chess* $(WAYB)*.o $(WAYR)*

$(WAYBIN)chess: $(WAYB)main.o $(WAYB)board_output.o $(WAYB)board_init.o $(WAYB)board_read.o $(WAYB)move.o
	gcc -o $(WAYBIN)chess -Wall -Werror -O0 $(WAYB)main.o $(WAYB)board_output.o $(WAYB)board_init.o $(WAYB)board_read.o $(WAYB)move.o

$(WAYB)move.o: $(WAYSC)move.c $(WAYSH)move.h
	gcc -c $(WAYSC)move.c -g -o $(WAYB)move.o

$(WAYB)board_read.o: $(WAYSC)board_read.c $(WAYSH)board_read.h
	gcc -c $(WAYSC)board_read.c -g -o $(WAYB)board_read.o

$(WAYB)board_init.o: $(WAYSC)board_init.c $(WAYSH)board_init.h
	gcc -c $(WAYSC)board_init.c -g -o $(WAYB)board_init.o

$(WAYB)board_output.o: $(WAYSC)board_output.c $(WAYSH)board_output.h
	gcc -c $(WAYSC)board_output.c -g -o $(WAYB)board_output.o

$(WAYB)main.o: $(WAYSC)main.c $(WAYSH)*.h
	gcc -c $(WAYSC)main.c -g -o $(WAYB)main.o

build:
	mkdir build

bin:
	mkdir bin
	
results:
	mkdir results

.PHONY: clean