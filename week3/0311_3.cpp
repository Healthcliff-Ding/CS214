#include <bits/stdc++.h>
using namespace std;

vector<pair<bool, pair<bool, int>>> pack;
vector<pair<int, int>> obj;
pair<bool, int> inSet(int k);
pair<bool, int> func(int k);

int main()
{
    int cap; // capacity
    int n; // n types of objects
    cin >> cap >> n;
    pack.resize(cap + 1), obj.resize(n);
    for (int i = 0; i < cap+1; ++i)
        pack[i] = pair<bool,pair<bool,int>>(false, make_pair(false, 0));
    pack[0].first = pack[0].second.first = true; pack[0].second.second = 0;
    for (int i = 0; i < n; ++i)
        cin >> obj[i].first >> obj[i].second;
    
    cout << func(cap).second << endl;
}

pair<bool, int> inSet(int k) {
    int a = obj.size();
    vector<int> b;
    for (int i = 0; i < a; ++i) {
        auto tmp = func(k - obj[i].first);
        if (tmp.first)
            b.emplace_back(tmp.second + obj[i].second);
    }
    if (b.empty())
        return make_pair(false, 1<<31);
    else
        return make_pair(true, *max_element(b.begin(), b.end()));
}

pair<bool, int> func(int k) {
    if (k < 0) 
        return make_pair(false, 1<<31);
    else if (!pack[k].first) {
        pack[k].first = true;
        return pack[k].second = inSet(k);
    }
    else 
        return pack[k].second;
}