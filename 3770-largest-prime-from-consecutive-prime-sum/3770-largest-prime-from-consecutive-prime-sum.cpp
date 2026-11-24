class Solution {
public:
    int largestPrime(int n) {

        vector<bool> isPrime(n + 1, true);

        isPrime[0] = false;

        if(n >= 1)
            isPrime[1] = false;

        // Sieve of Eratosthenes
        for(int i = 2; 1LL * i * i <= n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        // Prefix Sum of consecutive primes
        long long sum = 0;
        int ans = 0;

        for(int i = 2; i <= n; i++)
        {
            if(isPrime[i])
            {
                sum += i;

                if(sum > n)
                    break;

                if(isPrime[sum])
                {
                    ans = sum;
                }
            }
        }

        return ans;
    }
};