#include <math.h>
#include <stdio.h>


#include <stdarg.h>
int maxQ(char** matrix, int startX, int startY, int x, int y)
{
	if(x<1||y<1){
		return 0;
	}
	
	int maxS=0;

	for(int i = 0; i<fmin(x,y);i++){
	    bool failed = false;
		int k=0;
		for(;k<i+1;k++){
			if(matrix[startX+i][startY+k] - '0'== 0) {
				failed = true;
				break;
			}
		}
		if(failed) {
			int a = 0;
			if(fmin(x-i-1,y) > maxS) a = maxQ(matrix,startX+i+1,startY,x-i-1,y);
			int b = 0;
			if(fmin(x, y-k-1) > maxS) b = maxQ(matrix,startX,startY+k+1,x,y-k-1);
			return fmax(maxS,fmax(a,b));			
		}
		else{
			int m=0;
			for(;m<i;m++){
				if(matrix[startX + m][startY+i] - '0' == 0) {
					failed = true;
					break;
				}
			}
			if(failed){
				int a = 0;
				if(fmin(x-m-1,y)>maxS) a = maxQ(matrix,startX+m,startY,x-m-1,y);
				int b = 0;
				if(fmin(x, y-i-1) > i) b = maxQ(matrix,startX,startY+i+1,x,y-i-1);
				return fmax(maxS,fmax(a,b));				
			}
		}		
		maxS++;		
	}
	return maxS;
}

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL){
        return -1;
    }
    if(matrixRowSize<0||matrixColSize<0){
        return -1;
    }
    int s= maxQ(matrix,0,0,matrixRowSize,matrixColSize);
	return s*s;
}

int main()
{
	char *matrix[] = {"10111","11111","10111","10011"};
	printf("%d",maximalSquare(matrix,4,5));
}