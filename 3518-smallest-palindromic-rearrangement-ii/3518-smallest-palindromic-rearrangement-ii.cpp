class Solution {
public:

    long long nCr(int n, int r, int k) {
        //nCr == nC(n-r)
        r = min(r, n-r);

        long long result = 1;

        for(int i = 1; i <= r; i++) {//O(log2(k))
            result = result * (n - r + i)/i;

            if(result >= k) 
                return k;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if(n%2 == 1) { //odd length
            mid = s[n/2];
        }

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            if(n%2 == 1 && i == n/2) continue; //mid character reserverd
            count[s[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        string halfResult = "";
        int half = n/2;

        for(int i = 0; i < half; i++) { //O(n/2)
            bool placedCharacter = false;
            for(int j = 0; j < 26; j++) {
                if(count[j] > 0) {
                    count[j] -= 1;

                    // number of ways
                    long long ways = 1;
                    int letters = 0;
                    for(int c = 0; c < 26; c++) {
                        letters += count[c];
                    }

                    for(int c = 0; c < 26; c++) {
                        if(count[c] > 0) {
                            ways *= nCr(letters, count[c], k); //log2(k)
                            letters -= count[c];
                        }

                        if(ways >= k) {
                            break;
                        }
                    }

                    if(ways >= k) {
                        halfResult.push_back(j + 'a');
                        placedCharacter = true;
                        break;
                    }

                    k -= ways;
                    count[j] += 1;
                }
            }

            if(placedCharacter == false)
                return "";
        }

        string rev = halfResult;
        reverse(begin(rev), end(rev)); //O(n/2)

        if(mid != ' ') {
            halfResult.push_back(mid);
        }

        return halfResult + rev;
    }
};


    // number of permuations = n! 
    // bool ispossible(string &left, int &k){
    //     int nfact = 1;
    //     // int n = left.size(); //count of distinct chars
    //     set<char> st;
    //     for(char &ch: left){
    //         st.insert(ch);
    //     }

    //     int n = st.size();

    //     while(n>0){
    //         nfact *= n;
    //         n--;
    //     }

    //     if(nfact < k) return false;
    //     return true;
    // }

// number of possible permuations = n! / x! y! (repeated characters case)
//     bool ispossible(string &left, int k) {
//     int n = left.size();

//     long long ways = 1;

//     // n!
//     for (int i = 2; i <= n; i++)
//         ways *= i;

//     unordered_map<char,int> freq;
//     for (char c : left)
//         freq[c]++;

//     // divide by f!
//     for (auto &[_, cnt] : freq) {
//         long long fact = 1;
//         for (int i = 2; i <= cnt; i++)
//             fact *= i;
//         ways /= fact;
//     }

//     return ways >= k;
// }
//     string smallestPalindrome(string s, int k) {
//         int n = s.size();
//         int mid = n/2;

//         string left = "";
//         for(int i=0; i<mid; i++){
//             left += s[i];
//         }
//         if(!ispossible(left, k)) return "";

//         sort(left.begin(), left.end());

//         //kth smallest permuation
//         k--;
//         while(k-->0){
//             next_permutation(left.begin(), left.end());
//         }


//         string ans = left;
//         if(n%2 == 1) ans += s[n/2];

//         for(int i=left.size()-1; i>=0; i--){
//             ans += left[i];
//         }
//         return ans;
//     }
// };