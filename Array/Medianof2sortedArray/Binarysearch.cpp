class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n=nums1.size(),m=nums2.size();
        
        int div=(n+m+1)/2;
        
        int low=0,high=n;
        int l1,l2,r1,r2;
        
        while(low<=high){
            int mid=(low+high)/2;
            int cut1=mid;
            int cut2=div-mid;
            
            l1=cut1?nums1[cut1-1]:INT_MIN;
            l2=cut2?nums2[cut2-1]:INT_MIN;
            r1=cut1<n?nums1[cut1]:INT_MAX;
            r2=cut2<m?nums2[cut2]:INT_MAX;
            
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }else{
                    return max(l1,l2);
                }
                
            }
            else if(l1>r2){
                high=mid-1;
            }else if(l2>r1){
                low=mid+1;
            }
        }
        return 0;
    }
};