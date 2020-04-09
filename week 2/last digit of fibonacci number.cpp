#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
typedef long long ll;

struct seg{
    int l;
    int r;
    int t;
};


bool operator < (seg s1, seg s2){
    if (s1.l == s2.l){
        return s1.r < s2.r;
    }
    return s1.l < s2.l;
}

class Fibonacci final {
public:
    static int get_last_digit(int n) {
        assert(n >= 1);
        int f = 0;
        int s = 1;
        int t;
        for (int i = 2; i <= n; ++i){
            t = f;
            f = s;
            s = (f + t) % 10;
        }
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    std::cin >> n;
    if (n == 0){
	cout << 0 << '\n';
	return 0;
    }
    std::cout << Fibonacci::get_last_digit(n) << '\n';
}
