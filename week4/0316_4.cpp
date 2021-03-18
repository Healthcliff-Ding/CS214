#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> a;
int *init;

bool grt(const pair<int,int>& a, const pair<int,int>& b) {
    return a.first > b.first;
}

// 线段树
// 线段树要改一下
class interval
{
private:
    int l, r, info, tag, fixed;
    bool hasTag;
    interval *lc, *rc;
    void merge() {
        // if a node dosen't have child, then merge() won't be called
        fixed = lc->fixed + rc->fixed; 
        info = lc->info + rc->info;
    }
    // push ---- push down tags through interval tree nodes
    void push() {
        if (hasTag) {
            lc->tag += tag;
            rc->tag += tag;
            lc->hasTag = rc->hasTag = true;
            lc->info -= tag * (lc->r - lc->l + 1 - lc->fixed);
            rc->info -= tag * (rc->r - rc->l + 1 - rc->fixed);
            hasTag = tag = 0;
        }
    }
public:
    ~interval() {}
    interval(int ll, int rr): l(ll), r(rr) {
        hasTag = tag = fixed = 0;
        if (l == r) {
            lc = rc = NULL;
            info = init[ll];
            return; 
        }
        int mid = (l + r) >> 1;
        lc = new interval(l, mid);
        rc = new interval(mid+1, r);
        merge();
    }
    // set specific element fixed
    void fix(int posi) {
        if (l == r) {
            fixed = 1;
            return;
        }
        push();
        int mid = (l + r) >> 1;
        if (posi <= mid) lc->fix(posi);
        else             rc->fix(posi);
        merge();
        return;
    }
    // make a interval decrement
    void modify(int L, int R) {
        if (R < L) return;
        if (l >= L && r <= R) {
            hasTag = true;
            tag++;
            info -= (r - l + 1 - fixed);
            return;
        }
        int mid = (l + r) >> 1;
        push();
        if(L <= mid)    lc->modify(L, R);
        if(R > mid)     rc->modify(L, R);
        merge();
        return;
    }
    int query(int L, int R) {
        if(l >= L && r <= R) return info;
        push();
        int mid = (l + r) >> 1; 
        if(R <= mid)    return lc->query(L, R);
        if(L > mid)     return rc->query(L, R); 
        return lc->query(L, R) + rc->query(L, R);
    }
    int query(int posi) {
        return query(posi, posi);
    }
};

int main()
{
    int tmp;
    cin >> n; init = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a.emplace_back(make_pair(tmp, i));
        init[i] = n - i - 1;
    }
    sort(a.begin(), a.end(), grt);

    interval segment(0, n-1);
    
    for (int i = 0; i < n; ++i) {
        segment.fix(a[i].second);
        segment.modify(0, a[i].second - 1);
    }
    cout << segment.query(0, n-1) << endl;
}