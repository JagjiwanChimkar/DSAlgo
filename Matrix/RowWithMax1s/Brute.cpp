//https://practice.geeksforgeeks.org/problems/row-with-max-1s0023
//find row with max 1s and row is sorted
//Time Comp:O(n*m)

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int max=0,r=-1;
	    for(int i=0;i<n;i++){
	        int count=0;
	        for(int j=0;j<m;j++){
	            count+=arr[i][j];
	        }
	        if(count>max){
	            max=count;
	            r=i;
	        }
	    }
	    return r;
	}

};
