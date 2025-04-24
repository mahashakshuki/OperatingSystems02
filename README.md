# OperatingSystems02
Assignment 2 : Banker Algorithm for deadlock avoidance 

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken: 

<img width="468" alt="Picture1" src="https://github.com/user-attachments/assets/f27f60d6-5a20-4ebf-853b-b21252c23582" />

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

Explanation : 

This code exports the specified resource allocation table to a text file named matrix.txt, preserving the original tabular structure. The primary implementation of the Banker's Algorithm is contained within safety.cpp, while banker.cpp is responsible for invoking and managing its execution. 

Compilation process using the following commands: 

g++ banker.cpp -pthread -o banker

./banker 


