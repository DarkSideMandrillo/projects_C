/*
    Sviluppa un programma che crei, popoli, modifichi e stampi un array di interi o caratteri con diverse funzioni:
    Func crea
    Func popola: da 1 a 10 o da A a J
    Func modifica: aumenta di 1 o la lettera successiva
    Func stampa

    Usa la Malloc
*/

#include <stdio.h>
#include <stdlib.h>


void * createArray(int typeArray);
void populateArray(void * array, int typeArray);
void modifyArray(void * array, int typeArray);
void stampArray(void * array, int typeArray);




int main(){
int typeArray;
void *array;
printf("Scegli il tipo di array:\n1 - integer\n2 - character\n");
scanf("%d",&typeArray);


if (typeArray == 1)
    array = (int*)createArray(typeArray);
if (typeArray ==2)
    array = (char*)createArray(typeArray);

populateArray(array,typeArray);
modifyArray(array,typeArray);
stampArray(array,typeArray);
free(array);
}

void * createArray(int typeArray){
    if (typeArray == 1)
        {
            int *arr = (int*) malloc(10*sizeof(int));
            return arr;
        }
    if (typeArray == 2)
        {
            char *arr = (char*) malloc(10*sizeof(char));
            return arr;
        }
}

void populateArray(void * array, int typeArray){
    if (typeArray == 1)
    {   
        int *arrayInt = (int*) array;
        for (size_t i = 0; i < 10; i++)
        {
            arrayInt[i]=i;
        }        
    }
    if (typeArray == 2)
    {   
        char *arrayChar = (char*) array;
        for (size_t i = 0; i < 10; i++)
        {
            arrayChar[i]=65+i;
        }        
    }
}

void modifyArray(void * array, int typeArray){
    if (typeArray == 1)
    {   
        int *arrayInt = (int*) array;
        for (size_t i = 0; i < 10; i++)
        {
            arrayInt[i]=arrayInt[i]+1;
        }        
    }
    if (typeArray == 2)
    {   
        char *arrayChar = (char*) array;
        for (size_t i = 0; i < 10; i++)
        {
            arrayChar[i]=arrayChar[i]+1;
        }        
    }
}
    
void stampArray(void * array, int typeArray){
  
    if (typeArray == 1)
    { 
        int *arrayInt = (int*) array;
        for (size_t i = 0; i < 10; i++)
            printf("%d ",arrayInt[i]);
    }
    if (typeArray == 2)
    {   
        char *arrayChar = (char*) array;
        for (size_t i = 0; i < 10; i++)
            printf("%c",arrayChar[i]);  
    }
}
    

