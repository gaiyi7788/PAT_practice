#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string nota;
    cin >> nota;
    int E = 0;
    int len = nota.length();
    for(int i = 3;;i++){
        if(nota[i] == 'E'){
            E = i;
            break;
        } 
    }
    string expstr = nota.substr(E+2);
    int exp = atoi(expstr.c_str());
    if(nota[E+1] == '+'){
        
    }
    cout  << exp << endl;
    return 0;
}
