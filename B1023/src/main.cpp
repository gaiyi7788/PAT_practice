#include<iostream>
#include<algorithm>
#include<vector>
// #include<ctime>
using namespace std;
// clock_t start,end;
int main(){
    //int put[10] = {1,1,2,2,3,5,6,6,8,9};
    // start = clock();
    int put[10] = {0,0,1,1,3,5,6,6,8,9};
    vector<int> vec(put,put+10);
    sort(vec.begin(),vec.end());//先进行排序
    for(int i = 0;;i++){
        if(vec[i] != 0){  //找到除了0之外最大的
            cout << vec[i];
            vec.erase(vec.begin()+i); //这个方法可以删去vector中指定的元素
            break;
        }
    }
    for(int i = 0;i < vec.size();i++){
        cout << vec[i];
    }
    // end = clock();
    // double endtime = (double)(end-start)/CLOCKS_PER_SEC;
    // cout << endtime << endl;
    return 0;    
}