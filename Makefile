all: mdate

cons.o: cons.cc
	g++ -c cons.cc -o cons.o

mtools.o: mtools.cc mtools.h
	g++ -c mtools.cc -o mtools.o

mdate: mtools.o cons.o
	g++ mtools.o cons.o -o mdate

clean:
	rm -f *.o mtools.doc++ mdate

distclean:
	rm -f *.o mtools.doc++ mdate
	rm -fr html
	rm -f *~

mtools.doc++: mtools.h
	docify mtools.h mtools.doc++

html: mtools.doc++
	doc++ --dir html mtools.h
