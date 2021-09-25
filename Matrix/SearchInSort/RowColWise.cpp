//Top-Right  to left-Bottom  pointer approach
//Time Comp: O(n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int i=0,j=m-1;      //Take last element from first row

        while(i<n && j>=0){      
            
            if(target==matrix[i][j]){
                return 1;
            }
            else if(target>matrix[i][j]){   //move ptr to down-side
                i++;
            }
            else {                          //move ptr to left-side
                j--;
            }
        }
        
        return 0;                   //if ptr move-out of the bound             
    }
};