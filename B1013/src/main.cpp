#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a[105000];
    a[0] = 2;
    int p = 1;
    for(int i = 3;i<105000;i+=2){
        bool flag = 0;
        for(int j = 3;j<=sqrt(i);j++){
            if(i%j == 0){
                flag = 1;
            }
        } 
        if(flag != 1){
            a[p] = i;
            flag = 0;
            p++;
        }
    }
    int M,N = 0;
    cin>>M;
    cin>>N;
    int num = 0;
    for(int i = M-1;i<N-1;i++){
        cout << a[i];
        num++;
        if(num == 10){
            cout << endl;
            num = 0;
        }
        else cout << " ";
    }
    cout << a[N-1];
}
