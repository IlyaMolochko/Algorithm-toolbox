#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
typedef long long ll;

int binary_search(vector<int> &a, int item){
    int l = 0;
    int r = a.size() - 1;
    int mid = (l + r) / 2;
    while (a[mid] != item){
        if (a[mid] < item){
            l = mid + 1;
            mid = (l + r) / 2;
        } else if (a[mid] > item){
            r = mid - 1;
            mid = (l + r) / 2;
        }
        if (a[mid] == item){
            return mid;
        } else if (l >= r){
            return -1;
        }
    }
    return mid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }
    cin >> k;
    vector<int> b(k);
    for (auto &i : b){
        cin >> i;
        cout << binary_search(a, i) << ' ';
    }

}
