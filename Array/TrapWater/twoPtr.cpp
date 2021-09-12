//We destructing this formula : min(left_max,right_max) – arr[i]
//Instead of 2 prefix & Suffix array,
//We maintain left_max,right_max variables to store the maximum till that point.
//Move the pointers till lo <= hi

//Calculate water trapped on smaller elements out of A[lo] and A[hi] first 

//Time Comp: O(N)
//Space Comp : O(1)

class Solution {
public:
    
    int trap(vector<int>& height) {
        int trap=0;
        int n=height.size();
        
        int left_max=0,right_max=0;
        
        int l=0,h=n-1;
        
        while(l<=h){
            if(height[l]<=height[h]){
                if(height[l]>=left_max){
                    left_max=height[l];
                }else{
                    trap+=left_max-height[l];
                }
                l++;
            }
            else{
                if(height[h]>=right_max){
                    right_max=height[h];
                }else{
                    trap+=right_max-height[h];
                }
                h--;
            }
        }
        return trap;
    }
};