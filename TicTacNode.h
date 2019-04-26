/*****************************************
** File:    TicTacNode.h
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file creates the node for the linked list and trie tree
**   Also, contains the board and the children of the objects
**
**
**
***********************************************/
#ifndef TICTACNODE_H
#define TICTACNODE_H

#include <iostream>
#include <vector>
#include <map>


class TicTacNode
{
    public:

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a TicTacNode object
        TicTacNode();

        //input:map
        //output:N\A
        //Descriptaion: initializes the variables for a TicTacNode object with given information
        TicTacNode(std::map<int, char> data);


        std::vector<TicTacNode*> m_children;//a vector list of all the children


        std::map<int, char> m_board;// a map of the board

        //input: TicTacNode&
        //output: scout
        //Descriptaion: returns scout which is the board so later to be printed to later
        friend std::ostream& operator<<(std::ostream& sout, TicTacNode& b);

        //input:TicTacNode&
        //output:N/A
        //Descriptaion: weather the boards are equal to each other
        bool operator==(TicTacNode& rhs);

        //input:A tic tac node
        //output:N/A
        //Descriptaion: it changes the board of the LHS to the board of RHS
        void operator=(TicTacNode& b);


        TicTacNode *m_next;//is the next node for the linked list of tictactoe


};

#endif // TICTACNODE_H
