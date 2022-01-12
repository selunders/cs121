/* mazeSolver.cpp
*
* CS 121.Bolden.....gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)...Seth Lunders
* 3/9/20...PC: GE62VR 7RF REV:1.0; CPU: Intel i7-7700HQ...lund4272@vandals.uidaho.edu
*
* The program will take in a maze data file and output a path to the exit
*
* ---------------------------------------------------------------------
*/

#include<iostream>
#include<fstream>

//include

#include "maze.h"

void arrPrint(char[], int, int);

int main(){
    string mazeName;
    
    cout << "Enter the name of the maze file to solve: ";
    cin >> mazeName;
    cout << endl;
    ifstream myfile(mazeName); // Open the maze file
    if(myfile.fail()){
        cout << "Error accessing file: " << mazeName << "." << endl;
        return 1;
    }

    int rows = 0;
    int columns = 0;

    myfile >> rows;
    myfile >> columns;


    char maze[rows][columns];
    char mazeSolution[rows][columns];   
    
    queue mazePath;

    for(int i = 0; i < rows; i++) // Loop through each row
    {
        for(int j = 0; j < columns; j++) // Loop through each column
        {
            myfile >> maze[i][j];
            mazeSolution[i][j] = ' ';
            if(maze[i][j] == 'S')
            {
                mazePath.Enqueue(i,j); // Sets S as the start of the maze
                mazeSolution[i][j] = 'S'; // Sets S as 'visited'
            }
        }
    }

    int solveable = 1;

    while(solveable == 1){
        int solveTest = 0;
        int currRow = mazePath.start->row;
        int currCol = mazePath.start->column;

        if((maze[currRow-1][currCol] == '.') && ((currRow -1) != -1) && (mazeSolution[currRow-1][currCol] ==' ')){
             mazePath.Enqueue(currRow -1, currCol);
             ++solveTest;
         }
        if((maze[currRow+1][currCol] == '.') && ((currRow) <= rows) && (mazeSolution[currRow+1][currCol] == ' ')){
            mazePath.Enqueue(currRow +1, currCol);
            ++solveTest;
         }
        if((maze[currRow][currCol-1] == '.') && ((currCol -1) != -1) && (mazeSolution[currRow][currCol-1] ==' ')){
             mazePath.Enqueue(currRow, currCol-1);
             ++solveTest;
         }
        if((maze[currRow][currCol+1] == '.') && ((currCol) <= columns) && (mazeSolution[currRow][currCol+1] ==' ')){
             mazePath.Enqueue(currRow, currCol+1);
             ++solveTest;
        } 

        if((maze[currRow-1][currCol] == 'G') && ((currRow -1) != -1) && (mazeSolution[currRow-1][currCol] ==' ')){
             mazeSolution[currRow-1][currCol] = 'G';
             solveable = 2;            
         } else
        if((maze[currRow+1][currCol] == 'G') && ((currRow) <= rows) && (mazeSolution[currRow+1][currCol] ==' ')){
             mazeSolution[currRow+1][currCol] = 'G';
             solveable = 2; 
         } else
        if((maze[currRow][currCol-1] == 'G') && ((currCol -1) != -1) && (mazeSolution[currRow][currCol-1] ==' ')){
             mazeSolution[currRow][currCol-1] = 'G';
             solveable = 2; 
         } else
        if((maze[currRow][currCol+1] == 'G') && ((currCol) <= columns) && (mazeSolution[currRow][currCol+1] ==' ')){
             mazeSolution[currRow][currCol+1] = 'G';
             solveable = 2;
        }

        if(mazeSolution[currRow][currCol] != 'S')
                mazeSolution[currRow][currCol] = '.';

        mazePath.Dequeue();
        if((solveTest == 0) && (mazePath.start == NULL)){
            solveable = 0;
        }

        // ---------------------------------------
        // Test Code
        //
        // Prints the current maze after each loop
        // ---------------------------------------

        // for(int i = 0; i < rows; i++) // Rows
        // {
        //     for(int j = 0; j < columns; j++) // Columns
        //     {
        //         cout << mazeSolution[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;       

        // ----------------------------------------
        // End of Test Code
        // ----------------------------------------


    }

    if(solveable == 0){
        cout << "This maze could not be solved.\n";
    } else if (solveable == 2) {
        cout << endl << "Maze:" << endl;
    }

    // Print Maze
    for(int i = 0; i < rows; i++) // Row
    {
        for(int j = 0; j < columns; j++) // Column
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    cout << endl << "Maze Solution:" << endl;
    // Print Solution
    for(int i = 0; i < rows; i++) // Loop through each row
    {
        for(int j = 0; j < columns; j++) // Loop through each column
        {
           cout << mazeSolution[i][j];
        }
        cout << endl;
    }    
}



void arrPrint(char arr[], int r, int c)
{
    for(int i = 0; i < r; i++) // Row
    {
        for(int j = 0; j < c; j++) // Column
        {
            cout << arr[i];
        }
        cout << endl;
    }
}