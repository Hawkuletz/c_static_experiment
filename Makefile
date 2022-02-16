# Build my_sha1 (sha1sum), hmac_mysha1, hmac_openssl
CC = gcc
CCFLAGS = -Wall -O2

all: ex

buru:buru.c buru.h
	$(CC) $(CCFLAGS) -c buru.c

mumu:mumu.c mumu.h
	$(CC) $(CCFLAGS) -c mumu.c

ex:buru.o mumu.o ex.c mumu.h buru.h
	$(CC) $(CCFLAGS) ex.c buru.o mumu.o -o ex

clean:
	\rm -f buru.o mumu.o ex
