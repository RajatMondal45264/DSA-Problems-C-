class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i<= right; i++)
        {
            bool flag = true;
            int num = i;
            while(num)
            {
                int last = num % 10;
                if(last == 0)
                {
                    flag = false;
                    break;
                }

                if(i % last != 0)
                {
                    flag = false;
                    break;
                }

                num = num / 10;
            }

            if(flag)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};