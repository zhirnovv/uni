#include <iostream>
#include <string>

using namespace std;

struct Node{
    Node * prev;
    Node * next;
    int x;
    Node()
    {
      prev = nullptr; next = nullptr; x = 0;
    }

    Node(Node * a, Node * b, int c)
    {
      prev = a; next = b; x = c;
    }


};

struct deque{
        Node * Front = nullptr;
        Node * Back = nullptr;
        int Size = 0;

        int size(){
            return Size;
        }

        void push_back(int value)
        {
            if(Size == 0){
                Node * NewNode = new Node(Back,Front,value);
                Front = NewNode;
                Back = NewNode;
            }else{
                Node * NewNode = new Node(nullptr, Back, value);
                Back->prev = NewNode;
                Back = NewNode;
            }
            Size++;
        }
        void push_front(int value)
        {
            if(Size == 0){
                Node * NewNode = new Node(Back,Front,value);
                Front = NewNode;
                Back = NewNode;
            }else{
                Node * NewNode = new Node(Front, nullptr, value);
                Front->next = NewNode;
                Front = NewNode;
            }
            Size++;
        }
        int back()
        {
            if(Size != 0){
              return Back->x;
            }
            else{
              return 0;
            }
        }
        int front()
        {
            if(Size != 0){
              return Front->x;
            }
            else{
              return 0;
            }
        }
        int pop_front()
        {
            if(Size != 0){
                int x = Front->x;
                Node * NewNode = Front->prev;
                delete Front;
                Front = NewNode;
                Size--;
                return x;
            }else{
                return 0;
            }
        }
        int pop_back(){
            if(Size != 0){
                int x = Back->x;
                Node * NewNode = Back->next;
                delete Back;
                Back = NewNode;
                Size--;
                return x;
            }else{
                return 0;
            }
        }
        void clear(){
            while(Size > 0){
                Node * NewNode = Front->prev;
                delete Front;
                Front = NewNode;
                Size--;
            }
            Front = nullptr;
            Back = nullptr;
        }
};



int main() {
    deque D;
    string s;
    cin >> s;

    while(s != "exit")
    {
        if(s == "push_back"){
          int input;
          cin >> input;
          D.push_back(input);
          cout << "ok" << endl;
        }

        if(s == "push_front"){
            int input;
            cin >> input;
            D.push_front(input);
            cout << "ok" << endl;
        }

        if(s == "front"){
            if(D.size() == 0){
                cout << D.front() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }

        if(s == "back"){
            if(D.size() == 0){
                cout << D.back() << endl;
            }
            else{
                cout << "error" << endl;;
            }
        }

        if(s == "size"){
            cout << D.size() << endl;

        if(s == "pop_front"){
            if(D.size() == 0){
                cout << D.pop_front() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }

        if(s == "pop_back"){
            if(D.size() == 0){
                cout << D.pop_back() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if(s == "clear")
        {
            cout << "ok" << endl;
            D.clear();
        }
      }
    }
    cout << "bye" << endl;
    return 0;
}
