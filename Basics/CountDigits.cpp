#include <iostream>
using namespace std;

int countDigits(int num) {
    int count = 0;

    if (num == 0) {
        count = 1;
    } else {
        while (num != 0) {
            num /= 10;
            count++;
        }
    }

    return count;
}

<<<<<<< HEAD
int main() {
    cout << countDigits(500000000);
=======

int main() {
    cout << countDigits(5000);
>>>>>>> 4b5a69eb23f1e4f8dbea6514b147664d2bf11ee3

    return 0;
}
