class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";
        // split words and ignore extra spaces
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }

        if (!temp.empty()) {
            words.push_back(temp);
        }

        // reverse words
        int i = 0, j = words.size() - 1;
        while (i < j) {
            swap(words[i], words[j]);
            i++;
            j--;
        }

        // join words
        string ans = "";
        for (int k = 0; k < words.size(); k++) {
            ans += words[k];
            if (k != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};