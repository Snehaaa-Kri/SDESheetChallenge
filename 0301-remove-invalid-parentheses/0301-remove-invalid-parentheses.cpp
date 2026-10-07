class Solution {
public:
    int balance(string s) {
        int b = 0;

        for (char c : s) {
            if (c == '(') b++;
            else if (c == ')') b--;

            if (b < 0) return -1;
        }

        return b;
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> vis;
        queue<string> q;
        vector<string> ans;

        q.push(s);

        while (!q.empty()) {
            int size = q.size();
            bool found = false;

            while (size--) {
                string curr = q.front();
                q.pop();

                if (vis.count(curr)) continue;
                vis.insert(curr);

                if (balance(curr) == 0) {
                    ans.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (int i = 0; i < curr.size(); i++) {
                    q.push(curr.substr(0, i) + curr.substr(i + 1));
                }
            }

            if (found) return ans;
        }

        return {""};
    }
};