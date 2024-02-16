// Problem: Shortest Routes I
// Contest: CSES Problem Set
// Judge: CSES
// URL: https://cses.fi/problemset/task/1671
// Memory Limit: 512
// Time Limit: 1000
// Start: 16/02/2024 18:36

#include <climits>
#include <iostream>
#include <queue>
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
  ll n, m;
  cin >> n >> m;
  vector<vector<pair<ll, ll>>> adj(n);
  for (ll counter = 0; counter < m; ++counter) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    adj[a].push_back({b, c});
  }

  // Dijkstra algorithm
  vector<ll> distance(n, LONG_LONG_MAX);
  vector<bool> visited(n, false);
  priority_queue<pair<ll, ll>> pq;
  pq.push({0, 0});
  distance[0] = 0;
  while (!pq.empty()) {
    ll node = pq.top().second;
    pq.pop();
    if (visited[node]) {
      continue;
    }
    visited[node] = true;
    for (auto u : adj[node]) {
      int next_node = u.first;
      int cost_node_to_next = u.second;
      if (cost_node_to_next + distance[node] < distance[next_node]) {
        distance[next_node] = cost_node_to_next + distance[node];
        pq.push({-distance[next_node], next_node});
      }
    }
  }

  for (ll d : distance) {
    cout << d << ' ';
  }
  return 0;
}
