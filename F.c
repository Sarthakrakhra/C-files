/* Sarthak Rakhra
 * B00766801
 * CSID: rakhra
 * CSCI2132
 * Assignment 5
 * Question 4
 * 1/11/2018
 * This program reads all the characters from standard input and outputs it. This program is meant to run the luhn checksum algorithm. 
 * It is used to validate if a credit or debit card number is valid or not. This is done by checking the sum of all the integers in the standard input. But
 * it does not directly find the sum and give us an answer. Every second integer starting from the right of the input is multiplied by 2. If the product is two digits,
 * meaning greater than 9 
 * */


#include <stdio.h>
#include <string.h>
int luhn_checksum(int len, int arr[]);
int main(){
	int size;
	scanf("%d", &size);
	int loop =0;
	while(loop<size){
		loop++;
		int i, j;
		char c [51];//creating the size of 51 as \0 is the last character
		scanf("%50s", c);
		int sizeOfnewArray = strlen(c);//the length of the string which the user input
		int newArr [sizeOfnewArray];

		j=0;
		for (int i = sizeOfnewArray-1; i >= 0;i--){
			char ch = c[i];
			int num = ch - '0';
			newArr[j]=num;
			j++;
			
		}
		if(luhn_checksum(sizeOfnewArray, newArr)==1){
			printf("PASS\n");
		}else{
			printf("FAIL\n");
		}
	}

	return 0;
}

int luhn_checksum(int len, int arr[]){
	int j;
	int sum=0;
	int number=0;
	for(j=0; j<len;j++){
		if(j%2!=0){
			number = (arr[j]*2);
			if(number>9){
				int part1 = number/10;
				int part2 = number%10;
				number = part1 + part2;

			}
			sum+=number;
		}else{
			sum+=arr[j];
		}

	}
	if(sum%10==0){
		return 1;
	}
	
	return 0;



}