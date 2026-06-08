class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;
        int r=0;

        int cnt[256] = {0};
        int maxi = INT_MIN;

        while(r<n){
            cnt[s[r]]++;
            if(cnt[s[r]] > 1){
                while(l<=r && cnt[s[r]] != 1){
                    cnt[s[l]]--;
                    l++;
                }
            }

            int len = r-l+1;
            maxi = max(maxi, len);
            r++;
        }
        return maxi==INT_MIN? 0: maxi;
    }
};