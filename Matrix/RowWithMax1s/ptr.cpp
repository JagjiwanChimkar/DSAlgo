//Move a ptr from top-right corner to left-bottom corner
//if 1 counter,move left and record r
//else if 0 counter,move down
  
//Time Comp: O(n+m)

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   int r=-1;
	   int i=0,j=m-1;
	   while(i<n && j>=0){
	       if(arr[i][j]==1){
	           j--;
	           r=i;
	       }else{
	           i++;
	       }
	   }
	   return r;
	}

};