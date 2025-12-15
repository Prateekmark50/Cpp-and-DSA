/*
It is a linear data structure, in which insertion and deletion only allowed at the end, called the top of stack.
When we define a stack as an Abstrct data type, then we are only intersted in knowing the stack operation from user point of view(POV).
It simply mean, we are not intersted in knowing the details, we only intersted in what type of operation we can perform.
*/ 
#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int size;
    int top;

    public:

    bool flag;

    // Constructor
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int [s];
        flag = 1;
    }

    // Push
    void push(int value) {
        if (top == size-1) {
            cout << "Stack Overflow\n";
            return;
        }
        else {
            top++;
            arr[top] = value;
            cout << "Pushed " << value << " into the stack\n";
            flag = 0;
        }
    }

    // Pop
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
        }
        else {
            cout << "Popped " << arr[top] << " from the stack\n";
            top--;
            if (top == -1) {
                flag = 1;
            }
        }
    }

    // Peek
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        else {
            return arr[top];
        }
    }

    // IsEmpty
    bool IsEmpty() {
        // if (top == -1) {
        //     return 1;
        // }
        // else {
        //     return 0;
        // }
        // Instead we can directly write
        return top == -1;
    }

    // IsSize
    int IsSize() {
        return top + 1;
    }
};

int main() {
    Stack S(5);
    // S.push(5);
    // S.push(6);
    // S.push(8);
    // S.pop();
    // S.pop();
    // S.pop();
    // S.pop();
    // S.push(9);
    // S.push(10);
    // S.push(11);

    // cout << S.peek() << endl;
    // S.pop();
    // cout << S.peek() << endl;
    // cout << S.IsEmpty() << endl;
    // cout << S.IsSize() << endl;

    // S.push(-1);
    // cout << S.peek() << endl;

    int value = S.peek();
    if(S.flag == 0) {
        cout << value << endl;
    }
}