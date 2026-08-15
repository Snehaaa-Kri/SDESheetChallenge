class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        //sliding window
        int n = nums.size();
        
        int xr = 0;
        for(int &el: nums){
            xr ^= el;
        }
        //xr != 0
        if(xr != 0) return n;

        // xr == 0
        for(int &el: nums){
            if(el != 0) return n-1;
        }
        //all elements are zero
        return 0;
    }
};