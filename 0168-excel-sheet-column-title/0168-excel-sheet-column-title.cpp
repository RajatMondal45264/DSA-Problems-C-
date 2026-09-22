class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        map<int, char> mp;

        for(int i = 1; i <= 26; i++)
        {
            mp[i] = 'A' + (i - 1);
        }

        string ans = "";

        while(columnNumber > 0)
        {
            if(columnNumber <= 26)
            {
                ans += mp[columnNumber];
                break;
            }

            int rem = columnNumber % 26;

            if(rem == 0)
            {
                ans += 'Z';
                columnNumber = columnNumber - 26;
            }
            else
            {
                ans += mp[rem];
                columnNumber = columnNumber - rem;
            }

            columnNumber = columnNumber / 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};