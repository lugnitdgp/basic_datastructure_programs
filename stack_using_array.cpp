#include<iostream>
using namespace std;

int stack[100001];
int top=0;//Top is a variable which indicates the index of the stack at a particular instant

void push(int x)
{
	if(top==100001)//Conditon to check if the stack is full
	{
		cout<<"\nOverflow";
	}
	else
	{
		stack[top++]=x;//Inserts the element in the stack
	}
}

void popempty
	if (top==0)//Conditon to check if the stack is empty
	{
		cout<<"\nUnderflow";
	}
	else
	{
		cout<<"\n"<<stack[--top]<<" deleted";//Deletion operation performed
	}
}

void show()
{
	for (int i = 0; i < top; i++)
	{
		cout<<stack[i]<<"\n";//Displays the contents of the stack
	}
}

void topmost()
{
    cout << "\nTopmost element: "<<stack[top-1];//Prints the topmost element
}
int main()
{
	int ch, x;
	do
	{
		cout<<"\n1. Push";
		cout<<"\n2. Pop";
		cout<<"\n3. Print";
         	cout<<"\n4. Print topmost element:";
		cout<<"\n5. Quit:";
       		cout<<"\nEnter Your Choice : ";
		cin>>ch;
		if (ch==1)
		{
			cout<<"\nInsert : ";
			cin>>x;
			push(x);
		}
		else if (ch==2)
		{
			pop();
		}
		else if (ch==3)
		{
			show();
		}
       		 else if(ch==4)
		{
		       topmost();
		}
		else if(ch==5)
		{
		 	break;
		}
	}while(ch!=0);

	return 0;
}

