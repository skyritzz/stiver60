#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert_at_back(Node* &tail,int data)
{
    
    Node*temp = new Node(data);// create new node
    tail->next = temp;//attaching new node with tail ka next
    tail = tail->next;// tail ko update kr dia new node jha bna hai
}

void print(Node* &head)
{
    Node * temp = head;
    while(temp!= NULL)
    {
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

//MAIN CODE
Node* solve(Node* &head, Node* &head1)
{
    Node *a = head;
    Node *b = head1;

    //IF EITHER OF THEM ARE EMPTY RETURN THE OTHER ONE
    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a->data > b->data) swap(a,b);// IF DATA OF LIST A IS GREATER THAN B , THEN SWAP THEM 

    Node * res = a;// FINAL ANS WILL BE IN RESULT 

    while( a!= NULL && b!= NULL) // WHILE EITHER OF THEM NOT REACH THE END OF LIST
    {
        Node* temp = NULL;// TEMP WILL POINT TO LIST A
        while(a!= NULL && a->data<= b->data)// WHILE A DOES NOT REACH NULL AND IT IS LESS THAN B 
        {
            temp = a; // POINT TEMP TO A
            a= a->next; // MOVE A FORWARD
        }
        temp->next = b; //CONNEC TEMP WITH B
        swap(a, b); // NOW A WILL BE GREATER THAN B SO SWAP THEM 
    }
    return res; 
    
}


int main()
{
    //TAKING INPUT
    Node* node1 = new Node(1);
    Node *head = node1; Node *tail = node1;
    insert_at_back(tail, 2);
    insert_at_back(tail, 3);
    print(head);

    Node* node2 = new Node(1);
    Node *head1 = node2; Node *tail1 = node2;
    insert_at_back(tail1, 3);
    insert_at_back(tail1, 4);
    print(head1);


  
    Node* op = solve(head, head1);
    print(op);

    return 0;
}