program: main.cc
	g++ -o program main.cc

run: program
	./program.exe > img.ppm

clean:
	rm program