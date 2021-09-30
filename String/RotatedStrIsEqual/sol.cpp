//https://leetcode.com/problems/rotate-string
// Input: s = "abcde", goal = "cdeab"
// Output: true

class Solution {
public:
    bool rotateString(string s1, string s2) {
        if(s.size()!=goal.size()){   //is size not equal
            return false;
        }
         
        string tmp=s1+s1;                        //double of s1
        return tmp.find(s2)!=string::npos;      //check s2 is substring in tmp or not
    }
};