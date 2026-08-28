class Solution {
public:
    char midChar = '$';
    int halflen = 0;
    string result = "";

    bool solve(string &curr, vector<int> &freq, string &target,
               int i, bool greater)
    {
        // Half complete
        if(curr.length() == halflen)
        {
            string candidate = curr;

            string righthalf = curr;
            reverse(righthalf.begin(), righthalf.end());

            if(midChar != '$')
            {
                candidate += midChar;
            }

            candidate += righthalf;

            if(candidate > target)
            {
                result = candidate;
                return true;
            }

            return false;
        }

        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            if(freq[ch - 'a'] == 0)
            {
                continue;
            }

            // If prefix is equal to target's prefix,
            // we cannot choose a smaller character.
            if(!greater && ch < target[i])
            {
                continue;
            }

            curr.push_back(ch);
            freq[ch - 'a']--;

            bool isGreater = greater || (ch > target[i]);

            if(solve(curr, freq, target, i + 1, isGreater))
            {
                return true;
            }

            curr.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string target)
    {
        int n = s.size();

        vector<int> freq(26, 0);

        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        int oddCount = 0;

        for(int c = 0; c < 26; c++)
        {
            if(freq[c] % 2 == 1)
            {
                oddCount++;
                midChar = c + 'a';
            }
        }

        // Palindrome impossible
        if(oddCount > 1)
        {
            return "";
        }

        // We only need half of the characters
        for(int c = 0; c < 26; c++)
        {
            freq[c] /= 2;
        }

        halflen = n / 2;

        string curr = "";

        solve(curr, freq, target, 0, false);

        return result;
    }
};