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

    vector<char> a(n);
    for(int i=0; i<n; i++){
      cin >> a[i];
    }

    int mejor = 0, izq = 0;
    set<char> s;

    for(int der=0; der<n; der++){
      while(s.count(a[der])){
        s.erase(a[izq]);
        izq++;
      }
      s.insert(a[der]);
      mejor = max(mejor, der-izq+1);
    }

    cout << mejor << '\n';
    
  }

  return 0;
}
