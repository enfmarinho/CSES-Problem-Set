// Problem: Collecting Numbers
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2216
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 03:04

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
  int n;
  cin >> n;
  vi values(n);
  vi indexes(n + 1);
  for (int index{0}; index < n; ++index) {
    cin >> values[index];
    indexes[values[index]] = index;
  }

  int ans{1};
  for (int index{1}; index < n; ++index) {
    if (indexes[index] > indexes[index + 1]) {
      ++ans;
    }
  }
  cout << ans;
  return 0;
}
