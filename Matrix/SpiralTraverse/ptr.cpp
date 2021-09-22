class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int frow=0,fcol=0,lrow=matrix.size()-1,lcol=matrix[0].size()-1;

        int dir=0;

        while(frow<=lrow && fcol<=lcol){
            
            switch(dir){
                case 0:                                   // left to right
                    for(int i=fcol;i<=lcol;i++){
                        res.push_back(matrix[frow][i]);
                    }
                    frow++,dir=1;
                    break;

                case 1:                                   // up to down
                    for(int i=frow;i<=lrow;i++){
                        res.push_back(matrix[i][lcol]);
                    }
                    lcol--,dir=2;
                    break;

                case 2:                                   // right to left
                    for(int i=lcol;i>=fcol;i--){
                        res.push_back(matrix[lrow][i]);
                    }
                    lrow--,dir=3;
                    break;

                case 3:                                   // down to up
                    for(int i=lrow;i>=frow;i--){
                        res.push_back(matrix[i][fcol]);
                    }
                    fcol++,dir=0;
                    break;
            }
        }
        return res;
    }
};