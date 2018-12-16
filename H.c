#include <stdio.h>
#include <string.h>

//creating a struct to store a word and its number of occurences
struct Word{
	int count;
	char word[81];
};

int search(struct Word a[], int size, char tempString[]); 
void mergesort(struct Word array[], int lower, int upper);
void merge(struct Word array[], int lower, int middle, int upper);
void makeItSmall(char tempString[], int size);

int main(){

	struct Word arrayOfWords[10000];
	int i=0;//to go through the word itself
	int j=0;//to go through the array which stores the struct Word
	char temp;
	char tempString[81]; //temporary string to hold and modify the user input

	while( (scanf("%c", &temp)) != -1){

		//if the character is not an alphabet then we add it to the arrayOfWords
		if (!((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))){
			tempString[i] = '\0';//ending the string with a \0
			makeItSmall(tempString, i);//making the string lowercase

			if (strcmp(tempString,"") != 0){//if string is not empty then we check it
				if (search(arrayOfWords, j, tempString) == 0){//if the word does not exist then we copy it to the Word struct and store in the array
					strcpy(arrayOfWords[j].word, tempString);
					j++;//traversing the array
				}
			i=0;//resetting the i value so user can write again
			}

		}else{//if the character is an alphabet then we store it in the string
			tempString[i] = temp;
			i++;
		}
	}

	//adding the last string
	tempString[i]='\0';
	if((search(arrayOfWords, j, tempString)) == 0){
		strcpy(arrayOfWords[j].word, tempString);
		j++;
	}		

	//sorting the user input and using mergesort algorithm from class
	mergesort(arrayOfWords, 0, j);

	//first 2 spots are reserved for whitespace and EOF characters so that is why k = 2.
	int k=2;

	//printing all the words and its occurences.
	for(; k<=j;k++){
		printf("%s %d\n", arrayOfWords[k].word, arrayOfWords[k].count);
	}

	return 0;
}//end main

//search method to check whether the word already exists or not
int search(struct Word a[], int size, char tempString[]){

	int i=0;
	for(; i < size; i++){//traversing through the entire array
		if((strcmp(a[i].word, tempString) == 0)){//if it does exist then we increment its count
			a[i].count++;
			return 1;// or return true	
		}
	}

	//if the traversal is complete and there is no match we create a Word struct and store it in the arrayOfWords (a in this function)
	struct Word w;
	strcpy(w.word, tempString);
	w.count=1;
	a[size]= w;
	return 0;
}


//mergesort algorithm obtained from class
void mergesort(struct Word array[], int lower, int upper) {
  if (lower < upper) {
    int middle = (lower + upper) / 2;
    mergesort(array, lower, middle);
    mergesort(array, middle+1, upper);
    merge(array, lower, middle, upper);
  }
}

/* middle element is a part of lower sub-array */
void merge(struct Word array[], int lower, int middle, int upper) {
  int len_left = middle - lower + 1;
  int len_right = upper - middle;
  struct Word left[len_left], right[len_right];
  int i, j, k;

  for (i = 0, j=lower; i < len_left; i++, j++)
    left[i] = array[j];

  for (i = 0, j = middle+1 ; i < len_right; i++, j++)
    right[i] = array[j];

  i = j = 0; k = lower;
  while (i < len_left && j < len_right) {
    if ( strcmp(left[i].word, right[j].word) <= 0) array[k++] = left[ i++ ];
    else  array[k++] = right [ j++ ];
  }

  while (i < len_left)  array[k++] = left [ i++ ];
  while (j < len_right) array[k++] = right[ j++ ];

}

//makeItSmall function to convert string to all lowercase characters
void makeItSmall(char tempString[], int size){

	int i=0;
	for(; i<size; i++){
		if(tempString[i] >= 'A' && tempString[i] <= 'Z')
			tempString[i]+=32;//adding 32 to its ascii value will switch the uppercase letter with its corresponding lowercase letter
	}
}
