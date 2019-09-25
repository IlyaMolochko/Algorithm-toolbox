#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

typedef long long ll;

int main() {
    int n, k;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i : v){
        std::cin >> i;
    }
    std::cin >> k;
    std::vector<int> b(k);
    for (auto &i : b){
        std::cin >> i;
    }
    int l = 0, r = n - 1;
    for (int i = 0, j; i < k; ++i){
        l = 0; r = n - 1;
        while (r >= l){
            j = (r + l) / 2;
            if (v[j] == b[i]){
                std::cout << j << ' ';
                break;
            } else if (v[j] < b[i]){
                l = j + 1;
            } else {
                r = j - 1;
            }
        }
        if (v[j] != b[i]){
            std::cout << -1 << ' ';
        }
    }
}
