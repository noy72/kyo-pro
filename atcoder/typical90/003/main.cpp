#include <cassert>
#include <ctgmath>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define range(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, b) for (int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x) cerr << #x << " = " << (x) << endl;
using namespace std;

template <typename X, typename T> auto vectors(X x, T a) {
  return vector<T>(x, a);
}
template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
  auto cont = vectors(y, z, zs...);
  return vector<decltype(cont)>(x, cont);
}
template <typename T> ostream& operator<<(ostream& os, vector<T>& v) {
  rep(i, v.size()) { os << v[i] << (i == v.size() - 1 ? "" : " "); }
  return os;
}
template <typename T> istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v) {
    is >> x;
  }
  return is;
}

const int INF = 1e8;

class Tree {
  int n; // 頂点の数

  void bfs(int s, vector<int>& dis, vector<int>& pre) {
    queue<int> q;
    dis[s] = 0;
    q.emplace(s);

    while (not q.empty()) {
      int u = q.front();
      q.pop();
      for (auto e : g[u]) {
        if (dis[e.first] == INF) {
          dis[e.first] = dis[u] + e.second;
          pre[e.first] = u;
          q.emplace(e.first);
        }
      }
    }
  }

public:
  vector<vector<pair<int, int>>> g;
  vector<int> path; // 最長パス

  Tree(int n) : n(n), g(n) {}

  void addEdge(int a, int b, int c = 1) {
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }

  // 直径を返す
  int diameter() {
    vector<int> pre(n, -1), dis(n, INF);
    bfs(0, dis, pre);

    int maxi = 0, tgt = 0;
    rep(i, n) {
      if (dis[i] == INF)
        continue;
      if (maxi < dis[i]) {
        maxi = dis[i];
        tgt = i;
      }
    }

    pre = vector<int>(n, -1);
    dis = vector<int>(n, INF);
    bfs(tgt, dis, pre);
    maxi = 0; // tgtから最も遠い接点の距離maxi
    rep(i, n) {
      if (dis[i] == INF)
        continue;
      if (maxi < dis[i]) {
        maxi = dis[i];
        tgt = i;
      }
    }

    int pos = tgt;
    while (pre[pos] != -1) {
      path.emplace_back(pre[pos]);
      pos = pre[pos];
    }
    return maxi;
  }

  // 木の中心を返す。
  // 頂点数が偶数なら pair でふたつの頂点番号を返す。
  // 頂点数が奇数なら pair.second は -1 になる。
  pair<int, int> center() {
    if (path.empty())
      diameter();

    assert(path.size() == 0 and "path is empty");
    if (path.size() % 2 == 0) {
      return make_pair(path[path.size() / 2 - 1], path[path.size() / 2]);
    } else {
      return make_pair(path[path.size() / 2], -1);
    }
  }
};

int main() {
  int n;
  cin >> n;

  Tree t = Tree(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    t.addEdge(--a, --b);
  }
  cout << t.diameter() + 1 << endl;
}
