#include <bits/stdc++.h>
using namespace std;

int n, z;
vector<int> vec;

int seqSearch() {
    int step, curr = 0, tmp;

    while (curr <= n) {
        
        tmp = vec[curr];
        if (tmp == z)
            return curr + 1;
        else {
            step = abs(z-tmp);
            curr += step;
        }
    }
    return -1;
}

// Do not keep sort bin, just for illustration.
int binSearch() {
    bool *bin;
    int sup = (vec.front() + vec.back() + n) >> 1;
    int inf = (vec.front() + vec.back() - n) >> 1;
    int *posi;
    bin = new bool[sup + inf];
    posi = new int[sup + inf];
    for (int i = 0; i < n; ++i) {
        bin[vec[i] + inf] = true;
        posi[vec[i] + inf] = i + 1;
    }
    return (bin[inf+z])? posi[inf+z]: -1;
}

int main()
{
    int tmp;
    cin >> n;
    cin >> tmp;
    for (int i = 1; i < n; ++i) {
        vec.push_back(tmp);
        cin >> tmp;
        if (abs(tmp - vec.back()) > 1)
            cerr << "contradict to problem setting";
    }
    vec.push_back(tmp);
    if (vec.front() >= vec.back()) 
        cerr << "contradict to problem setting";
    cin >> z;
    
    int a = seqSearch();
    int b = binSearch();
    string str = (a > 0)? to_string(a): "Not found\n";
    // string str = (a > 0)? to_string(a): "Not found\n";
    cout << str;
}