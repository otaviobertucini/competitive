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
        int numi = nums->at(i);
        if(res == 1 || numi == 1){
            return res;
        }
        cout << i << endl;
        res = recursive_gcd(res, numi);
    }

    return res;
}

int main() {

    int n, l, c, total = 1, k = 1;
    vector<int> nums;
    cin >> n >> l;
    nums.reserve(n);

    for(int i = 0; i < n; i++){
        cin >> c;
        nums.push_back(c);
    }

    int gcdr = gcd(&nums);

    int res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        int numi = nums[i];
        res = (res*numi)/recursive_gcd(res, numi);
    }

    int lcm;
    if(nums.size() <= 2){
        lcm = res;
    }
    else{
        lcm = res / gcdr;
    }

    int x = 0;
    int i = 1, big = -1, n_big;
    while(i <= l){
        x = (i*lcm)/recursive_gcd(i, lcm);
        if(x > big && x <= l){
            big = x;
            n_big = i;
        }
        i++;
    }
    cout << n_big << endl;

    return 0;
}
