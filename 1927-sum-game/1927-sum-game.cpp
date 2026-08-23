class Solution {
public:
    bool sumGame(string num) {
        
        int count = 0;
        int n = num.size();

        for(int i = 0; i < n; i++)
        {
            if(num[i] == '?')
            {
                count++;
            }
        }

        // No '?'
        if(count == 0)
        {
            int leftSum = 0;
            int rightSum = 0;

            for(int i = 0; i < n / 2; i++)
            {
                leftSum += num[i] - '0';
            }

            for(int i = n / 2; i < n; i++)
            {
                rightSum += num[i] - '0';
            }

            return leftSum != rightSum;
        }

        // '?' present
        else
        {
            int leftMark = 0;
            int rightMark = 0;

            int leftSum = 0;
            int rightSum = 0;

            for(int i = 0; i < n / 2; i++)
            {
                if(num[i] == '?')
                {
                    leftMark++;
                }
                else
                {
                    leftSum += num[i] - '0';
                }
            }

            for(int i = n / 2; i < n; i++)
            {
                if(num[i] == '?')
                {
                    rightMark++;
                }
                else
                {
                    rightSum += num[i] - '0';
                }
            }

            // Odd difference in '?' count
            if(abs(leftMark - rightMark) % 2 != 0)
            {
                return true;
            }

            // Important condition
            int diff = leftMark - rightMark;

            if(leftSum + (diff * 9) / 2 == rightSum)
            {
                return false;
            }

            return true;
        }
    }
};