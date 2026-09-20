class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int a = 26;
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            mp[ch] = a;
            a--;
        }

        int sum = 0;
        for(int i = 0; i< n; i++)
        {
            sum = sum + (mp[s[i]] * (i+1));
        }

        return sum;
    }
};