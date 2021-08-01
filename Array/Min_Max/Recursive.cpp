//Tournament Method
//Divide and Conquer-Divide array in two part and compare max & min of both array.

#include <iostream>

using namespace std;

struct Pair{
  int min;
  int max;
};

struct Pair get_minMax(int arr[],int low,int high){
    struct Pair minMax;
    if(low==high){
        minMax.min=arr[low];
        minMax.max=arr[high];
        return minMax;
    }
    else if(high==low+1){
        if(arr[high]>arr[low]){
            minMax.min=arr[low];
            minMax.max=arr[high];
            return minMax;
        }else{
            minMax.min=arr[high];
            minMax.max=arr[low];
            return minMax;
        }
    }
    
    int mid=(low+high)/2;
    struct Pair mml=get_minMax(arr,low,mid);
    struct Pair mmr=get_minMax(arr,mid+1,high);
    
    if(mml.max>mmr.max){
        minMax.max=mml.max;
    }else{
         minMax.max=mmr.max;
    }
    
    if(mml.min<mmr.min){
        minMax.min=mml.min;
    }else{
        minMax.min=mmr.min;
    }
    
    
    return minMax;
    
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    struct Pair minMax=get_minMax(arr,0,n-1);
    
    cout<<minMax.min<<" "<<minMax.max<<endl;

    return 0;
}
