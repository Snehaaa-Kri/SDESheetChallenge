class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int l = 0;
        int r = piles.size()-1;

        int alicesum = 0, bobsum = 0;
        while(l<r){
            if(piles[l] > piles[r]){
                alicesum += piles[l];
                bobsum += piles[r];
            }
            else{
                alicesum += piles[r];
                bobsum += piles[l];
            }
            l++;
            r--;
        }

        return alicesum > bobsum;
    }
};