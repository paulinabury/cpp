#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class student {
private:
    string name, roll_no, course, email_id, contact_no, address;
public:
    [[noreturn]] void menu();

    void insert();

    void display();

    void modify();

    void search();

    void deleted();
};

[[noreturn]] void student::menu() {
    menu_start:
    int choice;
    char x;
    system("clear");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| Student management system |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1.Enter New Student" << endl;
    cout << "\t\t\t 2.Display Student" << endl;
    cout << "\t\t\t 3.Modify Student" << endl;
    cout << "\t\t\t 4.Search Student" << endl;
    cout << "\t\t\t 5.Delete Student" << endl;
    cout << "\t\t\t 6.Exit" << endl;

    cout << "\t\t\t----------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t----------------------------" << endl;
    cout << "Enter Your Choose:";
    cin >> choice;

    switch (choice) {
        case 1:
            do {
                insert();
                cout << "\n\t\t\tAdd Another Student(Y,N): ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\t\t\t Invalid choice... Please Try Again..." << endl;
    }
    goto menu_start;
}

void student::insert() {
    system("clear");
    fstream file;
    cout << "\n-----------------------------------------------";
    cout << "\n--------------Add Student Details--------------" << endl;
    cout << "\t\t\tEnter Name:";
    cin >> name;
    cout << "\t\t\tEnter Roll no:";
    cin >> roll_no;
    cout << "\t\t\tEnter Course:";
    cin >> course;
    cout << "\t\t\tEnter Email:";
    cin >> email_id;
    cout << "\t\t\tEnter Contact Number:";
    cin >> contact_no;
    cout << "\t\t\tEnter Address:";
    cin >> address;
    file.open("studentRecords.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address
         << "\n ";
    file.close();
}

void student::display() {
    system("clear");
    fstream file;
    int total = 1;
    cout << "\n-----------------------------------------------";
    cout << "\n--------------Show Record Table----------------" << endl;

    file.open("studentRecords.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present..." << endl;
        file.close();
    } else {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof()) {
            cout << "\n\t\t\tStudent No.: " << total++ << endl;
            cout << "\t\t\tStudent Name: " << name << endl;
            cout << "\t\t\tStudent Roll No.: " << roll_no << endl;
            cout << "\t\t\tStudent Course: " << course << endl;
            cout << "\t\t\tStudent Email: " << email_id << endl;
            cout << "\t\t\tStudent Contact No.: " << contact_no << endl;
            cout << "\t\t\tStudent Address: " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0) {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }
    file.close();
}

void student::modify() {
    system("clear");
    fstream file, file1;
    string rollNo;
    int found = 0;
    cout << "\n----------------------------------------------------";
    cout << "\n--------------Modify Student Details----------------" << endl;
    file.open("studentRecords.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data Is Present..." << endl;
    } else {
        cout << "\n Enter Roll No. of student which you want to Modify: ";
        cin >> rollNo;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;

        while (!file.eof()) {
            if (rollNo != roll_no) {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " "
                      << address << "\n";
            } else {
                cout << "\t\t\tEnter Name:";
                cin >> name;
                cout << "\t\t\tEnter Roll no:";
                cin >> roll_no;
                cout << "\t\t\tEnter Course:";
                cin >> course;
                cout << "\t\t\tEnter Email:";
                cin >> email_id;
                cout << "\t\t\tEnter Contact Number:";
                cin >> contact_no;
                cout << "\t\t\tEnter Address:";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " "
                      << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0) {
                cout << "\n\t\t\t Student Roll No. Not Found..." << endl;
            }
        }
        file1.close();
        file.close();
        remove("studentRecords.txt");
        rename("Record.txt", "studentRecords.txt");
    }
}

void student::search() {
    system("clear");
    fstream file;
    int found = 0;
    file.open("studentRecords.txt", ios::in);
    if (!file) {
        cout << "\n----------------------------------------------------";
        cout << "\n--------------Search Student Data-------------------" << endl;
        cout << "\n\t\t\tNo Data is Present..." << endl;
    } else {
        string rollNo;
        cout << "\n----------------------------------------------------";
        cout << "\n--------------Search Student Data-------------------" << endl;
        cout << "\nEnter Roll No. of Student Which You Want to Search: ";
        cin >> rollNo;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof()) {
            if (rollNo == roll_no) {
                cout << "\n\t\t\tStudent Name: " << name << endl;
                cout << "\t\t\tStudent Roll No.: " << roll_no << endl;
                cout << "\t\t\tStudent Course: " << course << endl;
                cout << "\t\t\tStudent Email: " << email_id << endl;
                cout << "\t\t\tStudent Contact No.: " << contact_no << endl;
                cout << "\t\t\tStudent Address: " << address << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0) {
            cout << "\n\t\t\tStudent Roll No. Not Found" << endl;
        }
        file.close();
    }
}

void student::deleted() {
    system("clear");
    fstream file, file1;
    string rollNo;
    int found = 0;
    cout << "\n----------------------------------------------------";
    cout << "\n--------------Delete Student Data-------------------" << endl;
    file.open("studentRecords.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\tNo Data is Present..." << endl;
        file.close();
    } else {
        cout << "\nEnter Roll No. of Student Which You Want to Delete:";
        cin >> rollNo;
        file1.open("Record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof()) {
            if (rollNo != roll_no) {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " "
                      << address << "\n";
            } else {
                found++;
                cout << "\n\t\t\tData successfully Deleted" << endl;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0) {
            cout << "\n\t\t\tStudent Roll No. Not Found" << endl;
        }
        file1.close();
        file.close();
        remove("studentRecords.txt");
        rename("Record.txt", "studentRecords.txt");
    }
}

int main() {
    student project;
    project.menu();
}
