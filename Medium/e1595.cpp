//https://www.urionlinejudge.com.br/judge/en/problems/view/1595

#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void make_sum(double* total_time, vector<int>* vec){
    for(int j = 0; j < vec->size(); j++){
        *total_time += 1.0/vec->at(j);
    }
}

void find_lowers(int c, vector<int>* steps, int r){
    sort(steps->begin(), steps->end());
    for(int i = 0; i < c; i++){
        steps->at(i) += r;
    }
}

int main() {
    srand(time(NULL));

    int t, s, c, r;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s >> c >> r;
        vector<int> steps;
        steps.reserve(s);

        for(int j = 0; j < s; j++){
            int step;
            cin >> step;
            //int step = rand() % 100 + 1;
            steps.push_back(step);
        }

        find_lowers(c, &steps, r);
        double total_time = 0.0;
        make_sum(&total_time, &steps);
        cout << std::fixed << std::setprecision(2) << total_time << endl;
    }

    return 0;
}
