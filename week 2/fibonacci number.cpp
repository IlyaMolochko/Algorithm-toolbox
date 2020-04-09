#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll a = 0, b = 1, s = 0;
    for (int i = 0; i <= n; ++i){
        s += a;
        a = b;
        b = s;
    }
    cout << s << '\n';
}
