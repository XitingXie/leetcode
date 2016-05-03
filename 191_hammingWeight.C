#include <stdio.h>
typedef unsigned int uint32_t;
int hammingWeight(uint32_t n) {
    int count=0;
    uint32_t number = n;
    while(number>0){
        if(number%2==1) count++;
        number = number/2;
    }
    return count;
}

int main(){
	uint32_t n = 2147483648;
	printf("%d\n", hammingWeight(n));
	
	return 1;
}