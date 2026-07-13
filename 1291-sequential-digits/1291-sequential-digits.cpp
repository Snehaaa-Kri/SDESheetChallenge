class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;

        for(int i=1;i<=9;i++){
            q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int curr = q.front();
                q.pop();

                if(curr>=low && curr<=high){
                    ans.push_back(curr);
                }

                if(curr%10<9){
                    int next_in_seq = curr*10+(curr%10+1);
                    if(next_in_seq<=high){
                        q.push(next_in_seq);
                    }
                }
            }
        }

        return ans;
    }
};