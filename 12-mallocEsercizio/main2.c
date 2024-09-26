#include <stdio.h>
#include <stdlib.h>

int* createArray(int dimArray);

int main(){
    int dimArray=0;
    printf("Crea un array di dim variabile");
    printf("Inserisci la dimensione: ");
    scanf("%d",&dimArray);

    int *arr = createArray(dimArray);

    for (size_t i = 0; i < dimArray; i++)
        printf("%d-",arr[i]);
    
}
int* createArray(int dimArray){
    int *arr = (int *) malloc(sizeof(int) * dimArray);
    for (size_t i = 0; i < dimArray; i++)
        arr[i]=i;
    return arr;
   }
