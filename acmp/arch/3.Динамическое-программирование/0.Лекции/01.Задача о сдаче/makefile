EXECUTABLE = main
CFLAGS = -c -Wall -g3 -DDEBUG
LDFLAGS =
LIBS =





# py
py:
	python3 main.py




# main
all: $(EXECUTABLE)

run: $(EXECUTABLE)
	$(EXECUTABLE) 


rebuild: clean $(EXECUTABLE)

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
