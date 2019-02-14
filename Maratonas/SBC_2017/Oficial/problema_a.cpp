//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>
#include <vector>

using namespace std;

int larg(vector<int>* vec){
    int index, large = -1;
    for(int i = 0; i < vec->size(); i++){
        int a = vec->at(i);
        if(a > large){
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
        vector<int> qtd(8, 0);

        for(int j = a; j < b-a+1; j++){
            qtd[notes[j]-1]++;
        }
        int n = larg(&qtd) + 1;

        for(int j = a; j <= b; j++){
            notes[i] += n;
            if(notes[i] > 8){
                notes[i] -= 9;
            }
        }
    }

    for(int i = 0; i < notes.size(); i++){
        cout << notes[i] << endl;
    }

    return 0;
}
