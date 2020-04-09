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

int gcd(int a, int b){
    int t;
    if (a < b){
        swap(a, b);
    }
    while (a % b){
        t = a % b;
        a = b;
        b = t;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
}
