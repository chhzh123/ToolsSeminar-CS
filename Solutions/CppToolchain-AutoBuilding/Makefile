CPP = g++
LIBS = -lglut -lGL -lGLU

.PHONY: all clean
all: test1 test2 test3 test4

test1: mesh.o display1.o
	$(CPP) $^ $(LIBS) -Llib -lstest -o test1

test2: mesh.o display2.o
	$(CPP) $^ $(LIBS) -Llib -lstest -o test2

test3: mesh.o display3.o
	$(CPP) $^ $(LIBS) -Llib -lstest -o test3

test4: mesh.o display4.o
	$(CPP) $^ $(LIBS) -Llib -lstest -o test4

mesh.o: mesh.cpp
	$(CPP) -Iinclude -c -o $@ $<

display1.o: display.cpp
	$(CPP) -Iinclude -DTEST1 -c -o $@ $<

display2.o: display.cpp
	$(CPP) -Iinclude -DTEST2 -c -o $@ $<

display3.o: display.cpp
	$(CPP) -Iinclude -DTEST3 -c -o $@ $<

display4.o: display.cpp
	$(CPP) -Iinclude -c -o $@ $<

clean:
	-rm *o test1 test2 test3 test4