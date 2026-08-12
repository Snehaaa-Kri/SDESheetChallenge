class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; //num, freq

        //sliding window
        int maxi = 1;
        int l = 0, r = 0;
        while(r<n){
            mp[nums[r]]++;
            if(mp[nums[r]] > k){
                int len = r-l;
                maxi = max(maxi, len);

                while(l<= r && mp[nums[r]] > k){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }
            }
            r++;
        }

        maxi = max(maxi, r-l);
        
        return maxi;
    }
};