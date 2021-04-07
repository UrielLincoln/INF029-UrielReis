#define QTD 5
#include <string.h>

void cadastrarprofessor();
//FUNçÕES DO ALUNO
//void cadastraraluno(char *nome[], char *data, char *sexo);
void menu();
//void menualuno();
//void listar();

//ESTRUTURAS
typedef struct{
    int matricula;
    char matri[10],nome[50],CPF[15],sexo,dtnasc[20];
    char sexoc[10];
    char copdat[10];
    int cadastrado;
} cadaluno;
cadaluno alunos[QTD];

typedef struct{
    int matricula;
    char matri[10], nome[50], CPF[15], sexo,dtnasc[20];
    char sexoc[10];
    char copdat[10];
    int cadastrado;
} cadprof;
cadprof prof[QTD];

typedef struct{
    char nome[20];
    long int codigo,semestre;
    char nomeprof[20];
} caddisc;
caddisc disc[QTD];