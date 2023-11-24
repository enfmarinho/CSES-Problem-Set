// Problem: Ferris Wheel
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1090
// Memory Limit: 512
// Time Limit: 1000
// Start: 24/11/2023 00:11

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

int main() {
  GO FAST;
  int n, x;
  cin >> n >> x;
  vi weights(n);
  for (int index{0}; index < n; ++index) {
    cin >> weights[index];
  }

  sort(range(weights));

  int ans{0}, begin{0}, end{n - 1};
  while (begin <= end) {
    if (begin == end) {
      ++ans;
      ++begin;
      --end;
    } else if (weights[begin] + weights[end] <= x) {
      ++ans;
      ++begin;
      --end;
    } else {
      ++ans;
      --end;
    }
  }
  cout << ans;
  return 0;
}
