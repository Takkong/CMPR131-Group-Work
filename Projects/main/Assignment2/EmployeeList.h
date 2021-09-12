// Team Members:
// Itz Rodriguez
// Ben Halpern
//
//
#pragma once
#include "input.h"
#include <iostream>
#include "myContainers.h"
#include <fstream>
#include <string>


bool debug = true;
//prototypes
char subMenuOptions_el();
class Employee;
void OptionA(LinkTList<Employee>& employeeList);
void OptionB(LinkTList<Employee>& employeeList);
void OptionC(LinkTList<Employee>& employeeList);
void OptionD(LinkTList<Employee>& employeeList);
void OptionE(LinkTList<Employee>& employeeList);

class Employee {
private:
    static int nextId;
    int employee_id = int();                                                                        //set to a string in case wants a non int id
    char status = char('U');                                                                        //initialized to unknown
    string lastName = string();
    string firstName = string();
    string startingDate = string();
    string endingDate = string();


public:

    Employee() {
        employee_id = nextId;
        //std::cout << nextId;
        nextId++;
    }//end default constructor

    

    //sets the employee_id value only and default status, used for populating an employee value without changing the nextId
    Employee(int code, char inStat = char('U')) {
        this->employee_id = code;
    }//end employee code constructor


    Employee(string inLast, string inFirst, string inStartDat, string inEndDat, int inEmpID = nextId, char inStat = char('U') ) {
        input( inLast, inFirst, inStartDat, inEndDat, inEmpID, inStat );
    }//end Employee

    Employee(const Employee &right) {
        this->employee_id = right.employee_id;
        this->lastName = right.lastName;
        this->firstName = right.firstName;
        this->status = right.status;
        this->startingDate = right.startingDate;
        this->endingDate = right.endingDate;
        
    }//end copy constructor

    Employee& operator = (const Employee& right)  {
        this->employee_id = right.employee_id;
        this->lastName = right.lastName;
        this->firstName = right.firstName;
        this->status = right.status;
        this->startingDate = right.startingDate;
        this->endingDate = right.endingDate;
        return *this;
    }//end = assingment operator

    bool operator < (const Employee& right) {
        return this->employee_id < right.employee_id;
    }//end operator <

    bool operator > (const Employee& right) {
        return this->employee_id > right.employee_id;
    }//end operator >


    /// Precondition:
    /// Postcondition:
    bool read(ifstream& file) {
        
        if(file.bad()) {                                                    //precondition check: if the file is invalid or the badbit is set,
            std:cout << "\nError: Bad File, please input a valid file\n\b"; //output an error to the screen 
            return false;                                                   //return false
        }//end if

        string line = string();                                             //
        getline(file, line);                                                //reads the next line from the file
        
        if (debug) std::cout << "\n" << line << "\n";                       //debugging check
        
        if (line.empty())                                                   //if line read is empty return false
            return false;
        
        LinkTList<string> record = LinkTList<string>(); 
        size_t delimIndex = size_t(1);                                      //sets the initial delimeter size to be greater than the start
        size_t start = size_t(0);                                           //sets the start to the beigining index
        //end initialization
    

        do{
            delimIndex = line.find(',', start);                             //sets the delimIndex from the offest of the start to find the next delimeter
            if (delimIndex < line.length()) {                               //if th delimeter exists within the line
                record.appendNode(line.substr(start, delimIndex - start));  //add a substring from the last delimeter to the current
                start = ++delimIndex;                                       //increment the delimeter and set it to start starting from the next delimeted index
            }//end if
        } while ((line.find(',', start) < line.length()));//end while 
        
        //adds last value
        if(delimIndex < line.length())                                      //if the last delimeter index used is before the end of the line
            record.appendNode(line.substr(delimIndex));                     //since the last value is skipped by the loop, add the last value is added 
        
        
        //example data:  |    D   | 2  | Quach | Nick  | 10/02/1998 | 12/02/2020 | 
        //               | status | id | Last  | First | StartDate  | EndDate    |
        if (debug) { std::cout << "\n[DEBUG]: " << record.print(); }        //debug check to display the values in the LinkList
        
        input( record[2], record[3], record[4], record[5], atoi(record[1].c_str()), record[0].at(0) );
        return true;
    }//end read

    /// Precondition: 
    /// Postcondition:
    void input(string inLast, string inFirst, string inStartDat, string inEndDat = "Current", int inEmpID = nextId, char inStat = char('U')) {
        this->status = inStat;
        this->employee_id = inEmpID;
        this->lastName = inLast;
        this->firstName = inFirst;
        this->startingDate = inStartDat;
        this->endingDate = inEndDat;

        if (debug) {
            std::cout << "\nInput: " << inStat << "," << inEmpID << "," << inLast << "," << inFirst << "," << inStartDat << ","<< inEndDat << "\n";
            std::cout << "\nThis:  " << this->status << "," << this->employee_id << "," << this->lastName << "," << this->firstName << "," << this->startingDate << ","<< this->endingDate << "\n";
        }




    }//end input

    /// Precondition:
    /// Postcondition:
    int getId() const {
        return this->employee_id;
    }

    /// Precondition:
    /// Postcondition:
    char getStatus() const {
        return this->status;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getLastName() const {
        return this->lastName;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getFirstName() const {
        return this->firstName;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getStartingDate() const {
        return this->startingDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    string getEndingDate() const {
        return this->endingDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setStatus(char newStat) {
        this->status = newStat;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setLastName(string newLastNm) {
        this->lastName = newLastNm;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setFirstName(string newFirstNm) {
        this->firstName = newFirstNm;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setStartingDate(string newStartDate) {
        this->startingDate = newStartDate;
    }

    /// Preconditiion: 
    /// Postcondition:
    void setEndingDate(string newEndDate) {
        this->endingDate = newEndDate;
    }

    friend ostream& operator << (ostream& strm, const Employee& obj) {
        strm << obj.getStatus() << "," << obj.getId() << "," << obj.getLastName() << "," << obj.getFirstName() << "," << obj.getStartingDate() << "," << obj.getEndingDate();
        return strm;
    }//overloading << operator

};//end employee class

int Employee::nextId = 1;



//###################################################################
// Driver function
//###################################################################


//driver for the EMployeeList header file
void runEmployeeList() {
    LinkTList<Employee> employeeList = LinkTList<Employee>();
    
    do
    {
        
        switch (subMenuOptions_el())
        {
        case '0': return; break;
        case 'A':OptionA(employeeList); break;
        case 'B':OptionB(employeeList); break;
        case 'C':OptionC(employeeList); break;
        case 'D':OptionD(employeeList); break;
        case 'E':OptionE(employeeList); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        pause();
    } while (true);
}//end runEmployeeList





//###################################################################
// Menu function
//###################################################################

char subMenuOptions_el() {

    clrScrn();
    header("\n\t\t1> List of Employees ");
    string options[] = { "\n\t\t\tA> Read data from file and store into a list ",
                        "\n\t\t\tB> Insert a new employee record into the list ",
                        "\n\t\t\tC> Update an employee record from the list ",
                        "\n\t\t\tD> Display all, active or inactive employee records from the list",
                        "\n\t\t\tE> Write data from the list to a file",
                        "\n" + string(100 , char(196)) +
                        "\n\t\t\t0> return "

    };
    for (string option : options)
        cout << option;
    header("");

    char optionCh = inputChar("\n\t\t\tOption: ", string("ABCDE0"));
    clrScrn();
    return optionCh;

}//end menu

//###################################################################
// A> Read data from file and store into a list
//###################################################################

void OptionA(LinkTList<Employee>& employeeList) {
    
    
    string filename = string();                                             
    ifstream* exists = new ifstream();                                     

    //This will be used to read the line and be broken down to local variables
    
    
    
    
    //Asking for the file name
    
    filename = inputString("\nEnter the filename: ", false);
    if(debug) filename = "EmployeeRecords.dat";                                       //debug stub overrides the value in input string


    //Opening the data file
    
    //checks to see if the file exists
    
    exists->open(filename, ios::in);
    //if opened the file successfully then continue
    if (!exists->fail())
    {
        exists->close();
        delete exists;

        ifstream dataFile = ifstream();
        dataFile.open(filename, ios::in);
        //end file initialization

        while (!dataFile.eof()) {
            Employee newEmployee(0);                                            //sets up an empty employee
            if (debug) std::cout << "\n" << newEmployee.getId() << "\n";        //for debugging purposes
            if (newEmployee.read(dataFile)) {                                   //if the line was read into the employee
                employeeList.appendNode(newEmployee);                           //add the employee to the employee list
            }//end if
        }//end while

        dataFile.close();                                                       //closing dataFile

        
        //action for after inserted into the list
        if (debug) {
            std::cout << "\n[DEBUG] size of list : " << employeeList.getSize() << "\n";
            std::cout << "\n[DEBUG] first value in list : " << employeeList[0] << "\n";
            std::cout << "\n[DEBUG] last value in list : " << employeeList[employeeList.getSize() - 1] << "\n";
            std::cout << "\n[DEBUG] all values of the list :\n";
            for (int i = 0; i < employeeList.getSize(); i++) {
                std:cout << "\n" << employeeList[i] << "\n";
            }//end for
        }//end debug
        
        
        /*
        
        code here
        
        */


    }
    else
    {
        cout << "ERROR: Cannot open the file" << endl;
    }

}
//end of OptionA()

/// Precondition:
/// Postcondition:
void OptionB(LinkTList<Employee> &employeeList) {
    Employee newEmployee = Employee();
    employeeList.insertNode(newEmployee);


}//end OptionB


/// Precondition: (linkList<Employee>) employeeList contains the list of employee records in sorted order by Id, no Id may repeat
/// Postcondition: prompts the user to update the value in the employee list
void OptionC(LinkTList<Employee>& employeeList) {
    if (employeeList.empty()) {                                                                     //if the employeeList is empty .: violating the precondition, output an error message and return
    std:cout << "\nERROR: the  list is empty, please add a record\n";
        return;
    }//end if
    int editId = int();
    Employee* editEmployee = nullptr;
    int firstId = int();
    int lastId = int();
    //ask for the employee id to edit

    firstId = 0;//stub change later
    lastId = employeeList.getSize() - 1;//stub change later
    editId = inputInteger("\nPlease enter an id ("+ to_string(firstId) +"..."+ to_string(lastId) +"): ",firstId, lastId );

    //display the menu





    




}//end OptionC

/// Precondition:
/// Postcondition:
void OptionD(LinkTList<Employee>& employeeList) {

}//end OptionD

/// Precondition: 
/// Postcondition:
void OptionE(LinkTList<Employee>& employeeList) {

}//end OptionE
