class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int &el: nums){
            st.insert(el);
        }

        int seqsum = nums[0];

        for(int j=1; j<n; j++){
            if(nums[j] == nums[j-1]+1) seqsum += nums[j];
            else break;
        }

        while(st.count(seqsum)) { seqsum++; }

        return seqsum;
    }
};