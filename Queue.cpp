#include <iostream>
#include <string>
#include<sstream>
using namespace std;

// create a class for grocery
class Grocery{
	public:
		int id;
		string name;
		string catagory;
		int price;
		string exp;
};

class Queue{
	public:
		Grocery data;
		Queue* next;

	//front of Queue
	Queue* front = NULL;

	//back of Queue
	Queue* rear = NULL;

	void enqueue(Grocery data){
		Queue* q = new Queue();

		q->data = data;

		if(front == NULL){
			front = rear = q;
			rear->next = NULL;
		}
		else{
			rear->next = q;
			rear = q;
			rear->next = NULL;
	 	}
    }

    void dequeue(){
    	if(front == NULL){
    		cout << "Queue is Empty" << endl;
		}
		else{
			Queue* p = front;
			front = front->next;
			delete(p);
		}
	}

	void first(){
		if(front != NULL){
		   cout << front->data.name <<endl;
     	}
     	else{
     		cout << "Queue is Empty";
		 }
	}

	void isEmpty(){
		if(front == NULL){
			cout << "It is Empty" << endl;
		}
		else{
			cout << "It is Not Empty" << endl;
		}
	}

	void makeNull(){
		front = rear = NULL;
	}

	void printQ(){
		Queue* itr = front;
		if(itr == NULL){
			cout << '\n';
			cout << "The Queue is Empty" << endl;
		}
		while(itr != NULL){
			cout << itr->data.name << endl;

			itr = itr->next;
		}
	}
};



// create linked list
class Node{
	public:
		Grocery data;
		Node* next;

		Queue q;

		// constructor that takes gorcery data
		Node(Grocery data){
			this->data = data;
			this->next = NULL;
		}
};

// insert into the list
// i take reference &head coz i want to change in original list
void insert(Grocery &g, Node* &head){
	Node* node = new Node(g);
	node->q.enqueue(g);
	if(head == NULL){
		head = node;
		return;
	}

	Node* itr = head;
	bool found = false;
	while(itr->next != NULL){
		if(itr->data.catagory == g.catagory)
		{
			itr->q.enqueue(g);
			found = true;
			break;
		}
		itr = itr->next;
	}
	if(!found){
		if(itr->data.catagory == g.catagory){
			itr->q.enqueue(g);
		}
		else{
		   itr->next = node;
	    }
    }
}

void deleteQ(Node* &head, string s){
	Node* itr = head;

	while(itr != NULL){
		if(itr->data.catagory == s){
			itr->q.dequeue();
			break;
		}
	itr = itr->next;
   }
}

isEmptyQ(Node* &head, string s3){
	Node* itr = head;

	while(itr != NULL){
		if(itr->data.catagory == s3){
			itr->q.isEmpty();
			break;
		}
		itr = itr->next;
	}
}

void makeNullQ(Node* &head, string s4){
	Node* itr = head;

	while(itr != NULL){
		if(itr->data.catagory == s4){
			itr->q.makeNull();
			break;
		}
		itr = itr->next;
	}
}

// for split the string
int* split(string str)
{
    string temp;

    string s[3];
    int j;
    for(int i=0;i<str.length();i++){
        if(str[i] != '/'){
            temp += str[i];
        }
        else{
          s[j] = temp;

          j++;
          temp = "";
        }
    }
    s[j] = temp;
    static int a[3];
    for(int i=0;i<3;i++){
    	stringstream strm(s[i]);
		int num;
		strm >> num;
		a[i] = num;
	}
    return a;
}

//count the number of itme in list from the catagory
void count(string c,string d, Node* &head){

    int* s = split(d);

    int dd = s[0];
    int mm = s[1];
    int yy = s[2];

	Node* itr = head;

	int count = 0;
	while(itr != NULL){
		if(itr->data.catagory == c){
			string s1 = itr->data.exp;
			int* temp = split(s1);

			int dd1 = temp[0];
		    int mm1 = temp[1];
		    int yy1 = temp[2];

		    if(yy1 < yy){
			    count++;
		    }
		    else if(yy1 == yy){
		    	if(mm1 < mm){
		    		count++;
				}
				else if(mm1 == mm){
					if(dd1 <= dd){
						count++;
					}
				}
			}
		itr = itr->next;
   }
   cout << "items: " << count << endl;
}
}

void insertItems(Node* &head){
		Grocery myGrocery;
		cout << "Type Id: ";
		cin >> myGrocery.id;
		cout << "Type name: ";
		cin >> myGrocery.name;
		cout << "Type catagory: ";
		cin >> myGrocery.catagory;
		cout << "Type price: ";
		cin >> myGrocery.price;
		cout << "Type exp: ";
		cin >> myGrocery.exp;

	    //insert into the queue
		insert(myGrocery, head);
}

void firstItem(Node* &head, string s2){
	Node* itr = head;

	while(itr != NULL){
		if(itr->data.catagory == s2){
			itr->q.first();
			break;
		}
	    itr = itr->next;
	}
}

//print method
void print(Node* &head){
	Node* itr = head;

	while(itr != NULL){

		cout << "Id: " << itr->data.id << endl;
		cout << "Name: "<< itr->data.name << endl;
		cout << "Catagory: "<< itr->data.catagory << endl;
		cout << "Price: "<< itr->data.price << endl;
		cout << "Exp: "<< itr->data.exp << endl;
		cout << "\n";
		cout << "Queue Items: " << endl;
		itr->q.printQ();
		cout << '\n';
		itr = itr->next;
	}
}


int main(){

	//head initially points to NULL
	Node* head = NULL;



     cout << "Choose an option..." << endl;
	 cout << '\n';
	 cout << " 1 : insert" << endl;
	 cout << '\n';
     cout << " 2 : Print List" << endl;
     cout << '\n';
     cout << " 3 : Delete an element from Queue" << endl;
     cout << '\n';
     cout << " 4 : First element" << endl;
     cout << '\n';
     cout << " 5 : check empty" << endl;
     cout << '\n';
     cout << " 6 : Count" << endl;
     cout << '\n';
     cout << " 7 : makeNULL" << endl;
     cout << '\n';
     cout << " 0 : exit" << endl;
     cout << '\n';
    int x;
    while(true){
    	 cin >> x;
	    switch (x) {
	    case 1:{
	        cout << "Insert items " << endl;
	        insertItems(head);
	        break;
	    }
	    case 2:{
	        cout << "Printing the items in List " << endl;
	        print(head);
	        break;
	    }
	    case 3:{
	        string s1;
	        cout<< "Type the catagory name: " << endl;
	        cin >> s1;
	        deleteQ(head, s1);
	        break;
	    }
	    case 4:{
	    	cout << "Type which category you want to check first" << endl;
	    	string s2;
	    	cin >> s2;
            cout << "The first element in " << s2 << "Queue: " << endl;
            firstItem(head, s2);
	        break;
	    }
	    case 5:{
	    	string s3;
	    	cout << "type which category you want to check empty or not" << endl;
	    	cin >> s3;
	    	isEmptyQ(head,s3);
	        break;
	    }
	    case 6:{
	    	string mn;
	    	string date;
	    	cout << "type the catagory name and date " << endl;
			cin >> mn;
			cin >> date;
			count(mn, date, head);
	    	break;
	    }
	    case 7:{
	    	string s4;
	    	cout << "Type which one you make NULL: " << endl;
	    	cin >> s4;
	    	makeNullQ(head, s4);
	    	break;
	    }
	    default:
	        exit(false);
	        break;

}
}
}

