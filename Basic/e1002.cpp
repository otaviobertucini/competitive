#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {

    double value;
    cin >> value;

    cout << std::fixed << std::setprecision(4) <<
    "A=" << pow(value, 2)*3.14159 << endl;

    return 0;
}
