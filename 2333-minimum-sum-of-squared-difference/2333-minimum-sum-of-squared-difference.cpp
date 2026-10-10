class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> d(100001, 0);
        long long k = (long long)k1 + k2;
        long long sum = 0;
        int max_diff = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            int diff = abs(nums1[i] - nums2[i]);
            d[diff]++;
            sum += diff;
            max_diff = max(max_diff, diff);
        }
        
        if (sum <= k) return 0;
        
        for (int i = max_diff; i > 0 && k > 0; i--) {
            if (d[i] > 0) {
                long long move = min(k, d[i]);
                d[i] -= move;
                d[i - 1] += move;
                k -= move;
            }
        }
        
        long long ans = 0;
        for (long long i = 1; i <= max_diff; i++) {
            if (d[i] > 0) {
                ans += i * i * d[i];
            }
        }
        return ans;
    }
};