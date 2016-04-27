char* longestPalindrome(char* s) {
	
	if(s==NULL) return NULL;
	
	int longest = 1;
	int N = strlen(s);
	int i,j,m,k;
	int start=0,end=0;
	
	if(N==1||N==0) return s;
	
	for(i=0;i<N-longest;i++){
		j = N-1;
		while(j-i+1>longest){
			m=i;
			k=j;
			while(m<k){
				if(s[m] != s[k]) break;
				m++;--k;
			}
			if(m>k || m==k){
				longest = j-i+1;
				start = i;
				end = j;
				break;
			}
			--j;
		}
	}
	
	s[end+1] = '\0';
	return s+start;
}