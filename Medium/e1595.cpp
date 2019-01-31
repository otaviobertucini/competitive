//https://www.urionlinejudge.com.br/judge/en/problems/view/1595

#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

void find_lowers(int c, vector<int>* steps, int r){
    set<int> lower;
    for(int i = 0; i < c; i++){
        int smaller = 101;
        int index_smaller;
        for(int j = 0; j < steps->size(); j++){
            if(steps->at(j) < smaller && !lower.count(j)){
                smaller = steps->at(j);
                index_smaller = j;
            }
        }
        steps->at(index_smaller) += r;
        lower.insert(index_smaller);
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
            // int step;
            // cin >> step;
            int step = rand() % 100 + 1;
            steps.push_back(step);
        }

        find_lowers(c, &steps, r);
        double total_time = 0.0;
        for(int j = 0; j < steps.size(); j++){
            total_time += 1.0/steps.at(j);
        }
        cout << std::fixed << std::setprecision(2) << total_time << endl;
    }

    return 0;
}
