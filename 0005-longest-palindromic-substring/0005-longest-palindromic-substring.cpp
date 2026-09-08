class Solution {
public:

    string ans = "";

    void expand(string &s, int l, int r) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            if(r - l + 1 > ans.size()) {
                ans = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }

        return ans;
    }
};