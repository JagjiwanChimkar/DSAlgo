//Two-Pointer
//O(n)

#include <iostream>

using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void sort_arr(int arr[],int n){
    int low=0,high=n-1;
    while(low<=high){
        if(arr[low]<0 && arr[high]<0){
            low++;
        }
        else if(arr[low]>0 && arr[high]<0){
            swap(arr[low++],arr[high--]);
        }
        else if(arr[low]>0 && arr[high]>0){
            high--;
        }else{
            low++,high--;
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
