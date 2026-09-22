class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string st = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";

        while(columnNumber > 0)
        {
            columnNumber--;

            int index = columnNumber % 26;

            ans += st[index];

            columnNumber = columnNumber / 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};