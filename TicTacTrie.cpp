/*****************************************
** File:    TicTacTrie.cpp
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file does all the things stated in the header file
**
**
***********************************************/
#include "TicTacTrie.h"
#include "TicTacNode.h"

TicTacTrie::TicTacTrie(){
    m_root = new TicTacNode;//makes the root a node as to make it easier for my to think
    m_xWins = 0;//makes the xWins to 0
    m_oWins = 0;//makes the oWins to 0
    m_draws = 0;//makes the draws to 0
    m_size = 0;//makes the size to 0
}

TicTacTrie::~TicTacTrie(){
    trieClear(m_root);//calls the clear of the function to free all the nodes

}

void TicTacTrie::addGame(TicTacToe t){
    //TicTacNode* currentAdding =  t.m_head;
    TicTacNode* currentAdding =  t.getHead();
    TicTacNode* currentAddingInto =  m_root;
    if(m_size == 0){//if the size of the trie is 0 then all the nodes of t is added to the trie
        while(currentAdding != NULL){//goes all the way through t and add them to the trie
            *currentAddingInto = *currentAdding;
            currentAddingInto->m_children.insert(currentAddingInto->m_children.begin(), NULL);//create a new node in the vector and then
            currentAddingInto->m_children[0] = new TicTacNode;//sets the new nodes board to currentAdding's board
            currentAddingInto = currentAddingInto->m_children[0];

            m_size += 1;//increases size each time through
            if(currentAdding->m_next == NULL){//checks to see if the next node for t is NULL
                currentAdding = NULL;//if it is set is null then make currentAdding NULL
            }else{
                currentAdding = currentAdding->m_next;//if it is not NULL then is makes currentAdding to currentAdding's children
            }

        }
    }else{//if size is not 0 then it goes through trie and tries to find if any nodes is unique
        if(*currentAdding == *currentAddingInto and currentAdding->m_next != NULL){//checks to see if the heads equal the same and if the next is not null
            currentAdding = currentAdding ->m_next;
            while(currentAdding != NULL){//goes though each currentAdding's node
                bool isItThere = false;
                int index = 0;
                for(unsigned int i = 0; i < currentAddingInto->m_children.size(); i++){//checks to see if there currentAdding node equals any of the children nodes for the tie

                    if(*(currentAddingInto->m_children[i]) == *currentAdding){
                        isItThere = true;
                    }else if(isItThere == false){
                        index++;
                    }
                }


                if(isItThere == true){//if it was there then we move down that node for trie and move down the node for currentAdding
                    currentAddingInto = currentAddingInto->m_children[index];
                    currentAdding = currentAdding->m_next;
                }else{//if it was not then I add the node to the children list and go down a node for each object
                    index++;
                    currentAddingInto->m_children.push_back(NULL);
                    currentAddingInto->m_children.back() =  new TicTacNode;
                    currentAddingInto = currentAddingInto->m_children.back();
                    *currentAddingInto = *currentAdding;

                    currentAdding = currentAdding->m_next;
                    m_size++;
                }
            }
        }
    }

    if(t.getResults() == 1){//checks to see the results and adds the wins to the respective element
        m_xWins++;
    }else if(t.getResults() == 2){
        m_oWins++;
    }else if(t.getResults() == 3){
        m_draws++;
    }
}

void TicTacTrie::trieClear(TicTacNode* root){
    for(unsigned int i=0; i < root->m_children.size(); ++i){//goes through each children and has the leafs delete first and then goes on upwards for deleting
        trieClear(root->m_children[i]);
    }
    root->m_children.erase(root->m_children.begin(), root->m_children.end());
    root->m_board.clear();
    delete root;


}

//does what each function says for everything below
int TicTacTrie::getDraws() const{
    return(m_draws);
}

int TicTacTrie::getSize() const{
    return(m_size);
}

int TicTacTrie::getOWins() const{
    return(m_oWins);
}

int TicTacTrie::getXWins() const{
    return(m_xWins);
}
