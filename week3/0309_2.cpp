#include <bits/stdc++.h>

using namespace std;

bool solve(const vector<int> &vec, int head) {
    int a = vec[head];
    int b = vec.size();

    if (head + a >= b) return true;
    
    while (a) {
        if ((head + a) < b && solve(vec, head + a))
            return true;
        --a;
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    nums.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    cout << boolalpha << solve(nums, 0);
}