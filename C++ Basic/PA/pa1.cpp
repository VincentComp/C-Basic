#include <iostream>
#include <ctime>
using namespace std;

/* -------------------------------------------------------------- */
/* This part serves as a pseudo random number generator for auto grade purpose only */
/* You are suggested not to refer to these codes in this assignment. */
/* You are not allowed to use global variables in this course. */
unsigned int next_num = 1; // Here we initiate an unsigned integer to be used in the following functions.

unsigned int pa1_rand() // This function is used to return a pseudo random number from 0 to 32767.
{
    next_num = next_num * 1103515245 + 2011;
    return static_cast<unsigned int>(next_num / 65536) % 32768;
}
void pa1_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed;
}
/* Everytime you call pa1_rand(), you will get a new pseudo random number. For the same seed, the sequence of pseudo 
   random number is fixed. For example, when seed = 3, the sequence of pseudo random number is fixed to be [17746, 
   30897, 9622, 18921, 4034, 17510, 24152, 14388, 23665, 31532, ...]. When seed = 5, the sequence of pseudo random 
   number is fixed to be [18655, 32247, 9873, 9718, 26373, 27678, 5314, 22512, 31845, 22885, ...] */
/* -------------------------------------------------------------- */



const int MAX_BOXES = 1000; // This constant stores the largest length of boxes[]. You can use it in your code.

// This function is used to fill the 1D array with a random sequence of unique numbers from 1 to the user input for the number of prisoners
void placeSlips(int boxes[], int num_prisoners)
{
    for (int i = 0; i < num_prisoners; i++)
        boxes[i] = -1;
    int counter = 0;
    while (counter < num_prisoners)
    {
        int num = pa1_rand() % (num_prisoners);
        if (boxes[num] == -1)
        {
            boxes[num] = counter;
            counter++;
        }
    }
}

// TASK 1: Simulate an actual riddle room
bool simulateRoom(const int boxes[], int num_prisoners, int num_trials)
{

    /* Please replace this to your own code below */
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {
        int box_num = prisoners_ID;

        for(int trials_time = 0; trials_time < num_trials; trials_time++)
        {
        
            if (prisoners_ID == boxes[box_num])
            {
                break;    
            }
            else
            {
                box_num = boxes[box_num];
                if (trials_time == num_trials - 1)
                return false;          
            } 
        } 

    } return true;


    return false;
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Here in this task, we provide some lines of code for your reference. Please write your code below and replace some of the given code */
    int statistics[4] = {0,0,0,0};
    
    
    int slips_looplist[num_prisoners]={};
    for(int i = 0; i <num_prisoners; i++)
        {
            slips_looplist[i]= 0;
        }
    
   
    int loop_group_num = 0;
    int total_number_of_loop = 0;

    
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {

        int box_num = prisoners_ID;
        int initial_box_num = prisoners_ID;
        
        if (slips_looplist[box_num]== 0)
            {loop_group_num++; total_number_of_loop++;}
            
        
        do{   
           
            if (slips_looplist[box_num] == 0)
            {
            slips_looplist[box_num]+= loop_group_num;
           
            }
            

            box_num = boxes[box_num];
        }while(box_num != initial_box_num);
            
    } statistics[1]=total_number_of_loop;
    

   
  
    int slips_looplist_freq[total_number_of_loop]={};
    
    for(int i = 0; i <total_number_of_loop; i++)
        {
            slips_looplist_freq[i]= 0;
        }
   

    for(int i = 1; i <= total_number_of_loop; i++)
        {
            int frequency = 0;
            int group_num = i;

            for(int j = 0; j <num_prisoners; j++)
            {
                if(slips_looplist[j] ==(group_num))
                {
                    frequency ++;
                }
            }
            slips_looplist_freq[i-1]= frequency;
            
        }

      

  
    int min_freq = slips_looplist_freq[0]; 
    for(int i = 0; i <total_number_of_loop; i++)
        {
            if(slips_looplist_freq[i]<min_freq)
            {
                min_freq = slips_looplist_freq[i];
            }
        } statistics[2] =min_freq;

    int max_freq = slips_looplist_freq[0];
    int max_freq_group = 1;
    for(int i = 0; i <total_number_of_loop; i++)
        {
            if(slips_looplist_freq[i]>max_freq)
            {
                max_freq = slips_looplist_freq[i];
                max_freq_group = (i+1);
            }
        } statistics[3] = max_freq;

    int prisoner_complete = 0;
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {
        int box_num = prisoners_ID;
        for(int trials_time = 0; trials_time < num_trials; trials_time++)
        {
        
            if (prisoners_ID == boxes[box_num])
            {
                prisoner_complete++;
                break;    
            }
            else
            {
                box_num = boxes[box_num];
            } 
        } 

    } 

    statistics[0] = prisoner_complete;



    cout << "The number of prisoners who find their slips: " << statistics[0] /* Please replace this to your own code */ << endl;
    cout << "Number of loops: " << statistics[1] /* Please replace this to your own code */ << endl;
    cout << "Smallest loop length: " << statistics[2] /* Please replace this to your own code */ << endl;
    cout << "Longest loop length: " << statistics[3] /* Please replace this to your own code */ << endl;
    
    
    cout << "Largest loop: ";
    
    
    int min_slip=-1;
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {
        if (slips_looplist[prisoners_ID] == max_freq_group)
        {
            if(min_slip == -1)
                {
                    min_slip = boxes[prisoners_ID];
                }
            else if(boxes[prisoners_ID] < min_slip)
            {
                min_slip = boxes[prisoners_ID];
            }
        }

    }
    

    
    
    /* Please replace this to your own code */
    
   
           
        int box_num = min_slip;
        do{   
            cout << " " << box_num;
            box_num = boxes[box_num];
        }while(box_num != min_slip);
            
    

    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    double num_of_success = 0;
    /* Please replace this to your own code below */
    for(int i = 0; i < 1000; i++)
        {
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
            {num_of_success ++;}
        }
    return num_of_success;

    return 0;
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */

    int slips_looplist[num_prisoners]={};
    for(int i = 0; i <num_prisoners; i++)
        {
            slips_looplist[i]= 0;
        }
    
   
    int loop_group_num = 0;
    int total_number_of_loop = 0;

    
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {

        int box_num = prisoners_ID;
        int initial_box_num = prisoners_ID;
        
        if (slips_looplist[box_num]== 0)
            {loop_group_num++; total_number_of_loop++;}
            
        
        do{   
           
            if (slips_looplist[box_num] == 0)
            {
            slips_looplist[box_num]+= loop_group_num;
           
            }
            

            box_num = boxes[box_num];
        }while(box_num != initial_box_num);
            
    } 
    

   
  
    int slips_looplist_freq[total_number_of_loop]={};
    
    for(int i = 0; i <total_number_of_loop; i++)
        {
            slips_looplist_freq[i]= 0;
        }
   

    for(int i = 1; i <= total_number_of_loop; i++)
        {
            int frequency = 0;
            int group_num = i;

            for(int j = 0; j <num_prisoners; j++)
            {
                if(slips_looplist[j] ==(group_num))
                {
                    frequency ++;
                }
            }
            slips_looplist_freq[i-1]= frequency;
            
        }

    int min_freq = slips_looplist_freq[0]; 
    for(int i = 0; i <total_number_of_loop; i++)
        {
            if(slips_looplist_freq[i]<min_freq)
            {
                min_freq = slips_looplist_freq[i];
            }
        } 

    int max_freq = slips_looplist_freq[0];
    int max_freq_group = 1;
    for(int i = 0; i <total_number_of_loop; i++)
        {
            if(slips_looplist_freq[i]>max_freq)
            {
                max_freq = slips_looplist_freq[i];
                max_freq_group = (i+1);
            }
        } 



    //================================
    //max freq //max_number of group
  

   

    bool need_intervension = false;
    for(int i = 0; i < total_number_of_loop; i++)
        {
           
            if(slips_looplist_freq[i] > num_trials)
            {

                  
                int longest_loop_first_slip_index;
                int longest_loop_middle_slip_index;
            
                for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner <=> boxes
                    {
                    

                    if (slips_looplist[prisoners_ID] == max_freq_group)
                        {
                            longest_loop_first_slip_index = prisoners_ID;
                            break;
                        }
                    }
                        
                        
                        
                int num_of_longest_loop_slip_found = 0;
                int box_num = -1;
                int value_of_middle_slip = 0;

                while (num_of_longest_loop_slip_found != (max_freq/2))
                    {   
                        if(box_num == -1)
                        {
                            box_num = longest_loop_first_slip_index;
                        
                            continue;
                        }
                    
                        box_num = boxes[box_num];
                        num_of_longest_loop_slip_found ++;
                    } value_of_middle_slip = box_num;



                for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner <=> boxes
                    {
                    

                    if (boxes[prisoners_ID] == value_of_middle_slip)
                        {
                            longest_loop_middle_slip_index = prisoners_ID;
                            break;
                        }
                    }

                
                int temp = boxes[longest_loop_first_slip_index];
                boxes[longest_loop_first_slip_index] = boxes [longest_loop_middle_slip_index];
                boxes [longest_loop_middle_slip_index] = temp;




                need_intervension = true;
                break;
            }
            
        }
      

    if(need_intervension == true)
    {

        return true;
    }

   



   



    return false;
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED.

int main()
{

    int num_prisoners, num_trials, seed;
    // set boxes, priosoners

    cout << "Enter the number of prisoners (from 1 to 1000) :" << endl;
    cin >> num_prisoners;
    cout << "Enter the number of boxes each prisoner can open (from 1 to 1000) :" << endl;
    cin >> num_trials;
    cout << "Enter the seed for randomization else enter 0 and the system will randomize for you :" << endl;
    cin >> seed;

    if (seed == 0)
    {
        pa1_srand(time(NULL));
    }
    else
    {
        pa1_srand(seed);
    }

    int boxes[MAX_BOXES]; // array for the boxes
    for (int i = 0; i < MAX_BOXES; i++)
        boxes[i] = 0;

    int choice;
    cout << "Please choose an option:" << endl;
    cout << "0.Print the boxes" << endl;
    cout << "1.Simulate a room" << endl;
    cout << "2.Compute statistics of a room:" << endl;
    cout << "3.Compute success rate over 1000 rooms" << endl;
    cout << "4.Apply nice guard intervention in a room" << endl;
    cin >> choice;

    switch (choice)
    {
    case 0:
        placeSlips(boxes, num_prisoners);
        for (int i = 0; i < num_prisoners; i++)
            cout << boxes[i] << " ";
        cout << endl;
        break;
    case 1:
        placeSlips(boxes, num_prisoners);
        if (simulateRoom(boxes, num_prisoners, num_trials) == true)
        {
            cout << "Success! All prisoners found their slip." << endl;
        }
        else
        {
            cout << "Failure! Not all prisoners were able to find their slip." << endl;
        }
        break;
    case 2:
        placeSlips(boxes, num_prisoners);
        statsRoom(boxes, num_prisoners, num_trials);
        break;
    case 3:
    {

        double prisoners_left = successRooms(boxes, num_prisoners, num_trials);
        cout << "All prisoners were able to leave " << prisoners_left << "/1000 of the rooms." << endl;
    }
    break;
    case 4:
    {
        placeSlips(boxes, num_prisoners);
        int copy_arr[MAX_BOXES];
        for (int i = 0; i < num_prisoners; i++)
        {
            copy_arr[i] = boxes[i]; // copying the array for checking if no more than 2 swaps are made
        }

        bool nice_guard_val = niceGuard(boxes, num_prisoners, num_trials);

        int swap_count = 0;
        for (int j = 0; j < num_prisoners; j++)
        {
            if (copy_arr[j] != boxes[j])
            {
                swap_count++;
            }
        }
        if (swap_count > 2)
        {
            cout << "Illegal intervention as you have more than 1 swap " << endl;
        }
        else
        {
            if (nice_guard_val == false)
                cout << "No intervention needed." << endl;
            else
            {
                cout << "Intervention applied." << endl;
                // validity function
                bool prisoners_left = simulateRoom(boxes, num_prisoners, num_trials);
                // should return true
                if (prisoners_left == true)
                    cout << "All the prisoners were able to escape" << endl;
                else
                {
                    cout << "All the prisoners were not able to escape" << endl;
                }
            }
        }
    }
    break;
    }

    return 0;
}