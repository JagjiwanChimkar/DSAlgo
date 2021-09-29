//1.Transpose the matrix 
//2.then reverse each row

//Time Comp: O(n*n)
//Space Comp: O(1)

class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++){                  //1
            for(int j=0;j<i;j++){              //iterate j till i
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());  //2
        }
    }
};