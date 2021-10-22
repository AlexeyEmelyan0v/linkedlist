#include <iostream>
#include "linkedlist.h"
using namespace std;
int main() {
    int t,cmnd,pos,ind,value;
    linkedlist<int> a;
    cout<<"Number of operations: ";
    cin>>t;
    cout<<"Enter 1 if you want check emptiness of linked list\n";
    cout<<"Enter 2 and then value and position where you want to insert\n";
    cout<<"Enter 3 and then position which you want to remove\n";
    cout<<"Enter 4 and then elements value which you want to remove\n";
    cout<<"Enter 5 and then element value which position you want to know\n";
    cout<<"Enter 6 and then position of element which you want to know\n"<<endl;
    for(int i=0;i<t;i++){
        cout<<"Enter the command: ";
        cin>>cmnd;
        if(cmnd==1){
            if(a.empty()){
                cout<<"Linked list is empty\n";
            }
        }
        if(cmnd==2){
            cin>>value>>pos;
            a.pospush(value,pos);
        }
        if(cmnd==3){
            cin>>pos;
            a.posdel(pos);
        }
        if(cmnd==4){
            cin>>value;
            a.valuedel(value);
        }
        if(cmnd==5){
            cin>>value;
            cout<<a.valuesearch(value);
        }
        if(cmnd==6){
            cin>>ind;
            cout<<a[ind-1];
        }
        cout<<endl;
        cout<<a<<endl<<endl;
    }
    return 0;
}
