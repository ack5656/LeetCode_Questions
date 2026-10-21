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

int main() {
    cout << countDigits(500000000);

    return 0;
}