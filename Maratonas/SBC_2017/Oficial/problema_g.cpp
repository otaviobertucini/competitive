//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>

using namespace std;

void generate(int t, int m, int n, int i, int* count, int tam = 0){
    tam++;
    if(tam == t){
        (*count)++;
        return;
    }
    if(i + 1 <= n){
        generate(t, m, n, i+1, count, tam);
    }
    if(i - 1 >= m){
        generate(t, m, n, i-1, count, tam);
    }
}

int main() {

    int t, m, n;

    cin >> t >> m >> n;
    int count = 0, k = m;

    for(int i = 0; i < (n-m+1)/2; i++, k++){
        cout << i << endl;
        generate(t, m, n, k, &count, 0);
    }
    count *= 2;
    if((n-m+1) % 2 != 0){
        generate(t, m, n, k, &count, 0);
    }

    cout << count << endl;

    return 0;
}
