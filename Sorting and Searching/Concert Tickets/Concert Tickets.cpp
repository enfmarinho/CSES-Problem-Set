// Problem: Concert Tickets
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1091
// Memory Limit: 512
// Time Limit: 1000
// Start: 24/11/2023 00:17

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <deque>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define F first
#define S second
#define FF F.F
#define FS F.S
#define SS S.S
#define SF S.F
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
#define FOR(i, limit) for (int i = 0; i < limit; i++)
#define MOD 1000000007
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tuple<ll, ll, ll> tll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

int main() {
  GO FAST;
  int n, m;
  cin >> n >> m;
  multiset<int> ticket_price;
  for (int counter{0}; counter < n; ++counter) {
    int tmp;
    cin >> tmp;
    ticket_price.insert(tmp);
  }
  vi maximum_price(m);
  for (int index{0}; index < m; ++index) {
    cin >> maximum_price[index];
  }

  for (int index{0}; index < m; ++index) {
    auto it = ticket_price.upper_bound(maximum_price[index]);
    if (it != ticket_price.begin()) {
      cout << *(--it) << '\n';
      ticket_price.erase(it);
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
