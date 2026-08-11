class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> children(n);

        for(int i=1; i<n; i++){
            children[parent[i]].push_back(i);
        }

        //hghtcal and dpeth filling
        int height = 1;
        vector<int> depth(n, 1);
        queue<int> q;
        q.push(0);


        while(!q.empty()){
            int node = q.front();
            q.pop();
            height = max(height, depth[node]);

            for(auto &ch: children[node]){
                depth[ch] = depth[node]+1;
                q.push(ch);
            }
        }

        //sum calculation
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += (1LL*nums[i]* (height-depth[i]+1));
        }
        return sum;
    }
};