#include <iostream>
#include <string>

using namespace std;

struct Deque{

    Deque (int _size = 20000){
      dequeSize = _size;
      head = 10000;
      tail = 10000;
      deque = new int [dequeSize];
    }

    ~Deque (){
      delete [] deque;
    }


    void resize(){
      int new_size = dequeSize*2;
      int * new_deque;
      new_deque = new int[new_size];
      for (int i=0; i < dequeSize; i++){
        new_deque[i] = deque[i];
      }
      delete [] deque;
      deque = new_deque;
      dequeSize = new_size;
    }


    void push_front(int element){
      if(head <= 0){
        resize();
      }
      deque[head--] = element;
    }

    void push_back(int element){
      if (tail + 1 == dequeSize){
        resize();
      }
      deque[tail++] = element;
    }

    void pop_front(){
        if (head == tail){
            cout << "error" << endl;
        } else {
            cout << deque[head+1] << endl;
            head++;
        }
    }

    void pop_back(){
        if (head == tail){
            cout << "error" << endl;
        } else {
            cout << deque[tail-1] << endl;
            tail--;
        }
    }

    void front(){
        if (head == tail){
            cout << "error" << endl;
        } else {
            cout << deque[head+1] << endl;
        }
    }

    void back(){
        if (head == tail){
            cout << "error" << endl;
        } else {
            cout << deque[tail-1] << endl;
        }
    }

    void size(){
      if(head != tail)
        cout << tail-head << endl;
      else cout << '0' << endl;
    }

    void clear(){
      while (tail > head) {
        deque[tail] = 0;
        tail--;
      }
      cout << "ok" << endl;
    }

    void show(){
      for(int i = head; i <= tail; i++)
        cout << deque[i] << ' ';
    }

    int * deque;
    int dequeSize;
    int head;
    int tail;
};

int main(){
    Deque d;//создание стека
    string input;//ввод
    cin >> input;

    while(input != "exit"){
      if(input == "push_back"){//пуш, следующее число считывается с помощью cin
        int pushValue;
        cin >> pushValue;
        d.push_back(pushValue);
        cout << "ok" << endl;
      }
      if(input == "push_front"){//пуш, следующее число считывается с помощью cin
        int pushValue;
        cin >> pushValue;
        d.push_front(pushValue);
        cout << "ok" << endl;
      }
      if(input == "pop_front"){//поп
        d.pop_front();
      }
      if(input == "pop_back"){//поп
        d.pop_back();
      }
      if(input == "front"){//последний элемент
        d.front();
      }
      if(input == "back"){//последний элемент
        d.back();
      }
      if(input == "size"){//вывод размера
        d.size();
      }
      if(input == "clear"){//чистка стека
        d.clear();
      }
      cin >> input;
    }
    cout << "bye" << endl;
    return 0;
}
 
