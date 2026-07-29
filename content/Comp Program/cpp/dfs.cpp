#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n+1);
    for (int i=0; i<m; i++){
      int u, v;
      cin >> u >> v;

      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<bool> visited(n+1, false);

    void dfs(int u){
      visited[u] = true;
      for (int v : g[u]){
        if (!visited[v]){
          dfs(v);
        }
      }
    }

    dfs(1);
  }

  return 0;
}
