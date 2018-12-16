/*
Sarthak Rakhra
25 October 2018
CSCI2132
A4
This program takes in a number and the user has to input that many values. Once the user reaches reaches the last value it will output the median and average values which were input. Those numbers are stored in an array. That array is then sorted, and the median and average is found from that same array.

*/

# include <stdio.h>

void mergesort(double arr[], int lower, int upper);
void merge(double arr[], int lower, int middle, int upper);
double avg(double arr[], int size);
double med(double arr[], int size); 
int main(){
  
  int size, i;
  
  scanf("%d", &size);

  while(size>0){
    double arr [size];
    for(i=0; i<size; i++){
      scanf(" %lf", &arr[i]);
    }
    mergesort(arr, 0, size-1);
   
    printf("Avg: %.3lf Med: %.3lf\n", avg(arr, size), med(arr, size));
    scanf("%d", &size);
  }

  return 0;
}

void mergesort(double arr[], int lower, int upper){
  if(lower<upper){
    int middle = (lower+upper)/2;
    mergesort(arr, lower, middle);//sorting the left half of the array
    mergesort(arr, middle+1, upper);//sorting the right half of the array
    merge(arr, lower, middle, upper);//merging the left and right half of the array
  }
}

void merge(double arr[], int lower, int middle, int upper){
  int len_left = middle-lower+1;
  int len_right = upper-middle;
  double left[len_left], right[len_right];
  int i, j, k;

  //assigning values to the left side of the array in another array
  for(i=0, j = lower; i<len_left; i++, j++)
    left[i]=arr[j];

  //assigning values to the right side of the array in another array
  for(i=0, j = middle+1; i<len_right; i++, j++)
    right[i]=arr[j];

  i=j=0;
  k=lower;

  while(i<len_left && j<len_right){
    if(left[i]<=right[j])//comparison. If any of them is greater than or less than then we assign them to the original array we sent in
      arr[k++]=left[i++];
    else
      arr[k++]=right[j++];
  }

  //if ever one sub-array has already reached its end then we just have to append the values of the longer sub-array into our original array
  while(i<len_left)
    arr[k++]=left[i++];
  while(j<len_right)
    arr[k++]=right[j++];

}

double avg(double arr[], int size){
  double avg, sum;
  int i;
  for(i=0; i<size; i++)
    sum+=arr[i];
  avg=sum/size;
  return avg;
}

double med(double arr[], int size){
  if(size%2==0){
    return (arr[(size/2)]+arr[(size/2)-1])/2;//if the array had even number of elements then we return the average of the two elements
  }else
    return arr[(size/2)];//if the array had odd number of elements then we just return the middle value
}
