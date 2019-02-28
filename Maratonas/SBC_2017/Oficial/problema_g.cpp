//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>

/*TODO: criar uma função recursiva para analisar os resultados.
OBS: não é a resposta do programa! é só para visualizar.
*/

using namespace std;

void generate(int t, int m, int n, int i, int* count, int tam = 0, int str = 0){
    str *= 10;
    str += i;
    tam++;
    if(tam == t){
        (*count)++;
        cout << str << endl;
        return;
    }
    if(i + 1 <= n){
        generate(t, m, n, i+1, count, tam, str);
    }
    if(i - 1 >= m){
        generate(t, m, n, i-1, count, tam, str);
    }
}

int main() {

    int t, m, n;

    cin >> t >> m >> n;
    int count = 0;

    for(int i = m; i <= n; i++){
        generate(t, m, n, i, &count, 0, 0);
        cout << "***********" << endl;
    }

    cout << count << endl;

    return 0;
}
