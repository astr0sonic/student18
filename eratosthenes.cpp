#include "eratosthenes.h"
#include <vector>
using namespace std;

std::vector<int> sieve(int n) {
    vector<bool> f(k + 1);
    vector<int> v;
    for (int i = 0; i <= k; i++)
        f[i] = true;

    for (int i = 2; i * i <= k; i++)
        if (f[i] == true)
            for (int j = i * i; j <= k; j += i)
                f[j] = false;
    for (int i = 2; i <= k; i++)
        if (f[i])
            v.push_back(i);
    return v;
}
