class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char, int> mp;

        for(int i = 1; i <= 26; i++)
        {
            mp['A' + (i - 1)] = i;
        }

        int ans = 0;

        for(int i = 0; i < columnTitle.size(); i++)
        {
            ans = ans * 26 + mp[columnTitle[i]];
        }

        return ans;
    }
};