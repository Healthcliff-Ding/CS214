#include <bits/stdc++.h>
using namespace std;

struct bolt {
    int id, sz;
    bolt(int i, int s): id(i), sz(s) {}
};
struct nut{
    int id, sz;
    nut(int i, int s): id(i), sz(s) {}
    nut(const nut& oth): id(oth.id), sz(oth.sz) {}
};

vector<pair<int,int>> table;
int n;

// merge的过程需要遍历一遍，是O(n)的
// 当每次确定了一个新的匹配之后，就可以调用两次
void match(const vector<bolt>& b_vec, const vector<nut>& n_vec) {
    if (table.size() < n) {
        int sz = b_vec[0].sz, tot = b_vec.size();
        vector<nut> l_n, g_n;
        vector<bolt> l_b, g_b;
        for (int i = 0; i < tot; ++i) {
            if (n_vec[i].sz == sz)
                table.emplace_back(make_pair(b_vec[0].id, n_vec[i].id));
            else if (n_vec[i].sz < sz)
                l_n.emplace_back(n_vec[i]);
            else
                g_n.emplace_back(n_vec[i]);
        }
        for (int i = 1; i < tot; ++i) {
            if (b_vec[i].sz < sz)
                l_b.emplace_back(b_vec[i]);
            else
                g_b.emplace_back(b_vec[i]);
        }
        if (!l_b.empty())   match(l_b, l_n);
        if (!g_b.empty())   match(g_b, g_n);
    }
    else return;
}

int main()
{
    vector<bolt> bolt_vec;
    vector<nut> nut_vec;
    cin >> n;
    // Input two permutation of [1:n]
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        bolt_vec.emplace_back(bolt(i, tmp));
    }
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nut_vec.emplace_back(nut(i, tmp));
    }
    
    match(bolt_vec, nut_vec);
    for (auto& it: table)
        cout << boolalpha << (bolt_vec[it.first].sz == nut_vec[it.second].sz) << endl;
}