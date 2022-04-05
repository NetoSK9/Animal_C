#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *LISTA_POSSIBILIDAES[]={
/*0*/                       "vertebrado",
/*1*/                       "invertebrado",
/*2*/                       "ave",
/*3*/                       "mamifero",
/*4*/                       "inseto",
/*5*/                       "anelideo",
/*6*/                       "carnivoro",
/*7*/                       "onivoro",
/*8*/                       "herbivoro",
/*9*/                       "hematofago"};

char *RESULTADOS[]={"aguia","pomba","homem","vaca","pulga","lagarta","sanguessuga","minhoca"};

//Os três primeiros numeros inteiros de cada lista representam as palavras que levam até aquele animal,
// e seu ultimo digito é a posição do animal na lista de resultados;
int AGUIA[]={ 0,2,6,0 };
int POMBA[]={0,2,7,1};
int HOMEM[]={0,3,7,2};
int VACA[]={0,3,8,3};
int PULGA[]={1,4,9,4};
int LAGARTA[]={1,4,8,5};
int SANGUESSUGA[]={1,5,9,6};
int MINHOCA[]={1,5,7,7};

int *ANIMAIS[8]={AGUIA,POMBA,HOMEM,VACA,PULGA,LAGARTA,SANGUESSUGA,MINHOCA};

//imprime a menssagem na formatacao correta
void presentate(int animal){
    printf("%s\n",RESULTADOS[animal]);
}

int set_frs_to_int(char *frs){
    int response;
    
    int i;
    for (i=0;i<(sizeof(LISTA_POSSIBILIDAES)/sizeof(LISTA_POSSIBILIDAES[0]));i++){
        if(strcmp(frs,LISTA_POSSIBILIDAES[i])==0){
            response=i;
        }
    }

    return response;
}

void select_animal(char *frs1,char *frs2,char *frs3){
    //muda as frazes coletadas para um inteiro correspondente e adiciona isso a lista;
    int colected_words[3];
    colected_words[0]=set_frs_to_int(frs1);
    colected_words[1]=set_frs_to_int(frs2);
    colected_words[2]=set_frs_to_int(frs3);
    
    int i,j,auxi,animal;
    for (i=0;i<(sizeof(ANIMAIS)/sizeof(ANIMAIS[0]));i++){
        auxi=0;
        for (j=0;j< ( (sizeof(AGUIA)/sizeof(AGUIA[0]) )-1 );j++){
            if(colected_words[j]==ANIMAIS[i][j]){
                auxi++;
            }
            if(auxi==3){
                animal=ANIMAIS[i][(sizeof(AGUIA)/sizeof(AGUIA[0]))-1];
            }
        }    
    }

    presentate(animal);
}

void read_data_and_run(){
    char frs1[50];
    char frs2[50];
    char frs3[50];
    
    scanf("%s %s %s", &frs1, &frs2, &frs3);

    select_animal(frs1,frs2,frs3);
    
}

int main(){
    read_data_and_run();

    return 0;
}