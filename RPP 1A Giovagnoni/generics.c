#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "generics.h"

void SetInt(int* num, char* msg){
    printf(msg);
    scanf("%d",num);
}

void SetFloat(float* num, char* msg){
    printf(msg);
    scanf("%f",num);
}

void SetString(char* str, char* msg){
    printf(msg);
    fflush(stdin);
    scanf("%s",str);
}

void SetChar(char* chara, char* msg){
    printf(msg);
    scanf("%c",chara);
}

void Alert(char* msg){
    printf(msg);
    system("pause");
    system("cls");
}
