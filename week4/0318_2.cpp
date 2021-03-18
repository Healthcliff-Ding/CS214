#include <bits/stdc++.h>
using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair;

int cnt = 0;
int max(int& a, int& b) {
    ++cnt;
    return std::max(a, b);
}
int min(int& a, int& b) {
    ++cnt;
    return std::min(a, b);
}

int numn, n, *a;
pair<int,int> d_a_q(int l, int r) {
    if (l == r)     return make_pair(a[l], a[r]);
    if (l == r - 1) return make_pair(min(a[l], a[r]), max(a[l], a[r]));
    auto p1 = d_a_q(l, l + r >> 1);
    auto p2 = d_a_q((l + r >> 1) + 1 , r);
    return make_pair(min(p1.first, p2.first), max(p1.second, p2.second));
}

int main()
{
    cin >> n;
    // compiler throws error if overflow
    numn = 1 << n;
    a = new int[1 < n];
    for (int i = 0; i < numn; ++i)
        cin >> a[i];
    
    auto b = d_a_q(0, numn-1);
    cout << "minimum: " << b.first << endl;
    cout << "maximun: " << b.second << endl;
    cout << "compare: " << cnt;
}