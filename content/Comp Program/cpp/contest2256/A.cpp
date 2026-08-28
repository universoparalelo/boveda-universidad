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

    vector<int> v(n);
    for(int i=0; i<n; i++){
      cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    int m = n-(n/3);

    int cont = 0, a = 0, sum = 0, cantExc = 0;
    for(int i=0; i<n; i++){
      if (v[i] != a){
        if (cantExc != 0){
          sum += (cantExc*a);
          cantExc = 0;
        }
        a = v[i];
        cont = 1;
      } else {
        cont++;
      }
      if (cont <= 2){ 
        sum += a;
      } else if (cont <= m){
        cantExc++;
      }
    }

    if (cantExc != 0 && cont <= m){
      sum += (cantExc*a);
    }

    cout << sum << '\n';
  }

  return 0;
}
