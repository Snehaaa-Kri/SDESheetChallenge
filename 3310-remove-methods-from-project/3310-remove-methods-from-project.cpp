class Solution {
public:
    void getsuspeciousnodes(int k, vector<bool> &suspecious,vector<bool> &vis, vector<int> &indegree, vector<vector<int>> &adj){
        //using bfs
        queue<int> q;
        q.push(k);

        while(!q.empty()){
            int node = q.front();
            q.pop();
            suspecious[node] = true;
            vis[node] = true;

            for(auto &nebr: adj[node]){
                indegree[nebr]--;
                if(!vis[nebr]){
                    vis[nebr] = true;
                    q.push(nebr);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> suspecious(n, false);
        vector<int> indegree(n, 0);

        vector<vector<int>> adj(n);
        for(auto &el: invocations){
            int u = el[0];
            int v = el[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<bool> vis(n, false);
        getsuspeciousnodes(k, suspecious, vis, indegree, adj);

        for(int i=0; i<n; i++){
            if(suspecious[i] && indegree[i] > 0){
                //return complete graph
                vector<int> ans;
                for(int j=0; j<n; i=j++){
                    ans.push_back(j);
                }
                return ans;
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!suspecious[i]) ans.push_back(i);
        }
        return ans;
    }
};