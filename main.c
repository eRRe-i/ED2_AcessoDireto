#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Registro {
    unsigned int cod_registro;
    int prox;
} Registro;

//void escrever_registro(FILE* file, unsigned int cod_registro);
void inicializar_tabela(FILE* file, char* hashSize);

int main (int argc, char* argv[]) {

    FILE* file;
    int value = 0;

    switch(argc){
        case 1:
        case 2: printf("Too few arguments.\n");
                return -1;
        case 3: if(atoi(argv[1]) == 1)
                inicializar_tabela(file, argv[2]);
                return 0;
    }

    return 0;
}


void inicializar_tabela(FILE* file, char* hashSize){

    char filename[20] = "arquivo";
    strcat(filename, hashSize);
    strcat(filename, ".bin");

    int hashSizeInt = atoi(hashSize);
    file = fopen(filename, "wb");
    Registro* reg = (Registro*)malloc(sizeof(Registro));
    reg->cod_registro = 0;
    reg->prox = -1;

    for(int i=0; i < hashSizeInt; i++){
        fwrite(reg, sizeof(Registro), 1, file);
    }

    printf("Tabela criada com %d posições\n", hashSizeInt);
    free(reg);
    fclose(file);
}

// void escrever_registro(FILE* file, unsigned int cod_registro ){

//     Registro* reg = (Registro*)malloc(sizeof(Registro));
//     reg->cod_registro = cod_registro;

//     fseek(file, sizeof(Registro), SEEK_END);
// }

