Program = NeuralNetworkSample

MatrixSource = Matrix/matrix.c
MatrixObject = matrix.o

MatrixOperationsSource = Matrix/matrixOperations.c
MatrixOperationsObject = matrixOperations.o

ImageSource = Util/Image.c
ImageObject = Image.o

MainSource = main.c
MainObject = main.o


all: $(MainObject) $(ImageObject) $(MatrixOperationsObject) $(MatrixObject)
	cc $^ -o $(Program)

$(MainObject): $(MainSource)
	cc -c $^

$(ImageObject): $(ImageSource)
	cc -c $^

$(MatrixOperationsObject): $(MatrixOperationsSource)
	cc -c $^

$(MatrixObject): $(MatrixSource)
	cc -c $^

clean:
	rm -rf *.o $(Program) Images/*.jpg

run:
	./$(Program)