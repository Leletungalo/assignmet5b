samp: audio.o samp.o
	g++ audio.o samp.o -o samp

audio.o: audio.cpp
	g++ -c audio.cpp

samp.o: samp.cpp
	g++ -c samp.cpp

run:
	./samp -r 4400 -b 8 -c 85 -o lele.raw -add sampleinput/siren40sec44100signed8bitmono.raw sampleinput/siren40sec44100signed8bitmono.raw

clean:
	rm *.o samp
