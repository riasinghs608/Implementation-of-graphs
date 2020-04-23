#include <iostream>

using namespace std;
#define MAX 10


int visited[10];
int visited1[10];

class stack
{
	public:
		int item[MAX];
		int top;
		stack()
		{
			top=-1;
		}
		
		void push(int n)
		{
			item[++top]=n;
		}
			
		
		int pop()
		{
			return item[top--];
		}
			
		
		int isempty()
		{
			if(top==-1)
				return 1;
			else 
				return 0;
		}
		
		int isfull()
		{
			if(top==MAX)
				return 1;
			else
				return 0;
		}
};

class queue
{
	public:
		int front,rear;
		int q[MAX];
		
		queue()
		{
			front=rear=-1;
		}
		
		void insert(int n)
		{
			if(front==-1)
			{
				front++;
				q[front]=n;
				
			}
			
			if(rear==9)
			{
				printf("\nQueue overflow\n");
			}
			
			rear++;
			q[rear]=n;
			printf("\n%d has been inserted successfully\n",n);
		}
		
		int delete()
		{
			int i;
			if(front==-1&&rear==-1)
			{
				printf("\nQueue Underflow\n");
			}
			
			if(front!=-1&&front==rear)
			{
				i=q[front];
				front=-1;
				rear=-1;
				return i;
			}
			
			return q[front++];
		}
}

class Node
{
	public:
    int data;
    Node *next;
};
 
 
class List
{
	public:
    Node *listptr;
    Node *temp;
};
 

class Graph
{
  	public:
        int V;
        List* array; 
        stack s;
        queue qu;
        
        Graph(int n)
        {
            V = n;
            array = new List [V];		
            for (int i = 0; i < V; ++i)
            {
            	array[i].listptr = NULL; 
            	array[i].temp = NULL; 
            	visited[i]=0;
			}
                		
        }

       
        void create(int current, int nextnode)
        {	
        
          	Node *newnode = new Node;  
            newnode->data = nextnode ;
            newnode->next = NULL;
            if(array[current].listptr==NULL)
            {
            	array[current].listptr=array[current].temp=newnode;
            }
            else
            {
            	array[current].temp->next=newnode;
              	array[current].temp=array[current].temp->next;
            }
           
           
			newnode = new Node;
            newnode->data = current;
            newnode->next = NULL;

            if(array[nextnode].listptr==NULL)
            {
            	array[nextnode].listptr=array[nextnode].temp=newnode;
            }
            else
            {
            	array[nextnode].temp->next=newnode;
              	array[nextnode].temp=array[nextnode].temp->next;
            }	
        }
        
        void display()
        {
            for (int i=0;i<V;i++)
            {
                Node *temp = array[i].listptr;	
                cout<<"\nlist of vertex "<<i<<" ";
                while (temp)
                {
                    cout<<"-> "<<temp->data;
                    temp = temp->next;
                }
                cout<<"\n";
            }
        }
        
        void nonrecDFS(int n)
        {
        	visited[n]=1;
        	Node *temp=array[n].listptr;
        	cout<<"\nDFS  : "<<n;
        	s.push(n);
        	{
        		while(s.isempty()!=1)
        		{
        			for(temp=array[n].listptr;temp!=NULL;temp=temp->next)
        			{
        				if(visited[temp->data]!=1)
        				{
        					visited[temp->data]=1;
        					cout<<" "<<temp->data;
        					s.push(temp->data);
        					n=temp->data;
						}
					}
					n=s.pop();
				}
			}
        	
		}
		
		void nonrecBFS(int n)
		{
			visited1[n]=1
		}
};



main()
{
    int s,r;
	char ch;
    Graph g(5);
    
    cout<<"\nCreate Adjacency Linked list\n";
    do
    {
    	cout<<"\nStarting node : ";
	    cin>>s;
	    cout<<"\nConnection : ";
	    cin>>r;
	    g.create(s,r);
	    
	    cout<<"\nDo you want to continue?(Y/N) :: ";
	    cin>>ch;
	    
	}while(ch=='y'||ch=='Y');
    
 	g.display();
 	
 	g.nonrecDFS(0);
}
