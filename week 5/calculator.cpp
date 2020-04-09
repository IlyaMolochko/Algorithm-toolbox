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
    std::vector<int> d(1000001);
    d[1] = 0;
    for (int i = 2; i <= n; ++i){
        if (i % 6 == 0){
            d[i] = std::min(d[i / 2] + 1, std::min(d[i / 3] + 1, d[i - 1] + 1));
        } else if (i % 3 == 0){
            d[i] = std::min(d[i / 3] + 1, d[i - 1] + 1);
        } else if (i % 2 == 0){
            d[i] = std::min(d[i / 2] + 1, d[i - 1] + 1);
        } else {
            d[i] = d[i - 1] + 1;
        }
    }
    std::vector<int> a;
    for (int i = n; i > 1;){
        if (i % 3 == 0 and d[i / 3] == d[i] - 1){
            a.push_back(i);
            i /= 3;
        } else if (i % 2 == 0 and d[i / 2] == d[i] - 1){
            a.push_back(i);
            i /= 2;
        } else {
            a.push_back(i);
            --i;
        }
    }
    std::cout << a.size() << '\n';
    std::cout << 1 << ' ';
    for (int i = a.size() - 1; i >= 0; --i){
        std::cout << a[i] << ' ';
    }
    return 0;
}