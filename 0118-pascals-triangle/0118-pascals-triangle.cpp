class Solution {
public:

    void getcurrRow(vector<int> &prev, vector<int> &curr){
        curr.push_back(1);

        for(int i=1; i<prev.size(); i++){
            curr.push_back(prev[i] + prev[i-1]);
        }

        curr.push_back(1);
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        vector<int> prev;

        for(int n = 1; n<=numRows; n++){
            if(n==1){
                ans.push_back({1});
            }
            else{
                vector<int> curr;
                getcurrRow(prev, curr);

                ans.push_back(curr);
            }

            prev = ans[ans.size()-1];
        }
        return ans;  
    }
};