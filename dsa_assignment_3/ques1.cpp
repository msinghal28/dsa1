#include <iostream>
using namespace std;

class stack{
	public:
	int maxlength=10;
	int arr[10];
	int top=-1;
	void display(){
		cout<<endl<<"Display:"<<endl;
	for(int i=top; i>=0;i--){
		cout<<endl<<arr[i];
	}
}
	void push(){
		int n;
		cout<<"enter number to push:";
		cin>>n;
		if (top==maxlength-1){
			cout<<"overflow";
		}
		else{
			top++;
			arr[top]=n;
		}
		
	}
	void pop(){
		if (top==-1){
			cout<<"underflow";
		}
		else{
			arr[top]=0;
			top--;
		}
		
	}	
	void isEmpty(){
		if(top==-1){
			cout<<"empty stack"<<endl;
		}
		else{cout<<"not empty"<<endl;
		}
			
	}
	void isFull(){
		if(top==maxlength-1){
			cout<<endl<<"Full stack";
		}
		else{cout<<endl<<"not full";
		}
			
	}
	void peek(){
		if (top==-1){
			cout<<"underflow"<<endl;
		}
		else{ cout<<endl<<arr[top]<<endl;
		}
	}
	void menu(){
		int key;
		int flag=1;
		while (flag){
		cout<<endl<<"enter 1 for push"<<endl;
        cout<<endl<<"2 for pop"<<endl;
        cout<<endl<<"3 for full"<<endl;
        cout<<endl<<"4 for isempty"<<endl;
        cout<<endl<<"5 for peek"<<endl;
        cout<<endl<<"6 for display"<<endl;
        cout<<endl<<"7 for exit"<<endl;
		cin>>key;
		switch(key){
			
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				isFull();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				peek();
				break;
			case 6:
				display();
				break;
			case 7:
				flag=0;
				break;
		}
	}
	}
};



int main(){
	stack s;
	s.menu();



}