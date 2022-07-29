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


Node* solve(Node* &head, int n)
{
    Node* dummy  = new Node(0);
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;

    for(int i = 0; i<=n; i++)//moving fast pointer till n
    {
        fast = fast->next;
    }

while(fast!= NULL)//moving both slow and fast pointer till fast!= NULL
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow->next;
    slow->next = slow->next->next;//main delte happening here
    delete(temp);

    return dummy->next;

}

int main()
{

    Node* node1 = new Node(1);
    Node *head = node1; Node *tail = node1;
    insert_at_back(tail, 2);
    insert_at_back(tail, 3);
    insert_at_back(tail, 4);
    insert_at_back(tail, 5);
    print(head);

    int n = 5;
    Node* op = solve(head, n);
    print(op);




    return 0;
}