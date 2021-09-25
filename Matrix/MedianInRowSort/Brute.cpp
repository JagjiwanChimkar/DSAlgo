//https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
//Time Comp: O((r*c)log(r*c))
//Space Comp: O(r*c)

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> arr;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                arr.push_back(matrix[i][j]);
            }
        }
        
        sort(arr.begin(),arr.end());
        return arr[(r*c)/2];
    }
};