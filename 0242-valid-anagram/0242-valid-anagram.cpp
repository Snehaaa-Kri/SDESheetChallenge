class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};

        for(char &ch : s){
            cnt[ch-'a']++;
        }

        for(char &ch: t){
            cnt[ch-'a']--;

            if(cnt[ch-'a'] < 0) return false;
        }

        for(auto &el: cnt){
            if(el != 0) return false;
        }
        return true;
    }
};