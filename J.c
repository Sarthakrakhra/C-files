//Help for this question was retrieved from: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

#include <stdio.h> 
#include <stdlib.h>

void swap(int array[], int p1, int p2);
void allPermutations(int num);
void permutaionOfN(int m, int n);
int findPermutation(int array[], int length);
void printPermutation(int array[], int length);

int main(){
  
  int m, n;
  scanf("%d %d", &m, &n);
  
  while(n!=0){
    
    if(m==0 && n!=0)
      allPermutations(n);
    else if(m>0)
      permutaionOfN(m, n);
    
    
    scanf("%d %d", &m, &n);
    
  }
  printf("End of output\n");
  return 0;
}

void allPermutations(int n){
  
  int i=1;
  int array[n]; //= malloc(n * sizeof(int));
  for(; i<=n;i++)
    array[i-1] = i;

  printf("Permutations of %d:\n", n);
  printPermutation(array, n);
  while( findPermutation(array, n) != 0 )
    printPermutation(array, n);
	
}

void permutaionOfN(int m, int n){
  printf("Permutation of %d number %d:\n", n, m);
  int i=1;
  int array[n]; //= malloc(n * sizeof(int));
  for(; i<=n;i++)
    array[i-1] = i;
  
  i=1; 
  for(; i<m; i++){
    if(findPermutation(array, n) == 0){
      return;
    }
  }
  printPermutation(array, n);
}

void printPermutation(int array[], int length){
  int i=0;
  //printing the array
  for(; i<length; i++)
    printf(" %d", array[i]);
  
  printf("\n");
}

int findPermutation(int array[], int length){
  //we go to the last number 
  int a = length-1;
  //keep decrementing a till we find its left value is less than itself
  while((a>0) && (array[a-1] >= array[a]) )
    a--;
  //if we reach the end that means we have reached the end of the permutations
  if(a==0)
    return 0;

  int b = length-1;
  //decrementing b while b is smaller than 1 less than a
  while(array[b] <= array[a-1])
    b--;
 
  //swapping b and a-1
  swap(array, a-1, b);
  
  b = length-1;
  //this while loop essentially sorts everything after a-1
  while(a<b){
    swap(array, a, b);
    a++;
    b--;
  }
  return 1;//returns success 
}

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
