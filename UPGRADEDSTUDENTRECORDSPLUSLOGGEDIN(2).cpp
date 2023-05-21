#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <cstdlib>

#define MAX 20

using namespace std;

typedef struct date
{
    int dd,mm,yyyy,choice;
}DATE;

typedef struct STUD
{
    int StudentNo;
    char firstName[10];
    char lastName[10];
    int marks[3];
    float average;
    DATE d;
}STUD;

int num;

// Function prototypes
int Menu();
int SortMenu();
void Login();

void AddStudent(STUD [MAX],int);
void DisplayRecords(STUD [MAX]);

void Sort(STUD [MAX]);
void SortByFirstName(STUD [MAX]);
void SortByLastName(STUD [MAX]);
void SortByStudentNo(STUD [MAX]);
void SortByAverage(STUD [MAX]);
void SortByDOB(STUD [MAX]);

void Search(STUD [MAX]);
void Modify(STUD [MAX]);
void Delete(STUD [MAX]);

void SaveToFile(STUD [MAX]);
void RetriveData(STUD [MAX]);

int main()
{
STUD s[MAX];
int choice,no;
RetriveData(s);
Login();
while(1)
{
    choice=Menu();
    switch(choice)
    {
        case 1:
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter the no of Students:- ";
            cin >> no;
            AddStudent(s,no);
            break;

        case 2:
            DisplayRecords(s);
            break;

        case 3:
            Sort(s);
            break;

        case 4:
            Search(s);
            break;

        case 5:
            Modify(s);
            break;

        case 6:
            Delete(s);
            break;

        case 7:
            SaveToFile(s);
            break;

        case 0:
            exit(0);

        default:
            cout << "\n\t\t\t\t\t\t\t\t\t\t  Enter correct Choice\n";
            getch();
            system("cls");
            break;
    }
  }
}

// Function to handle login functionality
void Login()
{
    char userName[30],passWord[30];
    int flag;
    while(1)
    {
        flag=0;
        cout<< endl <<endl;
        cout<< "\t\t\t\t\t\t\t\t\t\t  -------------------------------------------------------\n";
        cout<< "\t\t\t\t\t\t\t\t\t\t |                                                       |\n";
        cout<< "\t\t\t\t\t\t\t\t\t\t |          Student Record Management Database           |\n";
        cout<< "\t\t\t\t\t\t\t\t\t\t |                                                       |\n";
        cout<< "\t\t\t\t\t\t\t\t\t\t  -------------------------------------------------------\n\n\n\n\n";
        cout<< "";
        cout<< " \t\t\t\t\t\t\t\t\t\t     -------------------------------------------------\n";
        cout<< " \t\t\t\t\t\t\t\t\t\t    |                      Login                      |\n";
        cout<< " \t\t\t\t\t\t\t\t\t\t     -------------------------------------------------\n ";
        cout<< "\n\n\t\t\t\t\t\t\t\t\t\t\t         Enter Username:- ";
        gets(userName);
        cout<< "\t\t\t\t\t\t\t\t\t\t\t         Enter Password:- ";
        gets(passWord);
        if (strcmp(userName,"Ukinena"))
            flag=1;
        if (strcmp(passWord,"markylabuguen"))
            flag=1;

        if(flag)
        {
            cout <<"\n\n\t\t\t\t\t\t\t\t\t\t\t       Password or Username Incorrect\n";
            system("pause");
            system("cls");
        }
        else
        {
            break;
        }
    }
    cout<< "\n\n\n\n\n\t\t\t\t\t\t\t --------------------------------------------Welcome Back! " << userName <<  " ----------------------------------------------\n\n\n" ;
    system("pause");
    system("cls");
}

//This function displays a menu of options for a student record management system and prompts the user to choose an option. It takes no arguments and returns an integer representing the user's choice.
int Menu()
{
    int no;
    cout<< endl << endl;
    cout<< "\t\t\t\t\t\t  ------------------------------------------------------------------------------------------------------------\n";
    cout<< "\t\t\t\t\t\t |                                                                                                            |\n";
    cout<< "\t\t\t\t\t\t |                                    Student Record Management Database                                      |\n";
    cout<< "\t\t\t\t\t\t |                                                                                                            |\n";
    cout<< "\t\t\t\t\t\t  ------------------------------------------------------------------------------------------------------------\n\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |           - Menu -            |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  1 : Enter Data of Student    |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  2 : Display Data of Student  |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  3 : Sort                     |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  4 : Search                   |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  5 : Modify                   |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  6 : Delete                   |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  7 : Save Students data       |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  0 : Exit                     |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n" ;
    cout<< "\n\t\t\t\t\t\t\t\t\t\t   Give your choice:- ";
    cin >> no;
    return no;
}

//This function displays a menu of sorting options for the student records and prompts the user to choose a sorting option. It takes no arguments and returns an integer representing the user's choice.
int SortMenu()
{
    int no;
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |         - Sort Menu -         |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  1 : Sort by First Name       |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  2 : Sort by Last Name        |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  3 : Sort by Student No       |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  4 : Sort by Average Marks    |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  5 : Sort by Date Of Birth    |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     |  0 : Exit from Sort Menu      |\n";
    cout<< "\t\t\t\t\t\t\t\t\t\t     ---------------------------------\n";
    cout<< "\n\t\t\t\t\t\t\t\t\t\t   Give your choice:- ";
    cin >> no;
    return no;
}

//This function allows the user to add student records to the database. It takes an array of STUD structures s and the number of students no to add.
//It prompts the user to enter details for each student (first name, last name, student number, marks in math, science, and English, and date of birth) and stores them in the s array.//
void AddStudent(STUD s[MAX],int no)
{
    for(int i=num;i<num+no;i++)
    {
        cin.ignore();
        cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter details for Student " << i+1 << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t   First Name:- ";
        cin.getline(s[i].firstName, MAX);
        cout << "\t\t\t\t\t\t\t\t\t\t   Last Name:- ";
        cin.getline(s[i].lastName, MAX);
        cout << "\t\t\t\t\t\t\t\t\t\t   Student No:(8- digits):- ";
        cin >> s[i].StudentNo;
        cout << "\t\t\t\t\t\t\t\t\t\t   Marks obtained in Maths, Science and English (Each out of 100):- ";
        cin >> s[i].marks[0] >> s[i].marks[1] >> s[i].marks[2];
        s[i].average = (float)(s[i].marks[0]+s[i].marks[1]+s[i].marks[2])/3;
        cout << "\t\t\t\t\t\t\t\t\t\t   Enter Date, Month and Year of Birth:- ";
        cin >> s[i].d.dd >> s[i].d.mm >> s[i].d.yyyy;
    }
    num=num+no;
    system("cls");
}

//This function displays all the student records stored in the s array. It takes an array of STUD structures s as an argument.
//It formats and prints the records in a tabular format, including record number, student number, full name, marks in math, science, and English, average marks, and date of birth.
void DisplayRecords(STUD s[MAX])
{
    int i;
    cout << "\n\t\t\t\t\t  -------------------------------------------------------------------------------------------------------------------------------";
    cout << "\n\t\t\t\t\t  | Record No. | Student No. | Full Name           | Math Marks | Science Marks | English Marks | Average Marks | Date of Birth |";
    cout << "\n\t\t\t\t\t  -------------------------------------------------------------------------------------------------------------------------------";
    for(i=0;i<num;i++)
    {
        string fullName = std::string(s[i].firstName) + " " + s[i].lastName;
        printf("\n\t\t\t\t\t  | %10d | %11d | %-20s | %10d | %13d | %13d | %13.2f | %02d/%02d/%04d |",
       i+1, s[i].StudentNo, fullName.c_str(),
       s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].average,
       s[i].d.dd, s[i].d.mm, s[i].d.yyyy);
       
    }
    cout << "\n\t\t\t\t\t  -------------------------------------------------------------------------------------------------------------------------------\n";
    cin.get();
    system("pause");
    system("cls");
}

//This function is a utility function used in sorting algorithms. It takes two pointers to STUD structures (x and y) and swaps their values.
void swap(STUD *x,STUD *y)
{
    STUD temp = *x;
    *x = *y;
    *y = temp;
}

//This function provides a sorting menu and allows the user to sort the student records based on different criteria.
// It takes an array of STUD structures s as an argument. It repeatedly displays the sort menu, takes the user's sorting choice, and calls the corresponding sorting function.
void Sort(STUD s[MAX])
{
    int choice;
    char choice2;
    system("cls");
    while(1)
    {
    	cout<<endl<<endl;
     cout << "\t\t\t\t\t\t\t    --------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t    |                                                                                      |\n";
    cout << "\t\t\t\t\t\t\t    |                          Student Record Management Database                          |\n";
    cout << "\t\t\t\t\t\t\t    |                                                                                      |\n";
     cout << "\t\t\t\t\t\t\t    --------------------------------------------------------------------------------------\n\n";
        choice=SortMenu();
        switch(choice)
        {
            case 1:
                SortByFirstName(s);
                break;

            case 2:
                SortByLastName(s);
                break;

            case 3:
                SortByStudentNo(s);
                break;

            case 4:
                SortByAverage(s);
                break;

            case 5:
                SortByDOB(s);
                break;

            case 0:
                system("cls");
                return;

            default:
                std::cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter correct Choice\n";
                break;
        }
        cin.ignore();
        cout << "\n\t\t\t\t\t\t\t\t\t\t   Do you want to store sorted records? - ";
        cin >> choice2;
        if(choice2 =='y' || choice2 == 'Y')
            SaveToFile(s);
        else
            system("cls");
    }
}

//This function sorts the student records based on their first names in ascending order. It takes an array of STUD structures s as an argument and modifies the array accordingly.
void SortByFirstName(STUD s[MAX])
{
    int i, j;
    char choice;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (strcmp(s[j].firstName,s[j+1].firstName)>0)
              swap(&s[j],&s[j+1]);
        }
    }
    cout <<"\n\t\t\t\t\t\t\t\t\t\t   Records Sorted\n";
}

//This function sorts the student records based on their last names in ascending order. It takes an array of STUD structures s as an argument and modifies the array accordingly.
void SortByLastName(STUD s[MAX])
{
    int i, j;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (strcmp(s[j].lastName,s[j+1].lastName)>0)
              swap(&s[j],&s[j+1]);
        }
    }
    cout <<"\n\t\t\t\t\t\t\t\t\t\t   Records Sorted\n";
}

//This function sorts the student records based on their student numbers in ascending order. It takes an array of STUD structures s as an argument and modifies the array accordingly.
void SortByStudentNo(STUD s[MAX])
{
    int i, j;
    for (i = 0; i < num-1; i++)
    {
        for (j = 0; j < num-i-1; j++)
        {
            if (s[j].StudentNo > s[j+1].StudentNo)
              swap(&s[j],&s[j+1]);
        }
    }
    cout <<"\n\t\t\t\t\t\t\t\t\t\t   Records Sorted\n";
}


//This function sorts the student records based on their average marks in ascending order. It takes an array of STUD structures s as an argument and modifies the array accordingly.
void SortByAverage(STUD s[MAX])
{
    int i,j,pos;
    STUD temp;
    for (i = 0; i < num-1; i++)
    {
        pos=i;
        for (j = i+1;j<num;j++)
        {
            if (s[j].average < s[pos].average)
              pos=j;
        }
        if(pos!=i)
        {
            swap(&s[i],&s[pos]);
        }
    }
    cout <<"\n\t\t\t\t\t\t\t\t\t\t   Records Sorted\n";
}

//This function sorts the student records based on their date of birth in ascending order. It takes an array of STUD structures s as an argument and modifies the array accordingly.
void SortByDOB(STUD s[MAX])
{
    int i,j;
    for (i=0;i<num-1;i++)
    {
        for(j=0;j<num-1-i;j++)
        {
            if(s[j].d.yyyy>s[j+1].d.yyyy)
            {
                swap(&s[j],&s[j+1]);
            }
            if(s[j].d.yyyy == s[j+1].d.yyyy && s[j].d.mm>s[j+1].d.mm)
            {
                swap(&s[j],&s[j+1]);
            }
            if(s[j].d.yyyy == s[j+1].d.yyyy && s[j].d.mm == s[j+1].d.mm && s[j].d.dd>s[j+1].d.dd)
            {
                swap(&s[j],&s[j+1]);
            }
        }
    }
    cout <<"\n\t\t\t\t\t\t\t\t\t\t   Records Sorted\n";
}

//This function allows the user to search for a student record based on the student number. It takes an array of STUD structures s as an argument.
//It prompts the user to enter a student number and displays the corresponding record if found.
void Search(STUD s[MAX])
{
    int no,j,flag=0;
    std::cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter the Student No of the student to search:- ";
    std::cin >> no;
    for(j=0;j<num;j++)
    {
        if(s[j].StudentNo==no)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Record Found...\n";
            cout << "\n\t\t\t\t\t\t\t\t\t\t   First Name:- " << s[j].firstName;
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Last Name:- " << s[j].lastName;
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Student No:- " << s[j].StudentNo;
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Marks obtained in Maths, Science and English (Each out of 100):- " << s[j].marks[0] << " " << s[j].marks[1] << " " << s[j].marks[2];
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Average Marks Obtained:- " << s[j].average;
            cout << "\n\t\t\t\t\t\t\t\t\t\t   Date, Month and Year of Birth:- " << s[j].d.dd << "/" << s[j].d.mm << "/" << s[j].d.yyyy << endl;
            flag++;
            cin.get();
            system("pause");
            system("cls");
            break;
        }
    }
    if(!flag)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\t   Record with Student No " << no << " not found..." << endl;
        cin.get();
        system("pause");
        system("cls");
    }
}

//This function allows the user to modify a student record based on the student number. 
//It takes an array of STUD structures s as an argument. It prompts the user to enter a student number and, if found, allows them to update the record with new details (first name, last name, student number, marks in Math, Science, and English, and date of birth).
void Modify(STUD s[MAX])
{
    int no,j,flag=0;
    cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter the Student No of the student to modify:- ";
    cin >> no;
    for(j=0;j<num;j++)
    {
        if(s[j].StudentNo==no)
        {
            flag=1;
            break;
        }
    }
    
    
    if(flag)
    {
        cin.ignore();
        cout << "\n\t\t\t\t\t\t\t\t\t\t   Enter details for Student " << j+1 << std::endl;
        cout << "\t\t\t\t\t\t\t\t\t\t   First Name:- ";
        cin.getline(s[j].firstName, sizeof(s[j].firstName));
        cout << "\t\t\t\t\t\t\t\t\t\t   Last Name:- ";
        cin.getline(s[j].lastName, sizeof(s[j].lastName));
        cout << "\t\t\t\t\t\t\t\t\t\t   Student No:- ";
        cin >> s[j].StudentNo;
        cout << "\t\t\t\t\t\t\t\t\t\t   Marks obtained in Maths, Science and English (Each out of 100):- ";
        cin >> s[j].marks[0] >> s[j].marks[1] >> s[j].marks[2];
         s[j].average = (float)(s[j].marks[0]+s[j].marks[1]+s[j].marks[2])/3;
        cout << "\t\t\t\t\t\t\t\t\t\t   Enter Date, Month and Year of Birth:- " <<endl;
        cin >> s[j].d.dd >> s[j].d.mm >> s[j].d.yyyy;
        SaveToFile(s);
    }
    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\t   Record with Student No " << no << " not found...";
        cin.get();
        system("pause");
        system("cls");
    }
}

//This function allows the user to delete a student record from the database based on the student number. It takes an array of STUD structures s and a pointer to the number of students no as arguments.
//It prompts the user to enter a student number and, if found, removes the corresponding record from the array and updates the number of students.
     
void Delete(STUD s[MAX])
{
    int j,no,flag=0;
    cout  <<"\n\t\t\t\t\t\t\t\t\t\t   Enter the Student No of the student to Delete:- ";
    cin >>  no;
    for (j = 0; j < num; j++)
    {
        if (no == s[j].StudentNo)
        {
            flag++;
            for (int k = j; k < num-1; k++)
                s[k] = s[k + 1];
            num--;
            cout <<"\n\t\t\t\t\t\t\t\t\t\t   Record deleted successfully\n";
            break;
        }
    }
    if(flag)
        SaveToFile(s);
    else
    {
        cout <<"\n\t\t\t\t\t\t\t\t\t\t   Record with Student No"<< no <<" not found...";
        getch();
        system("pause");
        system("cls");
    }
}

//The SaveToFile() function is responsible for saving the student records stored in the s array to a binary file named "recs.bin". Here's an explanation of the function:
void SaveToFile(STUD s[MAX])
{
    FILE *fptr;
    fptr = fopen("recs.bin","wb");
    for(int i=0;i<num;i++)
    {
        fwrite(&s[i],sizeof(s[i]),1,fptr);
    }
    fclose(fptr);
    cout <<"\t\t\t\t\t\t\t\t\t\t   Records added Successfully...";
    getch();
    system("cls");
}

//The RetriveData() function is responsible for reading student records from a binary file named "recs.bin" and populating the s array with the retrieved data. 
void RetriveData(STUD s[MAX])
{
    int line=0;
    FILE *fptr;

    fptr = fopen("recs.bin", "rb");
    if (fptr == NULL)
    {
        cout <<"\t\t\t\t\t\t\t\t\t\t   Could not open file";
        return;
    }
    while(getc(fptr) != EOF)
    {
        fseek(fptr,-1,SEEK_CUR);
        fread(&s[line],sizeof(s[line]),1,fptr);
        line++;
    }
    fclose(fptr);
    num=line;
}
