#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a ,b;
    cin >> a >> b;
    int sum = a + b;
    if(sum < 0) {
        cout << '-';
        sum = -sum; //翻转
    } 
    int csum[10] = {0};
    int num = 0;
    //要把sum拆开放到一个数组中
    do{
        csum[num] = sum%10;
        sum /=10;
        num++;
    }while(sum != 0);
    //cout << num << endl;
    while(num > 0){
        cout << csum[num-1];
        if((num)%3 == 1 && num != 1){
            cout << "," ;
        }
        num--;
    }
}
