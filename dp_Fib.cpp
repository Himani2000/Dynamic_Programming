#include<iostream>
using namespace std;

int memo[1000];

int fibonacci(int n){
    if (n<=1) return n;
    if (memo[n]!=-1){
        return memo[n];
    }
    int fn= fibonacci(n-1)+fibonacci(n-2);
    memo[n]=fn;
    return fn;
}

int main(){
    for (int i=0;i<1000;i++) memo[i]=-1;
    cout<<fibonacci(43);
}
