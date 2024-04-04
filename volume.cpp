#include "volume.h"
#include <algorithm>
using namespace std;

int getMaxVolume(int a, int b, int c, int n, int* arr)
{
    int mx = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            int mn = min({ arr[i], arr[j], c });
            int t = (j - i < a) ? (j - i) * mn : a * mn;
            if (mx < t)
                mx = t;
        }
    return b * mx;
}