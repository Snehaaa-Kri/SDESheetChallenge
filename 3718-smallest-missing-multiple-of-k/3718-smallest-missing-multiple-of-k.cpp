class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;
        for(int &el: nums){
            st.insert(el);
        }

        for(int i=1; ; i++){
            int mul = i*k;
            if(!st.count(mul)) return mul;
        }
        return -1;
    }
};