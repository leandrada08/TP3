# Declaro y defino las variables que usare

SRC_DIR=./src
#Direccion de los codigos fuente
OUT_DIR=./build
#Direccion de la carpeta de salida
OBJ_DIR=$(OUT_DIR)/obj
#Direccion del codigo objeto
BIN_DIR=$(OUT_DIR)/bin
#Direccion del codigo ejecutable
DOC_DIR=$(OUT_DIR)/doc
#Direccion de la documentacion
SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
#Lista de archivos que hay que compilar
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
#Lista de archivos .o que necesito generar. El % es lo que no cambiara

# Defino las reglas
# Defino regla para ejecutar por defecto
.DEFAULT_GOAL:= all

# Creo la carpeta /build
$(OUT_DIR):
	mkdir $(OUT_DIR)
# Creo la carpeta /build/obj
$(OBJ_DIR): $(OUT_DIR)
	mkdir $(OBJ_DIR)
# Creo la carpeta build/doc
$(DOC_DIR): $(OBJ_DIR)
	mkdir $(DOC_DIR)

# Creo la carpeta /build/bin
$(BIN_DIR): $(OUT_DIR)
	mkdir $(BIN_DIR)

# Regla para generar los codigos objeto a partir de los codigos fuente 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR) 
	gcc -c $< -o $@ -I inc
# Que es el -I src?

# Defino la regla doc
doc: $(DOC_DIR) 
	doxygen doxyfile

# Defino la regla all
all: $(OBJ_FILES) $(BIN_DIR) #Pongo que necesito OBJ_FILES, para que cuando busque conseguir esto, consiga todo lo otro
	gcc -o $(BIN_DIR)/app.elf $(OBJ_FILES)

clean: $(OUT_DIR)
	rm -r $(OUT_DIR)
