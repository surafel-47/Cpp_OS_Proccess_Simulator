#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string to_string(int value);
int howManyProccess = 0;

struct process {
  string proccessName;
  int brustTime;
};

process* generateProccess() {

  // Get Number of Proccesses
  do {
    cout << "Enter How Many Processes : ";
    cin >> howManyProccess;
  } while (howManyProccess <= 0);
  cout << "\n";

  // Getting Brust Time for each proccess
  process* Processes = new process[howManyProccess];
  for (int i = 0; i < howManyProccess; i++) {
    Processes[i].proccessName = "P" + to_string(i+1);
   	
   do{
      cout << "Enter Process "<<Processes[i].proccessName<<" Burst Time : ";
      cin >> Processes[i].brustTime;
   }while (Processes[i].brustTime <= 0);
   
  }
 cout << "\n-----------------------------------------\n\n";
 return Processes;
}

void SJF(process* processes, int numProcesses) {
    // loop through each process to sort them
    for (int i = 0; i < numProcesses; i++) {
        int shortestIndex = i; // assume the current process has the shortest burst time
        // loop through remaining processes to find the one with the shortest burst time
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[j].brustTime < processes[shortestIndex].brustTime) {
                shortestIndex = j;
            }
        }
        // swap the current process with the one with the shortest burst time
        process temp = processes[i];
        processes[i] = processes[shortestIndex];
        processes[shortestIndex] = temp;
    }
    
    // execute the processes in the order of their sorted burst times
  int currentTime = 0;
  int totalWatingTime=0;
  for (int i = 0; i < numProcesses; i++) {
  	totalWatingTime+=currentTime;
  	cout<<currentTime<<" __ ("<<processes[i].proccessName<<") __ "; 
    currentTime += processes[i].brustTime;
  }
  cout<< currentTime<<"\n\n\n\n";
  
  cout<<"Total Waiting Time :"<<totalWatingTime<<"\n";
  cout<<"Average Waiting Time : "<<(double)totalWatingTime/numProcesses<<"\n\n\n";
}
int main() {
 restart:	
 
//************************************************************** 
  cout<<"\t Shortest Job First Algo\n\n\n";
  process* Processes=generateProccess(); 
  SJF(Processes, howManyProccess);
//************************************************************** 
 
 system("pause");
 system("cls");
 goto restart;
}
//The time complexity of Shortest Job First is O(n^2), where n is the number of processes












string to_string(int value) {
  stringstream ss;
  ss << value;
  return ss.str();
}


