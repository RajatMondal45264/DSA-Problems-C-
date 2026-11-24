
class Solution {
public:
    int largestPrime(int n) {

        vector<bool> isPrime(n + 1, true);

        if(n >= 0) isPrime[0] = false;
        if(n >= 1) isPrime[1] = false;

        // Generate Prime Numbers using Sieve
        for(int i = 2; i * i <= n; i++)
        {
            if(isPrime[i])
            {
                for(int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        // Store Prime Numbers
        vector<int> primes;

        for(int i = 2; i <= n; i++)
        {
            if(isPrime[i])
            {
                primes.push_back(i);
            }
        }

        // Cumulative Sum
        long long sum = 0;
        int ans = 0;

        for(int i = 0; i < primes.size(); i++)
        {
            sum += primes[i];

            if(sum > n)
                break;

            if(isPrime[sum])
            {
                ans = sum;
            }
        }

        return ans;
    }
};
