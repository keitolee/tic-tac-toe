#include <stdlib.h>
#include <iostream>
#include <string>
#include "ttt.h"

using namespace std;

int main(){
    
    char board[3][4] = { {' ', ' ', ' ', '\0'}, {' ', ' ', ' ', '\0'}, {' ', ' ', ' ', '\0'} };

    printBoard(board);

    // int check = checkboard(board);
    // cout << check << endl;

    int x;
    int y;

    for (int i=0; i<9; i++){
        if (i%2==0){
            cout << "PLAYER 1" << endl;
            int check = 0;
            while ( check != 1){

                cout << "x value: " << endl;
                cin >> x;

                cout << "y value: " << endl;
                cin >> y;

                if ( x < 0 || x > 2 || y < 0 || y > 2 ){
                    cout << "Invalid Input: x, y  values between 0 - 2" << endl;
                    cout << "Try again" << endl;
                }
                else{
                    if (checkplace(board, x, y) == 1){
                        check = 1;
                    }
                    else {
                        cout << "Invalid Input: spot not availible" << endl;
                        cout << "Try again" << endl;
                    }
                }
            }
            
            board[y][x] = 'X';
        }
        else{
            cout << "PLAYER 2" << endl;
            int check = 0;
            while ( check != 1){

                cout << "x value: " << endl;
                cin >> x;

                cout << "y value: " << endl;
                cin >> y;

                if ( x < 0 || x > 2 || y < 0 || y > 2 ){
                    cout << "Invalid Input: x and y values must be between 0 - 2" << endl;
                    cout << "Try again" << endl;
                }
                else{
                    if (checkplace(board, x, y) == 1){
                        check = 1;
                    }
                    else {
                        cout << "Invalid Input: spot not availible" << endl;
                        cout << "Try again" << endl;
                    }
                }
            }
            board[y][x] = 'O';
        }

        printBoard(board);
        if ( checkboard(board) == 1){
            // printBoard(board);
            break;
        }
    }

    cout << "Game over" << endl;
}