class Solution {
public:
    int cnt;

    vector<int> mergesort(int l, int r, vector<int> &nums){
        if(l==r) return {nums[l]};
        
        int mid = l+(r-l)/2;

        vector<int> left = mergesort(l, mid, nums);
        vector<int> right = mergesort(mid+1, r, nums);


        // Count reverse pairs
        int j = 0;
        for (int i = 0; i < left.size(); i++) {
            while (j < right.size() && left[i] > 2LL * right[j])
                j++;

            cnt += j;
        }

        vector<int> temp;
        int i = 0;
        j = 0;
        while(i< left.size() && j<right.size()){

            if(left[i] <= right[j]){
                temp.push_back(left[i]);
                i++;
            }
            else{
                temp.push_back(right[j]);
                j++;
            }
        }

        while(i<left.size()){
            temp.push_back(left[i]);
            i++;
        }

        while(j<right.size()){
            temp.push_back(right[j]);
            j++;
        }

        return temp;
    }
    int reversePairs(vector<int>& nums) {
        cnt = 0;
        int n = nums.size();

        vector<int> temp = mergesort(0, n-1, nums);

        return cnt;
    }
};