
#ifndef SAFETY_HPP_
#define SAFETY_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


//details on number of processes and resources and check for safety for the banker algorithim

const int numPro = 5; // # of processes
const int numRe = 3; //# of resources


bool checkSafe(int processes[], int available[], int max[][numRe], int allocated[][numRe]) 
{

    int need[numPro][numRe]; 
    for (int i = 0 ; i < numPro ; i++) 
        for (int j = 0 ; j < numRe ; j++) 
            need[i][j] = max[i][j] - allocated[i][j];
    
  
    bool done[numPro] = {0}; //keep track of which processes runs
    int sequence[numPro]; //sequence of processes if safe

    int work[numRe];
    for (int i = 0; i < numRe; i++) 
        work[i] = available[i];
  
    int completed = 0; //# of completed process
    while (completed < numPro) {

        bool found = false;
        for (int p = 0; p < numPro; p++) {
            if (done[p] == 0) { // if process has not run
                int j = 0;
                for (j = 0; j < numRe; j++) 
                    if (need[p][j] > work[j]) 
                        break;
                
                if (j == numRe) {//process p has run
                    for (int k = 0 ; k < numRe; k++) 
                        work[k] += allocated[p][k]; //add allocated back to avaiable amount
  
                    sequence[completed++] = p;
                    done[p] = 1; 
                    found = true;
                }
            }
        }
  
        if (!found) { //no next process to run
            cout << "The system is not in a safe state." << endl;
            return false;
        }
    }
  
    cout << "The system is in safe state. Safe sequence is: ";
    for (int i = 0; i < numPro ; i++) 
        cout << sequence[i] << ' ';
    cout << endl;
  
    return true;
}

#endif