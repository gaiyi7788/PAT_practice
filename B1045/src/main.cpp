#include<iostream>
#include<vector>
using namespace std;
/*****复杂度O(n^2)*********************************
int main(){
    //cout << "请输入序列元素个数:" << endl;
    int N = 0;
    cin >> N;
    int array[N];
    //cout << "请输入" << N << "个元素:" << endl;
    for(int i = 0;i < N;i++){
        cin >> array[i];
    }
    // for(int i = 0;i < N;i++){
    //     cout << array[i] << endl;
    // }
    vector<int> mp;
    for(int i = 0;i<N;i++){
        int point = array[i];
        bool flag = 0;
        for(int j = 0;j<i;j++){
            if(array[j] > point) flag = 1;
        }
        for(int j = i+1;j<N;j++){   
            if(array[j] < point) flag = 1;
        }
        if(flag == 0){
            mp.push_back(array[i]);
        }
    }
    cout << mp.size() <<endl;
    for(int i = 0;i < mp.size()-1;i++){
        cout << mp[i] << " ";
    }
    cout << mp[mp.size()-1];
    return 0;
}
**********************************************/
int main(){
    
}