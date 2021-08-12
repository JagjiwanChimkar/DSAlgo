//Modified Kadane algo
//Instead of check whether curr_sum is negative 
//we check and take maxi of arr[i] & curr_sum+arr[i]
//Also work on all negative elements in arr
//O(n)

#include <iostream>
using namespace std;

int maxSubArraySum(int arr[],int n){
    int curr_sum=arr[0];
    int max_so_far=arr[0];

    
    for(int i=1;i<n;i++){
        if(curr_sum+arr[i] > arr[i]){
            curr_sum=curr_sum+arr[i];
        }else{
            curr_sum=arr[i];
        }
        
        if(max_so_far<curr_sum){
            max_so_far=curr_sum;
        }
    }

    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, -1,-5};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;

    return 0;
}
