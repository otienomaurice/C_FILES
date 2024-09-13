
//program to print info about the compiler used
#define SIZE 100
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]){
//
char GCC_V[SIZE];
FILE *point = popen("gcc -v","r");
fgets(GCC_V,sizeof(GCC_V),point);
printf("%s",GCC_V);		
}