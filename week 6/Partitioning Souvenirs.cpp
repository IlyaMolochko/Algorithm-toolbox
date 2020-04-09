#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using ll = long long ;
using namespace std;
struct label{
    int x = 0;
    int y = 0;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum % 3 != 0){
        cout << 0 << '\n';
        return 0;
    }
    int s = sum / 3;
    vector<vector<int>> d(s + 1, vector<int>(n + 1));
    int item;
    int cnt = 0;
    for (int i = 1; i <= s; ++i){
        for (int j = 1; j <= n; ++j){
            d[i][j] = d[i][j - 1];
            if (a[j - 1] <= i){
                item =  d[i - a[j - 1]][j - 1] + a[j - 1];
                if (d[i][j] < item){
                    d[i][j] = item;
                }
            }
            if (d[i][j] == s){
                ++cnt;
            }
        }
    }
//    for (int i = 0; i <= s; ++i){
//        for (int j = 0; j <= n; ++j){
//            cout << d[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    if (cnt >= 3){
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}
