#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string to_string(int value);
int howManyProccess = 0;

struct process {
  string proccessName;
  int brustTime;
  int Priority;
};

process* generateProccess() {

  // Get Number of Proccesses
  do {
    cout << "Enter How Many Processes : ";
    cin >> howManyProccess;
  } while (howManyProccess <= 0);
  cout << "\n";

  // Getting Brust Time and Priority for each proccess
  process* Processes = new process[howManyProccess];
  for (int i = 0; i < howManyProccess; i++) {
    Processes[i].proccessName = "P" + to_string(i+1);
   	
   do{
      cout << "Enter Process "<<Processes[i].proccessName<<" Burst Time : ";
      cin >> Processes[i].brustTime;
   }while (Processes[i].brustTime <=0);
   
   do{
      cout << "Enter Process "<<Processes[i].proccessName<<" Priority : ";
      cin >> Processes[i].Priority;
   }while (Processes[i].Priority<0);
   
   cout<<"\n";
  }
 cout << "\n-----------------------------------------\n\n";
 return Processes;
}

void PS(process* processes, int numProcesses) {
    // loop through each process to sort them
    for (int i = 0; i < numProcesses; i++) {
        int higherPriority = i; // assume the current process has the higher Priority
        // loop through remaining processes to find the one with the higher Priority
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[j].Priority < processes[higherPriority].Priority) {
                higherPriority = j;
            }
        }
        // swap the current process with the one with higher Priority
        process temp = processes[i];
        processes[i] = processes[higherPriority];
        processes[higherPriority] = temp;
    }
    
    // execute the processes in the order of their sorted Priority
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
  cout<<"\t Priority Scheduling  Algo\n\n\n";
  process* Processes=generateProccess(); 
  PS(Processes, howManyProccess);
//************************************************************** 
 
 system("pause");
 system("cls");
 goto restart;
}


//The time complexity of Priority Scheduling  is O(n^2), where n is the number of processes









string to_string(int value) {
  stringstream ss;
  ss << value;
  return ss.str();
}


