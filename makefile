PNAME=edcare.out
CC=gcc
CC_FLAGS=-Wall      \
		 -g         
#		 -ansi
#		 -Wextra
#		 -pedantic
#CC_LIBS=-lm # Definir se precisar

.PHONY: all clean run valgrind

all: edcare.out

edcare.out:
	$(CC) $(CC_FLAGS) ./src/*.c -o $(PNAME) $(CC_LIBS)

run: $(PNAME)
	./$(PNAME)

valgrind: $(PNAME)
	valgrind --leak-check=full --track-origins=yes ./$(PNAME)

clean:
	@ rm -rf ./*.o ./*.out

# Em caso de dúvida...
# https://www.gnu.org/software/make/manual/html_node/index.html