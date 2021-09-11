//Use Hashing to remove 3rd nested loop 
//Reduce Time-Comp to O(N^2*logM)


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
         hs[nums[i]]--;                    //remove from hashtable 
          for(int j=i+1;j<n;j++){
              hs[nums[j]]--;                     //remove from hashtable 
                   if(hs.find(-(nums[i]+nums[j]))!=hs.end() && 
                      hs[-(nums[i]+nums[j])]>0){
                        vector<int> trp;

                        trp.push_back(nums[i]);
                        trp.push_back(nums[j]);
                        trp.push_back(-(nums[i]+nums[j]));

                        sort(trp.begin(),trp.end());
                        
                        set_res.insert(trp);            //add into Set to avoid duplicates
                       
                   }
                   hs[nums[j]]++;                  //add back to hashtable 
           }  
            hs[nums[i]]++;                         //add back to hashtable 
        }
        
        copy(set_res.begin(),set_res.end(),back_inserter(res));
        return res;
    }
};