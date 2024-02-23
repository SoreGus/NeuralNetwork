all: matrix.o
	cc matrix.o main.c -o NeuralNetworkSample

matrix.o: matrix.c
	cc -c matrix.c

clean:
	rm -f *.o NeuralNetworkSample

run:
	./NeuralNetworkSample