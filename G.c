#include <stdio.h>

void calculate(char holder[]);
int main(){
    

	char c;
	char holder[205];
	int i=0;

	while( (c = getchar()) != EOF){
		if(c == '\n')
			;
		else{
			holder[i] = c;
			i++;
		}

		if(c == 61){
			calculate(holder);
			int j; 
			for (j = 0; j < i; j++){
				holder[j] = '\0';
			}
			i=0;
		}

	}

	return 0;
}


void calculate(char holder[]){

	char string1[101];
	char string2[101];

	int number1[101];
	int number2[101];
	int sum[101];
	int i=0;	

	while( holder[i]!= 43 ){
		string1[i] = holder[i];
		i++;
	}
	string1[i]='\0';

	i++;
	int j=0;
	while( holder[i] != 61){
		string2[j] = holder[i];
		i++;
		j++;
	}
	string2[j]='\0';

	int k1=0;//length of number 1
	while(string1[k1]!='\0'){
		number1[k1] = string1[k1] - '0';
		k1++;
	}

	int k2=0; //length of number2
	while(string2[k2]!='\0'){
		number2[k2] = string2[k2] - '0';
		k2++;
	}

	int tracker1 = k1-1;
	int tracker2 = k2-1;
	int tracker3 = 0;
	int carryVal=0;

	while((tracker1 >= 0) && (tracker2 >= 0)){
		sum[tracker3] = number1[tracker1] + number2[tracker2] + carryVal;
		sum[tracker3] %= 10; //finding the right value if there is a need for carry

		carryVal = number1[tracker1] + number2[tracker2] + carryVal;
		carryVal /= 10; //we divide it by 10 so that we can find the carry value

		//decrementing all values
		tracker1--;
		tracker2--;
		tracker3++;
	}

	//if the first number is greater than the second number
	if(k1 > k2){

		while(tracker1 >= 0){
			sum[tracker3] = number1[tracker1]+carryVal;
			sum[tracker3] %= 10;

			carryVal = number1[tracker1] + carryVal;
			carryVal /= 10;

			tracker1--;
			tracker3++;
		}

	}else if(k2 > k1){

		while(tracker2 >= 0){
			sum[tracker3] = number2[tracker2]+carryVal;
			sum[tracker3] %= 10;

			carryVal = number2[tracker2] + carryVal;
			carryVal /= 10;

			tracker2--;
			tracker3++;
		}
	}//else{
		if(carryVal > 0){
			sum[tracker3] = carryVal;
			tracker3++;
		}
	//}

	i=0;
	for(;i<k1;i++)
		printf("%d", number1[i]);

	printf("+");


	i=0;
	for (; i < k2; i++)
		printf("%d", number2[i]);

	printf("=\n");
	for(tracker3--; tracker3 >= 0; tracker3--)
		printf("%d", sum[tracker3]);
	printf("\n");
}
