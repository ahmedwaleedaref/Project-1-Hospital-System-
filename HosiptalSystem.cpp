#include <stdio.h>
#include <iostream>

using namespace std;

struct patient
{
    string name;
    // (0 = regular, 1 urgent)
    bool statis;
};

bool Add_Patient(patient specialization[20][5], int availaible_sets_in_specialization[20], int specialization_number, string Name, bool statis)
{
    if (availaible_sets_in_specialization[specialization_number] < 5)
    {
        if (statis == 0)
        {
            /*
            for (int i{0}; i < 5; i++)
            {
                if (specialization[specialization_number][i].name == "")
                {
                    specialization[specialization_number][i] = {Name, statis};
                }
            }
            */
            specialization[specialization_number][availaible_sets_in_specialization[specialization_number]] = {Name, statis};
        }
        else
        {
            // need to do shift by one
            for (int i{4}; i > 0; i--)
            {
                // do a shift only if not urgent
                if (specialization[specialization_number][i - 1].statis == 0)
                {
                    specialization[specialization_number][i] = specialization[specialization_number][i - 1];
                    // no urgent patients first urgent one
                    if (i == 1)
                    {
                        specialization[specialization_number][0] = {Name, statis};
                    }
                }
                else
                {
                    specialization[specialization_number][i] = {Name, statis};
                    break;
                }
            }
        }
        availaible_sets_in_specialization[specialization_number]++;
        return true;
    }
    return false;
}

void Print_patients_in_specializtion(patient specialization[20][5], int availaible_sets_in_specialization[20],
                                     int specialization_number)

{
    for (int i = 0; i < availaible_sets_in_specialization[specialization_number]; i++)
    {
        if (specialization[specialization_number][i].name != "")
        {
            cout << specialization[specialization_number][i].name << " ";
        }
        else
        {
            break;
        }
    }
    cout << "\n";
}

void get_next_Patient(patient specialization[20][5], int availaible_sets_in_specialization[20], int specialization_number)
{
    if (availaible_sets_in_specialization[specialization_number] == 0)
    {
        cout << "Doctor, there are no patients.\n";
    }
    else
    {
        cout << specialization[specialization_number][0].name << " please go with the doctor\n";

        int current_count = availaible_sets_in_specialization[specialization_number];
        for (int i = 0; i < current_count - 1; i++)
        {
            specialization[specialization_number][i] = specialization[specialization_number][i + 1];
        }

        availaible_sets_in_specialization[specialization_number]--;

        // 5. Clean up the "old" last position so it doesn't look like an urgent patient
        int new_count = availaible_sets_in_specialization[specialization_number];
        specialization[specialization_number][new_count] = {"", 0};
    }
}

int main()
{
    int user_coiche = 0;
    // this array could be inilaized to Garbadge so
    patient specialization_arr[20][5];
    int availaible_sets_in_specialization[20] = {0};
    for (int i{0}; i < 20; i++)
    {
        for (int j{0}; j < 5; j++)
        {
            specialization_arr[i][j] = {"", 0};
        }
    }

    while (true)
    {
        cout << "Enter your choice : \n";
        cout << "1) Add new patient : \n";
        cout << "2) Print all patients : \n";
        cout << "3) Get Next patient : \n";
        cout << "4) Exit \n";
        cin >> user_coiche;
        if (user_coiche == 1)
        {
            int specialization_num{0};
            string Name{""};
            bool statis{false};
            cout << "Enter specialization,name,statis: ";
            cin >> specialization_num;
            cin >> Name;
            cin >> statis;
            specialization_num--;
            bool is_added = Add_Patient(specialization_arr, availaible_sets_in_specialization, specialization_num, Name, statis);
            if (is_added)
            {
                cout << "the patient is added succesfully \n";
            }
            else
            {
                cout << "Sorry , we cannot add more patients \n";
            }
        }
        else if (user_coiche == 2)
        {
            int specialization_num{0};
            cout << "Enter specialization number that you want to list: \n";
            cin >> specialization_num;
            specialization_num--;
            Print_patients_in_specializtion(specialization_arr, availaible_sets_in_specialization, specialization_num);
        }
        else if (user_coiche == 3)
        {
            int specialization_num{0};
            cout << "Enter specialization that you want to get patient from : \n";
            cin >> specialization_num;
            specialization_num--;
            get_next_Patient(specialization_arr, availaible_sets_in_specialization, specialization_num);   
        }
        else if (user_coiche == 4)
        {
            cout << "Thank you for using system \n";
            break;
        }
        else
        {
            cout << "Please Enter number from 1 to 4 \n";
        }
    }
    return 0;
}