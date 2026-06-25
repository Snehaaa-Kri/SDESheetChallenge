class Solution {
public:
//monotonic stack concept - O(n1+n2)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        // map el with nge for nums2
        unordered_map<int, int> mp;
        stack<int> st;
        for(auto &x: nums2){
            while(!st.empty() && x > st.top()){
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }


        //forming answer
        vector<int> ans;

        for(int x: nums1) {
            ans.push_back(mp[x]);
        }
        return ans;
    }
};