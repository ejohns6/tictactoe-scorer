/**************************************************************
** File:    Driver.cpp
** Project: CMSC 341 Project 2, Spring 2016
** Author:  Erich Johnson
** Date:    3/22/16
** Section: 03
** E-mail:  ejohns6@umbc.edu
**
**   This file is the driver for taking in a input file name which is the list of the files with the saves
**   and then reads through each save and then compines them all together to create a big trie tree with all the wanted info
**
**************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "TicTacTrie.h"
#include "TicTacToe.h"

using namespace std;

int main(int argc, char* argv[])
{
   if(argc != 2){//checks to see if argument is there or not
    cout << "wrong number of arguments!" << endl;
    return(0);
   }
    ifstream testFileNames(argv[1]);
    if(!testFileNames){//checks to see if the line
      cout << "No file name" << endl;  
      return(0);
    }
    string line;
    vector<string> fileNames;
    TicTacTrie recoredGames;

    while (getline(testFileNames, line)){//goes through each line and then later pushes the file name into a list that was made

        if(line != "\n"){
            fileNames.push_back(line);
        }
    }
    testFileNames.close();

    for(unsigned int i=0; i<fileNames.size(); ++i){
        TicTacToe recordedGame;

        recordedGame.readGame(fileNames[i]);
        std::cout << "====================" << std::endl;//prints what it is reading
        std::cout << "Reading: " << fileNames[i] << std::endl;
        std::cout << "====================" << std::endl;
        if(recordedGame.getResults() == 1){//will print out the last board if the game is over and then says the results and the final board

            std::cout << "Player X Won!" << std::endl;
            TicTacNode* toBePrinted = recordedGame.getHead();
            while(toBePrinted ->m_next != NULL){
                toBePrinted = toBePrinted -> m_next;
            }
            std::cout << *(toBePrinted) << std::endl;
        }else if(recordedGame.getResults() == 2){
            std::cout << "Player O Won!" << std::endl;
            TicTacNode* toBePrinted = recordedGame.getHead();
            while(toBePrinted ->m_next != NULL){
                toBePrinted = toBePrinted -> m_next;
            }
            std::cout << *(toBePrinted) << std::endl;
        }else if(recordedGame.getResults() == 3){
            std::cout << "The game was a draw!" << std::endl;
            TicTacNode* toBePrinted = recordedGame.getHead();
            while(toBePrinted ->m_next != NULL){
                toBePrinted = toBePrinted -> m_next;
            }
            std::cout << *(toBePrinted) << std::endl;
        }






        recoredGames.addGame(recordedGame);//adds the game to the trie
        recordedGame.toeClear();//is a manual deletion since if I put in the deconstructor than it is called once when leaving addGame and once when iterating through the for loop
    }

    std::cout << "Final Trie Statistics" << std::endl;//prints out the final trie statistics
    std::cout << "====================" << std::endl;
    std::cout << "Player X Wins: " << recoredGames.getXWins() << std::endl;
    std::cout << "Player O Wins: " << recoredGames.getOWins() << std::endl;
    std::cout << "Draws: " << recoredGames.getDraws() << std::endl;
    std::cout << "True Size:      " << recoredGames.getSize() << std::endl;

}
