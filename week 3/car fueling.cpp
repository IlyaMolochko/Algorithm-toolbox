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
    int d, m, n;
    cin >> d >> m >> n;
    vector<int> v(n);
    int s = 0;
    int last = 0;
    for (auto &i : v){
        cin >> i;
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i){
        if (v[i] - last > m){
            ++cnt;
            if (v[i - 1] - last > m){
                cout << -1 << '\n';
                return 0;
            }
            last = v[i - 1];
        }
    }
    if (d - last > m){
        if (d - v[n - 1] > m){
            cout << -1 << '\n';
            return 0;
        }
        ++cnt;
    }
    cout << cnt << '\n';
}
