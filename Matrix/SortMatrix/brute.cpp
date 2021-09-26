//Store mat elem in temp array of size n*n
//sort temp array
//store temp array elem into matrix

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> temp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                temp.push_back(Mat[i][j]);
            }
        }
        sort(temp.begin(),temp.end());
        
        for(int idx=0;idx<N*N;idx++){
            Mat[idx/N][idx%N]=temp[idx];  // row=index/n & col=index%n
        }
        return Mat;
    }
};