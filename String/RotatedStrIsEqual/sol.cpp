//https://leetcode.com/problems/rotate-string
// Input: s = "abcde", goal = "cdeab"
// Output: true

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){   //is size not equal
            return false;
        }
         
        string tmp=s+s;                        //double of s
        return tmp.find(goal)!=string::npos;   //check goal found in tmp or not
    }
};