#include<iostream>
#include<string>
using namespace std;
struct Person{
    string ID;
    string u_t; //unlock time
    string l_t; // lock time
    //改成用三个int分别存放 时：分：秒 比较好
};
int unlock_time_compare(Person *p,int i,int j){
    string a = (p+i)->u_t;
    string b = (p+j)->u_t;
    if(a > b) return j;
    else return i;
}
int lock_time_compare(Person *p,int i,int j){
    string a = (p+i)->l_t;
    string b = (p+j)->l_t;
    if(a > b) return i;
    else return j;
}
int main(){
    Person p[1000];
    int N;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> p[i].ID >> p[i].l_t >> p[i].u_t;
    }
    int u_temp = 0;
    int l_temp = 0;
    for(int i = 1;i < N;i++){
        u_temp = unlock_time_compare(p,i,u_temp);
        l_temp = lock_time_compare(p,i,u_temp);
    }
    cout << p[u_temp].ID << " " << p[l_temp].ID;
    return 0;
}
