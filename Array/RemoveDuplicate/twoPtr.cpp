//Time Comp : O(N)
//Space Comp : O(1)
 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0; 
        }
        
        int i=0,j=1,count=1;
        while(j<nums.size()){
            if(nums[i]!=nums[j]){   
                count++;
                i++;
                nums[i]=nums[j];
            }
            j++;
        }
        return count;
    }
};