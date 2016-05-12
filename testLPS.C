#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* shortestPalindrome(char* s) {
    if(s==NULL) return NULL;
    if(strlen(s) == 0) return s;
    
    int j = strlen(s)-1;
    while(j>-1 ){
        {
            int m =0;
            int n = j;
            while(m<n && s[m] == s[n]){
                m++;
                --n;
            }
            
            if(m>=n){
                if(j == strlen(s)-1) return s;
                
                char* prefix = (char*)malloc(sizeof(2*strlen(s)-j-1));
				if(prefix == NULL) {printf("Error!\n");return NULL;}
				
                for(int k = strlen(s) - 1;k>j;--k){
                    prefix[strlen(s)-1-k] = s[k];
                }
                
                for(int k =0;k<strlen(s);k++){
                    prefix[strlen(s)-1-j+k] = s[k];
                }
                return prefix;
            }
        }            
        --j;
    }
    return NULL;
}

int main()
{
	char s[]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char *news = shortestPalindrome(s);
	printf("%s\n",news);

}
