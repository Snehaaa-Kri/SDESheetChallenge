class Solution {
public:
    vector<int> nextSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top(); // -1 = no smaller element

            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsi = nextSmallerIndex(heights);
        vector<int> psi = prevSmallerIndex(heights);

        int n = heights.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            int w = nsi[i] - psi[i] - 1;
            int h = heights[i];

            maxi = max(maxi, h*w);
        }
        return maxi;
    }
};