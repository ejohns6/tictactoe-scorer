/*****************************************
** File:    TicTacToe.h
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file creates the linked list of tic tac toe to keep all of the moves of the read in
**   tic tac toe game. Also keeps track of who won/tied and if the game finished
**
**
***********************************************/
#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#include "TicTacNode.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>

class TicTacToe
{
    public:

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        TicTacToe();

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        ~TicTacToe();

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        int getTurns() const;

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        bool getIsOver() const;//gets isOver

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        int getResults() const;//gets the results of the game

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        void readGame(std::string fileName);//reads the game

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        void toeClear(/*TicTacNode* head*/);

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        TicTacToe& operator=(TicTacToe& b);

        //input:N/A
        //output:N/A
        //Descriptaion: get the head
        TicTacNode* getHead() const;

    private:
        TicTacNode* m_head;//is the m_head of the list

        bool m_isOver;//varible weather over or not
        int m_results;//varible on results
        int m_turns;//varible on the number of turns



};


#endif // TICTACTOE_H_INCLUDED
