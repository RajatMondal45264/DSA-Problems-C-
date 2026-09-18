class Solution {
public:

    bool palindrome(string &s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;

        for(int start = 0; start < n; start++)
        {
            for(int end = start; end < n; end++)
            {
                if(palindrome(s, start, end))
                {
                    count++;
                }
            }
        }

        return count;
    }
};