class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xorr = 0;
        for(int &el: nums){
            xorr ^= el;
        }
        return xorr;
    }
};