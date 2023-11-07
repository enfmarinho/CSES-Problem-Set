// Problem: Message Route
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1667
// Memory Limit: 512
// Time Limit: 1000
// Start: 06/11/2023 21:06

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
#include <variant>
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
typedef vector<vi> vvii;
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
  vvii adj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  vector<int> dist(n);
  vector<int> p(n, -1);
  dist[0] = 1;
  p[0] = 0;
  q.push(0);
  while (not q.empty()) {
    int a = q.front();
    q.pop();
    for (auto u : adj[a]) {
      if (p[u] != -1)
        continue;
      dist[u] = dist[a] + 1;
      p[u] = a;
      q.push(u);
    }
  }

  if (dist[n - 1] == 0) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << dist[n - 1] << '\n';
    vll ans;
    int u = n - 1;
    while (u != 0) {
      ans.push_back(u);
      u = p[u];
    }
    cout << 1 << ' ';
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
