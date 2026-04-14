#include<iostream>
#include<vector>
#include<string>
using namespace std;
void displaymenu(){
	cout<<" TASK MANAGER "<<endl;
	cout<<"1. Add New Task" << endl;
	cout<<"2. View All Tasks"<<endl;
	cout<<"3. Remove a Task"<<endl;
	cout<<"4. Exit"<<endl;
	cout<<"Enter your choice: ";
}
int main()
{
	vector<string> tasks;
	int choice;
	string task;
	while (true) {
		displaymenu();
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			cout << "Enter the Task description: ";
			getline(cin, task);
			tasks.push_back(task);
			cout << "Task added SuccessFully!!" << endl;
		}
		else if (choice == 2) {
			cout << " YOUR TASKS " << endl;
			if (tasks.empty())
				cout << "Your list is Empty " << endl;
			else
				for (size_t i = 0; i < tasks.size(); i++)
					cout << i + 1 << ". " << tasks[i] << endl;
		}
		else if (choice == 3) {
			cout << "YOUR TASKS" << endl;
			if (tasks.empty())
				cout << "Your list is Empty " << endl;
			else {
				int index;
				cout << "Enter the Task number to remove: " << endl;
				cin >> index;
				if (index > 0 && index <= tasks.size()) {
					tasks.erase(tasks.begin() + index - 1);
					cout << "Task removed successfully!" << endl;
				}
				else
					cout << "Invalid Task number!" << endl;
			}
		}
		else if(choice==4){
			cout<<"Exiting the Task Manager. Goodbye!"<<endl;
			break;
		}
		else
			cout << "Invalid choice! Please try again." << endl;
     }
	return 0;
}