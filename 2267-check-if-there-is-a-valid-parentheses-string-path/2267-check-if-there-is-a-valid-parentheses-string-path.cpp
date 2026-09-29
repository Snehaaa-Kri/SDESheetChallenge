class Solution
{
public:
    bool hasValidPath(const std::vector<std::vector<char>>& g) const noexcept
    {
        const size_t h = g.size();
        const size_t w = g[0].size();
        std::bitset<128> dp[101][101]{};
        dp[0][1] = 1u;
        for (size_t y = 0; y != h; ++y)
        {
            for (size_t x = 0; x != w; ++x)
            {
                auto p = dp[y + 1][x] | dp[y][x + 1];
                if (g[y][x] == '(')
                {
                    dp[y + 1][x + 1] = p << 1;
                }
                else
                {
                    dp[y + 1][x + 1] = p >> 1;
                }
            }
        }
        return dp[h][w][0];
    }
};