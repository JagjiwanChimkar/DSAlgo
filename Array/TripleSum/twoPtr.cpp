//Using Two Pointer method 
//a+b+c=0 then b+c=-a ,iterate over to set 'a' and use 2ptr over 'b+c'.
//NO need to use Set 
//Time-Comp : O(N^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        int n=nums.size();
        
        if(n<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2 ;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int l=i+1,h=n-1;
            
            while(l<h){
                
                
                if(nums[l]+nums[h]+nums[i]==0){
                    vector<int> trp;
                    
                    trp.push_back(nums[i]);
                    trp.push_back(nums[l]);
                    trp.push_back(nums[h]);
                    
                    res.push_back(trp);
                    
                    while(l<h && nums[l]==nums[l+1]){
                    l++;
                    }
                    while(l<h && nums[h]==nums[h-1]){
                    h--;
                    }
                    
                    l++,h--;
                }
                else if(nums[l]+nums[h]<-(nums[i])){
                    l++;
                }else{
                    h--;
                }
            }
            }
            
        }
        return res;
    }
};