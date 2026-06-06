class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        unordered_map<int, int> mp;
        for(auto &el: nums){
            mp[el]++;
        }

        for(auto &el: mp){
            if(el.second > floor(n/3)) ans.push_back(el.first);
        }
        return ans;
    }
};