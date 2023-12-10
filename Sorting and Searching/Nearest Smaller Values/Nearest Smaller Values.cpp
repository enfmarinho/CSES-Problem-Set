// Problem: Nearest Smaller Values
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1645
// Memory Limit: 512
// Time Limit: 1000
// Start: 10/12/2023 16:25

#include <iostream>
#include <stack>
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
  for (int index{0}; index < n; ++index) {
    cin >> values[index];
  }

  stack<pair<int, int>> s;
  for (int index{0}; index < n; ++index) {
    while (not s.empty() and s.top().first >= values[index]) {
      s.pop();
    }
    if (s.empty()) {
      cout << 0 << ' ';
    } else {
      cout << s.top().second << ' ';
    }
    s.push({values[index], index + 1});
  }
  return 0;
}
