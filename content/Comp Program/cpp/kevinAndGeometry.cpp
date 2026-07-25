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

    vector<long long> a(n);
    int posl = -1;
    bool bandera = false, found = false;
    for (int i=0; i<n; i++){
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (posl < n-2 && !bandera){
      for (int i=posl+1; i<n-1; i++){
        if (a[i+1] == a[i]){
          posl = i;
          found = true;
          break;
        }
      }
      if (!found){
        break;
      }
      long long last = -1;
      for(int i=0; i<n; i++){
        if (i == posl || i == posl+1){
          continue;
        }
        if (last == -1){
          last = i;
          continue;
        }
        
        if (a[i]-a[last] < 2*a[posl]){
          bandera = true;
          cout << a[posl] << " " << a[posl] << " " << a[last] << " " << a[i] << "\n";
          break;
        }

        last = i;
      }
      found = false;
      if (bandera){
        break;
      }
    }
    if (bandera == false){
      cout << "-1\n";
    }
  }

  return 0;
}
