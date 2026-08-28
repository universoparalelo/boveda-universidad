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
        long long sumTotal = 0;
        map<int,int> freq;
        
        for(int i=0;i<n;i++){
            cin >> v[i];
            sumTotal += v[i];
            freq[v[i]]++;
        }
        
        // encontrar el valor mas frecuente
        int mejorVal = -1, f = 0;
        for(auto& [val, cnt] : freq){
            if(cnt > f){ f = cnt; mejorVal = val; }
        }
        
        long long sumOther = sumTotal - (long long)f*mejorVal;
        long long huecos = (long long)(n-f) + 1;
        long long capturedV;
        
        if(f <= huecos){
            capturedV = f; // no hace falta chocar nunca
        } else {
            capturedV = huecos + 1; // llenamos todos los huecos + la que dispara el escudo
        }
        
        long long respuesta = sumOther + capturedV*(long long)mejorVal;
        cout << respuesta << '\n';
    }
    return 0;
}
