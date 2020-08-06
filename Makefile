#-------------------------------------------------------------------------------
#-------------------------------------------------------------------------------

OBJETOS	:= build/main.o build/input.o build/generarVector.o build/sort.o build/pruebaDicotomica.o

#-------------------------------------------------------------------------------
# make commands
#-------------------------------------------------------------------------------
all: Ordenacio

Ordenacio: $(OBJETOS)
	gcc -o Ordenacio $(OBJETOS)

build/main.o: main.c
	gcc -c main.c -o build/main.o

build/input.o: input.c input.h
	gcc -c input.c -o build/input.o

build/generarVector.o: generarVector.c generarVector.h
	gcc -c generarVector.c -o build/generarVector.o

build/sort.o: sort.c sort.h
	gcc -c sort.c -o build/sort.o

build/pruebaDicotomica.o: pruebaDicotomica.c pruebaDicotomica.h
	gcc -c pruebaDicotomica.c -o build/pruebaDicotomica.o
	
clean:
	rm -f Ordenacio.exe $(OBJETOS)