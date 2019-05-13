samp: samp.o
	g++ samp.o -o samp --std=c++11

#audio.o: audio.cpp
#	g++ -c audio.cpp

samp.o: samp.cpp
	g++ -c samp.cpp

run:
	./samp -r 4400 -b 8 -c 1 -o lele.raw -add sampleinput/siren40sec44100signed8bitmono.raw sampleinput/frogs18sec44100signed8bitmono.raw

clean:
	rm *.o samp
