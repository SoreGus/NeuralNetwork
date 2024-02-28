Program = NeuralNetworkSample

MatrixSource = Matrix/matrix.c
MatrixObject = matrix.o

MatrixOperationsSource = Matrix/matrixOperations.c
MatrixOperationsObject = matrixOperations.o

ImageSource = Util/Image.c
ImageObject = Image.o

ActivationsSource = NeuralNetwork/Activations.c
ActivationsObject = Activations.o

NeuralNetworkSource = NeuralNetwork/NeuralNetwork.c
NeuralNetworkObject = NeuralNetwork.o

MainSource = main.c
MainObject = main.o


all: $(MainObject) $(NeuralNetworkObject) $(ActivationsObject) $(ImageObject) $(MatrixOperationsObject) $(MatrixObject)
	cc $^ -o $(Program)

$(NeuralNetworkObject): $(NeuralNetworkSource) 
	cc -c $^

$(ImageObject): $(ImageSource)
	cc -c $^

$(ImageObject): $(ImageSource)
	cc -c $^

$(ActivationsObject): $(ActivationsSource)
	cc -c $^

$(MatrixOperationsObject): $(MatrixOperationsSource)
	cc -c $^

$(MatrixObject): $(MatrixSource)
	cc -c $^

clean:
	rm -rf *.o $(Program) Images/*.jpg

run:
	./$(Program)