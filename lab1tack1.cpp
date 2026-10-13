//This is a sample code of singliy link list

#include<iostream>
using namespace std;

struct Node {
    int data ;
    Node *next; 
    Node(int d) : data (d) , next (nullptr){}
};
Node *head = nullptr , *tail= nullptr;


void Inser_front(int key){
    Node *n = new Node(key);
    n->next = head;
    head = n;
    if (tail == nullptr) tail = n;
}


void Inser_back(int key) {
    Node *n = new Node(key);
    if (tail== nullptr ){head = tail = n;}
    else{ tail->next = n; tail = n; }    
}

void Insert_after_node(int key , int v){
    Node *cur = head; 
    while (cur && cur-> data != v){cur = cur->next;}
    if (!cur){cout << "value not found \n"; return;}
    Node *n = new Node(key);
    n->next = cur->next;
    cur->next = n ;
    if (cur==tail){tail = n;}
}

void Update_node(int key , int v){
    Node *cur = head ; 
    while (cur && cur->data !=v){cur=cur->next;}
    if (!cur){cout<< "Value not found"; return; }
    cur->data = key;
}

void Remove_head(){
    if (!head){cout<<"underflow\n " ; return;}
    Node *t = head;
    head = head->next;
    if (!head){tail = nullptr ;}
    delete t;
}

void Remove_elemnet(int key){
    Node *cur = head , *prev = nullptr; 
    while (cur && cur-> data != key){
        prev = cur;
        cur = cur->next;}
    if(!cur){cout<<"vakue not found"; return;}
    if (!prev){head=cur->next;}
    else {prev->next = cur->next;}
    if (cur == tail){tail = prev;}
    delete cur;
}


void Remove_end() {
    if (!head){head = tail = nullptr;}
    if (head == tail){ delete head; head = tail = nullptr; return;}
    Node *cur = head;
    while(cur->next != tail){
        cur = cur->next;}
    delete tail; 
    tail = cur; 
    tail->next = nullptr;
}

void Printlist(){
    if (!head){cout<<"head = null , tail = Null , Empty \n"; return;}
    cout <<"Head:- " << head->data << "Tail:- " << tail->data<< ", "; 
    for(Node *c = head ; c ; c = c->next){
        cout << c->data << (c->next ? " ": "");
    }
    cout<<"\n";
}


int main (){
    cout<<" Press 1 to insert at front\n";
    cout<<" Press 2 to insert at back \n ";
    cout<<" Press 3 to insert after a node \n";
    cout<<" Press 4 to update a node\n";
    cout<<" Press 5 to remove the first node\n ";
    cout<<" Press 6 to remove a node\n" ;
    cout<<" Press 7 to remove the last node\n";
    cout<<" Press 8 to exit\n";
    
    int opp = 0 , key , v;
    while (cin >> opp && opp != 8){

    switch(opp){
        case 1 : cin >> key; Inser_front(key); break;
        case 2 : cin >> key; Inser_back(key); break;
        case 3 : cin >> key >> v; Insert_after_node(key,v); break;
        case 4 : cin >> key >> v; Update_node(key,v); break;
        case 5: Remove_head(); break;
        case 6: cin >> key; Remove_elemnet(key); break;
        case 7: Remove_end(); break;
            default: continue;
    }
    Printlist();
 }
return 0 ;
}
