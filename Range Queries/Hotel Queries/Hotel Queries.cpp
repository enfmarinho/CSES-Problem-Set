// Problem: Hotel Queries
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1143
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 21:10

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

vll hotels;
vll segtree;

ll build(ll index, ll start, ll end) {
  if (start == end) {
    return segtree[index] = hotels[start];
  }
  ll mid = (start + end) / 2;
  return segtree[index] = max(build(index * 2, start, mid),
                              build(index * 2 + 1, mid + 1, end));
}

ll query(ll interval_begin, ll interval_end, ll index, ll start, ll end) {
  if (interval_end < start or interval_begin > end) {
    return INT_MIN;
  } else if (interval_begin <= start and interval_end >= end) {
    return segtree[index];
  }
  ll mid = (start + end) / 2;
  return max(query(interval_begin, interval_end, 2 * index, start, mid),
             query(interval_begin, interval_end, 2 * index + 1, mid + 1, end));
}

ll update(ll position, ll value, ll index, ll start, ll end) {
  if (position < start or position > end) {
    return segtree[index];
  } else if (start == end) {
    return segtree[index] = value;
  }
  ll mid = (start + end) / 2;
  return segtree[index] =
             max(update(position, value, 2 * index, start, mid),
                 update(position, value, 2 * index + 1, mid + 1, end));
}

int main() {
  GO FAST;
  int n, m;
  cin >> n >> m;
  hotels.resize(n);
  for (int index{0}; index < n; ++index) {
    cin >> hotels[index];
  }
  vll groups(m);
  for (int index{0}; index < m; ++index) {
    cin >> groups[index];
  }

  segtree.resize(4 * n);
  build(1, 0, n - 1);
  for (const ll &group : groups) {
    if (query(0, n - 1, 1, 0, n - 1) < group) {
      cout << 0 << ' ';
    } else {
      int left{0}, right{n - 1};
      while (left < right) {
        int mid = (left + right) / 2;
        if (query(0, mid, 1, 0, n - 1) >= group) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      cout << left + 1 << ' ';
      update(left, query(0, left, 1, 0, n - 1) - group, 1, 0, n - 1);
    }
  }

  return 0;
}
