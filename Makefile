all: trainer tester

trainer:
	gcc -Wall -O2 mnist.c mnist_file.c neural_network.c -lm -o mnist

tester:
	gcc -Wall -O2 mnist_tester.c mnist_file.c neural_network.c -lm -o mnist_tester
