#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define m 10
#define n 30

/** Full name: Hung Mao Chen **** Gnumber: G01145163  *********  README  ****************
********  I would explain my prgram flow here   *****************************************
********  we would get the input of 10 strings in main function first   *****************
********  then I use the chk_if_special function to check:    ***************************
********  1. is the word so long?   *****************************************************
********  2. you input an empty string?   ***********************************************
********  3. you input an invalid string with special char?   ***************************
********  4. you input a duplicate string?    *******************************************
********  you would need to re-input the string if you break any rules above   **********
********  after pass the check, the input char arrays would be put into   ***************
********  function of asc() to make Ascending Bubble Sort    ****************************
********  If user want ascending order, we print the char array from index of 0    ******
********  If user want descending order, we print the char array from the last one    ***
*****************************************************************************************/

int chk_if_special(char str[m][n],int index,int count);
void asc(char str[m][n]);

int main(){

	int i,x;     // use for loop index
	int ck;      // to record the index of loop
	int max = 30;      // the max limit length of input
	int number = 10;      // number of strings 
	char strings[10][30];    // char array to store our all input strings
	int count;         // the length of user input
	int chk_result;     // the result of the check
	char asc_or_desc;      // user want ascending or descending?

	printf("Enter 10 chracter strings:\n\n");

	for(i=0;i<10;i++){
		printf("Enter string %d: ",i+1);
		fgets(strings[i],max,stdin);            // get user input
		count = strlen(strings[i]);
		ck = i;

		do{
			chk_result = chk_if_special(strings,ck,count);
		}while(chk_result == 0);
	}
	asc(strings);                      // after checking, we can put our string to be bubble sorted
	printf("Print character strings in Ascending or Descending order:");
	scanf("%c",&asc_or_desc);
	
	printf("\n");
	
	if(asc_or_desc == 65){              // if user want ascending order
		for(x=0;x<10;x++){
			printf("%s",strings[x]);
		}
	}else if(asc_or_desc == 68){        // if user want descending order
		for(x=9;x>=0;x--){
			printf("%s",strings[x]);
		}
	}else{
		printf("No, you need to answer with A or D! Good Bye~\n");
	}
	printf("String with the lowest ascii value: %s\n",strings[0]);
	printf("String with highest ascii value: %s\n",strings[9]);
	return 0;
}

int chk_if_special(char str[m][n],int index,int count){
	int c,d;
	int result;
	int max = 30;
	result = 0;
	while(result == 0){
		if(count > 25){      // whether user input is so long?
			result = 0;
			printf("You string is so long\n");
			printf("Enter string %d:\n",index+1);
			fgets(str[index],max,stdin);
			break;
		}
		if(str[index][0] == '\n'){    // whether user input is empty
			result = 0;             // the first one of empty string must also be empty
			printf("You enter an empty string\n");
			printf("Enter string %d:\n",index+1);
			fgets(str[index],max,stdin);
			break;
		}
		for(c=0;c<count;c++){
			if(ispunct(str[index][c])!=0){         // whether user input is special characters?
				result = 0;                    // here we loop over any char in the string
				printf("You input an invalid string\n");  
				printf("Enter string %d:\n",index+1);
				fgets(str[index],n,stdin);
				break;
			}else{
				result = 1;
			}
		}
		for(d=0;d<index;d++){
			if(strcmp(str[index],str[d]) == 0){    // whether user input is same as previous ones?
				result = 0;
				printf("You enter a duplicate string\n");
				printf("Enter string %d:\n",index+1);
				fgets(str[index],max,stdin);
				break;
			}else{
				result = 1;
			}
		}
	}
	return result;
}

void asc(char str[m][n]){       // bubble sort in ascending order
	int a,b;
        char swap[30];
        for(a=0;a<10;a++){
                for(b=a;b<10;b++){
                        if(strcmp(str[a],str[b]) > 0){       // strcmp will compare with ascii value
                                strcpy(swap,str[a]);
                                strcpy(str[a],str[b]);
                                strcpy(str[b],swap);
                        }
                }
        }

}
