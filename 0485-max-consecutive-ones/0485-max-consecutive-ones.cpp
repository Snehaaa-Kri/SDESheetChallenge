class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int cnt = 0;

        while(j<n){
            if(nums[j] == 0){
                i=j+1;
                j++;
            }
            else{
                while(j<n && nums[j] == 1){
                    j++;
                }
                cnt = max(cnt, j-i);
            }
        }
        return cnt;
    }
};