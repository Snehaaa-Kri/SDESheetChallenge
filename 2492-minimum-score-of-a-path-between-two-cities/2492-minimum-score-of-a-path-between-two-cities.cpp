class Solution {
public:
    void dfs(int i, vector<bool> &vis, unordered_map<int, vector<pair<int, int>>> &adj, int &res){
        vis[i] = true;

        for(auto &nebr: adj[i]){
            int v = nebr.first;
            int dist = nebr.second;

            res = min(res, dist);

            if(!vis[v]){
                dfs(v, vis, adj, res);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        //creating adj list
        unordered_map<int, vector<pair<int, int>>> adj(n+1);

        for(auto &r: roads){
            int u = r[0];
            int v = r[1];
            int dist = r[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }


        int ans = INT_MAX;

        vector<bool> vis(n+1, false);

        // for(int i=1; i<n+1; i++){
        //     if(!vis[i]) dfs(i, vis, adj, ans);
        // }

        dfs(1, vis, adj, ans);
        return ans;
    }
};