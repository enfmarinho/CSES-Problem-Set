// Problem: Room Allocation
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1164
// Memory Limit: 512
// Time Limit: 1000
// Start: 09/12/2023 20:09

#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
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
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> customers(n);
  for (ll client{0}; client < n; ++client) {
    ll arrival, departure;
    cin >> arrival >> departure;
    customers[client] = make_tuple(departure, arrival, client);
  }
  sort(range(customers));

  multimap<ll, ll> arrivals;
  vll rooms(n);
  for (ll index = n - 1; index >= 0; --index) {
    ll departure, arrival, client;
    tie(departure, arrival, client) = customers[index];
    auto it = arrivals.upper_bound(departure);
    if (it != arrivals.end()) {
      rooms[client] = it->second;
      arrivals.erase(it);
    } else {
      rooms[client] = arrivals.size() + 1;
    }
    arrivals.insert({arrival, rooms[client]});
  }

  cout << arrivals.size() << '\n';
  for (int index = 0; index < n; ++index) {
    cout << rooms[index] << ' ';
  }
  return 0;
}
