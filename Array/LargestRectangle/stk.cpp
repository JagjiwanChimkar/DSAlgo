//We first calculate leftSmaller and rightSmaller heights for ith element
//and store it in its 2 separate Array
//then check Max area rectangle by (rightSmaller-leftSmaller+1)*arr[i];

//Time Comp: O(n)

class Solution {
public:
   
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> stk;
        vector<int> leftSml(n);
        vector<int> rightSml(n);
        
        for(int i=0;i<n;i++){    //iterate from left to right
            
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            leftSml[i]=stk.empty()?0:stk.top()+1;
                
            stk.push(i);
        }
       
       while(!stk.empty()){   //empty stack to reuse it
           stk.pop();
       }
        
        for(int i=n-1;i>=0;i--){   //iterate from right to left
            
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            rightSml[i]=stk.empty()?n-1:stk.top()-1;  
                 
            stk.push(i);
        }
        
       
        int res=INT_MIN;
        for(int i=0;i<n;i++){
            res=max(res,(rightSml[i]-leftSml[i]+1)*heights[i]);
        }
        
        
        return res;
    }
};