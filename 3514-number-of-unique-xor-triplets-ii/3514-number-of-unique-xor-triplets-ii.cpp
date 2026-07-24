class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int size = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int bits = log2(maxi)+1,count = 0;
        bool st[(int)pow(2,bits)];

        memset(st,false,sizeof(st));

        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                st[(nums[i]^nums[j])] = true;
            }
        }

        maxi = pow(2,bits)-1;

        for(int i=0;i<=maxi;i++)
        {
            for(int j = 0;j<size;j++)
            {
                int temp = i^nums[j];
                if(st[temp]){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};