all: selector.o pseudo.o descriptor.o tests clean

tests: *.c ./segment/selector.o ./segment/descriptor.o
	gcc -o $(basename $<) $^

selector.o: ./segment/selector.c ./segment/selector.h
	gcc -c ./segment/selector.c -o ./segment/selector.o

descriptor.o: ./segment/descriptor.c ./segment/descriptor.h
	gcc -c ./segment/descriptor.c -o ./segment/descriptor.o

pseudo.o: ./segment/pseudo.c ./segment/pseudo.h
	gcc -c ./segment/pseudo.c -o ./segment/pseudo.o

clean:
	rm ./segment/*.o
