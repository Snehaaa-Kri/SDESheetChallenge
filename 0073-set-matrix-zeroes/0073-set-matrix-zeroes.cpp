class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q; //to store 0th positions

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            auto pos = q.front(); q.pop();

            int x = pos.first;
            int y = pos.second;

            //row set
            for(int j=0; j<n; j++){
                matrix[x][j] = 0;
            }

            //col set
            for(int i=0; i<m; i++){
                matrix[i][y] = 0;
            }
        }

    }
};