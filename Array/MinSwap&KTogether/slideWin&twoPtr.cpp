//Sliding Window and Two-Ptr is used


int minSwap(int *arr, int n, int k) {
    int cnt=0;
    
    //count no. of element >=k in arr
    //fix this cnt to size of sliding window
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            cnt++;
        }
    }
   
    //count elem >k in first window
    int bad=0;
    for(int i=0;i<cnt;i++){
        if(arr[i]>k){
            bad++;
        }
    }
   
    
    //slide the window to know min. bad elem from each window
    int ans=bad;
    for(int i=0,j=cnt;j<n;i++,j++){
        if(arr[i]>k){
            bad--;
        }
        
        if(arr[j]>k){
            bad++;
        }
        
        ans=min(ans,bad);
    }
    
    return ans;
}