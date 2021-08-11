//union: O(n+m) , inserting element in set
//Intersection: O(n+m) , 1. insert element of arr1 in set, 2. iterate arr2 and find in set.

#include <bits/stdc++.h>
using namespace std;

void find_union(int arr1[],int arr2[],int n,int m){  
    set<int> hs;
    for(int i=0;i<n;i++){
        hs.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        hs.insert(arr2[i]);
    }
    
    cout<<"Union : ";
    for(auto it=hs.begin();it!=hs.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void find_intersection(int arr1[],int arr2[],int n,int m){
    set<int> hs;
    for(int i=0;i<n;i++){
        hs.insert(arr1[i]);
    }
    
    cout<<"Intersection : ";
    for(int i=0;i<m;i++){
        if(hs.find(arr2[i])!=hs.end()){
            cout<<arr2[i]<<" ";
        }
    }
    
}

int main()
{
    int arr1[] = { 7, 1, 5, 2, 3, 6 };
    int arr2[] = { 3, 8, 6, 20, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
 

    find_union(arr1,arr2,n,m);
    find_intersection(arr1,arr2,n,m);
    return 0;
}
