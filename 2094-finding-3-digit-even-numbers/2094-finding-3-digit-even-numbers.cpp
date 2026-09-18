class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;

        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j< n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    if(i == j || j == k || i == k)
                    {
                        continue;
                    }

                    if(digits[i] == 0)
                    {
                        continue;
                    }

                    if(digits[k] % 2 != 0)
                    {
                        continue;
                    }

                    int num = digits[i]*100 +
                              digits[j]*10 +
                              digits[k];

                    ans.push_back(num);
                }
            }
        }

        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};