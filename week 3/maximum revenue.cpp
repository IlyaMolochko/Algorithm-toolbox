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
    int c;
    int w;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i: a){
        cin >> i;
    }
    for (auto &i: b){
        cin >> i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll cnt = 0;
    for (int i = 0; i < n; ++i){
        cnt += a[i] * b[i];
    }
    cout << cnt << '\n';
}
