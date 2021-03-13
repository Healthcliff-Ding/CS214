#include <bits/stdc++.h>
using namespace std;

double global_max = 1;
double tmp[2] = {1, 1}; // suffix_p_max, suffix_n_max

void func(const vector<double>& vec, int k) {
    int m = 1;
    tmp[0] = max(1., vec[0]);
    tmp[1] = min(-1., vec[0]);
    // 使用了消除尾递归的技巧
    while (m < k) {
        double tail = vec[m++];
        if (tail > 0) {
            tmp[0] = max(tmp[0]*tail, 1.);
            tmp[1] = min(tmp[1]*tail, -1.);
            global_max = max(tmp[0], global_max);
        }
        else if (tail < 0) {
            tmp[0] = max(tmp[1]*tail, 1.);
            tmp[1] = min(tmp[0]*tail, -1.);
            global_max = max(tmp[0], global_max); 
        }
        else
            tmp[0] = tmp[1] = 1.0;
    }
} 

int main()
{
    vector<double> data;
    int n;
    cin >> n;
    data.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i];
    func(data, n);
    cout << global_max;
}