#include <stdio.h>

void fun1(int *pointer);
void fun2(int **doublePtr);

int main()
{
  int a = 3;

  int *ptr = &a;

  printf("Variabile a: %d\n", a);
  printf("Indirizzo di a: %p\n\n", &a);
  printf("Puntatore di ptr: %p\n", ptr);
  printf("Indirizzo di ptr: %p\n", &ptr);
  printf("Dereferenzazione ptr: %d\n\n", *ptr);

  fun1(ptr);
  fun2(&ptr);
}

void fun1(int *pointer)
{
  printf("Puntatore pointer: %p\n", pointer);
  printf("Indirizzo della dereferenzazione pointer: %p\n", &(*pointer));
  printf("Indirizzo di pointer: %p\n\n", &pointer);
}

void fun2(int **doublePtr)
{
  printf("Puntatore doublePtr: %p\n", doublePtr);
  printf("Indirizzo di doublePointer: %p\n", &doublePtr);
  printf("Deferenzazione di doublePointer che punta a contenuto di di ptr: %p\n", *doublePtr);
  printf("doppia deferenzazione di doublePointer: %d\n", **doublePtr);
}