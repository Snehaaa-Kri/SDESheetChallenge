class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy(arr);
        sort(copy.begin(), copy.end());

        map<int, int> mp;
        int rank = 1;
        for(int i=0; i<arr.size(); i++){
            int el = copy[i];
            if(mp.find(el) == mp.end()){
                mp[el] = rank;
                rank++;
            }
        }

        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};