#include <bits/stdc++.h>
using namespace std;
const int maxn = 300011;
char s[maxn];
int deg[maxn], d[maxn];
vector<int> w[maxn];
int Find(int u, int c) {
  if (d[u] != -1) return d[u];
  d[u] = 0;
  for (int v : w[u]) {
    d[u] = max(d[u], Find(v, c));
  }
  d[u] += (s[u] == c + 'a');
  return d[u];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    w[u].push_back(v);
    ++deg[v];
  }
  int ct = 0;
  queue<int> que;
  for (int i = 1; i <= n; ++i) {
    if (!deg[i])
      que.push(i), ++ct;
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : w[u]) {
      if (--deg[v] == 0)
        que.push(v), ++ct;
    }
  }
  if (ct < n) {
    puts("-1");
  } else {
    int ans = 0;
    for (int c = 0; c < 26; ++c) {
      memset(d, 0xff, sizeof d);
      for (int i = 1; i <= n; ++i)
        ans = max(ans, Find(i, c));
    }
    printf("%dn", ans);
  }
  return 0;
}