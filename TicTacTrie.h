/*****************************************
** File:    TicTacTrie.h
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file creates the trie tree to keep all of the unique moves of the
**   tic tac toe games. Also keeps track of all the wins/ties and how many nodes
**   are there.
**
**
***********************************************/
#ifndef TICTACTRIE_H_INCLUDED
#define TICTACTRIE_H_INCLUDED

#include "TicTacToe.h"
#include "TicTacNode.h"

class TicTacTrie
{
    public:

        //input:N/A
        //output:N/A
        //Descriptaion: initializes the variables for a tictactrie object
        TicTacTrie();

        //input:N/A
        //output:N/A
        //Descriptaion: deletes all the nodes of the tree to make sure that no memory leak has happened
        ~TicTacTrie();

        //input:N/A
        //output: the number of X wins
        //Descriptaion: gets the number of X wins
        int getXWins() const;

        //input:N/A
        //output: the number of O wins
        //Descriptaion: gets the number of O wins
        int getOWins() const;

        //input:N/A
        //output: the number of ties
        //Descriptaion: gets the number of ties
        int getDraws() const;

        //input:N/A
        //output:the size of the tree
        //Descriptaion: gets the size of the tree
        int getSize() const;

        //input:a tictactoe list
        //output:N/A
        //Descriptaion: adds the nodes to the tictactrie if the nodes are unique
        void addGame(TicTacToe t);

        //input: the root node of a trie
        //output:N/A
        //Descriptaion: it goes through and clears all of the root
        void trieClear(TicTacNode* root);

    private:
        int m_xWins;//the number of X wins
        int m_oWins;//the number of O wins
        int m_draws;//the number of draws
        int m_size;// the number of nodes in the trie tree
        TicTacNode* m_root;//the root of the trie tree


};

#endif // TICTACTRIE_H_INCLUDED
