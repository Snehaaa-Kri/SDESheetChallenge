class Solution {
public:
    long long gcdSum(vector<int>& nums) {
          int n=nums.size();
          vector<int>prefgcd(n); 
          int ma=nums[0];
          for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
            prefgcd[i]=gcd(ma,nums[i]);
          }

          sort(prefgcd.begin(),prefgcd.end());

          long long sum=0;              
          for(int i=0;i<(n/2);i++){
            sum+=gcd(prefgcd[i],prefgcd[n-1-i]);
          }

          return sum;
    }
};