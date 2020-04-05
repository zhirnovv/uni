#include <climits>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Queue {
  int *queue;
  int queueSize;
  int head;
  int tail;
  int minimum;

  Queue(int _size = 2) {
    queueSize = _size;
    head = 0;
    tail = 0;
    minimum = INT_MAX;
    queue = new int[queueSize];
  }

  ~Queue() { delete[] queue; }

  void resize() {
    int new_size = queueSize * 2;

    int *new_queue;
    new_queue = new int[new_size];

    for (int i = 0; i < queueSize; i++) {
      new_queue[i] = queue[i];
    }

    delete[] queue;
    queue = new_queue;
    queueSize = new_size;
  }

  void push(int element) {
    // if queue is full, resize
    if (tail + 1 == queueSize) {
      resize();
    }

    // enqueue, then shift tail by 1
    queue[tail++] = element;

    // update minimum in case a new, smaller, number is introduced into the
    // queue
    if (element < minimum) {
      minimum = element;
    }
  }

  void pull() {
    if (head == tail) {
      cout << "Error: queue is empty." << endl;
    } else {
      head++;
      if (head == tail) {
        minimum = INT_MAX;
      } else {
        for (int i = head; i < tail; i++)
          if (queue[i] < minimum)
            minimum = queue[i];
      }
    }
  }

  int min() {
    if (head == tail) {
      cout << "Error: queue is empty." << endl;
      return INT_MAX;
    }
    return minimum;
  }
};

int main() {
  Queue q;
  ifstream inFile("in.txt");
  ofstream outFile("out.txt");

  string command;

  if (!inFile.good()) {
    cout << "Error: failed to read file.";
    return 0;
  }

  while (inFile >> command) {
    switch (command[0]) {
    case '+':
      q.push(stoi(command.substr(1)));
      break;
    case '-':
      q.pull();
      break;
    case '?':
      outFile << q.min() << ' ';
      break;
    default:
      cout << "Error: invalid command";
    }
  }

  return 0;
}
