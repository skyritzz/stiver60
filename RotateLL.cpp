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


Node* solve(Node* &head, int k)
{
    if(!head || !head->next || k == 0)
    return NULL;

    Node* curr = head;
    int len = 1;
    while(curr->next && ++len)
    {
        curr = curr->next;
    }

    curr->next = head;

    k = k%len;
    k = len-k;

    while(k--)
    {
        curr= curr->next;
    }
    
    head = curr->next;
    curr->next = NULL;

    return head;

}


int main()
{
    Node* node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;//for single ele tail will also point at head

    
    insert_at_back(tail, 2);
    insert_at_back(tail, 3);
    insert_at_back(tail, 4);
    insert_at_back(tail, 5);
    insert_at_back(tail, 6);
    print(head);


    int k;
    cout << "enter k " ;
    cin >> k;

    Node* op = solve(head, k);
    print(head);



    return 0;
}