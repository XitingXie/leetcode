#include <stdio.h>

int Queens[8];
int count = 0;

void NQueens(int k){
	int i;
	int m;
	
	if(k>=8) {
		for(i=0;i<8;i++){			
			printf("%d,", Queens[i]);
		}
		printf("\n");
		count++;
		return;
	}
	

	for(m=0;m<8;m++){
		for(i=0;i<k;i++){
			if(Queens[i] - m == k-i || Queens[i] - m == i-k || m == Queens[i]){
				break;
			}
		}
		if(i==k){
			Queens[k]=m;
			NQueens(k+1);
		}
	}
	return;
}

int main(){
	for(int i=0;i<8;i++){
		Queens[i]=-1;
	}
	for(int i=0;i<8;i++){
		Queens[0]=i;
		NQueens(1);
	}
	printf("total:%d\n",count);
}