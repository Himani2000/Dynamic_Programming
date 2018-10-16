#include<iostream>
using namespace std;

int memo[100][100];

int MaxProfit(int arr[], int be, int en, int yr){
    if (be>en) return 0;
    if (memo[be][en]!=-1) return memo[be][en];
    int cProfit;
    if (be==en){
        cProfit=arr[be]*yr;
    } else {
        ///selling left one
        int lProfit=arr[be]*yr+MaxProfit(arr,be+1,en,yr+1);
        ///selling right one
        int rProfit=arr[en]*yr+MaxProfit(arr,be,en-1,yr+1);
        cProfit=max(lProfit,rProfit);

    }
    memo[be][en]=cProfit;
    return cProfit;
}


int main(){
    for (int i=0;i<100;i++){
        for (int j=0;j<100;j++){
            memo[i][j]=-1;
        }
    }
    int arr[]={2,3,5,1,4};
    int n=5;
    cout<<MaxProfit(arr,0,n-1,1);
}
