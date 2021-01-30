#include<iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int dis[N+1];
    dis[0] = 0;
    int m;
    int sum = 0;
    for(int i =0;i<N;i++){
        cin >> m;
        sum+=m; //每两个点之间的距离
        dis[i+1] = sum; //第一个点顺时针方向到各个点的距离
    }
    cin >> N;
    int save[N];
    int a,b;
    for(int i = 0;i<N;i++){
        cin >> a;
        cin >> b;
        if(a>b) swap(a,b);
        int temp = dis[b-1]-dis[a-1];
        save[i] = min(temp,sum-temp);
    }
    for(int i = 0;i<N;i++){
        cout << save[i] << endl;
    }
    return 0;
}
