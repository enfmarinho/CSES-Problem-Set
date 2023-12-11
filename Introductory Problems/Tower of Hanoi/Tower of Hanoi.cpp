// Problem: Tower of Hanoi
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/2165
// Memory Limit: 512
// Time Limit: 1000
// Start: 11/12/2023 02:53

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

void hanoi(int disc_size, int start, int aux, int dest) {
  if (disc_size == 0) {
    return;
  }
  hanoi(disc_size - 1, start, dest, aux);
  cout << start << ' ' << dest << '\n';
  hanoi(disc_size - 1, aux, start, dest);
}

int main() {
  GO FAST;
  int n;
  cin >> n;

  cout << pow(2, n) - 1 << '\n';
  int a{1}, b{2}, c{3};
  hanoi(n, a, b, c);
  return 0;
}
