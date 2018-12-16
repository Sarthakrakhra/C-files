/*Sarthak Rakhra
 * B00766801
 * CSID: rakhra
 * CSCI2132
 * Assignment 5
 * Question 3
 * 1/11/2018
 * This program reads from standard input and outputs all the alphabets it sees. If it ever encounters
 * any character which is not an alphabet then it will just be ignored or a new line will be [rinted
 * according to the state variable. If the state variable is 1 then a new line will be printed.
 * If it is zero then the character which is not a letter ill be ignored till an alphabet is read.
 * */

#include <stdio.h>

int main() {
    char c;
    int state = 0;

    while((c=getchar()) != EOF){
        if(state==0){
            if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c<= 'z')) {
                putchar(c);
                state = 1;
            }
            continue;
        }

        if(state==1){
            if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c<= 'z')) {
                putchar(c);
            }else{
                putchar('\n');
                state=0;
            }

        }

    }
    return 0;
}
