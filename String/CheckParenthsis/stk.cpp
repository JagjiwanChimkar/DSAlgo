//1. Traverse through elem of string
//2. If opening bracket => push in stack
//3  If closing bracket => check top of stack is matching with it's opening bracket and pop() else false
//4. After Traversing check stack is empty or not

//Time Comp:O(n)
//Space Comp:O(n)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s){
        
        int n=s.size();
        stack<char> stk;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' ||s[i]=='['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){    //stack can't be empty if s[i] is closing bracket
                    return false;
                }
                else if(s[i]=='}' && stk.top()!='{' || s[i]==']' && stk.top()!='[' 
                || s[i]==')' && stk.top()!='(' ){
                    return false;
                }else{
                    stk.pop();
                }
            }
        }

        return stk.empty();
    }

};