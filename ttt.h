#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

void printBoard(char board[3][4]){
    for (int i = 0; i < 12; i++)
    {
        if(i%4!=3)
        {
            cout<<" "<<board[i/4][i%4]; 
            if(i%4<2)
                cout<<" |";
        }
        else
        {
            if(i/4<2)
                cout<<endl<< "---+---+---";
            cout<<endl; 
        }
    }
}

int checkplace(char board[3][4], int x, int y){

    if (board[y][x] == ' '){
        return 1;
    }
    else{
        return 0;
    }
    
}

int checkboard(char board[3][4]){

    int horz = 0;
    for (int i=0; i<3; i++){
        char unit;
        int count = 0;
        for (int j=0; j<3; j++){
            if (j==0){
                unit = board[i][j]; 
                count = 1;
            }
            else{
                if (unit == board[i][j] && unit != ' ' ){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        if (count == 3){
            horz = 1;
        }
    }

    int vert = 0;    
    for (int j=0; j<3; j++){
        char unit;
        int count = 0;
        for (int i=0; i<3; i++){
            if (i==0){
                unit = board[i][j]; 
                count = 1;
            }
            else{
                if (unit == board[i][j] && unit != ' ' ){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        if (count == 3){
            vert = 1;
        }
    }

    int diagl = 0;
    char unitl;
    int countl = 0;
    for (int i=0; i<3; i++){
        if (i==0){
            unitl = board[i][i]; 
            countl = 1;
        }
        else{
            if (unitl == board[i][i] && unitl != ' ' ){
                countl++;
            }
            else{
                break;
            }
        }
        if (countl == 3){
            diagl = 1;
        }
    }

    int diagr = 0;
    char unitr;
    int countr = 0;
    for (int i=0; i<3; i++){
        if (i==0){
            unitr = board[i][2-i]; 
            countr = 1;
        }
        else{
            if (unitr == board[i][2-i] && unitr != ' ' ){
                countr++;
            }
            else{
                break;
            }
        }
        if (countr == 3){
            diagr = 1;
        }
    }

    if (horz == 1 || vert == 1 || diagl == 1 || diagr == 1){
        return 1;
    }
    else {
        return 0;
    }
}