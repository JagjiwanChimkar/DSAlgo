//1. Tranverse from right and check which index1 is arr[i]<arr[i+1] => 1 "3 5" 4 2
//2. Tranverse from right and check which index 2 is arr[index2]>arr[index1] => 1 '3' 5 "4" 2
//3. swap(arr[index1],arr[index2]); => 1 '4' 5 '3' 2
//4. reverse(index1+1,n); => 1 4 "2 3 5"

//Time Comp:O(n)
//Space Comp: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind1=-1,ind2;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }
        
        if(ind1!=-1){                    //if nums is not sorted in desc order "5 4 3 2 1"
            for(int i=n-1;i>ind1;i--){
                if(nums[i]>nums[ind1]){
                    ind2=i;
                    break;
                }
            }
            swap(nums[ind1],nums[ind2]);
        }
        
        reverse(nums.begin()+ind1+1,nums.end());
        
        
    }
};