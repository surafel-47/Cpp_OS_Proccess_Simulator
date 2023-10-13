#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string to_string(int value);
int howManyProccess = 0;
int quantum=0;
struct process {
  string proccessName;
  int brustTime;
};

process* generateProccess() {

  do {
    cout << "Enter How Many Processes : ";
    cin >> howManyProccess;
  } while (howManyProccess <= 0);
  do {
    cout << "Enter Quantum Unit : ";
    cin >> quantum;
  } while (quantum <= 0);
  cout << "\n\n";

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

void RR(process* processes, int numProcesses, int quantum) {
	
    int currentTime = 0;
    int completed = 0;
    
    while(completed!=numProcesses){
    	  for (int i = 0; i < numProcesses; i++) {
            if (processes[i].brustTime > 0) {
                if (processes[i].brustTime  <= quantum) {
                	cout << currentTime << " __ (" << processes[i].proccessName << ") __ ";
                    currentTime += processes[i].brustTime ;
                    processes[i].brustTime = 0;
                    completed++;
                } else {
                	cout << currentTime << " __ (" << processes[i].proccessName << ") __ ";
                    currentTime += quantum;
                    processes[i].brustTime  -= quantum;                  
                }
            }
        }
	}
    cout << currentTime << "\n\n";
}
int main() {
   restart:	
 
//************************************************************** 
  cout<<"\t	Rounding Robin Algo \n\n\n";
  process* Processes=generateProccess(); 
  RR(Processes, howManyProccess,quantum);
//************************************************************** 
 
 system("pause");
 system("cls");
 goto restart;
  
}

//The time complexity of Rounding Robin is O(n^2), where n is the number of processes

















string to_string(int value) {
  stringstream ss;
  ss << value;
  return ss.str();
}


