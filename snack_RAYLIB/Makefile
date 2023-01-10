#src= ponto c dos h
#obj = bn ou ponto da biblioteca .h
#include = ponto.h
#bin output = binario da main
#app = .c princiapl ou o main.c

#APPS = ./app
#OUTPUT = ./OUTPUT
#INCLUDE = ./include
#LIB = ./lib
#OBJ = ./obj
#SRC = ./src


#PROGRAM = List
#TESTE = testeDuplaEncadeada


all:
	gcc ./app/main.c  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./output/main.a.out
	./output/main.a.out
#libed myapps

#libed:
#compilar biblioteca
#	gcc -c $(SRC)/$(PROGRAM).c -I $(INCLUDE) -o $(OBJ)/$(PROGRAM).o

#myapps:
#compilar a main
#	gcc $(APPS)/$(TESTE).c $(OBJ)/*.o -I $(INCLUDE) -o $(OUTPUT)/app

#$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
#	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

#$(OUTPUT)/%: $(APPS)/%.c
#	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@

