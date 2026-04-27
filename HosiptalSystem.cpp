#include <stdio.h>
#include <iostream>

using namespace std;

struct patient 
{
   string name ;
   // (0 = regular, 1 urgent) 
   bool statis ;
};

bool Add_Patient(patient specialization[20][5] ,int availaible_sets_in_specialization[20]  
                , int specialization_number  , string Name , bool statis ){
    specialization_number--;
    if(availaible_sets_in_specialization[specialization_number] < 5 ){
        if(statis == 0){
            for(int i {0} ; i < 5 ; i++){
                if(specialization[specialization_number][i].name == ""){
                    specialization[specialization_number][i] = {Name , statis};
                }
            }
        }
        else{
            //need to do shift by one 
            for(int i {4} ; i > 0 ; i--){
                specialization[specialization_number][i] = specialization[specialization_number][i-1];
                specialization[specialization_number][0] = {Name , statis}; 
            }
        }
        availaible_sets_in_specialization[specialization_number]++;
    } 
    return false ;  
}

int main(){
    int user_coiche = 0 ;
    //this array could be inilaized to Garbadge so 
    patient specialization_arr[20][5];
    int availaible_sets_in_specialization[20] = {0};
    for(int i {0} ; i < 20 ; i++){
        for(int j {0} ; j < 5 ; j++){
            specialization_arr[i][j] = {"" , 0};
        }
    }

    while(true){
        cout<<"Enter your choice : \n";
        cout<<"1) Add new patient : \n";
        cout<<"2) Print all patients : \n";
        cout<<"3) Get Next patient : \n";
        cout<<"4) Exit \n";
        cin>>user_coiche ; 
        if(user_coiche == 1){
            int specialization_num {0};
            string Name {""};
            bool statis {false};
            cout<<"Enter specialization,name,statis: ";
            cin>>specialization_num ;
            cin>>Name;
            cin>>statis;
            bool is_added = Add_Patient(specialization_arr , specialization_num ,Name , statis );
            if(is_added){
                cout<<"the patient is added succesfully \n";
            }
            else{
                cout<<"Sorry , we cannot add more patients \n";
            }
        }
        else if(user_coiche == 2){

        }
        else if(user_coiche == 3){

        }
        else if(user_coiche == 4){
            cout<<"Thank you for using system \n";
            break;
        }
        else{
            cout<<"Please Enter number from 1 to 4 \n";
        }
    }
    return 0 ;
}