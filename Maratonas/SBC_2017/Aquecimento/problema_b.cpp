#include <iostream>
#include <vector>

using namespace std;

int main() {

    int j, r, p, big = 0, win;
    vector<int> jog;
    cin >> j >> r;

    jog.reserve(j);
    fill(jog.begin(), jog.end(), 0);

    for(int i = 0, k=1; i < j*r; i++, k++){
        cin >> p;
        jog[k-1] += p;
        if(jog[k-1] >= big){
            win = k;
        }
        if(k==j){
            k = 0;
        }
    }

    cout << win << endl;

    return 0;
}
