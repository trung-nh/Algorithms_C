// https://leetcode.com/explore/interview/card/top-interview-questions-easy/102/math/744/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Approach 1: memory save
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int countPrimes(int n)
{
    if (n <= 2)
    {
        return 0;
    }
    int i, count = 0;
    for (i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            count++;
        }
    }
    return count;
}

// Approach 2: Runtime save

int countPrimes(int n)
{
    if (n <= 2)
    {
        return 0;
    }
    // Init table of (n - 2) false values
    bool *non_prime_tab = (bool *)calloc(n, sizeof(bool));
    int count = 0, i;
    for (i = 2; i * i < n; i++)
    {
        if (non_prime_tab[i])
        {
            continue;
        }
        count = 2 * i;
        while (count <= n - 1)
        {
            non_prime_tab[count] = true;
            count += i;
        }
    }
    count = 0;
    for (i = 2; i < n; i++)
    {
        if (!non_prime_tab[i])
        {
            count++;
        }
    }
    free(non_prime_tab);
    return count;
}
