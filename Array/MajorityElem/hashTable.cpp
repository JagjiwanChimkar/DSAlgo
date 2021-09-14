//Time Comp: O(N)
//Space Comp: O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> hs;
       
        for(int i=0;i<nums.size();i++){
            hs[nums[i]]++;
        }
        for(auto i:hs){
            if(i.second>nums.size()/2){
               return i.first;
            }
        }
        return 0;
    }
};