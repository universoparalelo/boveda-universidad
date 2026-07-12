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
    for(int i=0; i<n; i++)
      cin >> a[i];

    long long points = 0;
    bool bandera = false;

    for(int i=0; i<n-1; i++){
      if (bandera && points > a[i+1]){
        points += a[i+1];
      } else {
        bandera = false;
        points = 0;
      }
      if(a[i]>a[i+1] && !bandera){
        bandera = true;
        points += a[i]+a[i+1];
      }
    }

    if(points == 0 && !bandera){
      points = a[n-1];
    }
    
    cout << points << '\n';
  }

  return 0;
}
