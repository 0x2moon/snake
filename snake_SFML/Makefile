#src= ponto c dos h
#obj = bn ou ponto da biblioteca .h
#include = ponto.h
#bin output = binario da main
#app = .c princiapl ou o main.c

APPS = ./app
OUTPUT = ./output
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

LFLAG = -lsfml-graphics -lsfml-window -lsfml-system
LIB_P = utils
TESTE = main


all: libed myapps

libed:
#compilar biblioteca
	@g++ -c $(SRC)/$(LIB_P).cpp -I $(INCLUDE) -o $(OBJ)/$(LIB_P).o

myapps:
#compilar a main
	@g++ -g $(APPS)/$(TESTE).cpp -o $(OUTPUT)/$(TESTE) $(LFLAG) $(OBJ)/*.o 
	@$(OUTPUT)/$(TESTE)

clean:
	@rm $(OBJ)/*.o 
	@rm $(OUTPUT)/$(TESTE)

teste:
	g++ $(APPS)/teste.cpp -o $(OUTPUT)/snake -lsfml-graphics -lsfml-window -lsfml-system
	@$(OUTPUT)/snake