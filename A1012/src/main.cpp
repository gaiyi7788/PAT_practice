#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Student{
    int ID; //考生号
    int grade[4];//按优先级分别表示A、C、M、E
};
char course[4] = {'A','C','M','E'};
int Rank[1000000][4] = {0}; //直接用ID号作为存放下标
int now; //这是用全局变量作为cmp比较的下标，其实是一种很垃圾的写法。
bool cmp(Student a,Student b){
    return a.grade[now] > b.grade[now];
}
int main(){
    int N,M;
    Student stu[2000];
    cin >> N >> M; 
    //scanf("%d%d",&N,&M);
    for(int i = 0; i < N;i++){
        cin >> stu[i].ID >> stu[i].grade[0] >> stu[i].grade[1] >> stu[i].grade[2];
        //需要取整
        stu[i].grade[3] = round((stu[i].grade[0]+stu[i].grade[0]+stu[i].grade[0])/3.0)+0.5; 
    }
    for(now = 0;now < 4;now++){
        sort(stu,stu+N,cmp); //对now下标进行排序
        Rank[stu[0].ID][now] = 1; //将分数最高的设为Rank1
        for(int i = 1; i < N;i++){
            if(stu[i].grade == stu[i-1].grade){ //和前一个人分数一样
                Rank[stu[i].ID][now] = Rank[stu[i-1].ID][now];
            }else Rank[stu[i].ID][now] = i+1; //不能有第0名
        }
    }
    int search; //保存查询ID的临时变量
    for(int i = 0;i < M ;i++){
        cin >> search;
        if(Rank[search][0] == 0){ //说明之前未进行过排序，该查询并不存在
            cout << "N/A" << endl;
        }
        else{ //查询有效
            int k = 0;
            for(int j = 0;j < 4;j++){
                if(Rank[search][j] < Rank[search][k]){
                    k = j;
                }
            }
            cout << Rank[search][k] <<" " << course[k] << endl;
        }
    }
    return 0;
}
