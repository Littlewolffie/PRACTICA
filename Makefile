OPCIONS =-g -O0 -Wall -Wno-sign-compare -Wno-deprecated -std=c++11


main.exe: main.o racional.o token.o
	g++ -o program.exe main.o llista.o solution.o
	rm *.o
racional.o: racional.cpp racional.hpp
	g++ -c racional.cpp $(OPCIONS)
	
token.o: token.cpp token.hpp
	g++ -c token.cpp $(OPCIONS)
	
expressio.o: expressio.cpp expressio.hpp
	g++ -c expressio.cpp $(OPCIONS)
	
variables.o: variables.cpp variables.hpp
	g++ -c variables.cpp $(OPCIONS)
	
math_sessio.o: math_sessio.cpp math_sessio.hpp
	g++ -c math_sessio.cpp $(OPCIONS)
	
main.o: main.cpp token.hpp racional.hpp
	g++ -c main.cpp $(OPCIONS)



clean:
	rm *.o
	rm *.exe
	rm *.gch
