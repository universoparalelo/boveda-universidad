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

    set<char> s;
    string x;
    for(int i=0; i<n; i++){
      cin >> x;
      s.insert(x[0]);
    }

    vector<string> t(m);
    for(int i=0; i<m; i++){
      cin >> t[i];
      transform(t[i].begin(), t[i].end(), t[i].begin(), ::tolower);
    }
    bool bandera = true;
    for(int i=0; i<m; i++){ 
      for(auto letter: t[i]){
        if (s.count(letter) == 0){
          bandera = false;
          break;
        }
      }
      if (!bandera){
        break;
      }
    }
    if (bandera) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
