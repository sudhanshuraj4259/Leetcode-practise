vector <vector <int>> x(34);
bool done=false;
 
class Solution {
public: 
    vector<int> getRow(int n) {
        if(!done){ 
            for(int i=0;i<34;i++){
                x[i].resize(i+1,1);
                for(int j=1;j<i;j++){
                    x[i][j]=(x[i-1][j]+x[i-1][j-1]);
                }
            } 
            done=true; 
        }
        return x[n];        
    }
};
