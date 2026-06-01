class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        set<int> x;
        set<int> y;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }

        //setting rows to be 0s
        for(auto &i: x){
            for(int j=0; j<n; j++){
                matrix[i][j] = 0;
            }
        } 

        // setting cols to be 0s
        for(auto &j: y){
            for(int i=0; i<m; i++){
                matrix[i][j] = 0;
            }
        }
    }
};