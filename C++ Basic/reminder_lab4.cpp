#include <iostream>
using namespace std;

// Maximum capacity of the queue system
const int MAX_QUEUE_LENGTH = 5;   //Set the max array size


//=============Part I==============
/*
initialize all element in the array = 0
*/

void initialize_queue_system(int queue[]){
    /* TASK 1 - implement function initialize_queue_system
        (1). Initialize the input queue system with all 0s inside
    */
    // Please write your code below


    
    for(int i = 0; i < MAX_QUEUE_LENGTH; i++)
    {
        queue[i] = 0;
    }


    // Your code ends here
}


//=========Part II===========
/*
when element is zero, add a ticket
ticket no.++
otherwise, return false signal
*/
bool take_a_queue_ticket(int queue[], int& next_ticket_number){
    /* TASK 2 - implement function take_a_queue_ticket
        (1). add the taken ticket to the input queue
        (2). you may need to maintain variable next_ticket_number for your usage
        (3). return true if the ticket number is sucessfully added, return false if the queue is already full
    */
    // Please write your code below
    
    for(int i = 0; i < MAX_QUEUE_LENGTH; i++)
    {
        if(queue[i] == 0)
        {
            queue[i] = next_ticket_number;
            next_ticket_number ++;
            return true;
        }
    }return false;
    
    // Your code ends here
}


//=========Part III===========
/*
default return = false
if element = 0
break

if element not zero--> array[i] = array[i+1]
if element = last element --> set last element = 0 
then return true
*/
bool serve_the_first_come_customer(int queue[]){
    /* TASK 3 - implement function serve_the_first_come_customer
        (1). remove the first-come ticket from the input queue
        (2). after removing, you may need to maintain the queue to a correct format for possible terminal printing
        (3). return true if the ticket number is sucessfully removed, return false if the queue is already empty
    */
    // Please write your code below
    

    bool result = false;

    for(int i = 0; i < MAX_QUEUE_LENGTH; i++)
    {
        if((queue[i] == 0))
        {
            break;
        } 
        
        else{  
            if (i !=MAX_QUEUE_LENGTH-1)
                {queue[i] = queue[i+1];}
            
            else
                {queue[i]=0;}
            }
            result = true;

    }
    return result;
    // Your code ends here
}


// Given: Print the current queue info to terminal
void show_current_queue(const int queue[]){             //print all element
    cout << "<-- [ ";
    for (int i = 0; i < MAX_QUEUE_LENGTH; ++i){
        cout << queue[i] << " ";
    }
    cout << "] <--" << endl;
}


int main()
{
    // A dummy queue for starting
    int queue[MAX_QUEUE_LENGTH];   //create an empty array

    // The starting ticket number, it should start at 1 and keep increse if people take more and more tickets
    int next_ticket_number = 1;    //initialize the ticket no. = 1

    // Initialize the queue system
    initialize_queue_system(queue); //go up

    // Run the real-time queue system
    while(true)
    {
        cout << "---------------------------------" << endl;  //print words
        cout << "Current waiting tickets are:" << endl;      
        show_current_queue(queue);                            //go up

        // Ask for user operation
        // - enter 1: customer take a ticket
        // - enter 2: serve the first-come waiting customer
        // - enter 0: exit the queue system
        int operation;
        while (true) {
            cout << "Enter an operation (1 = customer take a ticket; 2 = serve the first-come waiting customer; 0 = exit the queue system):";
            if(cin >> operation){                       //input operation
                if (operation >= 0 && operation <= 2){     //only valid input can break the loop      
                    break;
                }
            }
            // use cin.clear() and cin.ignore() to recover and clean the current input to require user input again.
            // if you are interested you can refer to https://www.quora.com/Can-you-explain-cin-ignore-and-cin-clear-for-C-When-is-it-appropriate-to-use-these-How-do-they-affect-the-next-cin.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, please re-enter." << endl;
        }    

        // run different input user operation
        if(operation == 0)  //quit
        {
            break;
        }

        switch(operation)
        {
            case 1:
            {
                // customer take a ticket
                // print operation success or failure info
                bool flag = take_a_queue_ticket(queue, next_ticket_number);// result from the function
                if (flag){
                    cout << "A customer successfully takes a ticket!" << endl;
                }
                else{
                    cout << "Fail to take a ticket because even our queue is already full!" << endl;
                }
                break;
            }
            case 2:
            {
                // serve the first-come waiting customer
                // print operation success or failure info
                bool flag = serve_the_first_come_customer(queue);   //result from the function
                if (flag){
                    cout << "Successfully serve a customer to go and dine in!" << endl;
                }
                else{
                    cout << "Fail to serve a customer because no one is waiting in the queue!" << endl;
                }
                break;
            }
        }
    }

    cout << "The queue system close successfully!" << endl;

    return 0;
}