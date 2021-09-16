//Find element which appears more than n/3 times

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote1=0,cand1=nums[0];
        int vote2=0,cand2=nums[0];
        
        int n=nums.size();
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(cand1==nums[i]){
                vote1++;
            }
            else if(cand2==nums[i]){
                vote2++;
            }
            else if(vote1==0){
                cand1=nums[i];
                vote1=1;
            }
            else if(vote2==0){
                cand2=nums[i];
                vote2=1;
            }
            else{
                vote1--;
                vote2--;
            }
        }


        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand1){
                cnt1++;
            }
            else if(nums[i]==cand2){
                cnt2++;
            }
        }
        
        if(cnt1>(n/3)){
            res.push_back(cand1);
        }
        if(cnt2>(n/3)){
            res.push_back(cand2);
        }
        return res;
    }
    
};