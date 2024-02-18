#include <iostream>
#include <fstream>

using namespace std;


//=================Part I======================
/*
Create a .txt containing all student ID
*/

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

//=================Part II======================
/*
When intput == q, print all the line in the .txt
*/
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

//=================Part III======================
// TODO: search for a student in the input file, student_list.txt, return true if found.
bool student_lookup(int student_id){
    int input_id; 
    ifstream ifs("student_list.txt");
    
    while(!ifs.eof()) //check every line in text
    {
        if(ifs>> input_id) //if have input(line)
        {

            if(input_id == student_id)// if input from file = human input
            {
                return true;    //a)true --> found
            }
            
        }
    } return false; //b)otherwise, false
    
    ifs.close();

}

//=================Part IV======================
// TODO: delete a student id from the input file.
// The result should not contain blank lines
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.

void delete_student(int student_id){
    rename("student_list.txt","temp.txt"); //orignal file --> temp. file
    ifstream ifs("temp.txt");              //input: temp 
    ofstream ofs("student_list.txt");      //outout: new_list(same name)

    int input_id;        
    bool exist = false;

    while(!ifs.eof())                       //check every lines of the txt
    {
        if(ifs >> input_id)                 //if have input
        {

            if(input_id != student_id)     //if human input not yet exist in file 
            {
            ofs << input_id <<"\n";        //a)copy the human data from "temp.file" to "new_list"
            
            }else{
                cout << "Student " << student_id << " is removed from the course!" << endl;
                exist = true;               //b)otherwise, skip the copying + indicate a removal is done 
            }
        }
    }
    if(!exist){                             //if removal didn't carry out --> output msg
    cout << "Student " << student_id << " is not taking the course!" << endl;
    }

    ifs.close();
    ofs.close();
    remove("temp.txt");                     //del the old temp.file
}


// TODO: insert a student in the input file such that the student ids are in ascending order
// It should not insert duplicate student id.
// Please check the section "Hint" in the lab page for how to rename a file or remove a file.
void insert_student(int student_id){
    
    rename("student_list.txt","temp.txt");//orignal file --> temp. file
    ifstream ifs("temp.txt");             //input: temp 
    ofstream ofs("student_list.txt");     //outout: new_list(same name)

    int input_id;        
    bool exist = false;
    bool insert = false;

    while(!ifs.eof())                     //check every lines of the txt
    {
        if(ifs >> input_id)               //if have input
        {

            if(input_id != student_id)    //if human input not yet exist in file
            {   if((student_id < input_id) && (insert == false)) //a)for ascending other + prevent duplication of the human_input
                {
                    ofs << student_id<<"\n";                     //copy the human input to new list
                    insert = true;                               //indicate copy is done
                }
            ofs << input_id <<"\n";       //copy the line from input to output everytime
            
            }else{
                ofs << input_id <<"\n";   //if human_input already exist
                cout << "Student " << student_id << " is already taking the course!" << endl;
                insert = true;            //also indicate copy is done
                exist = true;             //indicate a duplication is exist
            }
        }
    }
    if(!exist){                          //if no duplication --> success
    cout << "Student " << student_id << " is inserted successfully!" << endl;
    }

    ifs.close();
    ofs.close();
    remove("temp.txt");                  //del. old file
    
}

int main(){

    const char filename[] = "student_list.txt";
    char choice;
    int student_id;

    prepare_files(); //#1see above

    while (true){       

        cout << "1 for lookup; 2 for insertion; 3 for deletion; q for quit: ";
        cin >> choice; 

        if (choice == '1'){
            cout << "Please enter the id of the student you want to search for: ";
            cin >> student_id;
            if (student_lookup(student_id)){  //#2see above
                cout << "Student " << student_id << " is found!" << endl;
            }else{
                cout << "Student " << student_id << " is not found!" << endl;
            }
        }else if (choice == '2'){ //#3see above
            cout << "Please enter the id of the student you want to insert: ";
            cin >> student_id;
            insert_student( student_id);
        }else if (choice == '3'){ //#4 see above
            cout << "Please enter the id of the student you want to delete: ";
            cin >> student_id;
            delete_student(student_id);
        }else if (choice == 'q'){ //#5see aboce
            check_final_list();
            break;
        }else{
            cout << "Invalid input. Please input again." << endl;
        }
        cout << endl;
    }

    return 0;
}