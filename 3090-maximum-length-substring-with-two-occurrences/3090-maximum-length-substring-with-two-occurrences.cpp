class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        int end =0;
        int count = 0;
        unordered_map<char, int>freq;
        int n = s.size();
        int ans = 0;

        while(end < n)
        {
            freq[s[end]]++;
            while(freq[s[end]] > 2)
            {
                freq[s[start]]--;
                start++;
            }

            ans = max(ans, end - start + 1);

            end++;
        }

        return ans;
    }
};