#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>

using ll = long long ;


int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(std::max(n + 1, 5));
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 1;
    v[4] = 1;
    for (int i = 5; i <= n; ++i){
        v[i] = std::min(v[i - 1] + 1, std::min(v[i - 3] + 1, v[i - 4] + 1));
    }
    std::cout << v[n] << '\n';
    return 0;
}