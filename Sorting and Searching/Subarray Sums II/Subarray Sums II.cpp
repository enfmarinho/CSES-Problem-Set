// Problem: Subarray Sums II
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1661
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 01:34

#include <iostream>
#include <map>
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
  int n, x;
  cin >> n >> x;
  vi values(n);
  for (int index{0}; index < n; ++index) {
    cin >> values[index];
  }

  map<ll, ll> m;
  m[0] = 1;
  ll ans{0}, sum{0};
  for (int index{0}; index < n; ++index) {
    sum += values[index];
    ans += m[sum - x];
    ++m[sum];
  }
  cout << ans;
  return 0;
}
