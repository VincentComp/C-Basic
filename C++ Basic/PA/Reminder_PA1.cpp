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
    return static_cast<unsigned int>(next_num / 65536) % 32768; //constant in mod 32768
}
void pa1_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed; //random next_num --> change pa1_rand
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
    for (int i = 0; i < num_prisoners; i++) //set amount of box = amount of prisoner
        boxes[i] = -1; //set required boxes = -1
    int counter = 0;
    while (counter < num_prisoners)
    {
        int num = pa1_rand() % (num_prisoners); //different box no.
        if (boxes[num] == -1)//if the box required
        {
            boxes[num] = counter;//assign 1,2,3,4,5.. to the boxes
            counter++;  //next boxes
        }
    }
}

// TASK 1: Simulate an actual riddle room
bool simulateRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */
    //box = 0 to (N-1), num_prisoners = N, num_trials, idk
        for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //prisoners_ID from 0 to N-1
    {
        int box_num = prisoners_ID; //initial box_num = prisoners_ID 

        for(int trials_time = 0; trials_time < num_trials; trials_time++) //trials_time < trials
        {
        
            if (prisoners_ID == boxes[box_num]) //if correct matching 
            {
                break; //--> next prisoner
            }
            else
            {
                box_num = boxes[box_num]; //slips numebr = next box num
                if (trials_time == num_trials - 1) //if last trials time
                return false; //no chance la --> bye
            } 
        } 

    } return true;//complete all the task --> done


    return false;//maybe just for testing gua?
}

// TASK 2: Display certain statistics for a given room
void statsRoom(const int boxes[], int num_prisoners, int num_trials)
{
    /* Here in this task, we provide some lines of code for your reference. Please write your code below and replace some of the given code */
    int statistics[4] = {0,0,0,0}; //array for 4 output
    
    
    int slips_looplist[num_prisoners]={}; //initialize a list for storing the loop_no. of each box_num
    for(int i = 0; i <num_prisoners; i++)
        {
            slips_looplist[i]= 0;
        }
    
   
    int loop_group_num = 0; //initial group num = 0
    int total_number_of_loop = 0; //total_number_of_loop = 0

    
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) 
    {

        int box_num = prisoners_ID; //first box_num = prisoner ID
        int initial_box_num = prisoners_ID; //memorize the first box num
        
        if (slips_looplist[box_num]== 0) //if no group no. 
            {loop_group_num++; total_number_of_loop++;} // generate a new group no. --> total_number_of_loop ++(p.s. group number start from 1)
            
        
        do{   
           
            if (slips_looplist[box_num] == 0) //if no group no. 
            {
            slips_looplist[box_num]+= loop_group_num; //assign a group no. --> store in the slips_looplist
           
            }
            

            box_num = boxes[box_num];   //new box num = slip num
        }while(box_num != initial_box_num); //if box num != original box num <=> no reach the loop end --> repeat
            
    } statistics[1]=total_number_of_loop; 
    

   
  
    int slips_looplist_freq[total_number_of_loop]={}; //initialize a list: num_of_box in the loop 
    
    for(int i = 0; i <total_number_of_loop; i++)
        {
            slips_looplist_freq[i]= 0;
        }
   

    for(int i = 1; i <= total_number_of_loop; i++) //run through whole looplist
        {
            int frequency = 0; //clear the freq. every time
            int group_num = i; 

            for(int j = 0; j <num_prisoners; j++)
            {
                if(slips_looplist[j] ==(group_num)) //if the box belong to the group
                {
                    frequency ++; // freq ++
                }
            }
            slips_looplist_freq[i-1]= frequency; //store the value to the list (p.s. group number start from 1)
            
        }

      

  
    int min_freq = slips_looplist_freq[0]; //assume the 1st group has the samllest freq
    for(int i = 0; i <total_number_of_loop; i++) //run through whole looplist
        {
            if(slips_looplist_freq[i]<min_freq) // if find a loop < min 
            {
                min_freq = slips_looplist_freq[i]; // new min = this loop
            }
        } statistics[2] =min_freq;

    int max_freq = slips_looplist_freq[0];//assume the 1st group has the max freq
    int max_freq_group = 1; // assume the group num of(the group having the max freq) = 1
    for(int i = 0; i <total_number_of_loop; i++) //run through whole looplist
        {
            if(slips_looplist_freq[i]>max_freq)// if find a loop > max
            {
                max_freq = slips_looplist_freq[i]; // new max = this loop
                max_freq_group = (i+1); //new group num(p.s. group number start from 1)
            }
        } statistics[3] = max_freq;

    int prisoner_complete = 0; //initialize num of prisoner passing the task
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner
    {
        //run the stimulate room
        int box_num = prisoners_ID; 
        for(int trials_time = 0; trials_time < num_trials; trials_time++) 
        {
        
            if (prisoners_ID == boxes[box_num])
            {
                prisoner_complete++; //if can find --> num of complete ++
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

    int min_slip=-1; //initial min = -1
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner <=> boxes
    {
        if (slips_looplist[prisoners_ID] == max_freq_group) //if box having the max_freq_group
        {
            if(min_slip == -1) //if the min value not yet record
                {
                    min_slip = boxes[prisoners_ID]; //min value slip number 
                }
            else if(boxes[prisoners_ID] < min_slip)//else if the slip num < min
            {
                min_slip = boxes[prisoners_ID]; //new min = slip num
            }
        }

    }

    /* Please replace this to your own code */

    int box_num = min_slip; //first box number = min
        do{   
            cout << " " << box_num; //print the slip
            box_num = boxes[box_num]; //box num = slip
        }while(box_num != min_slip); //until repeat <=> reach the loop end
    cout << endl;
}

// TASK 3: Find the number of instances in 1000 rooms when the prisoners will all be able to escape
double successRooms(int boxes[], int num_prisoners, int num_trials) //  suceess rate of 1000 rooms basically repeating it a 1000 times
{
    /* Please replace this to your own code below */
     double num_of_success = 0; //initialize the number of succeed = 0
    for(int i = 0; i < 1000; i++)//run 1000 times
        {
        placeSlips(boxes, num_prisoners); // change the box and slip number
        if (simulateRoom(boxes, num_prisoners, num_trials) == true) //if found box == true
            {num_of_success ++;} //num of success ++
        }
    return num_of_success; //return num of success

    return 0;
   
}

// TASK 4: Nice guard will help the prisoners to successfully leave the room by breaking any loop which is greater than the number of trials
//         Return true if the intervention was applied, else return false
bool niceGuard(int boxes[], int num_prisoners, int num_trials)
{
    /* Please replace this to your own code below */

    int slips_looplist[num_prisoners]={}; //initialize a list for storing the loop_no. of each box_num
    for(int i = 0; i <num_prisoners; i++)
        {
            slips_looplist[i]= 0;
        }
    
   
    int loop_group_num = 0;//initial group num = 0
    int total_number_of_loop = 0;//total_number_of_loop = 0


    
    for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++)
    {

        int box_num = prisoners_ID;//first box_num = prisoner ID
        int initial_box_num = prisoners_ID;//memorize the first box num
        
        if (slips_looplist[box_num]== 0)//if no group no.
            {loop_group_num++; total_number_of_loop++;}// generate a new group no. --> total_number_of_loop ++(p.s. group number start from 1)
            
        
        do{   
           
            if (slips_looplist[box_num] == 0)//if no group no. 
            {
            slips_looplist[box_num]+= loop_group_num;//assign a group no. --> store in the slips_looplist
           
            }
            

            box_num = boxes[box_num];//new box num = slip num
        }while(box_num != initial_box_num);//if box num != original box num <=> no reach the loop end --> repeat
            
    } 
    

   
  
    int slips_looplist_freq[total_number_of_loop]={}; //initialize a list: num_of_box in the loop 
    
    for(int i = 0; i <total_number_of_loop; i++)
        {
            slips_looplist_freq[i]= 0;
        }
   

    for(int i = 1; i <= total_number_of_loop; i++) //run through whole looplist
        {
            int frequency = 0;//clear the freq. every time
            int group_num = i;

            for(int j = 0; j <num_prisoners; j++)
            {
                if(slips_looplist[j] ==(group_num))//if the box belong to the group
                {
                    frequency ++;// freq ++
                }
            }
            slips_looplist_freq[i-1]= frequency;//store the value to the list (p.s. group number start from 1)
            
        }

    int min_freq = slips_looplist_freq[0]; //assume the 1st group has the samllest freq
    for(int i = 0; i <total_number_of_loop; i++)//run through whole looplist
        {
            if(slips_looplist_freq[i]<min_freq)// if find a loop < min 
            {
                min_freq = slips_looplist_freq[i];// new min = this loop
            }
        } 

    int max_freq = slips_looplist_freq[0];//assume the 1st group has the max freq
    int max_freq_group = 1;// assume the group num of(the group having the max freq) = 1
    for(int i = 0; i <total_number_of_loop; i++)//run through whole looplist
        {
            if(slips_looplist_freq[i]>max_freq)//if find a loop > max
            {
                max_freq = slips_looplist_freq[i];// new max = this loop
                max_freq_group = (i+1);//new group num(p.s. group number start from 1)
            }
        } 



    //================================
    //max freq //max_number of group
  

   

    bool need_intervension = false; //test whether need intervension
    for(int i = 0; i < total_number_of_loop; i++)
        {
           
            if(slips_looplist_freq[i] > num_trials) //if loop_length > num_trails --> intervension
            {

                  
                int longest_loop_first_slip_index;
                int longest_loop_middle_slip_index;
            
                for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner <=> boxes
                    {
                    

                    if (slips_looplist[prisoners_ID] == max_freq_group)//Once detect the box belonging to the longest loop
                        {
                            longest_loop_first_slip_index = prisoners_ID; // Record the 1st box
                            break;
                        }
                    }
                        
                        
                        
                int num_of_longest_loop_slip_found = 0;
                int box_num = -1; 
                int value_of_middle_slip = 0;

                while (num_of_longest_loop_slip_found != (max_freq/2)) //set max_freq/2 --> find the middle element of the loop
                    {   
                        if(box_num == -1)
                        {
                            box_num = longest_loop_first_slip_index;//first box = 1st longest loop box
                            //since we want the 4th v.s. not the index 4 --> the first one no plus plus
                            continue;
                        }
                    
                        box_num = boxes[box_num]; //slip = new box
                        num_of_longest_loop_slip_found ++;//until the no. of box reach half
                    } value_of_middle_slip = box_num; //once reach max_freq/2 -->find the value of middle strip



                for(int prisoners_ID = 0; prisoners_ID < num_prisoners; prisoners_ID++) //run through all prisoner <=> boxes
                    {
                    

                    if (boxes[prisoners_ID] == value_of_middle_slip)
                        {
                            longest_loop_middle_slip_index = prisoners_ID;// use value find index
                            break;
                        }
                    }

                //simple switching
                int temp = boxes[longest_loop_first_slip_index];
                boxes[longest_loop_first_slip_index] = boxes [longest_loop_middle_slip_index];
                boxes [longest_loop_middle_slip_index] = temp;




                need_intervension = true; //indicate a intervension is carried out
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
    
    //input of prisoner no., no. of trails, seed
    cout << "Enter the number of prisoners (from 1 to 1000) :" << endl;
    cin >> num_prisoners;
    cout << "Enter the number of boxes each prisoner can open (from 1 to 1000) :" << endl;
    cin >> num_trials;
    cout << "Enter the seed for randomization else enter 0 and the system will randomize for you :" << endl;
    cin >> seed;

    if (seed == 0)
    {
        pa1_srand(time(NULL)); //use computer time as seed
    }
    else
    {
        pa1_srand(seed); //use input as seed
    }

    int boxes[MAX_BOXES]; // array for the boxes
    for (int i = 0; i < MAX_BOXES; i++) 
        boxes[i] = 0; //initialize 1000 boxes

    //input of choices
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
    case 0://print the boxes
        placeSlips(boxes, num_prisoners);
        for (int i = 0; i < num_prisoners; i++)
            cout << boxes[i] << " ";
        cout << endl;
        break;
    case 1://simulate a room
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
    case 2: //compute statistic of room
        placeSlips(boxes, num_prisoners);
        statsRoom(boxes, num_prisoners, num_trials);
        break;
    case 3: //compute success rate over 1000 rooms
    {

        double prisoners_left = successRooms(boxes, num_prisoners, num_trials);
        cout << "All prisoners were able to leave " << prisoners_left << "/1000 of the rooms." << endl;
    }
    break;
    case 4: // nice guard
    {
        placeSlips(boxes, num_prisoners); //change the box and slip number
        int copy_arr[MAX_BOXES];
        for (int i = 0; i < num_prisoners; i++)
        {
            copy_arr[i] = boxes[i]; // copying the array for checking if no more than 2 swaps are made
        }

        bool nice_guard_val = niceGuard(boxes, num_prisoners, num_trials); 

        int swap_count = 0;
        for (int j = 0; j < num_prisoners; j++) //check the new list v.s. old list
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