#include "volume.h"
#include <algorithm>
using namespace std;

int getMaxVolume(int a, int b, int c, int n, int* arr)
{
    int mx = 0;
    int i = 0, j = n - 1;
    while (i != j)
    {
        int mn = min({ arr[i], arr[j], c });
        int t = (j - i < a) ? (j - i) * mn : a * mn;
        if (mx < t)
            mx = t;
        if (arr[i] <= arr[j])
            i++;
        else
            j--;
    }
    return b * mx;
}