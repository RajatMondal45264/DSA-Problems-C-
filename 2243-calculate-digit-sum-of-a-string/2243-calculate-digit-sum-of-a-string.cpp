class Solution {
public:
    string digitSum(string s, int k) {

        while(s.size() > k)
        {
            int len = s.size();
            string ans = "";

            for(int i = 0; i < len; i += k)
            {
                int sum = 0;

                for(int j = 0; j < k && i + j < len; j++)
                {
                    int digit = s[i + j] - '0';
                    sum += digit;
                }

                ans += to_string(sum);
            }

            s = ans;
        }

        return s;
    }
};
