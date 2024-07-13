GCC = gcc
BIBLIOTECA = ./lib/*
FILE_MAIN = leitor.c
FILE_MAIN2 = hexinstall.c
FOLDER = ./bin/hexread
FOLDER2 = ./bin/hexinstall


all: compiler_hexread 


compiler_hexread:
	@$(GCC) $(FILE_MAIN) $(BIBLIOTECA) -o $(FOLDER) 

hexinstall:
	@$(GCC) $(FILE_MAIN2) $(BIBLIOTECA) -o $(FOLDER2)
