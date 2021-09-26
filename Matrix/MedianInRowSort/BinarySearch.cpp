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
        int mi=INT_MAX,mx=INT_MIN;
        for(int i=0;i<r;i++){
            mi=min(mi,matrix[i][0]);
        }
        for(int i=0;i<r;i++){
            mx=max(mx,matrix[i][c-1]);
        }
        
        int med_count=(r*c+1)/2;
        
        while(mi<mx){
            int mid=(mi+mx)/2;
            int count=0;
            for(int i=0;i<r;i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(count<med_count){
                mi=mid+1;
            }else{
                mx=mid;
            }
        }
        return mi;
    }
};