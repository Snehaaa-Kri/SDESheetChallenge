class Solution {
public:
    void combinationSum2_optLogic(int index, int remaining, vector<int> &c, vector<vector<int>> &ans, vector<int>& list) {
        if(remaining == 0){
            ans.push_back(list);
            return;
        }

        for(int i=index; i<c.size(); i++){
            if(i>index && c[i] == c[i-1]) continue;
            if(c[i] > remaining) break;
            list.push_back(c[i]);
            combinationSum2_optLogic(i+1, remaining-c[i], c, ans, list);
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum2_opt(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> list;
        vector<vector<int>> ans;
        combinationSum2_optLogic(0, target, candidates, ans, list);
        return ans;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return combinationSum2_opt(candidates, target);
    }
};