/**
 * 要构建足够大小的结构体数组，往里填数，因为存储空间大小往往是够的
**/
#include<iostream>
#include<string>
using namespace std;
struct Student{
    string ID; //考生准考证号
    //int Test;  //试机座位号
    int Real;  //考试座位号
    //构造函数
    //Student(string _ID,int _Test,int _Real):ID(_ID),Test(_Test),Real(_Real){};
};
int main(){
    int N;
    cin >> N;
    Student stu[1001];
    string id;
    int t,r = 0;
    for(int i = 0;i<N;i++){ //用结构体数组下标作为试机号，可以快速查找
        cin >> id >> t >> r;
        stu[t].ID = id;
        stu[t].Real = r; 
    }
    int search = 0;
    cin >> search;
    for(int i = 0;i<search;i++){
        cin >> t;
        cout << stu[t].ID << " " << stu[t].Real << endl;
    }
    return 0;
}
