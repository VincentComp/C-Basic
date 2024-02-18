#include <iostream>
#include <fstream>
#include "lab7.h"

using namespace std;

// TODO1: Reorder the linked list so that VIP customers come first
// Your would need to reorder the entries in the given array, with VIP customers comes first
//      Both the VIP customers and the normal customers would be then ordered by their ID repectively
//      Example: ID0_VIP, ID1_Non_VIP, ID2_VIP => ID0_VIP, ID2_VIP, ID1_Non_VIP
void swap (Customer*& srp1,Customer*& srp2)
{
    Customer*temp = srp1; srp1 = srp2; srp2 = temp;
}

void reorder_customer(Customer* queue [], int num_customer) {
    int VIP_index = 0;
    for (int i = 0; i < num_customer ; i++)
    {
        
        if(queue[i]->vip == true)
            {
            swap(queue[i],queue[VIP_index]);
            VIP_index ++;
            }
    }//sort vip

    int Normal_index = VIP_index;

    for (int i = Normal_index; i<num_customer ; i++ )
        {
            for (int j = Normal_index; j<num_customer ; j++ )
            {
                if(queue[i]->id < queue[j]->id )
                {
                    swap(queue[i],queue[j]);
                }
            }
        }// sort number in non-vip
    return;
}

// TODO2: Let customers check out from the store, and get the money
// Customers comes in the ordered of the array
// For each of the customers' needs, if the store can satisfy it, sell the corresponding amount and get the paid money, otherwise skip this need (sell nothing and earn nothing)
//      Example: If a customer need 5 Apples and 5 Bananas and the store have 10 Apples and 2 Bananas left, then sell 5 Apples (and 0 Bananas) to the customer
// You don't need to delete the pointers to customers in this TODO
int check_out(Fruit fruits [], const Customer* const queue [], int num_fruit, int num_customer) {
    int revenue = 0;

    for(int i = 0; i < num_customer; i++)
    {
        for(int j=0; j < num_fruit; j++)
        {//fruits[j]-->....
            if(queue[i]->need[j] <= (fruits[j].total_count-fruits[j].sold_count))
                {
                    revenue += (queue[i]->need[j])*fruits[j].unit_price;
                    fruits[j].sold_count += queue[i]->need[j];
                
                }
        }
    }
    
    return revenue;
}