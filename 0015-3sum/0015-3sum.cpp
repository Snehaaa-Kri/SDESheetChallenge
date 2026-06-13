class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int p = i+1;
            int q = n-1;

            while(p<q){
                long long sum = nums[p]+nums[q]+nums[i];

                if(sum == 0LL){
                    ans.push_back({nums[i], nums[p], nums[q]});

                    p++;
                    q--;
                    while(p<q && nums[p] == nums[p-1]) p++;
                    while(p<q && nums[q] == nums[q+1]) q--;
                }
                else if(sum < 0LL) p++;
                else q--;
            }
        }
        return ans;
    }
};