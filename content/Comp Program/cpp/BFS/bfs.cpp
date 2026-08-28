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

    vector<vector<int>> adj(n+1);

    for(int i=0; i<n-1; i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> nivelDe(n+1, -1);
    // vector<bool> visitado(n+1, false);
    // visitado[1] = true;
    queue<int> q;
    q.push(1);
    nivelDe[1] = 0;

    while(!q.empty()){
      // int tamNivel = q.size();
      // for(int i=0; i<tamNivel; i++){
      // if(!visitado[vecino]){
      // visitado[vecino] = true;
      // q.push(vecino)
      // }
      int actual = q.front();
      q.pop();

      for(auto vecino : adj[actual]){
        if(nivelDe[vecino] == -1){
          nivelDe[vecino] = nivelDe[actual] + 1;
          q.push(vecino);
        }
      }
    }
  }

  return 0;
}
