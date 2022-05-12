CC = g++
CFLAGS = -Wall
all: app

app: main.o calcHashMD5.o dirWalk.o hashAnalyze.o removeDupes.o calcHashMD5.h dirWalk.h hashAnalyze.h removeDupes.h
	g++ $(CFLAGS) -o UsmDuplicates main.o calcHashMD5.o dirWalk.o hashAnalyze.o removeDupes.o -lcrypto
	
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

calcHashMD5.o: calcHashMD5.cpp 
	$(CC) $(CFLAGS) -c calcHashMD5.cpp -lcrypto 

dirWalk.o: dirWalk.cpp
	$(CC) $(CFLAGS) -c dirWalk.cpp

hashAnalyze.o: hashAnalyze.cpp
	$(CC) $(CFLAGS) -c hashAnalyze.cpp	

removeDupes.o: removeDupes.cpp
	$(CC) $(CFLAGS) -c removeDupes.cpp

clean:
	rm -rf *.o UsmDuplicates
