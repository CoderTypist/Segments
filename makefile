SEGMENT_TARGETS := selector.o pseudo.o descriptor.o segment.o
SEGMENT_OBJ_FILES := $(addprefix ./segment/, $(SEGMENT_TARGETS))

OTHER_TARGETS := threads.o wsl.o
OTHER_OBJ_FILES := ./threads/threads.o ./wsl/wsl.o

TESTS := *.c

all: $(OTHER_OBJ_FILES) $(SEGMENT_TARGETS) tests clean

tests: $(TESTS) $(SEGMENT_OBJ_FILES) ./threads/threads.o
	$(foreach fname, $(wildcard $(TESTS)),       \
		gcc -o ./$(basename $(fname))            \
		$(SEGMENT_OBJ_FILES) $(OTHER_OBJ_FILES)  \
		$(fname)                                 \
		-lpthread;                               \
	)

selector.o: ./segment/selector.c ./segment/selector.h
	gcc -c ./segment/selector.c -o ./segment/selector.o

descriptor.o: ./segment/descriptor.c ./segment/descriptor.h
	gcc -c ./segment/descriptor.c -o ./segment/descriptor.o

pseudo.o: ./segment/pseudo.c ./segment/pseudo.h
	gcc -c ./segment/pseudo.c -o ./segment/pseudo.o

threads.o: ./threads/threads.c ./threads/threads.h
	gcc -c ./threads/threads.c -o ./threads/threads.o

segment.o: ./segment/segment.c ./segment/segment.h
	gcc -c ./segment/segment.c -o ./segment/segment.o

wsl.o: ./wsl/wsl.c ./wsl/wsl.h
	gcc -c ./wsl/wsl.c -o ./wsl/wsl.o

clean:
	rm ./threads/*.o
	rm ./segment/*.o
