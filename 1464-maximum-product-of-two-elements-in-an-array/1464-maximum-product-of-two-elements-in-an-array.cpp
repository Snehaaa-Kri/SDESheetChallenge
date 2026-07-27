class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN;

        for(int i =0; i<nums.size(); i++){
            first = nums[i]>first ? nums[i] : first;
        }

        int second = INT_MIN;
        int count = 0;
        for(int i =0; i<nums.size(); i++){
            if(nums[i] == first && count == 0){
                count++;
                continue;
            }
            second = (nums[i]>=second)? nums[i] : second;  
        }

        return (first-1)*(second-1);

    }
};