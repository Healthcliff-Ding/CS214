#include <bits/stdc++.h>
using namespace std;

vector<pair<bool, bool>> pack;
vector<int> obj;
bool inSet(int k);
bool func(int k);

int main()
{
    int cap; // capacity
    int n; // n types of objects
    cin >> cap >> n;
    pack.resize(cap + 1), obj.resize(n);
    for (int i = 0; i < cap+1; ++i)
        pack[i] = pair<bool,bool>(false, false);
    pack[0].first = pack[0].second = true;
    for (int i = 0; i < n; ++i)
        cin >> obj[i];
    cout << boolalpha << func(cap) << endl;
}

bool inSet(int k) {
    int a = obj.size();
    for (int i = 0; i < a; ++i) {
        if (func(k - obj[i])) 
            return true;
    }
    return false;
}

bool func(int k) {
    if (k < 0) 
        return false;
    else if (!pack[k].first) {
        pack[k].first = true;
        return pack[k].second = inSet(k);
    }
    else 
        return pack[k].second;
}