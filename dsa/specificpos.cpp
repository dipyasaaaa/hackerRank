//The first line contains an integer n, the number of elements in the linked list.
//Each of the next  lines contains an integer SinglyLinkedListNode[i].data.
//The next line contains an integer data , the data of the node that is to be inserted.
//The last line contains an integer position .
#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

//from here my funtion 

int size(SinglyLinkedListNode* llist) {
    int count=0;
    SinglyLinkedListNode* temp= llist;
    while(temp!=NULL){
        count++;
        temp=temp->next;
        
    }
    return count;
}
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    int length=size(llist);
    if(position==1){
        if(llist==NULL){
            llist= newNode;
        }
        else{
            newNode->next= llist;
            llist=newNode;
        }
    }
    else if(position==length+1){
        if(llist==NULL){
            llist= newNode;
        }
        else{
            SinglyLinkedListNode* temp= llist;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    else{
        SinglyLinkedListNode* cur=llist;
        SinglyLinkedListNode* prev=NULL;
        while(position!=0){
            prev=cur;
            cur=cur->next;
            position--;
        }
        prev->next=newNode;
        newNode->next=cur;
    }
    
return llist;  

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ", fout);
    fout << "\n";

    free_singly_linked_list(llist_head);

    fout.close();

    return 0;
}
