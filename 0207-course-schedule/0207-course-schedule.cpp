class Solution {
public:

    //using dfs
    bool iscyclePresent(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1; //visiting 

        for(auto &nebr: adj[node]){
            if(vis[nebr] == 1) return true; //cycle found
            else if(vis[nebr] == 0) {
                if(iscyclePresent(nebr, vis, adj)) return true;
            }
        }
        vis[node] = 2; //already visited safely
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        //create adj list
        vector<vector<int>> adj(n);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        vector<int> vis(n, 0); // 0 - not visited
        for(int comp = 0; comp < n; comp++){
            if(vis[comp] == 0){
                if(iscyclePresent(comp, vis, adj)) return false;
            }
        }
        return true;
    }
};