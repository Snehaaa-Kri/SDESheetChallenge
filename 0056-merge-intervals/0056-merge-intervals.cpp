class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            int j =  i;
            int maxi = intervals[j][1];
            int mini = intervals[i][0];

            while(j+1 < n && intervals[j+1][0] <= maxi){
                maxi = max(maxi, intervals[j+1][1]);
                mini = min(mini, intervals[i+1][0]);
                j++;
            }
            ans.push_back({mini, maxi});
            i = j;
        }
        return ans;
    }
};