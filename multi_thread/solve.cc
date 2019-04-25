#include <unistd.h>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;
/**
 * Multi threading
 */

void sayhello(int threadid) {
  cout << "Hello world! Threadid: " << threadid << endl;
  this_thread::sleep_for(chrono::seconds(threadid));
  cout << "end threadid " << threadid << endl;
}

int main() {
  thread t1(sayhello, 0);
  thread t2(sayhello, 1);

  t1.join();
  t2.join();
}