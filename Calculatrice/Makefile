ma-calculatrice : ma-calculatrice.cpp calculatrice.h calculatrice.o pile.o
	g++ -o ma-calculatrice ma-calculatrice.cpp calculatrice.o pile.o

calculatrice.o : calculatrice.cpp calculatrice.h pile.h
	g++ -c calculatrice.cpp

pile.o : pile.cpp pile.h Element.h
	g++ -c pile.cpp

clean :
	rm *.o ma-calculatrice