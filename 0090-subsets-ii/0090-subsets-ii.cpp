class Solution {
public:
    void subsetsWithDup_rec(int idx, vector<int>& list, vector<int>& nums, set<vector<int>> &ans){
        if(idx == nums.size()){
            ans.insert(list);
            return;
        }
        
        //pick
        list.push_back(nums[idx]);
        subsetsWithDup_rec(idx+1, list, nums, ans);
        //not pick
        list.pop_back();
        subsetsWithDup_rec(idx+1, list, nums, ans);   
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> list;
        set<vector<int>> ans;
        subsetsWithDup_rec(0, list, nums, ans);

        vector<vector<int>> anss;
        for(auto el : ans) anss.push_back(el);
        return anss;
    }
};