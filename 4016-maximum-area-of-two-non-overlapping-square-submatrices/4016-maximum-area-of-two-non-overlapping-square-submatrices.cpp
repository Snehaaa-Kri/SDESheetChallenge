class Solution {
public:
    int m, n;
    bool isvalid(int k, vector<vector<int>> &mat, vector<vector<int>> &ps){
        
        int minrow = m, maxrow = -1;
        int mincol = n, maxcol = -1;


        for(int i=0; i+k<=m; i++){
            for(int j=0; j+k<=n; j++){
                int fi = i+k;
                int fj = j+k;

                int sum = ps[fi][fj] - ps[i][fj] - ps[fi][j] + ps[i][j];

                if(sum != k*k) continue;

                minrow = min(minrow, i);
                maxrow = max(maxrow, i);

                mincol = min(mincol, j);
                maxcol = max(maxcol, j);
                
                if(maxrow - minrow >= k || maxcol-mincol >= k) return true;
            }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        
        //prefix sum 
        vector<vector<int>> ps(m+1, vector<int>(n+1, 0));

        //rem cells
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ps[i+1][j+1] = mat[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j];
            }
        }

        int low = 1;
        int high = min(m, n);
        int k = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(isvalid(mid, mat, ps)){
                k = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return k*k;
    }
};