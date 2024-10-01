/*
    Sviluppa un programma che crei, popoli, modifichi e stampi un array di interi con diverse funzioni:
    Func crea
    Func popola: da 1 a N
    Func modifica: aumenta di 1 i numeri dispari
    Func stampa

    Usa la Malloc
*/

#include <stdio.h>
#include <stdlib.h>


int * createArray(int const *lenghtArray);
void populateArray(int * array,int lenghtArray);
void modifyArray(int * array,int lenghtArray);
void stampArray(int * array,int lenghtArray);

int main(){
int lenghtArray;
printf("Quale vuoi che sia la lunghezza dell'array?");
scanf("%d",&lenghtArray);

int *array =createArray(&lenghtArray);
populateArray(array,lenghtArray);
modifyArray(array,lenghtArray);
stampArray(array,lenghtArray);

free(array);

}

int * createArray(int const *lenghtArray){
    return (int*)malloc((*lenghtArray)*sizeof(int));
}

void populateArray(int * array,int lenghtArray){
    for (size_t i = 0; i < lenghtArray; i++)
        array[i]=i+1;
    }

void modifyArray(int * array,int lenghtArray){
    for (size_t i = 0; i < lenghtArray; i++)
    {
        if (array[i]%2!=0)
        {
            array[i]+=1;
        }        
    }
    
}

void stampArray(int * array,int lenghtArray){
    for (size_t i = 0; i < lenghtArray; i++)
    {
        printf("%d - ",array[i]);
    }
    
}

