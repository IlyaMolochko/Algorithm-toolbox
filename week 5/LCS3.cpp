#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>

using ll = long long ;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }
    cin >> m;
    vector<int> b(m);
    for (auto &i : b){
        cin >> i;
    }
    cin >> l;
    vector<int> c(l);
    for (auto &i : c){
        cin >> i;
    }
    vector<vector<vector<int>>> d = vector(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1)));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            for (int k = 1; k <= l; ++k){
                if (a[i - 1] == b[j - 1] and c[k - 1] == a[i - 1]){
                    d[i][j][k] = d[i - 1][j - 1][k - 1] + 1;
                } else {
                    d[i][j][k] = max(d[i - 1][j][k], max(d[i][j - 1][k], d[i][j][k - 1]));
                }
            }
        }
    }
    cout << d[n][m][l] << '\n';
    return 0;
}