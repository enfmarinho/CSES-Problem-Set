// Problem: Two Knights
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1072
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 00:34

#include <cmath>
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
  for (ll x{1}; x <= n; ++x) {
    ll result = (pow(x, 4) - pow(x, 2)) / 2 - 4 * (pow(x, 2) - 3 * x + 2);
    cout << result << '\n';
  }
  return 0;
}
