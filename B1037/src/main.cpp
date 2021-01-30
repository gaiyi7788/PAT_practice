#include<iostream>
#include<cstdio>
using namespace std;
void cal(int *p,int *a,int *b){ //将两个数组传入，默认a[0] > b[0]
    if(a[2] < b[2]){ // a需要借位
        a[1]--;
        a[2]+=29;
    }
    p[2] = a[2]-b[2];
    if(a[1] < b[1]){
        a[0]--;
        a[1]+=17;
    }
    p[1] = a[1]-b[1];
    p[0] = a[0]-b[0];
}
int change(int *a){  //都换算成Knut
    int sum;
    sum = 17*29*a[0]+29*a[1]+a[2];
    return sum;
}
int main(){
    int P[3];
    int A[3];
    scanf("%d.%d.%d",&P[0],&P[1],&P[2]);
    scanf("%d.%d.%d",&A[0],&A[1],&A[2]);
    if(change(A)>=change(P)){ // 钱带的够
        int p[3];
        cal(p,A,P);
        cout << p[0] << "." << p[1] << "." << p[2];
    } 
    else{  //钱没带够
        int p[3];
        cal(p,P,A);
        cout << "-" << p[0] << "." << p[1] << "." << p[2];
    }
    return 0;
}
