# Suggested Makefile for CSE_1325 Homework #7 full_credit
CXXFLAGS += --std=c++17
FSFLAGS = -lstdc++fs
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: JADE

JADE: main.o mainwin.o controller.o view.o store.o product.o dialogs.o *.h
	${CXX} ${CXXFLAGS} -o JADE main.o mainwin.o controller.o view.o store.o product.o donut.o java.o dialogs.o $(FSFLAGS) $(GTKFLAGS)
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp $(GTKFLAGS)
mainwin.o: mainwin.cpp *.h
	${CXX} ${CXXFLAGS} -c mainwin.cpp $(GTKFLAGS)
controller.o: controller.cpp *.h
	${CXX} ${CXXFLAGS} -c controller.cpp $(GTKFLAGS)
view.o: view.cpp *.h
	${CXX} ${CXXFLAGS} -c view.cpp
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
dialogs.o: dialogs.cpp *.h
	${CXX} ${CXXFLAGS} -c dialogs.cpp  $(GTKFLAGS)

clean:
	-rm -f *.gch *.o *~ a.out JADE
