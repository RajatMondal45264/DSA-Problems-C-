class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000)
        {
            return 0;
        }

    long long total = 0;
    long long power = 1000;
    int commas = 1;
    
    while (power <= n) {
        long long start = power;
        long long end = min(n, power * 1000 - 1);
        
        total += (end - start + 1) * commas;
        
        power *= 1000;
        commas++;
    }
    
    return total;
    }
};