// Problem: Minimizing Coins
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1634/
// Memory Limit: 512
// Time Limit: 1000
// Start: 23/11/2023 21:33

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
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

vll coins;
vll tabel;
vb calculated;
ll dp(ll x) {
  if (x < 0)
    return INT_MAX;
  else if (x == 0)
    return 0;
  else if (calculated[x])
    return tabel[x];
  ll ans = INT_MAX;
  for (auto v : coins) {
    ans = min(ans, dp(x - v) + 1);
  }
  calculated[x] = true;
  return tabel[x] = ans;
}

int main() {
  GO FAST;
  ll n, x;
  cin >> n >> x;
  tabel.resize(x + 1, 0);
  calculated.resize(x + 1, false);
  coins.resize(n);
  for (ll index = 0; index < n; ++index) {
    cin >> coins[index];
  }
  ll ans = dp(x);
  if (ans == INT_MAX)
    cout << -1;
  else
    cout << ans;
  return 0;
}
