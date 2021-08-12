//Kadane's alog - if current_sum is negative then remove that sub-array.
//This alog don't work with all negative elements.
//O(n)

#include <iostream>
using namespace std;

int maxSubArraySum(int arr[],int n){
    int curr_sum=arr[0];
    int max_so_far=arr[0];
    
    int st_idx=0,end_idx=0;
    
    for(int i=1;i<n;i++){
        
        curr_sum+=arr[i];
        
        if(curr_sum<0){
            curr_sum=0;
            st_idx=i+1;
        }
        
        if(max_so_far<curr_sum){
            max_so_far=curr_sum;
            end_idx=i;
        }
    }
    
    cout<<st_idx<<" to "<<end_idx<<endl;
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;

    return 0;
}
