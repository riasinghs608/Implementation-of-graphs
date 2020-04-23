
#include <iostream>
using namespace std;

class graph
{
	int vertex [5][5];
	int no_ver;
	
	public:
		graph ()
		{
			no_ver = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					vertex[i][j] = 0;
				}
			}
		}
		
		void create()
		{
			cout << "\n\n\tCREATE\n\n";
			char ch;
			
			do
			{
				int num1,num2;
			
				cout << "Enter 1st vertex : ";
				cin >> num1;
				num1--;
				cout << "Enter 2nd vertex : ";
				cin >> num2;
				num2--;
				
				if (num1 > 5 || num2 > 5)
				{
					return;
				}
				
				if (vertex[num1][num2] == 0)
				{
					vertex[num1][num2] = 1;
					vertex[num2][num1] = 1;
					cout << "Edge created";
				}
				
				else
				{
					if (vertex[num1][num2] == 1 || vertex[num2][num1] == 1)
					{
						cout << "Edge already exists.";
					}
				}
				
				cout << "Do you want to continue? Y/N : ";
				cin >> ch;
			}while (ch == 'y' || ch == 'Y');
		}
		
		void display()
		{
			cout << "\n\n\tDISPLAY\n\n";
			
			cout << "\t0\t1\t2\t3\t4\n";
			
			for (int i = 0; i < 5; i++)
			{
				cout << i;
				for (int j = 0; j < 5; j++)
				{
					cout << "\t"<<vertex[i][j];
				}
				cout << "\n";
			}
		}
};

main()
{
	graph gh;
	int c;
	
	while (1)
	{
		cout << "\n\n1. Create\n2. Display\n3. Exit\nEnter your choice: ";
		cin >> c;
		
		switch (c)
		{
			case 1:
			{
				gh.create();
				break;
			}
			
			case 2:
			{
				gh.display();
				break;
			}
			
			case 3:
			{
				exit(0);
				break;
			}
			
			default:
			{
				
				cout << "Entered wrong choice.";
				break;
			}
		}
	}
}
