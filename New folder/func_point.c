#include <stdlib.h>
#include <stdio.h>

double calculate( double (* operation) (int,int), int, int);
double add(int a ,int b);
double sub(int a ,int b);
double mult(int a ,int b);
double div(int a,int b);

int main (){
    double (* operate) (int,int) ;
    int a = 10, b = 20;
    operate = add;
    printf("%f",calculate(operate,a,b));
     operate = sub;
    printf("%f",calculate(operate,a,b));
     operate = mult;
    printf("%f",calculate(operate,a,b));
     operate = div;
    printf("%f",calculate(operate,a,b));
}

double calculate( double (* operation) (int,int),int a, int b){
   return operation(a,b);
    }
    double add(int a ,int b){
        return (double) a+b;
    }
double sub(int a ,int b){
    return (double) (a >b)? a-b: b-a;
}
double mult(int a ,int b){
    return (double) a*b;
}
double div(int a,int b){
    if (b = 0){
        return -1;
    }
    return (double)a/b;
}
