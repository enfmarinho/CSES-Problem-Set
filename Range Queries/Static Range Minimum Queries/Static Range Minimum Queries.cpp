// Problem: Static Range Minimum Queries
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1647
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 12:47

#include <climits>
#include <iostream>
#include <tuple>
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

vll values;
vll segtree;

ll build(ll index, ll start, ll end) {
  if (start == end) {
    return segtree[index] = values[start];
  }
  ll mid = (start + end) / 2;
  return segtree[index] = min(build(index * 2, start, mid),
                              build(index * 2 + 1, mid + 1, end));
}

ll query(ll interval_begin, ll interval_end, ll index, ll start, ll end) {
  if (interval_end < start or interval_begin > end) {
    return INT_MAX;
  } else if (interval_begin <= start and interval_end >= end) {
    return segtree[index];
  }
  ll mid = (start + end) / 2;
  return min(query(interval_begin, interval_end, 2 * index, start, mid),
             query(interval_begin, interval_end, 2 * index + 1, mid + 1, end));
}

int main() {
  GO FAST;
  ll n, q;
  cin >> n >> q;
  values.resize(n);
  for (ll index = 0; index < n; index++) {
    cin >> values[index];
  }

  segtree.resize(4 * n);
  build(1, 0, n - 1);
  while (q--) {
    ll start, end;
    cin >> start >> end;
    --start;
    --end;
    cout << query(start, end, 1, 0, n - 1) << '\n';
  }
  return 0;
}
