//Brute-Force approach 
//Using Set to avoid duplicate
//Time-Comp : O(N^3*logM) , logM for inserting into Set with size M


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> set_res;
        vector<vector<int>> res;
        int n=nums.size();
        
        if(n<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        
      
        unordered_map<int,int> hs;
        for(int i=0;i<n;i++){
           hs[nums[i]]++;    
        }
        
       
        for(int i=0;i<n;i++){
                           
          for(int j=i+1;j<n;j++){
                            
            for(int k=j+1;k<n;k++){

                if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> trp;

                        trp.push_back(nums[i]);
                        trp.push_back(nums[j]);
                        trp.push_back(-(nums[i]+nums[j]));

                        sort(trp.begin(),trp.end());
                        
                        set_res.insert(trp);            //add into Set to avoid duplicates
                }
            }
                               
           }  
           
        }
        
        copy(set_res.begin(),set_res.end(),back_inserter(res));
        return res;
    }
};