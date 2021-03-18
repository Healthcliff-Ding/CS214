#include <bits/stdc++.h>
using namespace std;

// 1个
// 2个
// n个
int height, strength;
bool crash(int h) {
    return h > strength;
}
int eins() {
    int i = 1;
    while (!crash(i))
        ++i;
    return i - 1;
}
int zwei() {
    int a = sqrt(height);
    int i, j;
    for (i = a; i < height; i+=a) {
        if (crash(i)) break;
    }
    if (i >= height) {
        i -= a;
        for (j = i; j < height; ++j) {
            if (crash(j)) break;
        }
        return j - 1;
    }
    else {
        i -= a;
        for (j = i; j < height; ++j) {
            if (crash(j)) break;
        }
        return j - 1;
    }
}
int viele(int l, int r) { // 目标有可能出现的位置
    if (l == r) return l;
    if (l == r - 1) {
        return (crash(r))? l: r;
    }
    int mid = l + r >> 1;
    if (!crash(mid))
        return viele(mid, r);
    else
        return viele(l, mid-1);
}

int main()
{
    cout << "input an integer height: ";
    cin >> height;
    cout << "input a non-negative integer strength within height: ";
    cin >> strength;
    if (strength < 0 || strength > height)
        cerr << "invalid input";
    cout << "use a single bottle: " << eins() << endl;
    cout << "use double bottles: " << zwei() << endl;
    cout << "use plenty of bottles: " << viele(0, height) << endl;
}