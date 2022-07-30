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

Node* reverseLL(Node* &head)
{
     if(head == NULL || head->next == NULL)
            return head;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;
        while(curr!= NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
}


  bool isPalindrome(Node* head) {
        
        //edge case // only one node given
        if(head == NULL || head->next == NULL)
            return true;
        
        
        Node* slow = head;
        Node* fast = head;
        
        //find middle node
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //reverse  next of middle node
        slow->next  = reverseLL(slow->next);
        slow = slow->next; // move slow pointer one step
        
        Node* dummy = head;//dummy at head
        //move dummy and slow simultaneously as there data will be same if not then return false
        //till slow does not reaches end
        while(slow!= NULL) 
        {
            if(slow->data != dummy->data) return false;
            dummy = dummy->next;
            slow = slow->next;
        }
        
        return true;
    }


int main()
{
    Node* node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;//for single ele tail will also point at head
    insert_at_back(tail, 2);
    insert_at_back(tail, 3);
    insert_at_back(tail, 3);
    insert_at_back(tail, 2);
    insert_at_back(tail, 1);

    print(head);

    bool ans = isPalindrome(head);
    cout << "ans is " << ans; 


    return 0;
}