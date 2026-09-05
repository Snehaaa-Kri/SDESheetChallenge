class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        //prefix
        vector<int> pmax(n, 0), smin(n, 0);

        pmax[0] = nums[0];
        for(int i=1; i<n; i++){
            pmax[i] = max(pmax[i-1], nums[i]);
        }

        smin[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            smin[i] = min(smin[i+1], nums[i]);
        }

        //cal
        for(int i=0; i<n; i++){
            int iscore = pmax[i] - smin[i];

            if(iscore <= k) return i;
        }
        return -1;
    }
};