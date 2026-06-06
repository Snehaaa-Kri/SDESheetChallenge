class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n, 0), rightsum(n,0), diff(n);
        
        int sum = 0;
        for(int i=0; i<n; i++){
            leftsum[i] = sum;
            sum += nums[i];
        }

        sum = 0;
        for(int i=n-1; i>=0; i--){
            rightsum[i] = sum;
            sum += nums[i];
        }

        for(int i=0; i<n; i++){
            diff[i] = abs(leftsum[i] - rightsum[i]);
        }
        return diff;
    }
};