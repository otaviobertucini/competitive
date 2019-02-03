#include <iostream>

using namespace std;

int main() {

    int n, number, dig = 1;
    //cin >> n;
    cin >> number;
    int aux = number/10;
    while(aux != 0){
        dig *= 10;
        aux /= 10;
    }

    for(int i = 0; i < n-1; i++){}

    return 0;
}
