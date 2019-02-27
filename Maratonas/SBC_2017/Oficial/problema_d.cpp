//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>
#include <math.h>

using namespace std;

int isDespojado(long long n)
{
    if(n == 1){
        return 0;
    }
    int prime = 1;
    for(long long k = 2; k <= sqrt(n); k++){
        if(n % (k*k) == 0){
            return 0;
        }
        if(n % k == 0){
            prime = 0;
        }
    }
    return !prime;
}

int main() {

    long long n, k = 1;
    int count = 0;
    cin >> n;

    for(; k < sqrt(n); k++){
        if(n % k == 0){
            count += isDespojado(k);
            if(k != n/k){
                count += isDespojado(n/k);
            }
        }
    }

    cout << count << endl;

    return 0;
}
