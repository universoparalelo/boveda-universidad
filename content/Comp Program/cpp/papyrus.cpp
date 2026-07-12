#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    int n, c;
    cin >> n >> c;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
      cin >> a[i];
    }

    for (int i = 0; i < n; i++){
      cin >> b[i];
    }
    
    long long costo = 0;
    
    for (int i=0; i<n; i++){
      costo += (a[i] - b[i]);
    }

    if (costo < 0){
      cout << "-1" << '\n';
      continue;
    }

    bool bandera = false;
    
    for (int i=0; i<n; i++){
      if (a[i] < b[i]){
        bandera = true;
        break;
      }
    }

    if (!bandera){
      cout << costo << '\n'; 
      continue;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool reorder = false;
    for (int i=0; i<n; i++){
      if (a[i] < b[i]){
        reorder = true;
        break;
      }
    }

    if (reorder){
      cout << "-1" << '\n';
    } else {
      cout << costo+c << '\n';
    }
  }
  return 0;
}
