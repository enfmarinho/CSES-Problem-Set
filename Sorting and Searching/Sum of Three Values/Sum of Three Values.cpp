// Problem: Sum of Three Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1641
// Memory Limit: 512
// Time Limit: 1000
// Start: 24/11/2023 23:50

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

pii sum_of_two_values(const vpii &values, int target, int ignore) {
  int start{0}, end = values.size() - 1;
  while (start != end) {
    int sum = values[start].first + values[end].first;
    if (start == ignore) {
      ++start;
    } else if (end == ignore) {
      --end;
    } else if (sum > target) {
      --end;
    } else if (sum < target) {
      ++start;
    } else {
      return {start, end};
    }
  }
  return {-1, -1};
}

int main() {
  GO FAST;
  int n, x;
  cin >> n >> x;
  vpii values(n);
  for (int index{0}; index < n; ++index) {
    cin >> values[index].first;
    values[index].second = index + 1;
  }
  sort(range(values));

  for (int index{0}; index < n; ++index) {
    pii tmp = sum_of_two_values(values, x - values[index].first, index);
    if (tmp.first != -1) {
      cout << values[tmp.first].second << ' ' << values[tmp.second].second
           << ' ' << values[index].second;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
