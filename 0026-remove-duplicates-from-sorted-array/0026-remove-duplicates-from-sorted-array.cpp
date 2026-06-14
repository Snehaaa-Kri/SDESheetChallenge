class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0; //till sorted part
        int j = 1; // unsorted part

        while(j<n){
            if(nums[j] != nums[i]){
                i++;
                swap(nums[i], nums[j]);
            }
            j++;

        }
        return i+1;
    }
};