#include "safety.hpp"
using namespace std;

int main() {
    int processes[numPro];
    for(int i = 0 ; i < numPro ; i++)
        processes[i] = i;


    ifstream table("matrix.txt", ios_base::in);
    if (!table) {
        std::cout << "Failed to open matrix.txt." << std::endl;
        return EXIT_FAILURE;
    }

    int max[numPro][numRe];
    int allocated[numPro][numRe];
    int available[numRe];


    for (int i = 0; i < numPro; ++i) {
    //get the allocation
        for (int j = 0; j < numRe; ++j) table >> allocated[i][j];
        for (int j = 0; j < numRe; ++j) table >> max[i][j];

     
        if (i == 0) for (int j = 0; j < numRe; ++j) table >> available[j];
    }

    //print allocated matrix,
    cout << "Allocated: " << endl;
    for (int i = 0; i < numPro; ++i){
        cout << "P" << i << ": " ;
        for (int j = 0; j < numRe; ++j) 
            cout << allocated[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    //print the max matrix
    cout << "Max: " << endl;
    for (int i = 0; i < numPro; ++i){
        cout << "P" << i << ": " ;
        for (int j = 0; j < numRe; ++j) 
            cout << max[i][j] << ' ';
        cout << "\n";
    }
    cout << endl;

    //print the avaiable resources
    cout << "Available: ";
    for (int i = 0; i < numRe; ++i) 
        cout << available[i] << ' ';
    cout << "\n" << endl;

    //Is the system in a safe state? and what is the safe seqeucne in case of the safe state. 
    checkSafe(processes, available, max, allocated);
    
}
  