all: clean build run

build:
	g++ -Wall -g *.cpp -o main

run:
	./main

clean:
	rm -rf main