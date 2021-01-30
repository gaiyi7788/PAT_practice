#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int first = 0;
    int N = 0;
    cin >> first;
    cin >> N;
    int data[N+1];
    for(int i = 0;i<N+1;i++){
        data[i] = 0;
    }
    data[N] = first;
    int c = 0;
    int n = 0;
    while(scanf("%d%d",&c,&n) != EOF){
        data[n] = c;
    }
    if(N != 0){
        for(int i = 0;i<N;i++){
            data[i] = data[i+1]*(i+1);
        }
        data[N] = 0;
        for(int i = N-1;i>=0;i--){
            if(data[i] != 0){
                cout << data[i] << " " << i;
                if(i != 0) cout << " ";
            }
        }
    }
    else cout << "0 0";
    return 0;
}
