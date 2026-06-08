class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;

        for(int el : nums){
            if(el < pivot) ans.push_back(el);
        }

        for(int el : nums){
            if(el == pivot) ans.push_back(el);
        }

        for(int el : nums){
            if(el > pivot) ans.push_back(el);
        }

        return ans;
    }
};