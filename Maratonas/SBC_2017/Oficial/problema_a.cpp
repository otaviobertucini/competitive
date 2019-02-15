//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>
#include <vector>

using namespace std;

int larg(vector<int>* vec){
    int index, large = -1;
    for(int i = 0; i < vec->size(); i++){
        int a = vec->at(i);
        if(a >= large){
            large = a;
            index = i;
        }
    }
    return index;
}

int main() {

    int n, q, a, b;

    cin >> n >> q;
    vector<int> notes(n, 1);

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        vector<int> qtd(9, 0);

        for(int j = a; j <= b; j++){
            qtd[notes[j]]++;
        }
        int n = larg(&qtd);

        for(int j = a; j <= b; j++){
            notes[j] += n;
            if(notes[j] > 8){
                notes[j] -= 9;
            }
        }
    }

    for(int i = 0; i < notes.size(); i++){
        cout << notes[i] << endl;
    }

    return 0;
}
