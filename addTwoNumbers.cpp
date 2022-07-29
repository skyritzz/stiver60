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

Node* solve(Node* &head, Node* &head1)
{
    Node* a = head;
    Node* b = head1;

    Node* dummy = new Node(0);
    Node* temp = dummy;

    int carry = 0;
    while(a!= NULL || b!= NULL || carry!= 0)
    {

        int sum  = 0;
        if(a != NULL)
        {
            sum += a->data;
            a = a->next;
        }

        if(b != NULL)
        {
            sum += b->data;
            b = b->next;
        }

        sum += carry;
        carry = sum/10;

        //answer list
        Node* node = new Node(sum%10);
        temp->next = node;
        temp = temp->next;

    }
    return dummy->next;

}

int main()
{
     //TAKING INPUT
    Node* node1 = new Node(2);
    Node *head = node1; Node *tail = node1;
    insert_at_back(tail, 3);
    insert_at_back(tail, 4);
    print(head);

    Node* node2 = new Node(5);
    Node *head1 = node2; Node *tail1 = node2;
    insert_at_back(tail1, 6);
    insert_at_back(tail1, 7);
    print(head1);

    //returning answer
    Node* op = solve(head, head1);
    print(op);
 
    return 0;
}



// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.