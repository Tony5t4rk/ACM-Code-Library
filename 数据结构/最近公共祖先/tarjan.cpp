const int maxn = "Edit";
const int maxm = "Edit";
int n;
int pre[maxn];
int Find(int o) {
  return pre[o] == o ? o : pre[o] = Find(pre[o]);
}
void Union(int u, int v) {
  if (Find(u) != Find(v)) pre[Find(u)] = Find(v);
}
std::vector<int> g[maxn];
bool vis[maxn];
struct query { int v, id; };
std::vector<query> qry[maxm];
void Init() {
  for (int i = 1; i <= n; ++i) {
    pre[i] = i;
    vis[i] = false;
  }
}
void Tarjan(int u) {
  vis[u] = true;
  for (int &v : g[u]) {
    if (vis[v]) continue;
    Tarjan(v);
    Union(v, u);
  }
  for (query &q : qry[u]) {
    if (vis[q.v]) ans[q.id] = Find(q.v);
  }
}