/*****************************************
** File:    TicTacNode.cpp
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file does all the things that was stated in the header
**
**
***********************************************/
#include "TicTacNode.h"

#include "TicTacToe.h"
#include <stdlib.h>
#include <iostream>

TicTacNode::TicTacNode(){
    m_next = NULL;//makes m_next to NULL
}

TicTacNode::TicTacNode(std::map<int, char> data){
    m_next = NULL;//makes m_next to NULL
    m_board[1] = data[1];//makes each board to the list space as the inherited map
    m_board[2] = data[2];
    m_board[3] = data[3];
    m_board[4] = data[4];
    m_board[5] = data[5];
    m_board[6] = data[6];
    m_board[7] = data[7];
    m_board[8] = data[8];
    m_board[9] = data[9];
}

std::ostream& operator<<(std::ostream& sout, TicTacNode& b){//returns the board in sout as to be printed later
    sout << b.m_board[1] << b.m_board[2] << b.m_board[3] << "\n";
    sout << b.m_board[4] << b.m_board[5] << b.m_board[6] << "\n";
    sout << b.m_board[7] << b.m_board[8] << b.m_board[9] << "\n";


    return(sout);
}

bool TicTacNode::operator==(TicTacNode& rhs){//checks to see if the board is the same or not
    if(this->m_board[1] != rhs.m_board[1]){//goes through each postion in the map to see if it is same or not
        return(false);
    }else if(this->m_board[2] != rhs.m_board[2]){
        return(false);
    }else if(this->m_board[3] != rhs.m_board[3]){
        return(false);
    }else if(this->m_board[4] != rhs.m_board[4]){
        return(false);
    }else if(this->m_board[5] != rhs.m_board[5]){
        return(false);
    }else if(this->m_board[6] != rhs.m_board[6]){
        return(false);
    }else if(this->m_board[7] != rhs.m_board[7]){
        return(false);
    }else if(this->m_board[8] != rhs.m_board[8]){
        return(false);
    }else if(this->m_board[9] != rhs.m_board[9]){
        return(false);
    }
    return(true);
}

void TicTacNode::operator=(TicTacNode& b){
    m_board[1] = b.m_board[1];//copies each board in the position that was passed into this' board
    m_board[2] = b.m_board[2];
    m_board[3] = b.m_board[3];
    m_board[4] = b.m_board[4];
    m_board[5] = b.m_board[5];
    m_board[6] = b.m_board[6];
    m_board[7] = b.m_board[7];
    m_board[8] = b.m_board[8];
    m_board[9] = b.m_board[9];
}
