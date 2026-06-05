class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int majel = nums[0];
        int cnt = 1;

        for(int i=1; i<nums.size(); i++){
            if(nums[i] == majel){
                cnt++;
            }else{
                majel = nums[i];
                cnt = 1;
            }
            if(cnt > floor(n/2)) return majel;
        }
        return majel;
    }
};