// Worst-case :- 2(n-1) comparsion if Array is reverse sorted 
// Best-case :- n-1 comparsion if Array is  sorted
// Time-Comp :- O(n)
#include <iostream>

using namespace std;

void min_max(int arr[],int n){
    int min=arr[0],max=arr[0];
    
    for(int i=1;i<n;i++){
        if(max<arr[i])        /
            max=arr[i];
        else if min>arr[i]     //Only checked in worst-case
            min=arr[i];
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
    min_max(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
