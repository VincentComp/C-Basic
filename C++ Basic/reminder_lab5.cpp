#include <iostream>

using namespace std;

// width and height of the canvas
const int WIDTH = 20; //setting the width and the height of the canvas
const int HEIGHT = 10;



// Given
void initialize_canvas(char canvas[HEIGHT][WIDTH]) { //setting initial value to the canvas
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '.';
        }

    }

    canvas[0][0] = '#';
}




// Task 1: Print the canvas
void print_canvas(const char canvas[HEIGHT][WIDTH]) { //print the whole canvas

for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j< WIDTH;j++)
            {cout << canvas[i][j];}
            cout <<endl;
    }

}


// Task 2: change the cursor after painting the pixel
void paint_pixel(char canvas[HEIGHT][WIDTH], int row_position, int col_position) {
    canvas[row_position][col_position]='X'; // assign the current position = X
}

// Task 3: change the cursor after painting the pixel
void erase_pixel(char canvas[HEIGHT][WIDTH], int row_position, int col_position) {
    canvas[row_position][col_position]='#'; // assign the current position = #
}


// Task 4: check whether the move is valid and move the cursor
bool move_brush(char canvas[HEIGHT][WIDTH], int &row_position, int &col_position, char move) {
    if (move == 'i') //case I
    {
        if(row_position != (0)) // if not the uppest row
        {
            if (canvas[row_position][col_position] !='X') //if the original position is not painted --> turn # into .
                canvas[row_position][col_position] ='.';
            else
                {canvas[row_position][col_position] ='x';} //if the new position = X --> turn into x
            row_position -= 1; //update the coordinate
            if (canvas[row_position][col_position] !='x')  //if the new position i painted --> don't paint
                canvas[row_position][col_position] ='#';
            else
                {canvas[row_position][col_position] ='X';} //if the new position = x --> turn into X
            return true;//indication for success function
        }

    };

    if (move == 'k')
    {
        if(row_position != (HEIGHT-1))
        {
            if (canvas[row_position][col_position] !='X')
                canvas[row_position][col_position] ='.';
            else
                {canvas[row_position][col_position] ='x';} //if the new position = X --> turn into x
                
            row_position += 1;
            if (canvas[row_position][col_position] !='x')    
                canvas[row_position][col_position] ='#';
            else
                {canvas[row_position][col_position] ='X';}
            return true;
        }

    };

    if (move == 'j')
    {
        if(col_position != (0))
        {
            if (canvas[row_position][col_position] !='X')
                canvas[row_position][col_position] ='.';
            else
                {canvas[row_position][col_position] ='x';} //if the new position = X --> turn into x
            col_position -= 1;
            if (canvas[row_position][col_position] !='x')
                canvas[row_position][col_position] ='#';
            else
                {canvas[row_position][col_position] ='X';}
            return true;
        }

    }

    if (move == 'l')
    {
        if(col_position != (WIDTH-1))
        {
            if (canvas[row_position][col_position] !='X')
                canvas[row_position][col_position] ='.';
            else
                {canvas[row_position][col_position] ='x';} //if the new position = X --> turn into x
            col_position += 1;
            if (canvas[row_position][col_position] !='x')
                canvas[row_position][col_position] ='#';
            else
                {canvas[row_position][col_position] ='X';}
            return true;
        }

    };
}


// Task 5: Print the canvas without the cursor
void print_canvas_without_cursor(const char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j< WIDTH;j++)
            {
            if(canvas[i][j] =='#') //if the position = # --> print .
                {cout << '.';}
            else if(canvas[i][j] =='X') //if the position = X --> print x
                {cout << 'x';}
            else
                {cout << canvas[i][j];}
                }
            cout <<endl;
    }

}




int main() {
    // initial canvas definition
    char canvas[HEIGHT][WIDTH]; //Creating the canvas with height and width


    initialize_canvas(canvas);

    //printing the sentences
    cout << "****************************************************************" << endl;
    cout << "******************* Welcome to CPPPaint! ***********************" << endl;
    cout << "****************************************************************" << endl;
    cout << "An empty canvas region is represented by \'.\'" << endl;
    cout << "An painted canvas region is represented by \'x\'" << endl;
    cout << "\'#\' represents your cursor over an emtpy region" << endl;
    cout << "\'X\' represents your cursor over a painted region" << endl;
    
    cout << "###################### Painting the Pixel ######################" << endl;
    cout << "Press \'r\' to paint the current pixel" << endl;
    cout << "Press \'e\' to erase the current pixel" << endl;
    cout << "####################### Moving the cursor ######################" << endl;
    cout << "Press \'i\',\'k\',\'j\',\'l\' to move up, down, left, or right respectively" << endl;
    cout << "Press \'q\' to stop the program and display your final work" << endl;

    cout << endl;
    cout << endl;
    cout<< "Your canvas is currently empty" << endl;
    

    char movement;//creating the variable for holding the choice
    int row_position = 0;//initial cursor position =(0,0)
    int col_position = 0;

    print_canvas(canvas); //see above

    do {
        cout<< "Select action to perform (r to paint pixel, e to erase pixel; i,k,j,l to move): " << endl;
        cin >> movement; //get input choice

        if ((movement == 'i') || (movement == 'j') || (movement == 'k') || (movement == 'l')) { //check the input is correct
            if (!move_brush(canvas, row_position, col_position, movement)){ //then run the function + check if the function run successfully
                cout << "move invalid" << endl;
            }
            else {
                print_canvas(canvas); //if successfully run --> print the whole canvas
            }
        }

        else if (movement == 'r') {
            paint_pixel(canvas, row_position, col_position); //see above
            print_canvas(canvas);
        }

        else if (movement == 'e') {
            erase_pixel(canvas, row_position, col_position); //see above
            print_canvas(canvas);
        }


        else if ((movement == 'q')) {
            cout << "Thanks for using CPPPaint!" << endl; //see above
            break; //break the loop
        }
        else {

            cout << "wrong option" << endl;
        }

    } while (true);

    cout << "Here is your finished painting!" << endl;
    print_canvas_without_cursor(canvas); //see above
    return 0;
}