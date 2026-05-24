#include <stdio.h>
#include <iostream>

using namespace std;

struct patient
{
    string name;
    int state;
    patient()
    {
        name = "";
        state = -1;
    }
    patient(string _name, int _state)
    {
        name = _name;
        state = _state;
    }
};

struct hospital_queue
{
    patient arr[5];
    int len;
    int spec;
    hospital_queue()
    {
        len = 0;
        spec = -1;
    }

    hospital_queue(int _spec)
    {
        len = 0;
        spec = _spec;
    }
    bool add_end(patient p)
    {
        if (len < 5)
        {
            arr[len++] = p;
            return true;
        }
        return false;
    }

    bool add_front(patient p)
    {
        if (len < 5)
        {
            // global shift right
            for (int i{len}; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = p;
            len++;
            return true;
        }
        return false;
    }

    void add_patient(patient p)
    {
        if (p.state == 0)
        {
            if (add_end(p))
            {
                cout << "patient " << p.name << " is been added !\n";
            }
            else
            {
                cout << "the queue is fall try again latter!\n";
            }
        }
        else if (p.state == 1)
        {
            if (add_front(p))
            {
                cout << "patient " << p.name << " is been added !\n";
            }
            else
            {
                cout << "the queue is fall try again latter!\n";
            }
        }
    }

    void get_patient()
    {
        patient p = remove_front();
        if (p.name != "" && p.state != -1)
        {
            cout << p.name << " please go to the docotor \n";
        }
        else
        {
            cout << "there is no patient wating \n";
        }
        return;
    }

    patient remove_front()
    {
        patient first_p{};
        if (len > 0)
        {
            first_p = arr[0];
            // global shift left
            for (int i{0}; i < len - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            len--;
        }
        return first_p;
    }
    void print_wating_patients()
    {
        for (int i{0}; i < len; i++)
        {
            cout << arr[i].name << " ";
        }
        cout << "\n";
    }
};

struct Hospital_System
{
    // 100 maximum number of specalizations
    hospital_queue queues[100];
    int number_of_spec;
    Hospital_System()
    {
        number_of_spec = 0;
    }
    Hospital_System(int _number_of_spec)
    {
        number_of_spec = _number_of_spec;
        if (_number_of_spec > 100)
        {
            cout << "this is more than allowed limit for specalaizations \n";
        }
        else
        {
            for (int i{0}; i < number_of_spec; i++)
            {
                queues[i].spec = i;
            }
        }
    }

    void add_patient_to_spec(patient p, int spec)
    {
        queues[spec].add_patient(p);
    }
    void get_Next_patient_from_spec(int spec)
    {
        queues[spec].get_patient();
    }
    void print_spec_queue(int spec)
    {
        queues[spec].print_wating_patients();
    }

    void print_all_waiting_patients()
    {
        for (int spec = 0; spec < number_of_spec; ++spec)
        {
            if (queues[spec].len > 0)
            {
                cout << "Specialization " << (spec + 1) << ": ";
                queues[spec].print_wating_patients();
            }
        }
    }

    void menu()
    {
        int choice{};
        while (true)
        {
            cout << "Enter your choice : \n";
            cout << "1) Add new patient : \n";
            cout << "2) Print all patients : \n";
            cout << "3) Get Next patient : \n";
            cout << "4) Exit \n";
            cin >> choice;
            if (choice == 1)
            {
                int specialization_num{0};
                string Name{""};
                int statis{-1};
                cout << "Enter specialization,name,statis: ";
                cin >> specialization_num;
                cin >> Name;
                cin >> statis;
                patient p = patient(Name, statis);
                specialization_num--;
                add_patient_to_spec(p, specialization_num);
            }
            else if (choice == 2)
            {
                print_all_waiting_patients();
            }
            else if (choice == 3)
            {
                int specialization_num{0};
                cout << "Enter specialization number that you want to list: \n";
                cin >> specialization_num;
                specialization_num--;
                get_Next_patient_from_spec(specialization_num);
            }
            else if(choice == 4){
                break;
            }
            else{
                cout<<"Please enter a valid choice pick number from 1 to 4\n";
            }
        }
    }
};

int main(){
    Hospital_System hos = Hospital_System(20);
    hos.menu();
}