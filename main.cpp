#include <iostream>
#include "linkedlist.h"
#include <cassert>
using namespace std;
int main() {
    int cmnd, pos, ind, value;
    linkedlist<int> a;
    cout << "Enter 999 if you want to end\n";
    cout << "Enter 1 if you want check emptiness of linked list\n";
    cout << "Enter 2 and then value and position where you want to insert\n";
    cout << "Enter 3 and then position which you want to remove\n";
    cout << "Enter 4 and then elements value which you want to remove\n";
    cout << "Enter 5 and then element value which position you want to know\n";
    cout << "Enter 6 and then position of element which you want to know\n";
    cout << "Enter 7 and value if you want to insert to the beginning of the linked list\n";
    cout << "Enter 8 and value if you want to insert to the end of the linked list\n";
    cout << "Enter 9 if you want to remove an element from the beginning\n";
    cout << "Enter 10 if you want to remove an element from the end\n";
    while(cmnd!=999) {
        cout << "Enter the command: ";
        cin >> cmnd;
        if (cmnd == 1) {
            if (a.empty()) {
                cout << "Linked list is empty\n";
            }
        }
        if (cmnd == 2) {
            cin >> value >> pos;
            try{
                a.pospush(value, pos);
            }
            catch(const char *msg){
                cerr<<msg<<endl;
            }
        }
        if (cmnd == 3) {
            cin >> pos;
            a.posdel(pos);
        }
        if (cmnd == 4) {
            cin >> value;
            a.valuedel(value);
        }
        if (cmnd == 5) {
            cin >> value;
            int ans=a.valuesearch(value);
            if(ans==-1){
                cout<<"There are no elements that are equel to "<<value;
            }else{
                cout<<ans;
            }
        }
        if (cmnd == 6) {
            cin >> ind;
            try {
                cout << a[ind - 1];
            }
            catch(const char* msg){
                cerr<<msg<<endl;
            }
        }
        if (cmnd == 7){
            cin>>value;
            a.begpush(value);
        }
        if(cmnd == 8){
            cin>>value;
            a.endpush(value);
        }
        if(cmnd == 9){
            a.begdel();
        }
        if(cmnd == 10){
            a.enddel();
        }
        cout << endl;
        cout << a << endl << endl;
    }
    return 0;
}
