all: trainer tester

trainer:
	gcc -Wall -O2 mnist.c mnist_file.c neural_network.c -lm -o mnist.x

tester:
	gcc -Wall -O2 dataset_gen.c mnist_file.c -lm -o dataset_gen.x
	./dataset_gen.x
	gcc -Wall -O2 mnist_tester.c neural_network.c -lm -o mnist_tester.x

clean:
	rm -f *.x