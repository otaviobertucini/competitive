//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>
#include <vector>

using namespace std;

/*
Pseudo:
Given a number n, divide n starting by 2. If it's
divisable, go on and try to divide by the nexts
primes. If it's not divisable by 2, try the next primes.
If there's no prime to divide, the algo is over.
*/

// int isPrime(int n){
//     int count = 0;
//     if(n <= 2){
//         return 1;
//     }
//     for(int i = 2; i < n; i++){
//         if(n % i == 0){
//             return 0;
//         }
//     }
//     return 1;
// }

int isPrime(int n)
{
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;

    if (n%2 == 0 || n%3 == 0) return 0;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return 0;

    return 1;
}

//TODO: verificar resposta

int main() {

    int n = 252, count = 0, k = 2;
    //cin >> n;

    while(n != 1){
        if(isPrime(k) && n % k == 0){
            count++;
            n /= k;
        }
        k++;

        if(k == n){
            cout << 0 << endl;
            return 0;
        }
    }

    cout << k << endl;


    return 0;
}
