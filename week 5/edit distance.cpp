#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>

using ll = long long ;


int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> d(n + 1, std::vector<int> (m + 1));
    for (int i = 0; i < n + 1; ++i){
        d[i][0] = i;
    }
    for (int j = 0; j < m + 1; ++j){
        d[0][j] = j;
    }
    int c = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            c = 1 - (s1[i - 1] == s2[j - 1]);
            d[i][j] = std::min(d[i][j - 1] + 1, std::min(d[i - 1][j] + 1, d[i - 1][j - 1] + c));
        }
    }
    std::cout << d[n][m] << '\n';
    return 0;
}