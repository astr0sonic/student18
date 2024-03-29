#include "sundaram.h"
#include <vector>
#include <cmath>
using namespace std;

std::vector<int> sieve(int k) {
    k = (k - 1) / 2;
    vector<bool> f(k + 1);
    vector<int> primes = { 2 };
    for (int i = 0; i <= k; i++)
        f[i] = true;

    for (int i = 1; i <= (sqrt(2 * k + 1) - 1) / 2; i++)
        for (int j = i; i + j + 2 * i * j <= k; j++)
            f[i + j + 2 * i * j] = false;

    for (int i = 1; i <= k; i++)
        if (f[i])
            primes.push_back(i * 2 + 1);
    return primes;
}
