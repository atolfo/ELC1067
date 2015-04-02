#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_alunos(int* matriculas, char nomes[][50], int* n){
    int mat;
    char c;
    char nome[50];
    int i;
    int linha;
    FILE*f = fopen("alunos.txt", "r");
    linha = 0;

    while(feof(f) == 0){
        if(fscanf(f, "%d", &mat) < 0)
        break;
        i = 0;
        c = fgetc(f);
        while(c != '\n'){
            nome[i] = c;
            c = fgetc(f);
            i++;
        }
        nome[i] = '\0';
        matriculas[linha]=mat;
        nomes[linha] = (int*) malloc(TAM*sizeof(int));
        strcpy(nomes[linha],nome);
        linha++;
         if(linha >= 50)
            {
                matAlunos = (int*) realloc(matriculas, TAM*sizeof(int));
                nomes = (int**) realloc(nomes, TAM*sizeof(int*));
            }
    }
    *n = linha;
    fclose(f);
}

void le_notas (float* medias){
    int i=0,mat;
    float n1,n2;
    FILE*f = fopen("notas.txt", "r");
    while(feof(f) == 0){
        if(fscanf(f, "%d %f %f\n", &mat, &n1, &n2) < 0)
        break;
        medias[i]=(n1+n2)/2;
        i++;
    }
    fclose(f);
}

void procura_aluno (char nome[50], char nomes[][50], int n, float* medias){
    int i=0;
    for(i = 0; i<n; i++){
        if(strstr(nomes[i], nome)!=NULL){
            printf("%f %s", medias[i], nomes[i]);
        }
    }
    return;
}

int main(int argc, char** argv){
    char nome[50];
    if(argc > 1){
        strcpy(nome, argv[1]);
    }
    printf("%s\n", nome);
    int matriculas[50];
    char nomes[50][50];
    int n;
    le_alunos(matriculas, nomes, &n);
    float medias[50];
    le_notas(medias);
    procura_aluno(nome,nomes,n,medias);

}
