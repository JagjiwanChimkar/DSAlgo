//O(n);
#include <iostream>

using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void sort_arr(int arr[],int n){
    int low=0,mid=0,high=n-1;

    while(mid<=high){
        switch(arr[mid]){
            case 0:
                swap(arr[low++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[high--]);
                break;
        }
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
