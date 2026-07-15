class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int originalcolor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            ans[r][c] = color;
            vis[r][c] =  true;

            for(int i=0; i<4; i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];

                if(nr >=0 && nr < m && nc >= 0 && nc < n && ans[nr][nc] == originalcolor && !vis[nr][nc]){
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};