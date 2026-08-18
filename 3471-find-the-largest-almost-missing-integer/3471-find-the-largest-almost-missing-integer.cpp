class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        
        for(int i=0; i<=n-k; i++){
            unordered_set<int> st;
            for(int j=i; j<i+k; j++){
                st.insert(nums[j]);
            }

            for(auto &x: st){
                mp[x]++;
            }
        }

        int maxi = INT_MIN;
        for(auto &el: mp){
            if(el.second == 1){
                maxi = max(maxi, el.first);
            }
        }

        return maxi == INT_MIN ? -1: maxi;
    }
};