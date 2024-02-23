Program = NeuralNetworkSample
MatrixSource = Matrix/matrix.c
MatrixOperationsSource = Matrix/matrixOperations.c
MainSource = main.c

all: $(Program)

$(Program): $(MainSource) $(MatrixOperationsSource) $(MatrixSource)
	cc $(MainSource) $(MatrixOperationsSource) $(MatrixSource) -o $(Program)

clean:
	rm -f *.o $(Program)

run:
	./$(Program)