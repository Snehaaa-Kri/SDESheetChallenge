class Solution {
public:
    int m, n;

    int drow[4] = {-1, 0, +1, 0};
    int dcol[4] = {0, +1, 0, -1};

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if(m==1 && n==1){
            if(grid[0][0] == 0) return 0;
            else if(grid[0][0] == 1) return -1;
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int, int>> q; 
        //insert rotten oranges first
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        // process
        int time = -1;
        while(!q.empty()){
            int size = q.size();
            time++;

            while(size--){
                auto node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;

                vis[r][c] = true;

                for(int k=0; k<4; k++){
                    int nr = r + drow[k];
                    int nc = c + dcol[k];

                    if(nr >= 0 && nr < m && nc >=0 && nc < n && !vis[nr][nc] && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }

        // itna krne se better q me time variable le lena chahiye tha
        bool allzeroes = true;
        bool istwopresent = false;
        bool onepresent = false;
        for(auto &r: grid){
            for(auto &el: r){
                if(el == 1){
                    onepresent = true;
                }
                if(el != 0) allzeroes = false;
                if(el == 2) istwopresent = true;
            }
        }

        if(allzeroes) return 0;
        if(istwopresent && onepresent) return -1;
        if(onepresent) return -1;

        return time;
    }
};