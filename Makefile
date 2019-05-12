samp: audio.o samp.o
	g++ audio.o samp.o -o samp

audio.o: audio.cpp
	g++ -c audio.cpp

samp.o: samp.cpp
	g++ -c samp.cpp

clean:
	rm *.o samp
