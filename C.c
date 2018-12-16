/*
Sarthak Rakhra
25 October 2018
CSCI2132
A4
This program reads the number of characters in a line from standard input. Then it prints out the line with the number of characters in that line. 
*/
#include <stdio.h>

int main(){
  
  int counter=0;
  char c;
  while(c!= EOF){//if it is evr the EOF then it will just exit the loop
    c = getchar();
    if(c!='\n' && c!=EOF){//as long as the character is not a new line and is not the end of file we increment our counter and output
      putchar(c);
      counter++;
      
    }else if(c =='\n'){//if ever the character is a new line character then we print the number of characters and then reset the counter to 0
      printf(":%d", counter);
      printf("\n");
      counter=0;
    }
   
  }
  return 0;
}
