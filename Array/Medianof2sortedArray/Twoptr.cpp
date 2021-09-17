//Using 2 ptr by comparing arr1 and arr2 elem and
//store them in sequence into arr
//calculate median in arr
//Time Comp: O(m+n)
//Space Comp: O(m+n) 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i++]);
            }else{
                arr.push_back(nums2[j++]);
            }
        }
        
        while(i<n){
            arr.push_back(nums1[i++]);
        }
        
        while(j<m){
            arr.push_back(nums2[j++]);
        }
         
        
        int s=arr.size();
         if(s%2==0){
             return (double)(arr[s/2]+arr[(s/2)-1])/2;
         }else{
             return arr[s/2];
         }
    }
};