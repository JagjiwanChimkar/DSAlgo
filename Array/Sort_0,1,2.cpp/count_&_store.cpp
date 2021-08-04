//Count the number of 0s, 1s and 2s in the given array. 
//Then store all the 0s in the beginning followed by all the 1s then all the 2s.
//Time comp :- O(n)

#include <iostream>

using namespace std;

void sort_arr(int arr[],int n){
    int ct0=0,ct1=0,ct2=0;

    for(int i=0;i<n;i++){
        
        switch(arr[i]){
            case 0:
                ct0++;
                break;
            case 1:
                ct1++;
                break;
            case 2:
                ct2++;
                break;
        }
        
    }
    
    int i=0;
    while(ct0>0){
        arr[i++]=0;
        ct0--;
    }
    
    while(ct1>0){
        arr[i++]=1;
        ct1--;
    }
    
    while(ct2>0){
        arr[i++]=2;
        ct2--;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    sort_arr(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
