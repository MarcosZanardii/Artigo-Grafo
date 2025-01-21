# Nome do executável e arquivos fonte
EXEC = app
SRC = t2.cpp
OBJ = t2.o

SRC_G = Graph.cpp
OBJ_G = Graph.o

SRC_N = Node.cpp
OBJ_N = Node.o

# Alvo padrão
all: $(EXEC) output

# Regra para criar o executável
$(EXEC): $(OBJ) $(OBJ_G) $(OBJ_N)
	@g++ -o $(EXEC) $(OBJ) $(OBJ_G) $(OBJ_N)

# Regra para compilar o arquivo objeto principal
$(OBJ): $(SRC)
	@g++ -c $(SRC)

# Regras para compilar os arquivos objeto de Graph e Node
$(OBJ_G): $(SRC_G)
	@g++ -c $(SRC_G)

$(OBJ_N): $(SRC_N)
	@g++ -c $(SRC_N)

# Regra para executar
run:

	@echo -n "caso40_a.txt : "
	@./$(EXEC) < caso40_a.txt

	@echo -n "caso80_a.txt : "
	@./$(EXEC) < caso80_a.txt

	@echo -n "caso100_a.txt: "
	@./$(EXEC) < caso100_a.txt	

	@echo -n "caso120_a.txt: "
	@./$(EXEC) < caso120_a.txt

	@echo -n "caso150_a.txt: "
	@./$(EXEC) < caso150_a.txt	

	@echo -n "caso180_a.txt: "
	@./$(EXEC) < caso180_a.txt
	
	@echo -n "caso200_a.txt: "
	@./$(EXEC) < caso200_a.txt
	
	@echo -n "caso250_a.txt: "
	@./$(EXEC) < caso250_a.txt
	
# Regra para limpar arquivos gerados
clean:
	@rm -f $(OBJ) $(OBJ_G) $(OBJ_N) $(EXEC)

#regra para saida em arq
output:

	@./$(EXEC) < caso40_a.txt 1> output.txt	

	@./$(EXEC) < caso80_a.txt 1>> output.txt

	@./$(EXEC) < caso100_a.txt 1>> output.txt

	@./$(EXEC) < caso120_a.txt 1>> output.txt

	@./$(EXEC) < caso150_a.txt 1>> output.txt

	@./$(EXEC) < caso180_a.txt 1>> output.txt

	@./$(EXEC) < caso200_a.txt 1>> output.txt

	@./$(EXEC) < caso250_a.txt 1>> output.txt

	@cat output.txt
