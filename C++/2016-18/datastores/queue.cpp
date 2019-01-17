#include <iostream>
#include <string>

using namespace std;

struct Queue{

    Queue (int _size = 2){
        queueSize = _size;
        head = 0;
        tail = 0;
        queue = new int [queueSize];
    }

    ~Queue (){
        delete [] queue;
    }


    void resize(){
        int new_size = queueSize*2;
        int * new_queue;
        new_queue = new int[new_size];
        for (int i=0; i < queueSize; i++){
            new_queue[i] = queue[i];
        }
        delete [] queue;
        queue = new_queue;
        queueSize = new_size;
    }


    void push(int element){
        if (tail + 1 == queueSize){
            resize();
        }
        queue[tail++] = element;
    }
    
    void pop(){
        if (head == tail){
            cout << "error" << endl;
        } else {
            cout << queue[head] << endl;
            head++;
        }
    }

    void front(){
        if (head == tail){
            cout << "error" << endl;;
        } else {
            cout << queue[head] << endl;
        }
    }

    void size(){
      if(head != tail)
        cout << tail-head << endl;
      else cout << '0' << endl;
    }

    void clear(){
      while (tail > head) {
        queue[tail] = 0;
        tail--;
      }
      cout << "ok" << endl;
    }

    int * queue;
    int queueSize;
    int head;
    int tail;
};

int main(){
    Queue q;//создание стека
    string input;//ввод
    cin >> input;

    while(input != "exit"){
      if(input == "push"){//пуш, следующее число считывается с помощью cin
        int pushValue;
        cin >> pushValue;
        q.push(pushValue);
        cout << "ok" << endl;
      }
      if(input == "pop"){//поп
        q.pop();
      }
      if(input == "front"){//последний элемент
        q.front();
      }
      if(input == "size"){//вывод размера
        q.size();
      }
      if(input == "clear"){//чистка стека
        q.clear();
      }
      cin >> input;
    }
    cout << "bye" << endl;
    return 0;
}
