//https://leetcode.com/problems/median-of-two-sorted-arrays/
//store elem of arr1 and arr2 in arr
//sort arr and calculate median
//Time Comp: O((m+n)log(m+n))
//Space Comp: O(m+n) 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int> arr;
         for(int i=0;i<nums1.size();i++){
             arr.push_back(nums1[i]);
         }
         for(int i=0;i<nums2.size();i++){
             arr.push_back(nums2[i]);
         }
        
         sort(arr.begin(),arr.end());
         
        int n=arr.size();
         if(n%2==0){
             return (double)(arr[n/2]+arr[(n/2)-1])/2;
         }else{
             return arr[n/2];
         }
    }
};