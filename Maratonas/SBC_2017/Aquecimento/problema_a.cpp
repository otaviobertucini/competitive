#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k=0;
    vector<int> values;
    values.push_back(1);

    cin >> n;

    while(n != 0){
        int i = 0;
        while(values[i] < n){
            i++;
            if(i > values.size() - 1){
                values.push_back(values[i-1]*(i+1));
            }
        }
        if(values[i] != n){
            i--;
        }
        k++;
        n = n - values[i];
    }

    cout << k << endl;
    return 0;
}
