#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include <chrono>
#include <queue>

using namespace std;
string toString(int value) {
  stringstream ss;
  ss << value;
  return ss.str();
}


int counter=0;
int i=0, j=1;
int turn=i;
bool flag[2]={false,false};


queue <string> bufferQueue;

void Producer(){

  do{
	flag[i]=true;
	turn=j;
	while(flag[j] && turn==j);
		
		//critical section
			bufferQueue.push("P"+toString(counter));
			counter++;
		//exit critical section
	cout<<"Proccess P"<<counter-1<<" is Produced \n";
	this_thread::sleep_for(std::chrono::milliseconds(500));
  }while(true);
}


void Consumer(){

  do{
	flag[j]=true;
	turn=i;
	while(flag[i] && turn==i);
		string value;
		//critical section
		  if(!bufferQueue.empty()){
		  	value=bufferQueue.front();
		  	bufferQueue.pop();
		  }
		//exit critical section
	cout<<"   Proccess "<<value<<" is Consumed \n";
	this_thread::sleep_for(std::chrono::milliseconds(500));
  }while(true);
}



int main() {
  cout<<"***********************************************************************\n";
  cout<<"*\tProducer-Consumer Suimlation Using Thread and Queue Buffer    *\n";
  cout<<"***********************************************************************\n\n\n\n";
  
  thread producerThread(Producer);
  thread consumerThread(Consumer);
  
  producerThread.join();
  consumerThread.join();
  
}
















