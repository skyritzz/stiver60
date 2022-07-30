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

//utility function to create cycle
void createCycle(Node* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    Node* p1 = head;
    Node* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}

bool Iscycle(Node* &head)
{
    if(head == NULL || head->next == NULL)
    return false;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL || fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }

    }

    return false;

}



int main()
{
    Node* node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    
    insert_at_back(tail, 2);
    insert_at_back(tail, 3);
    insert_at_back(tail, 4);
    print(head);
    createCycle(head,1,3);
    

    if(Iscycle(head) == true)
    cout<<"Cycle detected\n";
    else
    cout<<"Cycle not detected\n";
    return 0;
}