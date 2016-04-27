char* longestPalindrome(char* s) {
    int cur=0;
    int longest = 1;
    int N = strlen(s);
    int i,j,length;
    int start=0,end=0;
    
    while(cur+1<N){
        if(s[cur] == s[cur+1]){
            i = cur-1;j=cur+2;
            length=2;
        }
        else{
            i=cur-1;j=cur+1;
            length = 1;
        }
        
        while(i>-1 && j<N){
            if(s[i] == s[j]){
                length +=2;
                --i;
                j++;
            }
            break;
        }
        
        if(longest<length) {
            longest = length;
            start = i+1;
            end = j-1;
        }
        cur++;
    }
    
    char *new_S = (char*)malloc(sizeof(char)*(longest+1));
    for(i=0;i<longest;i++){
        new_S[i] = s[start+i];
    }
    
    return new_S;
}