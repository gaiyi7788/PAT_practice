#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int K1,K2 = 0;
    float data[1000] = {0};
    float result[2001] = {0};
    cin >> K1;
    int n = 0;
    float c = 0;
    for(int i = 0;i < K1;i++){
        cin >> n >> c;
        data[n] = c;
    }
    cin >> K2;
    float temp = 0;
    for(int i = 0;i < K2;i++){
        cin >> n >> c;
        for(int j = 0;j < 1000;j++){
            temp = data[j]*c;
            result[n+j] += temp;
        }
    }
    int num = 0;
    for(int i = 0;i <2001;i++){
        if(result[i] != 0) num++;
    }
    cout << num << " ";
    for(int i = 2000;i>=0;i--){
        if(result[i] != 0){
            printf("%d %0.1f",i,result[i]);
            if(i != 0) cout << " "; 
        }
    }
    return 0;
}
