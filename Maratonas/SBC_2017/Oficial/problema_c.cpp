//http://maratona.ime.usp.br/hist/2017/prim-fase17/maratona.pdf

#include <iostream>
#include <vector>

using namespace std;

int recursive_gcd(int a, int b){
    if(!b){
        return a;
    }
    return recursive_gcd(b, a%b);
}

int gcd(vector<int>* nums){
    int res = nums->at(0);
    for(int i = 1; i < nums->size(); i++){
        if(res == 1){
            return res;
        }
        res = recursive_gcd(res, nums->at(i));
    }

    return res;
}

int main() {

    int n, l, c, total = 1, k = 1;
    cin >> n >> l;
    vector<int> nums(n);

    for(int i = 0; i < n; i++){
        cin >> c;
        total *= c;
        nums.push_back(c);
    }

    int lcm = total / gcd(&nums);

    int x = 0;
    int i = 1, big = -1, n_big;
    while(i <= l){
        x = (i*lcm)/recursive_gcd(i, lcm);
        // if(x > l){
        //     break;
        // }
        // int x_sum = x;
        // while(x_sum <= l){
        //     x_sum += x;
        // }
        // if(x_sum > l){
        //     x_sum -= x;
        // }
        if(x > big){
            big = x;
            n_big = i;
        }
        i++;
    }
    cout << n_big << endl;

    return 0;
}
