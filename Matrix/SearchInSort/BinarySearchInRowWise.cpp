//https://leetcode.com/problems/search-a-2d-matrix/
//First find a row in which target can present 
//then apply binary search on that row of matrix
//Time Comp: O(n+logm)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        bool flag=false;
        int n=matrix.size(),m=matrix[0].size();
        
        for(int i=0;i<n;i++){
              if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                  row=i;
                  flag=true;
                  break;
              }
        }   
        
        if(flag){                  //if row found
            int low=0,high=m-1;

            while(low<=high){
                int mid=(low+high)/2;
                int value=matrix[row][mid];

                if(value==target){
                    return 1;
                }
                else if(value<target){
                    low=mid+1;
                }
                else if(value>target){
                    high=mid-1;
                }
            }
        }
        
        return 0;                   //if row or target in bonary search not found
    }
};