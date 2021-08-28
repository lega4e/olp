EXECUTABLE = main
CFLAGS = -std=gnu++17 -c -Wall -DDEBUG
LDFLAGS =
LIBS =





# main
all: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE) < input


re: clean $(EXECUTABLE)

rerun: clean $(EXECUTABLE)
	$(EXECUTABLE)



$(EXECUTABLE): main.o
	g++ $(LDFLAGS) -o $(EXECUTABLE) main.o $(LIBS)

main.o: main.cpp
	g++ $(CFLAGS) -o main.o main.cpp





# clean
clean:
	-rm *.o $(EXECUTABLE)





# end
