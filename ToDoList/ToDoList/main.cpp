/*  PROJECT TO-DO LIST: SAVE PROGRESS UPDATE
	NEW FEATURES:
	-> You can save current progress through a text file
	-> You can load progress in the add task menu
	-> all task must limit to nine slots (It avoids storage overload)
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

void UI() {
    cout << "\t  TO-DO-LIST \n "    <<
        "\tSelect option: \n\n" <<
        "\t(1) add task \n"     <<
        "\t(2) edit task \n"     <<
        "\t(3) complete task \n"<<
        "\t(4) save progress \n"<<
        "\n\tPress a number...";    
}

void view(vector<string> arr) {    
    cout << "\n"; 
    for(int i = 0; i < arr.size(); i++) cout << "\n\t[ ] "<< i + 1 <<". " << arr[i];
    cout << "\n"; 
}

void e() {
    cout << "\n     ---INVALID CREDENTIALS---"; getch();    
}

void save(vector<string> arr) {
	ofstream out("database.dat");
	for (int i = 0; i < arr.size(); i++) {
		out << arr[i] << "\n";
	}
	cout << "\n\tProgress saved! Press any key to continue..."; getch();
	out.close();
}

int main() {

    vector<string> arr;
    
    bool run = true;
    while (run){
        UI();
        view(arr);
        
        char key = _getch();
        string name, b;
        if(key == '1'){ //ADD TASK
        	cout << "\n\tSelect option: \n" <<
        		    "\t1 -> Manual \n" <<
        		    "\t2 -> Save file \n"<<
        		    "\tPlease press a number...";
            char choice = _getch();
        	switch (choice) {
        		case '1': { // MANUAL
        			system("cls");
        			cout<<"\n\tIt should have at least nine slots. Press \'*\' to stop adding tasks\n";
		            while(name != "*"){
		                cout << "\tEnter task name:";
		                getline(cin, name);
		                if (name != "*" && name != "" && arr.size() < 9) { arr.push_back(name); } 
						else { 
							e(); 
							break;
						}               
		            }; 
		            system("cls");
					break;
				}
		        case '2': { // FROM SAVE
		        	arr.clear();
		        	ifstream in("database.dat");
					while (getline (in, b) && arr.size() < 9) arr.push_back(b); 
		        	cout << "\n\tSave generated. Press any key to continue..."; getch(); system("cls");		        	
		        	break;
		    	}
		        default: 
		        	e();
		        	system("cls");
		        	break;
			}
        }
        
        else if(key == '2'){  //EDIT TASK
            cout << "\n\n\tPress a number key on the list: ";
            
            char key = _getch();
            int index = (key - '0') - 1;
            
            if(isdigit(key) && index < arr.size()) {
                
                cout << "\n\tRename: ";
                string m; getline(cin, m); 
                if (m != "") arr[index] = m;
                    
            } else e();
            system("cls");
        }
        
        else if(key == '3'){  //COMPLETE TASK
            cout << "\n\n\tPress a number key on the list: ";
            char key = _getch();
            if(isdigit(key)) {
                int index = (key - '0') - 1;
                if (index < arr.size()){
                    arr.erase(arr.begin() + index);
                    cout << "\n\tDONE!"; getch(); 
                } else e();
            }
            system("cls"); 
        }
        else if(key == '4'){  //COMPLETE TASK
            save(arr);
            system("cls"); 
        }
        else system("cls");
            
        Sleep(100);
    } 
    return 0;
}
