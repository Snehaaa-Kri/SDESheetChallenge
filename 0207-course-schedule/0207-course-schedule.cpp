class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        //directed graph
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);

        for(auto &p: prerequisites){
            int u = p[1];
            int v = p[0];

            adj[u].push_back(v);
            indeg[v]++;
        }


        // bfs topo short
        int cnt = 0;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto nebr: adj[node]){
                indeg[nebr]--;

                if(indeg[nebr] == 0){
                    q.push(nebr);
                }
            }
        }
        return cnt == n;
    }
};