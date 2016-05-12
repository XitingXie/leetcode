

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int r[120][5];
int count=0;
int size=5;
int nums[]={1,2,3,4,5};
void putIn(int* a, int cur){
	if(cur==size){
		for(int i=0;i<size;i++){
			r[count][i]=a[i];
		}
		count++;
		return;
	}
	int j;
	for(int i=0;i<size;i++){
		for(j=0;j<cur;j++){
			if(nums[i]==a[j]) break;
		}
		if(j==cur) {
			a[j]=nums[i];
			putIn(a,cur+1);
		}
	}
}

void permute(int* nums, int numsSize) {    
    
    int* a = (int*)malloc(sizeof(int)*3);
	
	putIn(a,0);
    
}

int main(int argc, char* argv[]){
		
	permute(nums,size);
	
	for(int i=0;i<120;i++){
		for(int j=0;j<size;j++){
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",count);
	return 1;
}