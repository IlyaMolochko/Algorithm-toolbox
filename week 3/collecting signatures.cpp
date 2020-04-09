#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
typedef long long ll;

struct label{
    int l;
    int r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<label> a(n);
    for (auto &i: a){
        cin >> i.l >> i.r;
    }
    sort(a.begin(), a.end(), [](label l1, label l2){
        if (l1.r == l2.r){
            return l1.l < l2.l;
        }
        return l1.r < l2.r;
    });
    int cnt = 1;
    int lst = a[0].r;
    vector<int> v;
    v.push_back(lst);
    for (int i = 1; i < n; ++i){
        if (a[i].l > lst){
            ++cnt;
            lst = a[i].r;
            v.push_back(lst);
        }
    }
    cout << v.size() << '\n';
    for (auto i : v){
        cout << i << ' ';
    }
}
