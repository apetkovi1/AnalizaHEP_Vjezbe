CC=g++
CFLAGS=-I. $(shell root-config --cflags)
LDFLAGS = $(shell root-config --libs)
DEPS = PDFGenerator.h

%.o: %.cpp $(DEPS)
	$(CC) $(LDFLAGS) -c -o $@ $< $(CFLAGS)

analyzer: analyze.o PDFGenerator.o
	$(CC) $(LDFLAGS) -o analyze analyze.o PDFGenerator.o

clean:
	rm -rf *.o analyze

 
