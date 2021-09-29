//https://leetcode.com/problems/rotate-image/
//Copy matrix(n,m) into another matrix(m,n) 
//first row to last column  to last row to first column

//Time Comp:O(n*n)
//Space Comp:O(n*n)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int mat[m][n];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[j][i]=matrix[i][j];
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};