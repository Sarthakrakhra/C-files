/*Question3, Sarthak Rakhra, B00766801*/

#include <stdio.h>
#include <float.h>

void minMax(double, double);

int main(){
    int size;
    scanf("%d", &size);
    if(size < 0)
        return 1;
    
    double i, num, min, max;
    min = DBL_MAX;
    max = DBL_MAX*-1;
    while(size > 0){
        for(int i=0; i<size; i++){
            scanf(" %lf", &num);
            if(num<min)
                min = num;
            
            if(num>max)
                max = num;
        }
        minMax(min, max);
        scanf("%d", &size);
        min = DBL_MAX;
        max = DBL_MAX*-1;
    }
    return 0;
}

void minMax(double min, double max){
    printf("Min: %.4lf Max: %.4lf\n", min, max);
}
