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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    int s = m / 10;
    m %= 10;
    s += m / 5 + m % 5;
    cout << s << '\n';
}
