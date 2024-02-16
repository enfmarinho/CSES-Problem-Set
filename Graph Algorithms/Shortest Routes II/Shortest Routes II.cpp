// Problem: Shortest Routes II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1672
// Memory Limit: 512
// Time Limit: 1000
// Start: 16/02/2024 19:12

#include <climits>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define ull unsigned ll
#define ld long double
#define range(a) a.begin(), a.end()
#define GO ios_base::sync_with_stdio(false);
#define FAST cin.tie(nullptr);
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
  ll n, m, q;
  cin >> n >> m >> q;
  vector<vector<ull>> distances(n, vector<ull>(n, LONG_LONG_MAX));
  for (ll counter{0}; counter < m; ++counter) {
    ull a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    distances[a][b] = min(distances[a][b], c);
    distances[b][a] = min(distances[b][a], c);
  }

  for (ll x = 0; x < n; ++x) {
    for (ll y = 0; y < n; ++y) {
      for (ll z = 0; z < n; ++z) {
        distances[y][z] =
            min(distances[y][z], distances[y][x] + distances[x][z]);
      }
    }
  }

  while (q--) {
    ll a, b;
    cin >> a >> b;
    --a;
    --b;
    if (a == b) {
      cout << 0 << '\n';
    } else if (distances[a][b] == LONG_LONG_MAX) {
      cout << -1 << '\n';
    } else {
      cout << distances[a][b] << '\n';
    }
  }
  return 0;
}
