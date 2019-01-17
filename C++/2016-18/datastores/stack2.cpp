#include <iostream>
#include <string>
using namespace std;

struct Stack{

    Stack (int _size = 2){
        stackSize = _size;
        topIndex = 0;
        stack = new int [stackSize];
    }

    ~Stack (){
        delete [] stack;
    }


    void resize(){
        int new_size = stackSize*2;
        int * new_stack;
        new_stack = new int[new_size];
        for (int i=0; i < stackSize; i++){
            new_stack[i] = stack[i];
        }
        delete [] stack;
        stack = new_stack;
        stackSize = new_size;
    }


    void push(int element){
        if (topIndex + 1 == stackSize){
            resize();
        }
        stack[topIndex++] = element;
    }

    void pop(){
        if ( topIndex <= 0 ){
            cout << "error" << endl;
        } else {
            cout << stack[topIndex-1]; 
            --topIndex;
        }
    }

    void back(){
        if ( topIndex <= 0 ){
            cout << "error" << endl;;

        } else {
            cout << stack[topIndex-1] << endl;
        }
    }

    void size(){
      if(topIndex >= 0)
        cout << topIndex << endl;
    }

    void clear(){
      while (topIndex > 0) {
        stack[topIndex-1] = 0;
        topIndex--;
      }
      cout << "ok" << endl;
    }

    int * stack;
    int stackSize;
    int topIndex;
};

int main(){
    Stack stk;//создание стека
    string input;//ввод
    cin >> input;

    while(input != "exit"){
      if(input == "push"){//пуш, следующее число считывается с помощью cin
        int pushValue;
        cin >> pushValue;
        stk.push(pushValue);
        cout << "ok" << endl;
      }
      if(input == "pop"){//поп
        stk.pop();
      }
      if(input == "back"){//последний элемент
        stk.back();
      }
      if(input == "size"){//вывод размера
        stk.size();
      }
      if(input == "clear"){//чистка стека
        stk.clear();
      }
      cin >> input;
    }
    cout << "bye" << endl;
    return 0;
}
