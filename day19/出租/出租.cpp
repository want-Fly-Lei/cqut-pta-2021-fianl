#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string s;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, b[11], c[10];
    cin >> s;
    for (int i = 0; i < 11; i++){
        a[s[i] - 48] = 1;
    }
    int k = 0, n = 0;
    for (int l = 0; l < 10; l++){
        if (a[l] == 1){
            ++n;
        }
    }

    cout << "int[] arr = new int[]{";
    for (int j = 9; j >= 0; j--){
        if (a[j] == 1 && k < n - 1){
            cout << j << ",";
            c[k] = j;
            k++;
        }

        else if (a[j] == 1){
            cout << j;
            c[k] = j;
            k++;
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    for (int p = 0; p < s.length(); p++){
        for (int t = 0; t < k; t++){
            if (s[p] - '0' == c[t] && p < 10) {
                cout << t << ",";
            } else if (s[p] - '0' == c[t]) {
                cout << t;
            }
        }
    }
    cout << "};" << endl;
}
