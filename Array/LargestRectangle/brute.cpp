//https://leetcode.com/problems/largest-rectangle-in-histogram/
//Time Comp: O(n^n)
class Solution {
public:
    int left_smaller(vector<int>& heights,int st){
       int r=-1;
       for(int i=st-1;i>=0;i--){
           if(heights[st]>heights[i]){
               r=i;
               break;
           }
       }
       return r+1;
    }
    
    int right_smaller(vector<int>& heights,int st){
        int r=heights.size();
        for(int i=st+1;i<heights.size();i++){
            if(heights[st]>heights[i]){
                r=i;
                break;
            }
        }
        return r-1;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int left=left_smaller(heights,i);
            int right=right_smaller(heights,i);
            int area=(right-left+1)*heights[i];
            res=max(res,area);
        }
        return res;
    }
};