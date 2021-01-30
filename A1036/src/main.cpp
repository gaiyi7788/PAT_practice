#include<iostream>
#include<string>
//#include<cmath>
using namespace std;

struct Student{
    string name;
    //char gender;
    string ID;
    int grade;
};

int main(){
    int N;
    Student stuM[1000];
    Student stuF[1000];
    for(int i = 0;i < 1000;i++){
        stuM[i].grade = -1;
        stuF[i].grade = -1;
    }
    cin >> N;
    int j1 = 0;
    int j2 = 0;
    for(int i = 0;i < N;i++){
        string n,id;
        char ge;
        int gr;
        cin >> n >> ge >> id >> gr;
        if(ge == 'M'){
            stuM[j1].name = n;
            stuM[j1].ID = id;
            stuM[j1].grade = gr;
            j1++;
        }
        else{
            stuF[j2].name = n;
            stuF[j2].ID = id;
            stuF[j2].grade = gr;
            j2++;
        }
    }
    int gradeM = -1;
    int gradeF = -1;
    Student *p;
    p = stuF;
    if(p->grade != -1){ //结构体数组非空
        p = stuF;
        p++;
        Student temp = stuF[0];
        while(p->grade != -1){
            if(p->grade < temp.grade){
                temp = *p;
            }
            p++;
        }
        cout << temp.name << " " << temp.ID << endl;
        gradeF = temp.grade;
    }
    else{
        cout << "Absent" << endl;
    }
        p = stuM;
    if(p->grade != -1){ //结构体数组非空        
        p++;
        Student temp = stuM[0];
        while(p->grade != -1){
            if(p->grade < temp.grade){
                temp = *p;
            }
            p++;
        }
        cout << temp.name << " " << temp.ID << endl;
        gradeM = temp.grade;
    }
    else{
        cout << "Absent" << endl;
    }
    if((gradeF == -1) || (gradeM == -1)){
        cout << "NA";
    }
    else cout << (gradeF-gradeM);
    return 0;
}
