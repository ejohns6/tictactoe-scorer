/*****************************************
** File:    TicTacToe.cpp
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
#include "TicTacToe.h"
#include "TicTacNode.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>

TicTacToe::TicTacToe(){
    m_head = new TicTacNode();//make m_head  a new initialized node
    m_results = 0;//sets the results as zero
    m_isOver = false;//sets the game as is not over
}

TicTacToe::~TicTacToe(){//does not do jack because the addgame method calls it when leaving the method

}


void TicTacToe::readGame(std::string fileName){//reads the file and enters each triplet of lines into a node
    std::string line;
    char XO;
    int turns = 0;
    std::ifstream game;//opens the file
    game.open(fileName.c_str());
    TicTacNode* current =  m_head;
    int postion = 0;
    while(getline(game, line)){//goes through each line
        std::stringstream onLine(line);
        if(postion == 0 and line != "\n"){
            if(turns != 0){
                current->m_next = new TicTacNode;
                current =  current->m_next;
            }
            turns++;
        }

        for(int a = 0; a < 3; a++){//inserts each char to a specific position on the map
            postion++;
            onLine >> XO;
            current->m_board[postion] = XO;
        }
        if(postion == 9){

            getline(game, line);//skips over the blank line
            postion = 0;//resets the position to 0
        }
    }
    //checks to see if anybody won and then checks to see who won
    if(current->m_board[1] != '-' && current->m_board[1] == current->m_board[2] && current->m_board[2] == current->m_board[3]){
        if(current->m_board[1] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[1] != '-' && current->m_board[1] == current->m_board[4] && current->m_board[4] == current->m_board[7]){
        if(current->m_board[1] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[1] != '-' && current->m_board[1] == current->m_board[5] && current->m_board[5] == current->m_board[9]){
        if(current->m_board[1] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[2] != '-' && current->m_board[2] == current->m_board[5] && current->m_board[5] == current->m_board[8]){
        if(current->m_board[2] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[3] != '-' && current->m_board[3] == current->m_board[6] && current->m_board[6] == current->m_board[9]){
        if(current->m_board[3] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[3] != '-' && current->m_board[3] == current->m_board[5] && current->m_board[5] == current->m_board[7]){
        if(current->m_board[3] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[4] != '-' && current->m_board[4] == current->m_board[5] && current->m_board[5] == current->m_board[6]){
        if(current->m_board[4] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else if(current->m_board[7] != '-' && current->m_board[7] == current->m_board[8] && current->m_board[8] == current->m_board[9]){
        if(current->m_board[7] == 'X'){
            m_results = 1;
            m_isOver = true;
        }else{
            m_results = 2;
            m_isOver = true;
        }
    }else{//if no one won then checks to see if tie happened or not done
        if(turns == 10){
            m_results = 3;
            m_isOver = true;
        }else{
            m_results = 0;
            m_isOver = false;
        }
    }
    m_turns = turns;

    game.close();
}

int TicTacToe::getTurns() const{
    return(m_turns);//returns the amount of turns
}

bool TicTacToe::getIsOver() const{
    return(m_isOver);//returns weather if it is done or not
}

int TicTacToe::getResults() const{
    return(m_results);//returns the results
}



void TicTacToe::toeClear(){//is my manual deconstructor (the reason why I made this is stated in the driver)
    TicTacNode* current;
    current = m_head;
    while (current != NULL) {//Goes through each node and deletes it separately
        TicTacNode* next = current->m_next;
        delete current;
        current = next;

    }


}


TicTacToe& TicTacToe::operator=(TicTacToe& b){//is a deep copy of the tictactoe

    if(this != &b){//deletes the list if there is something already existing
        TicTacNode* current;
        current = m_head;
        while(current != NULL){
            TicTacNode* next = current -> m_next;
            delete current;
            current = next;
        }
    }
    m_head = new TicTacNode;//copies over each node to the new lsit
    TicTacNode* parent = m_head;
    TicTacNode* child = b.m_head->m_next;
    while(child != NULL){
        parent -> m_next = new TicTacNode(child->m_board);
    }


    return *this;
}



TicTacNode* TicTacToe::getHead() const{
    return(m_head);//returns the head of the object
}
