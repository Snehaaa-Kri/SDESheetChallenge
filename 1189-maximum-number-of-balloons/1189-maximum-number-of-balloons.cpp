class Solution {
public:
    int maxNumberOfBalloons(string text) {
        //balloon
        int cnt[26] = {0};
        cnt['b'-'a'] = 1;
        cnt['a'-'a'] = 1;
        cnt['l'-'a'] = 2;
        cnt['o'-'a'] = 2;
        cnt['n'-'a'] = 1;

        int freq[26] = {0};
        for(auto &ch: text){
            freq[ch-'a']++;
        }

        int mini = INT_MAX;
        for(int i=0; i<26; i++){
            if(cnt[i] != 0){
                int times = freq[i]/cnt[i];
                mini = min(mini, times);
            }
        }

        return mini == INT_MAX? 0 : mini;

    }
};