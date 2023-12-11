// Problem: Number Spiral
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1071
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 00:13

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
  int t;
  cin >> t;

  while (t--) {
    ll y, x;
    cin >> y >> x;
    if (y > x) {
      if (y % 2 == 0) {
        cout << y * y - x + 1 << '\n';
      } else {
        cout << (y - 1) * (y - 1) + x << '\n';
      }
    } else if (x % 2 == 1) {
      cout << x * x - y + 1 << '\n';
    } else {
      cout << (x - 1) * (x - 1) + y << '\n';
    }
  }
  return 0;
}
