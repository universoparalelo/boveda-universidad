#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n;
    cin >> n;

    vector<int> par(n+1, 0);
    for(int i=2; i<=n; i++){
      cin >> par[i];
    }

    int m;
    cin >> m;

    vector<char> isDam(n+1, 0);
    for(int i=0; i<m; i++){
      int a; cin >> a;
      isDam[a] = 1;
    }

    vector<char> f(n+1, 0);
    vector<vector<int>> trueChildren(n+1);
    for(int i=1; i<=n; i++){
      f[i] = isDam[i];
    }

    for(int i=n; i>=2; i--){
      if(f[i]){
        int p = par[i];
        trueChildren[p].push_back(i);
        f[p] = 1;
      }
    }

    vector<int> cameras;
    cameras.reserve(n);
    for(int v=1; v<=n; v++){
      int c = trueChildren[v].size();
      if (isDam[v]){
        for(int u: trueChildren[v]) cameras.push_back(u);
      } else if(c>=2){
        for(int i=0; i<c-1; i++) cameras.push_back(trueChildren[v][i]);
      }
    }

    cout << cameras.size();
    for(int v : cameras) cout << ' ' << v;
    cout << '\n';
  }

  return 0;
}
