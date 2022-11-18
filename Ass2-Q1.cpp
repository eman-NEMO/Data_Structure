#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int max_size = 100;
template<class T>
class Stack {
private:
    // string name;
    struct Node {
        T data;
        Node* next;
    };
    Node* top;
public:
    Stack() {
        top = NULL;
    }
    void puch_(T element) {
        Node* newnode = new Node;
        newnode->data = element;
        newnode->next = top;
        top = newnode;
    }
    bool is_empty() {

        return top ==NULL;
    }
    void popp() {
        if (is_empty()) {
            cout << "stack is empty" << endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }

    }
    void popp(T &element) {
        if (is_empty()) {
            cout << "stack is empty" << endl;
        }
        else {
            element = top->data;
            Node* temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }

    }

    string getTOP() {
        if (is_empty()) {
            cout << "stack is empty" << endl;
        }
        else {
            // stack_top = top->data;
            return top->data;
        }
    }
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void print() {
        //print stack in order
        Node* temp;
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data << " ";

            // Assign temp link to temp
            temp = temp->next;
        }
    }
};
class simplifiy_stack {
private :
    Stack<string> S;
public:
    void PrintStack(Stack<string> S) {
        if(S.is_empty()) {
            cout << "/" ;
        }

        Stack<string> S1;
        while (!S.is_empty()) {

            S1.puch_(S.getTOP());
            S.popp();
            S1.puch_("/");

        }
        S1.print();

    }
    simplifiy_stack(string path) {
        for (int i = 0; i < path.length();) {
            if (path[i] != '/') {
                string check = "";

                while (i < path.length() && path[i] != '/') check+=path[i++];
                if(check == ".."){
                    if(S.size())
                        S.popp();

                }
                else if (check != ".") {
                    S.puch_(check);
                }
            }
            else ++i;
        }
        PrintStack(S);
        cout<<"\"";
        cout << endl;
    }
};
int main() {
    cout<<" test case   |  "<<"      path                    | "<<"simplified path"<<endl;
    cout<<"-------------|--------------------------------|-----------------------"<<endl;
    cout<<"test  case 1 | path = \"/a/./b/../../c/\" "<<"      | path= \"";
    simplifiy_stack("/a/./b/../../c/");
    cout<<"-------------|--------------------------------|-----------------------"<<endl;
    cout<<"test  case 2 | path = \"/a//b////c/d//././/..\" "<<"| path= \"";
    simplifiy_stack s("/a//b////c/d//././/..");
    cout<<"-------------|--------------------------------|-----------------------"<<endl;
    cout<<"test  case 3 | path = \"/a//b//c//////d\" "<<"      | path= \"";
    simplifiy_stack p("/a//b//c//////d");
    cout<<"-------------|--------------------------------|-----------------------"<<endl;
    cout<<"test  case 4 | path = \" /../../../../../a\" "<<"   | path= \"";
    simplifiy_stack l(" /../../../../../a");
    cout<<"-------------|--------------------------------|-----------------------"<<endl;
    cout<<"test  case 5 | path = \"//////////////\" "<<"       | path= \"";
    simplifiy_stack k("////////////");

}






