hello: FileManager.o FileS.o
	g++ -o hello FileManager.o FileS.o
	mv *.o \ofiles

FileManager.o: FileManager.cpp FileManager.h
	g++ -c FileManager.cpp -std=c++17 -lstdc++fs

FileS.o: FileS.cpp
	g++ -c FileS.cpp -std=c++17 -lstdc++fs