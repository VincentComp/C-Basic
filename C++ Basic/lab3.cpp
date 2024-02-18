#include <iostream>
#include <fstream>

using namespace std;

// Do not change this function. It is used for checking the lab.
void prepare_files(){
    ofstream ofs ("student_list.txt");

    if (ofs){
        ofs << 20185639 << endl;
        ofs << 22435497 << endl;
        ofs << 23143658 << endl;
        ofs << 29372413 << endl;
        ofs << 29567638 << endl;
        ofs << 29576389 << endl;
    }
}


// Do not change this function. It is used for checking the lab.
void check_final_list(){
    ifstream ifs ("student_list.txt");
    if (ifs){
        int line;
        while (ifs >> line){
            cout << line << endl;
        }
        ifs.close();
    }
}


// TODO: search for a student in the input file, student_list.txt, return true if found.
bool student_lookup(int student_id){
    int input_id;
    ifstream ifs("student_list.txt");
    
    while(!ifs.eof())
    {
        if(ifs>> input_id)
        {

            if(input_id == student_id)
            {
                return true;
            }
            
        }
    } return false;
    
    ifs.close();

}


// TODO: delete a student id from the input file.
// The result should not contain blank lines
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void delete_student(int student_id){
    rename("student_list.txt","temp.txt");
    ifstream ifs("temp.txt");
    ofstream ofs("student_list.txt");

    int input_id;        
    bool exist = false;

    while(!ifs.eof())
    {
        if(ifs >> input_id)
        {

            if(input_id != student_id)
            {
            ofs << input_id <<"\n";
            
            }else{
                cout << "Student " << student_id << " is removed from the course!" << endl;
                exist = true;
            }
        }
    }
    if(!exist){
    cout << "Student " << student_id << " is not taking the course!" << endl;
    }

    ifs.close();
    ofs.close();
    remove("temp.txt");
}


// TODO: insert a student in the input file such that the student ids are in ascending order
// It should not insert duplicate student id.
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void insert_student(int student_id){
    
    rename("student_list.txt","temp.txt");
    ifstream ifs("temp.txt");
    ofstream ofs("student_list.txt");

    int input_id;        
    bool exist = false;
    bool insert = false;

    while(!ifs.eof())
    {
        if(ifs >> input_id)
        {

            if(input_id != student_id)
            {   if((student_id < input_id) && (insert == false))
                {
                    ofs << student_id<<"\n";
                    insert = true;
                }
            ofs << input_id <<"\n";
            
            }else{
                ofs << input_id <<"\n";
                cout << "Student " << student_id << " is already taking the course!" << endl;
                insert = true;
                exist = true;
            }
        }
    }
    if(!exist){
    cout << "Student " << student_id << " is inserted successfully!" << endl;
    }

    ifs.close();
    ofs.close();
    remove("temp.txt");
    
}

int main(){

    const char filename[] = "student_list.txt";
    char choice;
    int student_id;

    prepare_files();

    while (true){       

        cout << "1 for lookup; 2 for insertion; 3 for deletion; q for quit: ";
        cin >> choice;

        if (choice == '1'){
            cout << "Please enter the id of the student you want to search for: ";
            cin >> student_id;
            if (student_lookup(student_id)){
                cout << "Student " << student_id << " is found!" << endl;
            }else{
                cout << "Student " << student_id << " is not found!" << endl;
            }
        }else if (choice == '2'){
            cout << "Please enter the id of the student you want to insert: ";
            cin >> student_id;
            insert_student( student_id);
        }else if (choice == '3'){
            cout << "Please enter the id of the student you want to delete: ";
            cin >> student_id;
            delete_student(student_id);
        }else if (choice == 'q'){
            check_final_list();
            break;
        }else{
            cout << "Invalid input. Please input again." << endl;
        }
        cout << endl;
    }

    return 0;
}