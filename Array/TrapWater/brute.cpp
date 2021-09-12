class Solution {
public:
    int max_ht(vector<int>& height,int st,int end){
        int res=height[st];
        for(int i=st+1;i<end;i++){
            res=max(height[i],res);
        }
        return res;
    }
    int trap(vector<int>& height) {
        int trap=0;
        int n=height.size();
        for(int i=1;i<n-1;i++){
           int left_maxHt=max_ht(height,0,i);
           int right_maxHt=max_ht(height,i+1,n);
           int res=(min(left_maxHt,right_maxHt)-height[i]); 
           if(res>0){
               trap+=res;
           }
        }
        return trap;
    }
};