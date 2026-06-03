class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // transpose 
        for(int i=0; i<m; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        //reverse each rows
        for(auto &row: matrix){
            int l=0;
            int r = row.size()-1;

            while(l<=r){
                swap(row[l], row[r]);
                l++;
                r--;
            }
        }
    }
};