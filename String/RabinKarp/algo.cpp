// Rabin Karp algo for String pattern matching 

// n=s1 String size ,m=s2 subString size

// Calculate hash number for each sub-string => s[0]*10^(m-1)+s[1]*10^(m-2)..s[2]*10^(m-m) 
// Sliding Window techq known as rolling hashing ,window size=m
//  `-> remove previous index(i-1) and add next index(i+m-1)
//  subsq_hash = (subsq_hash-(s1[i-1]*10^(m-1))*10 + s1[i+m-1] 

// Time Comp: avg: O(n+m-1) ,worst O(nm)
// Space Comp: O(n)
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void check_subseq(string s1,string s2){
    int n=s1.size(),m=s2.size();
    ll req_hash=0,subsq_hash=0;
    for(int i=0;i<m;i++){
        req_hash += (ll)(s2[i]*(ll)pow(10,m-i-1));
        subsq_hash += (ll)(s1[i]*(ll)pow(10,m-i-1));
    }
    if(req_hash==subsq_hash){
       cout<<"index at 0"<<endl;   
    }
    
    for(int i=1;i<=n-m;i++){
        subsq_hash=( subsq_hash-(ll)(s1[i-1]*(ll)pow(10,m-1)) )*10+ (ll)(s1[i+m-1]) ;
        
        if(req_hash==subsq_hash){
            cout<<"index at : "<<i<<endl;   
        }
    }
}

int main()
{
    string s1="jagjagwanjag",s2="jag";
    check_subseq(s1,s2);
    return 0;
}
