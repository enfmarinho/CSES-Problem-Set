// Problem: Josephus Problem I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2162
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 00:55

#include <iostream>
#include <set>
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
  set<int> children;
  for (int i{1}; i <= n; i++) {
    children.insert(i);
  }

  auto it = children.begin();
  while (not children.empty()) {
    if (it == children.end()) {
      it = children.begin();
    }
    ++it;
    if (it == children.end()) {
      it = children.begin();
    }
    cout << *it << ' ';
    children.erase(it++);
  }
  return 0;
}
