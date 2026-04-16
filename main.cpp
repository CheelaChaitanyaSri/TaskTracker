#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
void displaymenu(){
	cout<<" TASK MANAGER "<<endl;
	cout<<"1. Add New Task" << endl;
	cout<<"2. View All Tasks"<<endl;
	cout<<"3. Remove a Task"<<endl;
	cout<<"4. Mark Task as Completed"<<endl;
	cout<<"5. Exit"<<endl;
	cout<<"Enter your choice: ";
}
struct Task{
    string title;
    bool completed;
};
int main()
{   
	vector<Task> tasks;
	//vector<string> tasks;
	int choice;
	string task;
	while (true) {
		displaymenu();
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			cout << "Enter the Task description: ";
			getline(cin, task);
			tasks.push_back({task,false});
			cout << "Task added SuccessFully!!" << endl;
		}
		else if (choice == 2) {
			cout << " YOUR TASKS " << endl;
			if (tasks.empty())
				cout << "Your list is Empty " << endl;
			else
				for (size_t i = 0; i < tasks.size(); i++)
					cout << i + 1 << ". " << tasks[i].title<<" ["<<(tasks[i].completed ? "Done" : "Pending")<<"]"<< endl;
		}
		else if (choice == 3) {
			cout << "YOUR TASKS" << endl;
			if (tasks.empty())
				cout << "Your list is Empty " << endl;
			else {
				cout<<"Select a task to remove:"<<endl;
				for (size_t i = 0; i< tasks.size();i++){
					cout<<i+1 <<". "<<tasks[i].title<<" ["<<(tasks[i].completed ? "Done" : "Pending") << "]"<<endl;
                }
				int index;
				cout << "Enter the Task number to remove: " << endl;
				cin >> index;
				cin.ignore();
				if (index > 0 && index <= tasks.size()) {
					string confirm;
					cout<<"Are you sure you want to delete this task? (yes/no):" <<endl;
					cin>>confirm;
					for(char &c:confirm){
						c=tolower(c);
					}
					if(confirm =="yes"){
					   tasks.erase(tasks.begin() + index - 1);
					   cout << "Task removed successfully!" << endl;
				    }
				    else
					cout << "Cannot Delete!" << endl;
		        }
				else
				cout << "Invalid Task number!" << endl;
			}
		}
		else if(choice==4){
			if(tasks.empty())
			cout<<"No tasks available" <<endl;
		    else {
				cout<<"Select a Task:\n";
				for(size_t i=0;i<tasks.size();i++){
					cout<<i+1 <<". "<<tasks[i].title<<" ["<<(tasks[i].completed ? "Done" :"Pending")<<"]"<<endl;
				}
				int index;
				cout<<"Enter task number: ";
				cin>> index;
				cin.ignore();
				if(index>0 && index<=tasks.size()){
					string confirm;
					cout<<"Mark this task as Completed ? (yes/no):";
					cin>> confirm;
					for(char &c:confirm){
						c=tolower(c);
					}
					if(tasks[index-1].completed){
						cout<<"Task is already Completed!"<<endl;
					}
					else{
					if(confirm == "yes"){
						tasks[index-1].completed=true;
						cout<<"Task marked as Completed!"<<endl;
					}
					else{
						cout<<"Cannot Mark!! Invalid"<<endl;
					}
				   }
				}
				else{
					cout<<"Invalid task Number!"<<endl;
				}
			}
		}
		else if(choice==5){
			cout<<"Exiting the Task Manager. Goodbye!"<<endl;
			break;
		}
		else
			cout << "Invalid choice! Please try again." << endl;
     }
	return 0;
}