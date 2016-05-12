/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(digits== NULL) {*returnSize=0;return NULL;}
    if(digitsSize==0) {*returnSize=digitsSize;return digits;}
    
    int* r = (int*)malloc(sizeof(int)*(digitsSize+1));
    
    int m = digits[digitsSize-1]+1;
    r[digitsSize]=m%10;
    int k = m/10;
    
    for(int i=digitsSize-1;i>0;--i){
        m = digits[i-1]+k;
        r[i]=m%10;
        k=m/10;
    }
    
    r[0] = k;
    *returnSize = digitsSize+k;
    return r+1-k;
}

int main(){
	int d[]={0};
	int l=0;
	int *r = plusOne(d,sizeof(d)/sizeof(int),&l);
	for(int i=0;i<l;i++){
		printf("%d,",r[i]);
	}
	printf("\n");

}