// Problem: Polygon Area
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2191
// Memory Limit: 512
// Time Limit: 1000
// Start: 23/02/2024 02:52

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
  vector<pair<ll, ll>> vertices(n);
  for (int idx{0}; idx < n; ++idx) {
    cin >> vertices[idx].first >> vertices[idx].second;
  }
  vertices.push_back(vertices[0]);

  ll sum{0};
  for (int idx{0}; idx < n; ++idx) {
    sum += vertices[idx].first * vertices[idx + 1].second -
           vertices[idx + 1].first * vertices[idx].second;
  }
  cout << abs(sum);
  return 0;
}
