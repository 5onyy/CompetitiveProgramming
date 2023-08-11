#include<bits/stdc++.h>
using namespace std;
int main() {

    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;

    if (h1 * w1 + h2 * w2 + h3 * w3 != h1 * h1) {
        cout << "NO" << endl;
        return 0;
    }

    int counterOfHmax = 1;
    if (h1 == h2) {
        ++counterOfHmax;
    }
    if (h1 == h3) {
        ++counterOfHmax;
    }
    if (counterOfHmax == 3 && (w1 + w2 + w3 == h1)) {
        cout << "YES" << endl;
    }
    else if (counterOfHmax == 2) {
        cout << "NO" << endl;
    }
    else {
        if ((h2 + h3 == h1) && (w3 + w1 == h1) && (w2 + w1 == h1)) {
            cout << "YES" << endl;
        }
        else if ((h3 + w2 == h1) && (h2 + w1 == h1) && (w3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        else if ((h2 + w3 == h1) && (w2 + w1 == h1) && (h3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        else if ((w2 + w3 == h1) && (w1 + h2 == h1) && (h3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
