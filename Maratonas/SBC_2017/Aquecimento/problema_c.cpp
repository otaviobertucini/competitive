#include <iostream>
#include <vector>

using namespace std;

//Solução burra

int main() {

    int c, a, n = 0;
    cin >> c;
    cin >> a;

    while(a > 0){
        a = a-c-1;
        n++;
    }

    if(a == 0){
        cout << n+1 << endl;
    }
    else{
        cout << n << endl;
    }

    return 0;
}
