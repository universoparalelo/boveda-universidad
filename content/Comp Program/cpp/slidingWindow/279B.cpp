#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;
  
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  int izq=0, suma=0, mejor=0;

  for(int der=0; der<n; der++){
    suma += a[der];
    while(suma > t){
      suma -= a[izq];
      izq++;
    }
    mejor = max(mejor, der-izq+1);
  }

  cout << mejor << '\n';

  return 0;
}
