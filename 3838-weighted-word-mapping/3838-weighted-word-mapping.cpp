class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<char, int> mp;

        for(int i=0;i <weights.size(); i++){
            mp['a'+i] = weights[i];
        }

        string ans = "";

        for(auto &w: words){
            int sum = 0;
            for(char &ch: w){
                sum = (sum+mp[ch])%26;
            }
            
            char ch = 'z'-sum;
            ans += ch; 
        }
        return ans;
    }
};