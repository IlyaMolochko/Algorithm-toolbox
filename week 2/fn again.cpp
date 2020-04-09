#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
typedef long long ll;

struct seg{
    int l;
    int r;
    int t;
};


bool operator < (seg s1, seg s2){
    if (s1.l == s2.l){
        return s1.r < s2.r;
    }
    return s1.l < s2.l;
}

int gcd(int a, int b){
    int t;
    if (a < b){
        swap(a, b);
    }
    while (a % b){
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m, n;
    cin >> n >> m;
    vector<ll> v(2);
    v[0] = 0;
    v[1] = 1;
    if (n <= 1){
        cout << n;
        return 0;
    }
    ll f = 0, s = 1;
    int count = 0;
    ll t;
    for (int i = 2; i <= m * m; ++i){
        t = (f + s) % m;
        v.push_back(t);
        f = s;
        s = t;
        ++count;
        if (t == 1 and f == 0){
            break;
        }
    }
    cout << v[n % count] << '\n';
}
