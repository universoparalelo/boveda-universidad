#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    const long long N;
    cin >> N;
    bitset<n> a,b;
    cin >> a;
    cin >> b;
    cout << a << " " << b << '\n';

    if(a==b || ~a!=b){
      cout << "NO" << '\n';
    } else {
      cout << "YES" << '\n';
    }
  }

  return 0;
}
