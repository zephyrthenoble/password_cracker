CC      = g++
CFLAGS  = 
LDFLAGS = -Wall

all: password_cracker clean

password_cracker: password_cracker.o
	$(CC) -o $@ $^ $(LDFLAGS)

password_cracker.o: password_cracker.cpp password_cracker.h
	$(CC) -c $(CFLAGS) $<

run:
	./password_cracker

.PHONY: clean cleanest

clean:
	rm *.o

cleanest: clean
	rm password_cracker
