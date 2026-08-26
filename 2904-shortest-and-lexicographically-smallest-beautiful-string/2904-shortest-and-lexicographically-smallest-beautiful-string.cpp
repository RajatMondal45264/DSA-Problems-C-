class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int start = 0;
        int end = 0;
        int n = s.size();

        int ones = 0;
        string ans = "";

        while(end < n)
        {
            if(s[end] == '1')
            {
                ones++;
            }

            // More than k ones
            while(ones > k)
            {
                if(s[start] == '1')
                {
                    ones--;
                }
                start++;
            }

            // Exactly k ones
            if(ones == k)
            {
                // Remove leading zeros to make window shortest
                while(s[start] == '0')
                {
                    start++;
                }

                string curr = s.substr(start, end - start + 1);

                if(ans == "" || curr.length() < ans.length())
                {
                    ans = curr;
                }
                else if(curr.length() == ans.length())
                {
                    ans = min(ans, curr);
                }
            }

            end++;
        }

        return ans;
    }
};