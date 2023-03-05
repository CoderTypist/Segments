all: selector.o descriptor.o table.o tests clean

tests: *.c ./segment/selector.o ./segment/descriptor.o
	gcc -o $(basename $<) $^

selector.o: ./segment/selector.c ./segment/selector.h
	gcc -c ./segment/selector.c -o ./segment/selector.o

descriptor.o: ./segment/descriptor.c ./segment/descriptor.h
	gcc -c ./segment/descriptor.c -o ./segment/descriptor.o

table.o: ./segment/table.c ./segment/table.h
	gcc -c ./segment/table.c -o ./segment/table.o

clean:
	rm ./segment/*.o
