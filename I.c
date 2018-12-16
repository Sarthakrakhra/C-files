#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **array, int k, int j);
void sort(char **array, int i);
void reallocateMemory(char **array, int i, int j);

int main(){

  char **array;//declaring 2d array
  int size = 1024;
  array = malloc(size * sizeof(char *));//giving it memory for 1024 rows

  char c, prevChar;
  int i, j;
  i=0; j=0;
  
  array[i] = malloc(size * sizeof(char));//allocating memory to the 1st long string in the 2d array

  while( (c = getchar()) != EOF){

    if( (j+2) >= size){//if the string is reaching the buffer size then we reallocate memory to double the 'size'
      size *= 2;
      reallocateMemory(array, i, size);
    }
    
    //if the previous character is a backslash then we add the following new line to the string
    if(c == '\n' && prevChar == '\\'){
      array[i][j] = c;
      j++;
      continue;
    }
    
    //if the character is a new line and the previous character is not a backslash then we end the string and add a '\0'
    if(c == '\n'){
      array[i][j]='\0';
      j=0;
      i++;
      //sort(array, i);
      size = 1024;
      array[i] = malloc(size * sizeof(char *));
      
    }
    //this means that the input is a valid character. Part of the string. 
    else{
      prevChar = c;
      array[i][j] = c;
      j++;
    }
  }
  sort(array, i);//sorting the array
  int i2=0, j2=0;
  //printing the contents
  for(; i2<i;i2++){
    printf("%s\n", array[i2]);	
  }
  
  return 0;
}


void sort(char **array, int i){
  int k = 0;
  
  int j = 0;
  int t;
  
  for(; k<i; k++){
    for(; j<i; j++){
      if(strcmp(array[k], array[j]) < 0){
	swap(array, j, k);
      }
    }
    j=0;
  }
}

void swap(char **array, int k, int j){
  
  char *temp = array[k];
  array[k] = array[j];
  array[j] = temp;
}

void reallocateMemory(char **array, int i, int j){
  array[i] = realloc(array[i], j * sizeof(char));
}
