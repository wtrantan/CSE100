#include <iostream>
#include <list>
using namespace std;


void insert(list<int>hash[], int num, int size){
    int mod;
    mod = num % size;
    if(size != 0){
        hash[mod].push_front(num);
    }
}


void search(list<int>hash[], int num, int size){
    int mod = num % size;
    int k = 0;
    bool found = false;
    list<int> :: iterator i;
    for(i = hash[mod].begin(); i != hash[mod].end(); i++){
        if(*i == num){
            cout<<num<<":FOUND_AT"<<mod<<","<< k<<";"<<endl;
            found = true;
        }
        k++;
    }
    if(!found){
        cout << num <<":NOT_FOUND;"<<endl;
    }
}



void deleteHash(list<int>hash[], int num, int size){
    int mod = num % size;
    int k = 0;
    bool found = false;
    list<int> :: iterator i;
    for(i = hash[mod].begin(); i != hash[mod].end(); i++){
        if(*i == num){
            hash[k].erase(i);
            cout << num << ":DELETED;" << endl;
            found = true;
            break;
        }
        k++;
    }
    if(!found){
        cout << num <<":DELETE_FAILED;"<< endl;
    }
}


void print(list<int>hash[], int size){
    for(int i = 0; i < size; i++){
        list<int> :: iterator it;
        cout << i << ":";
        for(it = hash[i].begin(); it != hash[i].end(); it++){
            cout << *it << "->";
        }
        cout << ";" << endl;
    }
}

int main(int argc, const char* argv[]){
    int size;
    char func;
    int num;
    cin >> size;
    list<int>hash[size];
    while(func != 'e'){
        cin >> func;
        if (func == 'i'){
            cin >> num;
            insert(hash, num, size);
        }
        if (func == 's'){
            cin >> num;
            search(hash, num, size);
        }
        if (func == 'o'){
            print(hash, size);
        }
        if (func == 'd'){
            cin >> num;
            deleteHash(hash, num, size);
        }
    }
    return 0;
}