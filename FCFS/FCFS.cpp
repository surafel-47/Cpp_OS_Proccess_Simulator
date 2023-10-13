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


void FCFS(process* processes, int numProcesses) {
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
  cout<<"\tFirst Come First Serve Algo\n\n\n";
  process* Processes=generateProccess(); 
  FCFS(Processes, howManyProccess);
//************************************************************** 
 
 system("pause");
 system("cls");
 goto restart;
}


//The time complexity of FCFS is O(n), where n is the number of processes












string to_string(int value) {
  stringstream ss;
  ss << value;
  return ss.str();
}


