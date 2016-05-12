#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<string> > queens;
    vector<string> s_queen;
    int* queen;
    
    void NQueens(int k, int n){
        int i,m;
        if(k>=n){
            s_queen.clear();
            for(i=0;i<n;i++){
                string s;
                for(m=0;m<queen[i];m++){
                    s.push_back('.');
                }
                s.push_back('Q');
                for(m=queen[i]+1;m<n;m++){
                    s.push_back('.');
                }
                s_queen.push_back(s);
            }
            queens.push_back(s_queen);
        }
        
        for(m=0;m<n;m++){
            for(i=0;i<k;i++){
                if(queen[i]-m == i-k || queen[i]-m == k - i || queen[i] == m) break;
            }
            if(i==k){
                queen[k] = m;
                NQueens(k+1,n);
            }
        }
        return;
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
		queen = (int*)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++){
		    queen[0]=i;
		    NQueens(1,n);
	    }
        return queens;
    }
	
	Solution(){}
};

int main(int argc,char *argv[]){
	Solution s;
	vector< vector<string> > v(s.solveNQueens(100));

	cout<<v.size()<<endl;
	
	return(0);
}

