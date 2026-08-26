class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;

        int si = -1;
        int minlen = INT_MAX;
        int onescnt = 0;
        while(j<n){
            if(s[j] == '1') onescnt++;

            while(onescnt > k){
                if(s[i] == '1') onescnt--;
                i++;
            }

            if(onescnt == k){
                //shrink left point
                while(s[i] != '1'){
                    i++;
                }

                int len = j-i+1;
                if(len < minlen || (len == minlen && s.substr(i, len) < s.substr(si, minlen)) ){
                    si = i;
                    minlen = len;
                }
            }
            j++;
        }

        return si == -1? "": s.substr(si, minlen);
    }
};