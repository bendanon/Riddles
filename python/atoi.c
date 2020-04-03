#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>

//gcc atoi.c -lm -o atoi -g

/*
We only need to handle four cases:
    Discards all leading whitespaces
    Sign of the number
    Overflow
    Invalid input

Detecting overflow gets tricky. You need to detect overflow before the number is
about to overflow. So:

    If the number is positive and the current number is greater than MAX_INT/10,
    and you are about to append a digit, then certainly your number will overflow.
    If the current number = MAX_INT / 10, then based on the last digit, we can
    detect if the number will overflow.

*/

int my_atoi(const char* A) {
    int num = 0;
    int i = 0;
    int j = 0;
    int negative = 0;    
    char buf[10];
    memset(buf, '0', sizeof(buf));
    
    while(A[i] == ' ' || A[i] == '\t') i++;
    
    while(j < sizeof(buf)){
        char c = A[i++];

	if(j == 0 && c == '-') {
		negative = 1;
		c = A[i++];
	}
 
        if(!isdigit(c)) break;
        
        buf[j++] = c;
    }

    
    int multiplier = 1;

    
    for(i = j-1; i >= 0; i--){
        num += ((int)(buf[i]) - 48) * multiplier;
	if(j == 10 && num > (INT_MAX % multiplier) || (negative && num < (INT_MIN % multiplier))){
		return negative ? INT_MIN:INT_MAX;
	}
        multiplier *= 10;
    }
    
    return negative ? 0 - num : num;
}

int test_print(const char* A, int expected){
	int num = my_atoi(A);
	if(num == expected){
		printf("Success with %d\n", num); 
	}
	else{
		printf("Failure. result: %d, expected: %d\n", num, expected);
	}
}

int main(){

	test_print("552147483648 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393", INT_MAX);
	test_print("5121478262 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393", INT_MAX);
	test_print("999", 999);
	test_print("-999", -999);
	test_print("    1", 1);
	test_print("2147483648", INT_MAX);
	test_print("-2147483648", INT_MIN);
	test_print("-2147483649", INT_MIN);
	test_print("*4444**345", 0);
}

