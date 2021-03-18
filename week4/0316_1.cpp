#include <bits/stdc++.h>
using namespace std;

int sqrt_(int n)
{
    if (n < 0) cerr << "input is negative";
    if (n == 1) return 1;
    int mid = n >> 1, left = 0, right = n;
    bool z1, z2;
    while (!(z1 = mid * mid <= n) || !(z2 = (mid+1) * (mid+1) > n)) {
        if (!z1) {
            right = mid;
            mid = (left + right) >> 1;
        }
        else if (!z2) {
            left = mid;
            mid = (left + right) >> 1;
        }
    }
    return mid;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sqrt_(n));
}