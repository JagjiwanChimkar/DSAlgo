class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        
        queue<char> q1;
        queue<char> q2;
        for(int i=0;i<s.size();i++){
                q1.push(s[i]);
        }
        for(int i=0;i<goal.size();i++){
                q2.push(goal[i]);
        }
        
        int k=goal.size();
        while(k--){                      //Rotate queue element one by one 
            char c=q2.front();
            q2.pop();
            q2.push(c);
            if(q2==q1){                 //and check if they become equal or not
                return true;
            }
        }
        return false;
    }
};