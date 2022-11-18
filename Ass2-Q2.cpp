#include "iostream"
#include "queue"
using namespace std;
//implementing queue using linked list
class Queue {
    struct node {
        int data;
        node *next;
    };
    node *front, *rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int data) {
        node *newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        if (front == NULL) {
            front = newnode;
            rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "queue is empty" << endl;
        } else {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //function get value by index
    int get(int index) {
        node *temp = front;
        int i = 0;
        while (i < index) {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    //get front value
    int getfront() {
        return front->data;
    }

    //get size of queue
    int size() {
        int count = 0;
        node *temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
class calculate {
    Queue q;
    int pos;
    int c=0;
    int k=0;
public:
    calculate(int n) {
        pos = n;

    }
    calculate(int arr[], int n, int pos) {
        this->pos = pos;
        for (int i = 0; i < n; i++) {
            q.enqueue(arr[i]);
        }
    }
    bool checck(){
        for (int i = 0; i < q.size(); ++i) {
            if(q.get(i)==1){
                k++;
            }
        }
        if(k==q.size()){
           return false;
        }
        else{
            return true;
        }
    }
    void Nemo(){
        int a = q.get(pos);
        if(q.get(0)!=1 ){
            do {
                for (int i = 0; i < q.size(); ++i) {
                    if (q.get(0) != 0) {
                        int x = q.getfront();
                        q.dequeue();
                        c++;
                        q.enqueue(x - 1);
                    }
                    if (q.get(0) == 0) {
                        int x = q.getfront();
                        q.dequeue();
                        q.enqueue(x);
                    }
                }
                a--;

            } while (a > 0);
            cout << c <<" "<<"seconds"<< endl;
        }
        else if(checck()==false){
            cout<<pos+1<<" "<<"seconds"<<endl;
        }
        else{
            cout<<1<<" "<<"second"<<endl;
        }
    }

};
int main() {

    cout<<"test case num|         input             |    time "<<endl;
    cout<<"-------------|---------------------------|----------- "<<endl;
    cout<<"test case 1"<<"  |   array ={2,3,2}  pos=2   |  ";
    int arr1[]={2,3,2}; int pos=2;
    calculate c(arr1,3,pos);
    c.Nemo();
    cout<<"=============|===========================|==========="<<endl;
    cout<<"test case 2"<<"  |   array ={5,1,1,1}  pos=0 |  ";
    int arr2[]={5,1,1,1,}; int pos2=0;
    calculate c1(arr2,4,pos2);
    c1.Nemo();
    cout<<"=============|===========================|==========="<<endl;
    cout<<"test case 3"<<"  |   array ={1,5,5}  pos=0   |  ";
    int arr3[]={1,5,5};int pos3=0;
    calculate c2(arr3,3,pos3);
    c2.Nemo();
    cout<<"=============|===========================|==========="<<endl;
    cout<<"test case 4"<<"  |   array ={1,1,1,1}  pos=2 |  ";
    int arr4[]={1,1,1,1};int pos4=2;
    calculate c3(arr4,4,pos4);
    c3.Nemo();
    cout<<"=============|===========================|==========="<<endl;
    cout<<"test case 5"<<"  |   array ={2,2,1}  pos=0   |  ";
    int arr5[]={2,2,1};int pos5=0;
    calculate c4(arr5,3,pos5);
    c4.Nemo();
}