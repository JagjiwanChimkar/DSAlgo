//choose a candidate from the given set of elements 
//if it is the same as the candidate element, increase the votes. 
//Otherwise, decrease the votes if votes become 0, 
//and select another new element as the new candidate.

//Time Comp: O(N)
//Space Comp: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int vote=0,cand=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(vote==0){
                cand=nums[i];
            }
            vote+=(nums[i]==cand)?1:-1;
        }


        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand){
                cnt++;
            }
        }
       
        if(cnt>(n/2)){
            return cand;
        }
        return 0;
    }
    }
};