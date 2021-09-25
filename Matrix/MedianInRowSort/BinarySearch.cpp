//User function template for C++
//first take min and max from matrix
//binary search on min and max and 
//find mid whose count is less than equal to (r*c)/2
//count no of element who is less than eqaul to mid by row wise;

//Time Comp: O(32*r*log(c))
//Spac Comp: O(1)

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
       int min=INT_MIN,max=INT_MAX;
       for(int i=0;i<r;i++){
           if(matrix[i][0]<min){
               min=matrix[i][0];
           }
           if(matrix[i][c-1]>max){
               max=matrix[i][c-1];
           }
       }
       
       int med_count=(r*c+1)/2;
       
       while(min<max){
           int count=0;
           int mid=(min+(max-min))/2;
           for(int i=0;i<r;i++){
               count+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
           }
           if(count<med_count){
               min=mid+1;
           }else{
               max=mid;
           }
       }
       
       return min;
    }
};