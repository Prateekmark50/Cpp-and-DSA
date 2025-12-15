#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int value){
            data = value;
            next = NULL;
        }
};

int main(){
    Node *Head, *Tail;
    Tail = Head = NULL;

    int arr[] = {2,4,6,8,10};
    // Insert the value at end
    for(int i = 0; i < 5; i++){
        // Linked List is empty
        if(Head == NULL){
            Head = new Node(arr[i]);
            Tail = Head;
        }
        // Linked List exists karti hai
        else{
            Tail->next = new Node(arr[i]);
            Tail = Tail->next;
        }
    }

    // Print the Linked List
    Node *temp;
    temp = Head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/*
Time Complextit :- O(n)
Space Complexity:- O(1)
*/ 

// We can write code in another way but above code has less time complexity. So we prefer above code.
// int main(){
//     Node *Head;
//     Head = NULL;

//     int arr[] = {2,4,6,8,10};
//     // Insert the value at end
//     for(int i = 0; i < 5; i++){
//         // Linked List is empty
//         if(Head == NULL){
//             Head = new Node(arr[i]);
//         }
//         // Linked List exists karti hai
//         else{
//             Node *Tail = Head;
//             while(Tail->next != NULL){
//                 Tail = Tail->next;
//             }
//             Tail->next = new Node(arr[i]);
//         }
//     }

//     // Print the Linked List
//     Node *temp;
//     temp = Head;

//     while(temp){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }