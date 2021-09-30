//https://leetcode.com/problems/valid-palindrome
//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        string lowerS="";            //As we need only lower alphanumeric 
        for(int i=0;i<s.size();i++){
            if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122 || s[i]>=48 && s[i]<=57){
                char c=tolower(s[i]);
                lowerS+=c;
            }
        }
        string tmp=lowerS;
        reverse(lowerS.begin(),lowerS.end());   //reverse string
        
        return tmp==lowerS ;
    }
};