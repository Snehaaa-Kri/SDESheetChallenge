class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int permutationscnt = 1;  // n!
        for(int i=1; i<=n; i++){
            permutationscnt *= i;
        }

        vector<vector<int>> ans;
        for(int i=1; i<= permutationscnt; i++){ //O(N!)
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end()); //O(N)
        }

        return ans;
    }
};