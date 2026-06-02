class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini = INT_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        //try out all ways
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //land -> water
                int lf = landStartTime[i] + landDuration[i];

                int finish1 = max(lf, waterStartTime[j]) + waterDuration[j];

                //water -> land
                int wf = waterStartTime[j] + waterDuration[j];
                int finish2 = max(wf, landStartTime[i]) + landDuration[i];

                mini = min({mini, finish1, finish2});
            }
        }
        return mini;
    }
};