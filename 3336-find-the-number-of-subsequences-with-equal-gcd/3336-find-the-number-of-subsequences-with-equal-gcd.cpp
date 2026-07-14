using ll = long long;
class Solution {
    vector<vector<vector<int>>> dp;
    const int mod = 1e9 + 7;
    int n;
    int f(int idx, int g1, int g2, vector<int> &v){
        if(idx == n){
            if(g1 && g1 == g2) return 1;
            return 0;
        }
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];
        ll w = 0;
        w = (w + f(idx + 1, g1, g2, v)) % mod;
        int ng1 = (g1 == 0) ? v[idx] : __gcd(g1, v[idx]);
        w = (w + f(idx + 1, ng1, g2, v)) % mod;
        int ng2 = (g2 == 0) ? v[idx] : __gcd(g2, v[idx]);
        w = (w + f(idx + 1, g1, ng2, v)) % mod;
        return dp[idx][g1][g2] = w;
    }
public:
    int subsequencePairCount(vector<int>& v) {
        n = v.size();
        int mae = *max_element(begin(v), end(v));
        dp.assign(n, vector<vector<int>>(mae + 1, vector<int>(mae + 1, -1)));
        return f(0, 0, 0, v);
    }
};