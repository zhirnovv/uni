#include <iostream>
#include <string>
using namespace std;

struct Stack
{
  int * stack;
  int top;
  int length;
  void resize();
  void push();
  void pop();
  void back();
  void size();
  void clear();
};
Stack::Stack()
{
  length = 1;
  stack = new int[length];
  top = 0;
}

Stack::~Stack()
{
  delete [] stack;
}

void Stack::resize()
{
  int new_length = length * 2;//doubling the size

  int * new_stack;
  new_stack = new int [new_length]; //creating a new stack
  for (size_t i = 0; i < size; i++) {
    new_stack[i] = stack[i]; //copying the stack
  }

  delete [] stack; //deleting the old stack

  stack = new_stack;
  length = new_length;//new stack becomes a default
}


void Stack::push(int value)//value to push in
{
  if(top + 1 == resize)
    resize();//resize if stack is full
  stack[top+1] = value;//pushing the value
  cout << "ok";
}

void Stack::pop()
{
  if(top <= 0){
    cout << "error";
  }
  else top--;
}

void Stack::size()
{
  return top+1;
}

int Stack::back()
{
  if(top <= 0){
    cout << "error";
  }
  else return stack[top];
}

void Stack::clear()
{
  for(int i = top; i >= 0; i--)
    stack[i] = 0;
  cout << "ok" << endl;
}

int main()
{
  stack stek;
  string input;
  cin >> input;
  switch (input) {
    case "push":  int n;
                  cin >> n;
                  stek.push(n);
                  cin >> input;
    case "pop":  stek.pop();
                 cin >> input;
    case "back":  stek.back();
                  cin >> input;
    case "size": stek.size();
                 cin >> input;
    case "clear": stek.clear();
                  cin >> input;
    case "exit": cout << "bye";
                 return 0;
  }

}
