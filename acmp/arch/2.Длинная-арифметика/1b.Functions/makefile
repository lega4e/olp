EXECUTABLE = main
CFLAGS = -c -Wall -g3 -DDEBUG
LDFLAGS =
LIBS =





# main
all: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE) 


rebuild: clean $(EXECUTABLE)

rerun: clean $(EXECUTABLE)
	$(EXECUTABLE)



$(EXECUTABLE): main.o long_arithmetic.o
	g++ $(LDFLAGS) -o $(EXECUTABLE) main.o long_arithmetic.o $(LIBS)

main.o: main.cpp
	g++ $(CFLAGS) -o main.o main.cpp

long_arithmetic.o: long_arithmetic.cpp
	g++ $(CFLAGS) -o long_arithmetic.o long_arithmetic.cpp





# clean
clean:
	-rm *.o $(EXECUTABLE)





# end
