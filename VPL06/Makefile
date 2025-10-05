CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
ENTIDADES_DIR=src/entidades
BUILD_DIR=build

#Primeiro comando é executar o main
all: main

#O main requer o main.o, circulo.o e ponto.o (todos na pasta build)
main : $(BUILD_DIR)/main.o $(BUILD_DIR)/circulo.o $(BUILD_DIR)/ponto.o
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/circulo.o $(BUILD_DIR)/ponto.o -o vpl_execution
	echo "Compilação e criação de vpl_execution.exe concluídas!"

#O main.o requer todos os headers (Circulo.hpp e Ponto.cpp)
$(BUILD_DIR)/main.o : $(INCLUDE_DIR)/Circulo.hpp $(INCLUDE_DIR)/Ponto.hpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I $(INCLUDE_DIR) -o $(BUILD_DIR)/main.o
	echo "Arquivo main.o criado!"

#O 
$(BUILD_DIR)/circulo.o : $(INCLUDE_DIR)/Circulo.hpp $(ENTIDADES_DIR)/Circulo.cpp 
	$(CC) $(CFLAGS) -c $(ENTIDADES_DIR)/Circulo.cpp -I $(INCLUDE_DIR) -o $(BUILD_DIR)/circulo.o
	echo "Arquivo circulo.o criado!"

$(BUILD_DIR)/ponto.o : $(INCLUDE_DIR)/Ponto.hpp $(ENTIDADES_DIR)/Ponto.cpp
	$(CC) $(CFLAGS) -c $(ENTIDADES_DIR)/Ponto.cpp -I $(INCLUDE_DIR) -o $(BUILD_DIR)/ponto.o
	echo "Arquivo ponto.o criado!"

clean:
	rm -f main $(BUILD_DIR)/*.o

















