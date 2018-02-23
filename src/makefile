

GCCPARAMS = -W -Wall -Wextra -Werror -O3
LDPARAMS = -lm -O3
OBJECTS = main.o neuralNetwork.o neuralNetworkGettersAndSetters.o perceptron.o

EXEC = mlib.ex




all:$(EXEC)


%.o: %.cpp
	g++ $(GCCPARAMS) -c $^ -o $@
	
$(EXEC):$(OBJECTS)
	g++ $^ -o $@ $(LDPARAMS)


run: $(EXEC)
	./$<
	
clean:
	rm -rf $(OBJECTS)

remove:
	rm -rf $(OBJECTS) $(EXEC)
