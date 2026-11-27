class Solution {
public:
    int minChanges(string s) {

        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i += 2) {

            int zero = 0;
            int one = 0;

            if(s[i] == '0') zero++;
            else one++;

            if(s[i + 1] == '0') zero++;
            else one++;

            ans += min(zero, one);
        }

        return ans;
    }
};