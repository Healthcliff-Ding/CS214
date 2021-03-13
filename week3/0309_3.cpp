#include <bits/stdc++.h>
#define A 0
#define B 1
#define C 2
using namespace std;

vector<int> posi, target;
int buffer, cnt;
bool flag, ifPrint;

void print() {
    for (auto& iter : posi) 
        cout << iter + 1 << ' ';
    cout << endl;
}

bool cmp() {
    int a = posi.size();
    for (int i = 0; i < a; ++i) {
        if ((posi[i]+1) != target[i])
            return false;
    }
    if (ifPrint) cout << "Here------";
    return flag = true;
}

void func(int src, int dest, int other, int num) {
    if (num == 1) {
        posi[num-1] = dest; ++cnt;
        if (!flag && cmp())  buffer = cnt;
        if (ifPrint) print();
        return;
    }
    func(src, other, dest, num - 1);
    posi[num-1] = dest; ++cnt;
    if (!flag && cmp())  buffer = cnt;
    if (ifPrint) print();
    func(other, dest, src, num - 1);
}

int main()
{
    int n;
    flag = cnt = 0;
    // You can "trun" ifPrint to "true"
    // to make a log in terminal.
    ifPrint = false;
    cin >> n;
    posi.resize(n); target.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> target[i];
    for (int i = 0; i < n; ++i)
        posi[i] = 0;

    if (ifPrint) {
        cout << "start-----";
        print();
    }

    func(A, C, B, n);

    if (flag)
        cout << "answer:" << buffer;
    else
        cout << "-1";
}