class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int prev = nums[0];
        for(int i=1; i<n; i++){
            if(prev + 1 != nums[i]){
                while(prev+1 < nums[i]){
                    ans.push_back(prev+1);
                    prev++;
                }
            }
            prev = nums[i];
        }
        return ans;
    }
};