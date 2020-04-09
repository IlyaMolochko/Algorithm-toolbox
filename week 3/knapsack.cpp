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
    int n, W;
    cin >> n >> W;
    vector<label> v(n);
    for (auto &i : v){
        cin >> i.c >> i.w;
    }
    sort(v.begin(), v.end(), [](label s1, label s2){
        return double(s1.c) / s1.w > double(s2.c) / s2.w;
    });
    double s = 0;
    int i = 0;
    while (W > 0){
        if (W > v[i].w){
            W -= v[i].w;
            s += v[i].c;
            ++i;
        } else {
            s += double(W)  * v[i].c / v[i].w;
            break;
        }
        if (i == n){
            break;
        }
    }
    cout << fixed << setprecision(5);
    cout << s << '\n';
}
