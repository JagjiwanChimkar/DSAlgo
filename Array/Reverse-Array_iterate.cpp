#include <iostream>

using namespace std;

void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void reverse(int arr[],int n){
    for(int i=0,j=n-1;i<j;i++,j--){
        swap(arr[i],arr[j]);
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
    reverse(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}


//Time-Comp:- O(n)