#include<iostream>
#include <cmath>
using namespace std;

bool IsArmstrong(int num){
    
    if(num<0) return false;
    if(num ==0) return true;
    
    int numDigits = 0;
    int sum = 0;
    int temp = num;
    int originalNum = num;


    //count the total number of digits
     
    while(temp>0){
        numDigits++;
        temp/=10;

    }

    // calculate the sum of digits raised to the power of numDigits

    temp = num;
    
    while(temp>0){
        int digit = temp%10;
        sum+=round(pow(digit,numDigits));
        temp/=10;
    }

    return sum == originalNum;


}

int main(){

    cout<<IsArmstrong(153);

    return 0;
}