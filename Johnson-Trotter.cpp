#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Esse algoritmo é usado para encontrar todas as permutações (incluir listas ordenadas e sem repetiçāo)
//se um componente k apontar pra um número menor ao lado, o componente k deve ser um componente móvel
//primeira etapa: definiçāo da maior etapa do componente móvel
//segunda etapa: troca-se o componente móvel com o dígito ao lado
//etapa três: para todos os dígitos maior que os componentes móveis, inverter a direçāo desses dígitos.


struct element {
    int value;
    int state;
};
#define MAXN 100
element arr[MAXN];
int counter=0;


void swap(int i,int j){
    element t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

void JST(int n,int maxIndex) {
    printf("The %dth:",++counter);
    for(int i=1; i<=n; i++) {
        printf("%d",arr[i]);
    }
    printf("\n");


    int maxIndexValue=arr[maxIndex].value;
    swap(maxIndex,maxIndex+arr[maxIndex].state);

    for(int i=1;i<=n;i++){
        if(arr[i].value>maxIndexValue){
            arr[i].state=(arr[i].state==1)?-1:1;
        }
    }

    int isCanMove=false;
    int flagMax;
    int valueMax=-1;
    for(int i=1; i<=n; i++) {

        if(arr[i].state==1) {
            if(arr[i].value>arr[i+1].value&&arr[i].value>=valueMax) {
                flagMax=i;
                valueMax=arr[i].value;
                isCanMove=true;
            }
        }

        if(arr[i].state==-1) {
            if(arr[i].value>arr[i-1].value&&arr[i].value>=valueMax) {
                flagMax=i;
                valueMax=arr[i].value;
                isCanMove=true;
            }
        }
    }
    if(isCanMove) JST(n,flagMax);
    else {
        printf("The %dth:",++counter);
        for(int i=1; i<=n; i++) {
            printf("%d",arr[i]);
        }
    }
    return ;
}
int main() {
    srand(time(NULL));
    int n = rand() % 5+2;
    arr[0].value=8888;
    arr[n+1].value=8888;
    for(int i=1; i<=n; i++) {
        arr[i].value=i;
        arr[i].state=-1;
    }
    JST(n,n);
    printf("\n The number of %d is arranged in a total of %d",n,counter);
}