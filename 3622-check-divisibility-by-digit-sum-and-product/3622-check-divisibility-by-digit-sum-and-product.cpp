class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int sum = 0;
        int temp = n;
        while(temp)
        {
            int last = temp % 10;
            sum = sum + last;
            prod = prod * last;

            temp = temp / 10;
        }

        if(n % (sum + prod) == 0)
        {
            return true;
        }

        return false;
    }
};