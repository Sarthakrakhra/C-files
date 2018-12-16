#include <stdio.h>
#include <math.h>

void prime(double num);
int main(){
    double num;
    while (1==scanf(" %lf", &num) && num>1) {
        prime(num);
    }
    return 0;
}

void prime(double n){
    int x;
    int num = (int)n;

    for(x=2; x<(num/2)+1; x++){
        if(num%x==0){
            printf("%d IS NOT PRIME\n", num);
            return;
        }
    }
    printf("%d IS PRIME\n", num);
}
