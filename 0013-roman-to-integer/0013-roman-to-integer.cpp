class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            int currentVal = mp[s[i]];

            // check next character for subtractive case
            if (i + 1 < s.length() && currentVal < mp[s[i + 1]]) {
                num -= currentVal;
            } else {
                num += currentVal;
            }
        }

        return num;
    }
};