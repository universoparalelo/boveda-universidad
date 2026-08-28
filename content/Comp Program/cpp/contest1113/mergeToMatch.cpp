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

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int j=0;
    while(j<m){
      int i = j;
      if(a[i]<=b[j] && a[i+1]>=b[j]){
        a.erase(i,2);
        a.insert(a.begin()+i, b[j]);
        n--;
      }
      if(a[i+1]<=b[j+1] && a[i+2]>=b[j+1]){
        j++;
      }
      
    }
    
  }

  return 0;
}
