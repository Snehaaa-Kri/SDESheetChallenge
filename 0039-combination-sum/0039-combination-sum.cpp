class Solution {
public:
    void solve(int i, int sum, vector<int> temp, vector<int> &can, vector<vector<int>> &ans){
        if(i == can.size() || sum < 0) return;
        if(sum == 0){
            ans.push_back(temp);
            return;
        }

        //nottake , take
        solve(i+1, sum, temp, can, ans);
        temp.push_back(can[i]);
        solve(i, sum-can[i], temp, can, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(0, target, {}, candidates, ans);
        return ans;
    }
};