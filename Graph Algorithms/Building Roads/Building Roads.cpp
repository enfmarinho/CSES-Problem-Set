// Problem: Building Roads
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512
// Time Limit: 1000
// Start: 06/11/2023 20:29

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

vector<int> sz;
vector<int> link;

int find(int x) {
  while (x != link[x])
    x = link[x];
  return x;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  sz[a] += sz[b];
  link[b] = a;
}

int main() {
  GO FAST;
  int n, m;
  cin >> n >> m;
  sz.resize(n + 1);
  link.resize(n + 1);
  for (int i = 0; i <= n; i++) {
    link[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    unite(a, b);
  }

  set<int> rep;
  for (int i = 1; i <= n; i++) {
    rep.insert(find(i));
  }

  cout << rep.size() - 1 << '\n';
  for (auto it = ++rep.begin(); it != rep.end(); it++) {
    cout << *rep.begin() << ' ' << *it << '\n';
  }

  return 0;
}
