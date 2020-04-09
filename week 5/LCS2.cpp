#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>
#include <set>

using ll = long long ;

void solve(std::vector<int> &a, std::vector<int> &b){
    std::vector<std::vector<int>> d(a.size(), std::vector<int> (b.size()));
    int mx = 0;
    for (int j = 0; j < b.size(); ++j){
        mx = std::max(mx, 0 + (b[j] == a[0]));
        d[0][j] = mx;
    }
    for (int i = 1; i < a.size(); ++i){
        if (a[i] == b[0]){
            d[i][0] = 1;
        } else {
            d[i][0] = d[i - 1][0];
        }
        for (int j = 1; j < b.size(); ++j){
            if (a[i] == b[j]){
                d[i][j] = d[i - 1][j - 1] + 1;
            } else {
                d[i][j] = std::max(d[i][j - 1], std::max(d[i - 1][j - 1], d[i - 1][j]));
            }
        }
    }
    std::cout << d[a.size() - 1][b.size() - 1] << '\n';
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a){
        std::cin >> i;
    }
    std::cin >> m;
    std::vector<int> b(m);
    for (auto &i : b){
        std::cin >> i;
    }
    std::vector<std::pair<int, int>> matrix;
    if (n < m){
        solve(b, a);
    } else {
        solve(a, b);
    }
    return 0;
}
