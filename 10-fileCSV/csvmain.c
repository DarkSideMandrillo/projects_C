#include <stdio.h>
#include <string.h>

int main(){
FILE *fp = fopen("file.csv","r");

if (fp == NULL)
{
    perror("File non aperto");
    return 1;
}

char buffer[1024];

;
while (fgets(buffer,1024,fp))
{
    printf("%s",buffer);
}

fclose(fp);
}


