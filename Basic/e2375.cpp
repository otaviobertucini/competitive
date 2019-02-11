//https://www.urionlinejudge.com.br/judge/en/problems/view/2375

#include <iostream>

using namespace std;

int main() {

    int d, s;
    cin >> d;
    for(int i = 0; i < 3; i++){
      cin >> s;
      if(s < d){
        cout << "N" << endl;
        return 0;
      }
    }

    cout << "S" << endl;
    return 0;
}
