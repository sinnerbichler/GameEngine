#Makefile

objs = Window.o Log.o Physics.o Timer.o Texture.o Bezier.o Object.o
makeobj = g++ -c -fpic -lSDL2 $< -Wall

libGameEngine.so : $(objs)
	g++ -shared -o libGameEngine.so $(objs)

Window.o : Window.cpp Window.hpp
	$(makeobj)

Log.o : Log.cpp Log.hpp
	$(makeobj)

Physics.o : Physics.cpp Physics.hpp
	$(makeobj)

Timer.o : Timer.cpp Timer.hpp
	$(makeobj)

Texture.o : Texture.cpp Texture.hpp
	$(makeobj)

Bezier.o : Bezier.cpp Bezier.hpp
	$(makeobj)

Object.o : Object.cpp Object.hpp
	$(makeobj)
