// Problem: Range Xor Queries
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1650
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 19:06

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

vll values;
vll segtree;

int build(int index, int begin, int end) {
  if (begin == end) {
    return segtree[index] = values[begin];
  }
  int mid = (begin + end) / 2;
  return segtree[index] = (build(2 * index, begin, mid) ^
                           build(2 * index + 1, mid + 1, end));
}

int query(int interval_begin, int interval_end, int index, int begin, int end) {
  if (interval_end < begin or interval_begin > end) {
    return 0;
  } else if (interval_begin <= begin and interval_end >= end) {
    return segtree[index];
  }
  int mid = (begin + end) / 2;
  return (query(interval_begin, interval_end, 2 * index, begin, mid) ^
          query(interval_begin, interval_end, 2 * index + 1, mid + 1, end));
}

int main() {
  GO FAST;
  int n, q;
  cin >> n >> q;
  values.resize(n);
  for (int index{0}; index < n; ++index) {
    cin >> values[index];
  }

  segtree.resize(4 * n);
  build(1, 0, n - 1);
  while (q--) {
    int interval_begin, interval_end;
    cin >> interval_begin >> interval_end;
    --interval_begin;
    --interval_end;
    cout << query(interval_begin, interval_end, 1, 0, n - 1) << '\n';
  }
  return 0;
}
