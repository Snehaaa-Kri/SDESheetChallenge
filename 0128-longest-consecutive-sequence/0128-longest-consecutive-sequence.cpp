class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int el = nums[0];
        int maxi = 1;

        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == el+1){
                cnt++;
                maxi = max(maxi, cnt);
                el = nums[i];
            }
            else{
                el = nums[i];
                cnt = 1;
            }
        }
        return maxi;
    }
};