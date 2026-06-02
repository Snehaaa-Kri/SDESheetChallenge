class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int p=0;
        int q=0;
        int r = n-1;

        while(q<=r){
            if(nums[q] == 0){
                swap(nums[p], nums[q]);
                p++;
                q++;
            }else if(nums[q] == 1){
                q++;
            }
            else{
                swap(nums[q], nums[r]);
                r--;
            }
        }
    }
};