#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
struct Student
{
    string ID;
    string name;
    int num;
    int score;
    int all_rank;
    int rank;
    //构造函数
    Student(string _ID,string _name,int _num,int _score):ID(_ID),name(_name),num(_num),score(_score){}
};
//sort函数调用的比较函数
//cmp函数的含义，如果返回值是 True，表示 要把 序列 (X,Y)，X放Y前。
bool cmp(Student a,Student b){
    if(a.score != b.score) return a.score>b.score;
    else return a.ID < b.ID;
}

int main(){
    //初始化结构体数组
    Student stu[5] = {Student("000001","yyt",1,100),Student("000002","cpy",1,0),Student("000003","mwj",1,99),Student("000004","lwm",2,110),Student("000005","lyb",2,130)};
    int cate[5];
    //将所有人的考场号提取出来
    for(int i = 0;i<5;i++){
        cate[i] = stu[i].num;
    }
    //构建set集合对考场号存放数组去重，得到全部的考场号
    set<int> st(cate,cate+5);//(待处理数据结构的起始地址，结束地址的下一个地址)
    vector<int> cate_vec;
    //set集合只能通过迭代器迭代访问,因此将set集合处理好的数据提取出来放在vector中
    for(set<int>::iterator it = st.begin();it != st.end();it++){
        cate_vec.push_back(*it);
    }
    // for(int i = 0;i<cate_vec.size();i++){
    //     cout << cate_vec[i]<<endl;
    // }
    //练习用vector建立二维数组，下面的方式可以统计出每个考场的总人数，保存成cate_mat矩阵
    // vector< vector<int> > cate_mat(cate_vec.size()); 
    // for (int i = 0; i < cate_mat.size(); i++)
    //     cate_mat[i].resize(2);
    // for(int i = 0;i<cate_mat.size();i++){
    //     cate_mat[i][0] = cate_vec[i];
    // }
    // for(int i = 0;i<5;i++){
    //     for(int j = 0;j<cate_mat.size();j++){
    //         if(stu[i].num == cate_mat[j][0]) cate_mat[j][1]++;
    //     }
    // }
    sort(stu,stu+5,cmp); //sort函数实现对结构体数组的排序
    for(int i = 0;i<5;i++){ //总排名输出
        stu[i].all_rank = i+1;
        cout << stu[i].name<<":"<<stu[i].all_rank<< endl;
    }
    int rank = 1;
    //因为结构体数组已经有序，所以可以直接通过标签，进行分类输出
    for(int i = 0;i<cate_vec.size();i++){
        cout << "考场" << cate_vec[i] << ":" <<endl;
        for(int j = 0;j<5;j++){
            if(stu[j].num == cate_vec[i]){
                cout << stu[j].name<<":"<<rank<< endl;
                rank++;
            }
        }
        rank = 1;
    }
    return 0;
}