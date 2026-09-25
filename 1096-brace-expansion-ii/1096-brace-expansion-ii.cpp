class Solution {
public:

    set<string> combine(set<string> A, set<string> B) {
        set<string> result;
        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }
        return result;
    }

    set<string> parse(string &s, int &i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                for (string word : current) {
                    result.insert(word);
                }

                current = {""};
                i++;
            }

            else if (s[i] == '{') {
                i++;
                set<string> inside = parse(s, i);
                i++;

                current = combine(current, inside);
            }

            else {
                set<string> letter = {string(1, s[i])};
                current = combine(current, letter);
                i++;
            }
        }
        for (string word : current) {
            result.insert(word);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};