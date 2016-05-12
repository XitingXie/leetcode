#include <stdlib.h>
#include <stdio.h>
void moveZeroes(int* nums, int numsSize) {
    if(nums==NULL || numsSize<2) return;
    
    int zero[numsSize+1];
    int count =0;
    int i=0;
    int j=0;
    for(i =0;i<numsSize;i++){
        if(nums[i]==0){
            zero[j]=i;
            j++;
        }
    }
    
    count = j;
    zero[count]=numsSize;
    
    for(i=0;i<count;i++){
        int a=zero[i];
        int b=zero[i+1];
        for(int k=a+1;k<b;k++){
            nums[k-1-i] = nums[k];
        }
    }
    
    for(int k=numsSize-1;k>=numsSize-count;--k){
        nums[k]=0;
    }	
}

int main(){
	int s[]={0,1,0,3,0,0,0,0,0,12};
	moveZeroes(s,sizeof(s)/sizeof(int));
	for(int i=0;i<sizeof(s)/sizeof(int);i++){
		printf("%d,",s[i]);
	}
	
}