#include <stdio.h>
#include <iostream>

using namespace std;

struct patient 
{
   string name ; 
   bool status ;
};


int main(){
    int user_coiche = 0 ;
    patient specialization[20][5];

    while(true){
        cout<<"Enter your choice : \n";
        cout<<"1) Add new patient : \n";
        cout<<"2) Print all patients : \n";
        cout<<"3) Get Next patient : \n";
        cout<<"4) Exit \n";
        cin>>user_coiche ; 
        if(user_coiche == 1){
            //add new patient 
        }
        else if(user_coiche == 2){

        }
        else if(user_coiche == 3){

        }
        else if(user_coiche == 4){

        }
        else{
            cout<<"Please Enter number from 1 to 4 \n";
        }
    }
    return 0 ;
}