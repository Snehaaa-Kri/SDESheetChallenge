class Solution {
public:
    void bfs_traversal(int i, unordered_map<int, vector<int>>& ump_adj, vector<bool>& vis, int &v, int &e) {
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            v++;
            e += ump_adj[f].size();

            // neighbors
            for (auto &nbr : ump_adj[f]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> ump_adj;

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ump_adj[u].push_back(v);
            ump_adj[v].push_back(u);
        }

        int cnt = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0, e = 0;
                bfs_traversal(i, ump_adj, vis, v, e);

                //  is component complete grpah?
                if ((v * (v - 1)) / 2 == e / 2) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};