#include<iostream>
using namespace std;



int reversenum(int num){

    int reverse = 0;

    while(num!=0){

        int digit = num%10;
        reverse = reverse*10+digit;
        num/=10;
    }

    return reverse;
}

int main(){
    
    cout<<reversenum(12345);

    return 0;
}