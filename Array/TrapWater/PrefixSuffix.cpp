//Instead of calculate left_maxHt,right_maxHt for every iteration
//We compute it already and store it in prefix,suffix array
//Time-Comp : O(N)
//Space-Comp : O(N) 
class Solution {
public:
    
    int trap(vector<int>& height) {
        int trap=0;
        int n=height.size();
        
        int prefix[n];
        int prefix_max=height[0];
        for(int i=0;i<n;i++){
            prefix_max=max(prefix_max,height[i]);
            prefix[i]=prefix_max;
        }
        
        int suffix[n];
        int suffix_max=height[n-1];
        for(int i=n-1;i>=0;i--){
            suffix_max=max(suffix_max,height[i]);
            suffix[i]=suffix_max;
        }
        
        for(int i=1;i<n-1;i++){
           
           int res=(min(prefix[i],suffix[i])-height[i]); 
           if(res>0){
               trap+=res;
           }
        }
        return trap;
    }
};