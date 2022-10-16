#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

typedef struct Student
{
    char studentName[50];
    char studentId[15];
    char studentDept[10];
    char studentAddress[100];
    char studentContactNum[15];
    float studentCGPA;
} Student;

void createAccount();
void displayInfo();
void updateInfo();
void deleteInfo();
void searchInfo();
void home();  
void head();  
void login(); 
void menu();  

void addBook();          
void deleteBook();       
void updateList(int);    
int searchList(int);     
void viewSearchedList(); 
int searchBook(int);     
void viewSearchedBook(); 
void addMember();        
void deleteMember();     
int searchMember(int);   
void viewSearchedMember();
void choice();
void endScreen(){

    system("cls");
    printf("\t\t\tLibrary Management System and Student Database management in C  \n\n");
    printf("\t\t\t\t     Creator: Pradhyumna Upadhya \n\n");
    printf("\t\t\t\t\t\t  Thank you!! \n\n");
    
    printf("\n\nPress any key to exit.\n");

    getch();
    exit(0);
}



void home_s()
{
    system("cls");
    printf("\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n\t|||||||||||||             Welcome to Prad's Student Database management System!           ||||||");
    printf("\n\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    Sleep(4000);
    choice();
}

void choice()
{
    char option;

    while (option != '0')
    {

        system("cls");
        printf("\n\n\n\t\t\t\t\t\t*** What would you like to do? ***\n");
        printf("\n\t\t\t1. Create Student Account");
        printf("\n\t\t\t2. Display All Students Information");
        printf("\n\t\t\t3. Update Student Information");
        printf("\n\t\t\t4. Delete Student Information");
        printf("\n\t\t\t5. Search Student Information");
        printf("\n\t\t\t0. Exit");

        printf("\n\n\n\t\t\tEnter Your Option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case '1':
            createAccount();
            break;
        case '2':
            displayInfo();
            break;
        case '3':
            updateInfo();
            break;
        case '4':
            deleteInfo();
            break;
        case '5':
            searchInfo();
            break;
        case '0':
            endScreen();
            break;
        default:
            printf("\n\t\t\tInvalid Option, Please Enter Right Option !\n");
        }
    }
    return;
}

void createAccount()
{
    FILE *fileOne = fopen("studentInfo.bin", "ab+");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t====== Create Student Account ======\n");

    printf("\n\t\t\tEnter Student's Name : ");
    getchar();
    gets(stundentInformation.studentName);
    printf("\t\t\tEnter Student's ID : ");
    gets(stundentInformation.studentId);
    printf("\t\t\tEnter Student's Depertment : ");
    gets(stundentInformation.studentDept);
    printf("\t\t\tEnter Student's Address : ");
    gets(stundentInformation.studentAddress);
    printf("\t\t\tEnter Student's Contact Number : ");
    gets(stundentInformation.studentContactNum);
    printf("\t\t\tEnter Student's Current CGPA : ");
    scanf("%f", &stundentInformation.studentCGPA);

    fwrite(&stundentInformation, sizeof(stundentInformation), 1, fileOne);

    printf("\n\n\t\t\tInformations have been stored sucessfully\n");
    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void displayInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    Student stundentInformation;

    system("cls");

    printf("\t\t\t\t====== All Students Information ======\n");

    printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
    printf("\t\t----------------------------------------------------------------------------------------");

    while (fread(&stundentInformation, sizeof(stundentInformation), 1, fileOne) == 1)
    {
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", stundentInformation.studentName, stundentInformation.studentId, stundentInformation.studentDept, stundentInformation.studentAddress, stundentInformation.studentContactNum, stundentInformation.studentCGPA);
    }

    printf("\n\n\t\tEnter any keys to continue.......");
    getch();

    fclose(fileOne);
}

void updateInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Update Students Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tChoose your option :\n\t\t\t1.Update Student Name\n\t\t\t2.Update Student Dept.\n\t\t\t3.Update Student Address\n\t\t\t4.Update Student Contact No.\n\t\t\t5.Update Student CPGA");
            printf("\n\n\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\t\t\tEnter Student's Name to Update: ");
                getchar();
                gets(tempInformation.studentName);
                strcpy(studentInformation.studentName, tempInformation.studentName);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 2)
            {
                printf("\n\t\t\tEnter Student's Dept. to Update: ");
                getchar();
                gets(tempInformation.studentDept);
                strcpy(studentInformation.studentDept, tempInformation.studentDept);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 3)
            {
                printf("\n\t\t\tEnter Student's Address to Update: ");
                getchar();
                gets(tempInformation.studentAddress);
                strcpy(studentInformation.studentAddress, tempInformation.studentAddress);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 4)
            {
                printf("\n\t\t\tEnter Student's Contact No. to Update: ");
                getchar();
                gets(tempInformation.studentContactNum);
                strcpy(studentInformation.studentContactNum, tempInformation.studentContactNum);

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else if (choice == 5)
            {
                printf("\n\t\t\tEnter Student's CGPA to Update: ");
                scanf("%f", &tempInformation.studentCGPA);
                studentInformation.studentCGPA = tempInformation.studentCGPA;

                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
                printf("\n\n\t\t\tUpdated successfully!\n\n");
            }
            else
            {
                printf("\n\t\t\tInvalid Option.");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void deleteInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    Student studentInformation, tempInformation;

    int choice, flag = 0;

    if (fileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Delete Student Information ======\n");

    printf("\n\t\t\tEnter Student's ID : ");
    getchar();
    gets(tempInformation.studentId);

    while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
    {
        if (strcmp(studentInformation.studentId, tempInformation.studentId) == 0)
        {
            flag++;
            printf("\n\t\t\tAre you sure to delete ??\n\t\t\t\t1.Yes\n\t\t\t\t2.Back\n\t\t\t\tEnter Your Option : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\n\n\t\t\tInformation has been deleted successfully!\n\n");
            }
            else if (choice == 2)
            {
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
            else
            {
                printf("\n\t\t\tInvalid Option");
                fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
            }
        }
        else
        {
            fwrite(&studentInformation, sizeof(studentInformation), 1, temp);
        }
    }

    fclose(fileOne);
    fclose(temp);

    remove("studentInfo.bin");
    rename("temp.bin", "studentInfo.bin");

    if (flag == 0)
    {
        printf("\n\t\t\tStudent Id is not found");
    }

    printf("\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

void searchInfo()
{
    FILE *fileOne = fopen("studentInfo.bin", "rb");

    Student studentInformation;

    int choice, flag = 0;
    char studentID[20], studentDept[10];

    if (fileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");

    printf("\t\t\t\t====== Search Student Information ======\n");

    printf("\n\t\t\tChoose your option :\n\t\t\t1.Search by Student ID\n\t\t\t2.Search by Student Dept.");
    printf("\n\n\t\t\tEnter Your Option : ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student ID : ");
        getchar();
        gets(studentID);
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (strcmp(studentInformation.studentId, studentID) == 0)
            {
                flag++;
                printf("\n\t\t\tStudent Name : %s\n\t\t\tStudent ID : %s\n\t\t\tStudent Dept. : %s\n\t\t\tStudent Address : %s\n\t\t\tStudent Contact No. : %s\n\t\t\tStudent CGPA : %.2f\n", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else if (choice == 2)
    {
        system("cls");
        printf("\t\t\t\t====== Search Student Information ======\n");
        printf("\n\n\t\t\tEnter Student Dept. : ");
        getchar();
        gets(studentDept);
        printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-s\n", "Name", "ID", "Dept.", "Address", "Contact", "CGPA");
        printf("\t\t----------------------------------------------------------------------------------------");
        while (fread(&studentInformation, sizeof(studentInformation), 1, fileOne) == 1)
        {
            if (stricmp(studentInformation.studentDept, studentDept) == 0)
            {
                flag++;
                printf("\n\n\t\t%-20s%-13s%-10s%-25s%-15s%-.2f", studentInformation.studentName, studentInformation.studentId, studentInformation.studentDept, studentInformation.studentAddress, studentInformation.studentContactNum, studentInformation.studentCGPA);
            }
        }
        if (flag == 0)
        {
            printf("\n\t\t\tStudent Id is not found");
        }
    }
    else
    {
        printf("\n\t\t\tInvalid Option");
    }

    fclose(fileOne);

    printf("\n\n\n\t\t\tEnter any keys to continue.......");
    getch();
}

struct books
{
    unsigned int num;
    char name[50], author[50];
};

struct members
{
    unsigned int num;
    char name[50], addr[100], mob[11], email[50];
};

struct records
{
    unsigned int b_num, m_num;
};

void head()
{
    system("cls");
    printf("\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n\t|||||||||||||              Welcome to Prad's Library management System            ||||||||||||||");
    printf("\n\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    Sleep(4000);
    system("cls");
    menu();
}

void deleteBook()
{
    unsigned int num, flag = 0;
    FILE *fpR, *fpW;
    struct books b;

    system("cls");

    fpR = fopen("books.bin", "rb");
    if (fpR = NULL)
    {
        printf("\n\n\t\tUnable to fetch records!!!");
        getch();
        return;
    }

    fpW = fopen("temp.bin", "wb");
    printf("\n\n\t\tEnter Book no. to delete => ");
    scanf("%u", &num);

    while (fread(&b, sizeof(b), 1, fpR))
    {
        if (num != b.num)
            fwrite(&b, sizeof(b), 1, fpW);
        else
        {
            printf("\n\n\t\tBook Deleted");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\tNo such book exist!!!");
        getch();
    }
    fclose(fpR);
    fclose(fpW);
    remove("books.bin");
    rename("temp.bin", "books.bin");
}
int searchMember(int mem)
{
    int flag = 0;
    struct members m;
    FILE *fpM;
    fpM = fopen("members.bin", "rb");
    if (fpM == NULL)
    {
        printf("\n\n\t\t\tRecords could not be fetched!!!");
        getch();
        return 0;
    }
    while (fread(&m, sizeof(m), 1, fpM))
    {
        if (mem == m.num)
        {
            flag = 1;
            fclose(fpM);
            return flag;
        }
    }
    fclose(fpM);
    return flag;
}

int searchList(int book)
{
    int flag = 0;
    struct records r;
    FILE *fpR;

    fpR = fopen("records.bin", "rb");
    if (fpR == NULL)
    {
        printf("\n\n\t\t\tRecords could not be fetched!!!");
        getch();
        return 0;
    }
    while (fread(&r, sizeof(r), 1, fpR))
    {
        if (book == r.b_num)
        {
            flag = 1;
            fclose(fpR);
            return flag;
        }
    }
    fclose(fpR);
    return flag;
}

int searchBook(int book)
{
    int flag = 0;
    struct books b;
    FILE *fpB;

    printf("\n\nfubgdrgbhsfrikbughrsfikndbgkujndfbrhvgkujh");
    fpB = fopen("books.bin", "rb");
    if (fpB == NULL)
    {
        printf("\n\n\t\t\tRecords could not be fetched!!!");
        getch();
        return flag;
    }
    while (fread(&b, sizeof(b), 1, fpB))
    {
        if (book == b.num)
        {
            flag = 1;
            fclose(fpB);
            return flag;
        }
    }
    fclose(fpB);
    return flag;
}

void updateList(int a)
{
    if (a == 1)
    {
        unsigned int book, mem;
        FILE *fpR;
        struct records r;

        system("cls");

        printf("\n\nEnter member ID => ");
        scanf("%u", &mem);

        if (searchMember(mem) == 1)
        {
            printf("\nEnter book no. => ");
            scanf("%u", &book);

            if (searchList(book) == 0)
            {
                if (searchBook(book) == 1)
                {
                    fpR = fopen("records.bin", "wb");
                    if (fpR == NULL)
                    {
                        printf("\n\nUnable to fetch records!!");
                        getch();
                        return;
                    }
                    r.b_num = book;
                    r.m_num = mem;
                    fprintf(fpR, "\n%u %u", r.b_num, r.m_num);
                    fclose(fpR);
                    printf("\n\n\n\t\tBook issued to member ID => %u", mem);
                    getch();
                }
                else
                {
                    printf("\n\n\t\tNo such book exist in records!!!");
                    getch();
                    return;
                }
            }
            else
            {
                printf("\n\n\t\tBook no. %u is already issued!!!", book);
                getch();
                return;
            }
        }
        else
        {
            printf("\n\n\t\tNo Such member exist!!\n\t\tCheck member ID or add a new member..");
            getch();
            return;
        }
    }

    else if (a == 2)
    {
        unsigned int book, flag = 0;
        FILE *fpR, *fpW;
        struct records r;

        system("cls");

        printf("\n\nEnter book no. => ");
        scanf("%u", &book);

        fpR = fopen("records.bin", "rb");
        if (fpR = NULL)
        {
            printf("\n\n\t\tUnable to fetch records!!!");
            getch();
            return;
        }
        fpW = fopen("temp.bin", "wb");
        r.b_num = book;

        while (fread(&r, sizeof(r), 1, fpR))
        {
            if (book != r.b_num)
                fwrite(&r, sizeof(r), 1, fpW);
            else
            {
                printf("\n\n\t\tBook returned");
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("\n\n\t\tBook no. %u is not issued!!!", book);
            getch();
        }
        fclose(fpR);
        fclose(fpW);
        remove("records.bin");
        rename("temp.bin", "records.bin");
    }
}

void addBook()
{
    FILE *fpB;
    struct books b;

    system("cls");

    fpB = fopen("books.bin", "ab");
    if (fpB == NULL)
    {
        printf("\n\nUnable to fetch records!!");
        getch();
        return;
    }
    printf("\n\nEnter Book No. => ");
    scanf("%u", &b.num);
    fflush(stdin);
    if (searchBook(b.num == 1))
    {
        printf("\n\n\t\t\tBook number already taken!! Try Again..");
        fclose(fpB);
        getch();
        return;
    }
    printf("\nEnter Book Name => ");
    gets(b.name);
    fflush(stdin);
    printf("\nEnter Author Name => ");
    gets(b.author);

    fwrite(&b, sizeof(b), 1, fpB);
    fclose(fpB);

    printf("\n\n\t\t\t\tBook added Successfully!!!");
    getch();
}

void addMember()
{
    FILE *fpM;
    struct members m;

    system("cls");

    fpM = fopen("members.bin", "ab");
    if (fpM == NULL)
    {
        printf("\n\nUnable to fetch records!!");
        getch();
        return;
    }

    printf("\n\nEnter Member No. => ");
    scanf("%u", &m.num);
    fflush(stdin);
    if (searchMember(m.num) == 1)
    {
        printf("\n\n\t\t\tMember number already taken!! Try Again..");
        fclose(fpM);
        getch();
        return;
    }
    printf("\nEnter Member Name => ");
    gets(m.name);
    fflush(stdin);
    printf("\nEnter Member address => ");
    gets(m.addr);
    printf("\nEnter Member mob. no. => ");
    scanf("%s", &m.mob);
    fwrite(&m, sizeof(m), 1, fpM);
    fclose(fpM);

    printf("\n\n\t\t\t\tMember added Successfully!!!");
    getch();
}
void deleteMember()
{
    unsigned int num, flag = 0;
    FILE *fpM, *fpW;
    struct members m;

    system("cls");

    fpM = fopen("members.bin", "rb");
    if (fpM = NULL)
    {
        printf("\n\n\t\tUnable to fetch records!!!");
        getch();
        return;
    }
    fpW = fopen("temp.bin", "wb");
    printf("\n\n\t\tEnter member no. to delete => ");
    scanf("%u", &num);

    while (fread(&m, sizeof(m), 1, fpM))
    {
        if (num != m.num)
            fwrite(&m, sizeof(m), 1, fpW);
        else
        {
            printf("\n\n\t\tMember Deleted");
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\n\n\t\tNo such member exist!!!");
        getch();
    }
    fclose(fpM);
    fclose(fpW);
    remove("members.bin");
    rename("temp.bin", "members.bin");
}

void menu()
{
    int ch;
    do
    {
        system("cls");

        printf("\n\n\n\t\t\t\t*** What would you like to do? ***");
        printf("\n\n\t\t1.Add Book");
        printf("\n\t\t2.Delete Book");
        printf("\n\t\t3.Issue Book");
        printf("\n\t\t4.Return Book");
        printf("\n\t\t5.Add Member");
        printf("\n\t\t6.Delete Member");
        printf("\n\t\t0.Exit");

        printf("\n\n\n\t\tEnter your option: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addBook();
            break;
        case 2:
            deleteBook();
            break;
        case 3:
            updateList(1);
            break;
        case 4:
            updateList(2);
            break;
        case 5:
            addMember();
            break;
        case 6:
            deleteMember();
            break;
        case 0:
            endScreen();
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }
    } while (ch != 0);
}

void login()
{
    system("clr");
    
    int i = 3;
    while (i >= 1)
    {
        char us[20];
        char pass[20];
        int j=0;
        char ch = '\0';
        system("cls");
        // head();

        printf("\n\n\n\t\t\t\t\t\t   LOGIN PAGE");
        printf("\n\n\n\t\t\tEnter your Username:  ");
        scanf("%s",&us);
        printf("\n\t\t\tEnter your Password:  ");

        while (ch != 13)
        {
            ch = getch();

            if (ch != 13 && ch != 8)
            {
                putch('*');
                pass[j] = ch;
                j++;
            }
        }
        pass[j] = '\0';

        if ((strcmp(us, "Prad") == 0) && strcmp(pass, "pass") == 0)
        {
            printf("\n\n\n\t\t\t\t\t     LOGIN SUCCESSFULL!!!\n\t\t\t\t\t   Press any key to continue!\n\n\n\n");
            getch();
            return;
            break;
        }
        else
        {
            printf("\n\n\n\t\t\t\t\t    INVALID CREDENTIALS!!!\n\n");
            printf("\n\n\t\t\t\t\t    You have %d more tries!\n", --i);
            printf("\n\t\t\t\t\t   Press any key to continue\n");
            
            getch();
        }
    }
    if (i <= 0)
    {
        printf("\n\n\n\t\t\t\t    You have exhausted all your attempts!\n\n\n\n");
        exit(-1);
    }
}

int main()
{
    int choice;
    system("cls");
    printf("\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n\t\t|||||||||||||              WELCOME TO PRAD'S LSDMS!            |||||||||||||\n");
    printf("\n\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
    Sleep(8000);
    system("cls");
    login();
    system("cls");
    printf("\t\t\t\t   Which system would you like to enter? \n\n");
    printf("\t\t\t\t  1. Student Database Management System\n");
    printf("\t\t\t\t  2. Library Management System \n\n");
    printf("\t\t\t\t\t  Your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("clr");
        home_s();
        break;
    case 2:
        system("clr");
        head();
        break;
    }
}
