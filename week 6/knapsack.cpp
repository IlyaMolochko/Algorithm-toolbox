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

using ll = long long ;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int W, n;
    cin >> W >> n;
    vector<int> w(n);
    for (auto &i : w){
        cin >> i;
    }
    vector<vector<int>> d(n + 1, vector<int>(W + 1));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= W; ++j){
            d[i][j] = d[i - 1][j];
            if (w[i - 1] <= j){
                d[i][j] = max(d[i][j], w[i - 1] + d[i - 1][j - w[i - 1]]);
            }
        }
    }
    cout << d[n][W] << '\n';
}
