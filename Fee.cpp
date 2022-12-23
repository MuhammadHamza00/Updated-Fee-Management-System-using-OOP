#include <cstring>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits
#include <fstream>
using namespace std;
// ///////////////////////////////////////////////////////////////////////////////////////
//                                      ADMIN AREA
// ///////////////////////////////////////////////////////////////////////////////////////
// Functions in Main Program
void info_admin();
int *admin_search();
void del_catch(int pop);
void ptr_one_less(int p[]);
void info_operator();
void info_student();
void search_stu_opt();
void reg_com();
void show_com();
// to file data
void tofile();
// from file data
void getdata();
// go data to file
void instudent();
// get data from file
void studentdata();
// int s_a = 0; // search array count
int ad_size = 0;
int incre=0;
// int static stop;
int const arr = 10;

int total_admin_size = 100;
int total_stu_size = 100;

int access_count;
struct complain{
    string roll;
    char name[10];
    char comp[50];
};
complain pp[10];
// Access Giving Function ------------------------------------------------------------------?
struct pass
{
    char u_n[10];
    char d_n[10];
    int p;
};
pass d[arr];
void give_per()
{
    int i = 0;
    while (true)
    {
        cout << "Enter Username" << endl;
        cin >> d[i].u_n;
        cout << "Enter Password Assigned" << endl;
        cin >> d[i].p;
        cout << "Enter Department" << endl;
        cin >> d[i].d_n;
        int ch;
        cout << "Want to Exit(Press 0)" << endl;
        cin >> ch;
        if (ch == 0 || i == arr)
        {
            break;
        }
        i++;
    }
    access_count += i;
}
// ///////////////////////////////////////////////////////////////////////////////////////
//                                 END ADMIN AREA
// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////
//                                 DATA ENTRY OPERATOR
// /////////////////////////////////////////////////////////////////////////////////////
int opt_size = 0;
// ///////////////////////////////////////////////////////////////////////////////////////
//                                 END ADMIN AREA
// //////////////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////////////////
//                                  Admin Class
// ////////////////////////////////////////////////////////////////////////////////////////
class opt;
class admin
{
    friend class opt;

protected:
    char d_name[20];
    char program[10];

    int b_card;
    int com_f;
    int dev;
    int exam;
    int tour;
    int lab;
    int tuition;

public:
    friend void tofile();
    friend void getdata();
    // no argument constructor
    admin() : b_card(0), com_f(0), dev(0), exam(0), tour(0), lab(0), tuition(0)
    {
        strcpy(d_name, "");
        strcpy(program, "");
    }

    // get data 1
    int get_arg(char mer, char ftype, int t_fee)
    {
        if (mer == 's')
        {
            t_fee = t_fee * 2;
        }
        if (ftype == 'h')
        {
            t_fee = t_fee - (t_fee * 0.50);
        }
        if (ftype == 'd')
        {
            t_fee = t_fee - (t_fee * 0.70);
        }
        if (ftype == 's')
        {
            t_fee = t_fee - (t_fee * 0.90);
        }
        if (ftype == 'n')
        {
            t_fee = t_fee;
        }
        return t_fee;
    }
    // Get Data 2
    void getad()
    {
        cout << "\nEnter Tuition Fund" << endl;
        cin >> tuition;

        cout << "\nEnter Department Name" << endl;
        cin >> d_name;
        for (int i = 0; i < strlen(d_name); i++)
        {
            d_name[i] = tolower(d_name[i]);
        }

        cout << "\nEnter Program Name(e.g:BSCS,BSSE)" << endl;
        cin >> program;
        for (int i = 0; i < strlen(program); i++)
        {
            program[i] = tolower(program[i]);
        }

        cout << "\nEnter Bus Card Fee" << endl;
        cin >> b_card;

        cout << "\nEnter Computer Fund" << endl;
        cin >> com_f;
        cout << "\nEnter Development Fund" << endl;
        cin >> dev;
        cout << "\nEnter Exam Fund" << endl;
        cin >> exam;

        cout << "\nEnter Tour Fund" << endl;
        cin >> tour;

        cout << "\nEnter Lab Fund" << endl;
        cin >> lab;
    }
    // Show function
    void show_admin()
    {
        cout << "Tuition Fund\t" << tuition << endl;

        cout << "Department Name\t" << d_name << endl;

        cout << "Program Name(e.g:BSCS,BSSE)\t" << program << endl;

        cout << "Bus Card Fee\t" << b_card << endl;

        cout << "Computer Fund\t" << com_f << endl;

        cout << "Development Fund\t" << dev << endl;

        cout << "Exam Fund\t" << exam << endl;

        cout << "Tour Fund\t" << tour << endl;

        cout << "Lab Fund\t" << lab << endl;
    }
    // Search by Department Name
    int admin_s(char s[])
    {
        int r = strcmp(d_name, s);
        return r;
    }
    // Search by Program
    int admin_s_p(char d[])
    {
        int r = strcmp(program, d);
        return r;
    }
    // Match
    int match(char dep[], char pro[])
    {
        int r = strcmp(d_name, dep);
        int g = strcmp(program, pro);

        if (r == 0 && g == 0)
        {

            return 1;
        }
        else
        {

            return 0;
        }
    }
};
admin *admin_ptr = new admin[total_admin_size];
// ////////////////////////////////////////////////////////////////////////////////////////
//                                  Data Entry Class
// ////////////////////////////////////////////////////////////////////////////////////////
class opt : public admin
{
private:
    // Checking
    char o_name[10];
    char o_prog[10];
    // voucher
    char name[10];
    int rollno;
    int sess;
    char fname[10];
    int sems;
    char s_r;
    char f_type;
    string duedate;
    char status[10];
    // Voucher columns
    int s_b_card;
    int s_com_f;
    int s_dev;
    int s_exam;
    int s_tour;
    int s_lab;
    int s_tuition;
    // Total
    int t_total;

public:
    friend void instudent();
    friend void studentdata();
    void get_stud()
    {

        cout << "\nEnter Department Name" << endl;
        cin >> o_name;
        for (int i = 0; i < strlen(o_name); i++)
        {
            o_name[i] = tolower(o_name[i]);
        }

        cout << "\nEnter Program" << endl;
        cin >> o_prog;
        for (int i = 0; i < strlen(o_prog); i++)
        {
            o_prog[i] = tolower(o_prog[i]);
        }

        cout << "\nEnter Student name" << endl;
        cin >> name;
        for (int i = 0; i < strlen(name); i++)
        {
            name[i] = tolower(name[i]);
        }

        cout << "\nEnter roll no" << endl;
        cin >> rollno;

        cout << "\nEnter Session" << endl;
        cin >> sess;

        cout << "\nEnter Father Name" << endl;
        cin >> fname;
        for (int i = 0; i < strlen(fname); i++)
        {
            fname[i] = tolower(fname[i]);
        }

        cout << "\nEnter Semester" << endl;
        cin >> sems;

        cout << "\nEnter Self or Regular(\nPress 's' for Self\t Press 'r' for Regular)" << endl;
        cin >> s_r;
        s_r = tolower(s_r);

        cout << "\nEnter Fee Type:\n=> Hafiz(Press h) \n=>Disabled(Press d) \n =>Scholarship(Press s)\n=>Normal Fee(Press n)" << endl;
        cin >> f_type;
        f_type = tolower(f_type);

        cout << "\nEnter Due Date" << endl;
        cin >> duedate;

        cout << "\nEnter Fee Status:" << endl;
        cin >> status;

        for (int i = 0; i < strlen(status); i++)
        {
            status[i] = tolower(status[i]);
        }

        for (int i = 0; i < ad_size; i++)
        {
            int mtch = admin_ptr[i].match(o_name, o_prog);
            if (mtch == 1)
            {
                s_b_card = admin_ptr[i].b_card;
                s_com_f = admin_ptr[i].com_f;
                s_dev = admin_ptr[i].dev;
                s_exam = admin_ptr[i].exam;
                s_tour = admin_ptr[i].tour;
                s_lab = admin_ptr[i].lab;
                s_tuition = admin_ptr[i].tuition;
            }
        }
        s_tuition = get_arg(s_r, f_type, s_tuition);
        t_total = s_b_card + s_com_f + s_dev + s_exam + s_tour + s_lab + s_tuition;
    }

    void show_stu()
    {

        cout << "Name of student\t" << name << endl;

        cout << "Department Name\t" << o_name << endl;

        cout << "Program Name\t" << o_prog << endl;

        cout << "Tuition Fee\t" << s_tuition << endl;

        cout << "Roll no\t" << rollno << endl;

        cout << "Session\t" << sess << endl;

        cout << "Father Name\t" << fname << endl;

        cout << "Semester\t" << sems << endl;
        tolower(s_r);
        tolower(f_type);

        if (s_r == 'r')
        {
            cout << "Self or Regular\tRegular" << endl;
        }
        else if (s_r == 's')
        {
            cout << "Self or Regular\tSelf" << endl;
        }

        if (f_type == 'h')
        {
            cout << "Fee Type\tHafiz" << endl;
        }
        else if (f_type == 's')
        {
            cout << "Fee Type\tScholarship" << endl;
        }
        else if (f_type == 'd')
        {
            cout << "Fee Type\tDisabled Student" << endl;
        }
        else
        {
            cout << "Fee Type\tNormal" << endl;
        }

        cout << "Bus Card Fee\t" << s_b_card << endl;

        cout << "Computer Fund\t" << s_com_f << endl;

        cout << "Development Fund\t" << s_dev << endl;

        cout << "Exam Fund\t" << s_exam << endl;

        cout << "Tour Fund\t" << s_tour << endl;

        cout << "Lab Fund\t" << s_lab << endl;

        cout << "Due Date\t" << duedate << endl;

        cout << "Fee Status\t" << status << endl;

        cout << "===========================================================================================" << endl;
        cout << "Total\t" << t_total << endl;
        cout << "===========================================================================================" << endl;
    }

    // Search by Department Name
    int opt_d(char s[])
    {
        int r = strcmp(o_name, s);
        return r;
    }
    // Search by Program Name
    int opt_p(char d[])
    {
        int r = strcmp(o_prog, d);
        return r;
    }
    // Search by Roll no
    int opt_r(int roll)
    {
        if (rollno == roll)
        {
            return 0;
        }
    }
    // Search by Name
    int opt_n(char d[])
    {
        int r = strcmp(name, d);
        return r;
    }
    // sEARCH BY Status
    int opt_st(char d[])
    {
        int r = strcmp(status, d);
        return r;
    }
};
opt *opt_ptr = new opt[total_stu_size];

///////////////////////////////////////////////////////////////////////////////////////////
// ===================================Main Class=========================================//
// /////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    fstream in;
    in.open("asize.txt", ios::in);
    if (in.is_open())
    {
        in >> ad_size;
    }
    fstream in2;
    in2.open("ssize.txt", ios::in);
    if (in2.is_open())
    {
        in2 >> opt_size;
    }
    getdata();
    instudent();
// Start here:=====================================================================>
mania:
    cout << "Welcome to University of Sargodha" << endl;
    cout << "Fee Management System" << endl;
    cout << "Who Are You?\n1.Admin \n 2.Data Operator \n 3.Student \n 4.Exit" << endl;
    int choice2;
    cin >> choice2;
    switch (choice2)
    {
    case 1:
    {
        cout << "Status \tAdmin" << endl;
        info_admin();
        goto mania;
    }
    case 2:
    {
        cout << "Status:\tOperator" << endl;
        info_operator();
        goto mania;
    }
    case 3:
    {
        cout << "Status:\tStudent" << endl;
        info_student();
        goto mania;
    }
    case 4:
    {
        fstream out;
        out.open("asize.txt", ios::out);
        if (out.is_open())
        {
            out << ad_size << endl;
        }
        fstream out2;
        out2.open("ssize.txt", ios::out);
        if (out2.is_open())
        {
            out2 << opt_size << endl;
        }
        out2.close();
        tofile();
        studentdata();
        exit(1);
    }
    }

    return 0;
}
// Info Admin---------------------------------------------------------------------------------
void info_admin()
{
start:
    int ch = 0;
    do
    {
        cout << "Enter Option You Want to Do? \n 1.Add Data \n 2.Search Data \n 3.Edit Data \n 4.Delete Data \n 5.Display All Data \n6.See Complaint Box \n7.Exit \n"
             << endl;
        int c_a_1;
        cin >> c_a_1;
        switch (c_a_1)
        {
            // Add Data-----------------------------------------------------------------------------------
        case 1:
        {
            int i;
            for (int i = 0; i < total_admin_size; i++)
            {
                cout << "I am enter" << endl;
                admin_ptr[i].getad();
                ad_size++;
                cout << "Want to continue:(Press 1)" << endl;
                int choice;
                cin >> choice;
                if (choice == 1)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            goto start;
        }
            // Search Data------------------------------------------------------------------------------
        case 2:
        {
            cout << "Enter Option:\n1.Department Name\n2.Program Name" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                cout << "Enter Department Name:" << endl;
                char d_name[20];
                cin >> d_name;
                for (int i = 0; i < strlen(d_name); i++)
                {
                    d_name[i] = tolower(d_name[i]);
                }
                for (int i = 0; i < ad_size; i++)
                {
                    int r = admin_ptr[i].admin_s(d_name);

                    if (r == 0)
                    {
                        admin_ptr[i].show_admin();
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else if (ch == 2)
            {
                cout << "Enter Program Name" << endl;
                char p_name[10];
                cin >> p_name;
                for (int i = 0; i < strlen(p_name); i++)
                {
                    p_name[i] = tolower(p_name[i]);
                }
                for (int i = 0; i < ad_size; i++)
                {
                    int r = admin_ptr[i].admin_s_p(p_name);

                    if (r == 0)
                    {
                        admin_ptr[i].show_admin();
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else
            {
                cout << "Not Found" << endl;
            }

            goto start;
        }
            // Edit Data-------------------------------------------------------------------------------
        case 3:
        {
            cout << "Enter Program Name to Edit:" << endl;
            char p_name[10];
            cin >> p_name;
            for (int i = 0; i < strlen(p_name); i++)
            {
                p_name[i] = tolower(p_name[i]);
            }
            for (int i = 0; i < ad_size; i++)
            {
                int r = admin_ptr[i].admin_s_p(p_name);

                if (r == 0)
                {
                    admin_ptr[i].getad();
                }
                else
                {
                    continue;
                }
            }

            goto start;
        }
            // Delete Data--------------------------------------------------------------------------------
        case 4:
        {
            cout << "Delete by \n1.BY Program \n 2. BY Department" << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                cout << "Enter Program Name" << endl;
                char p_name[10];
                cin >> p_name;
                for (int i = 0; i < strlen(p_name); i++)
                {
                    p_name[i] = tolower(p_name[i]);
                }
                for (int i = 0; i < ad_size; i++)
                {
                    int r = admin_ptr[i].admin_s_p(p_name);

                    if (r == 0)
                    {
                        del_catch(i);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            else if (ch == 2)
            {
                cout << "Enter Department Name:" << endl;
                char d_name[20];
                cin >> d_name;
                for (int i = 0; i < strlen(d_name); i++)
                {
                    d_name[i] = tolower(d_name[i]);
                }
                for (int i = 0; i < ad_size; i++)
                {
                    int r = admin_ptr[i].admin_s(d_name);

                    if (r == 0)
                    {
                        del_catch(i);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            goto start;
        }

        case 5:
        {
            for (int i = 0; i < ad_size; i++)
            {
                admin_ptr[i].show_admin();
            }
            goto start;
        }
        case 6:
        {
            show_com();
        }
        default:
            break;
        }
        cout << "Want to Continue Press 1" << endl;
        cin >> ch;
    } while (ch == 1);
}
// del catch----------------------------------------------------------------------------------
void del_catch(int pop)
{
    for (int i = pop; i < ad_size; i++)
    {
        admin_ptr[i] = admin_ptr[i + 1];
    }
    ad_size = ad_size - 1;
}
void del_catch_stu(int pop)
{
    for (int i = pop; i < opt_size; i++)
    {
        opt_ptr[i] = opt_ptr[i + 1];
    }
    opt_size = opt_size - 1;
}
// Ending of the ADMIN CLASS ================================================================>

// /////////////////////////////////////////////////////////////////////////////////////////
//                                   Operator Area
// ////////////////////////////////////////////////////////////////////////////////////////
void info_operator()
{
start2:

    cout << "Enter Option You Want to Do? \n 1.Add Data \n 2.Search Data \n 3.Edit Data \n 4.Delete Data \n 5.Display All Data \n6.Exit\n"
         << endl;
    int c_a_1;
    cin >> c_a_1;
    switch (c_a_1)
    {
    // AddData-----------------------------------------------------------------------------------
    case 1:
    {

        for (int i = opt_size; i < total_stu_size; i++)
        {
            opt_ptr[i].get_stud();
            opt_size++;
            cout << "Want to continue:(Press 1)" << endl;
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        goto start2;
    }
        // SearchData------------------------------------------------------------------------------
    case 2:
    {
        search_stu_opt();
        goto start2;
    }
        // EditData-------------------------------------------------------------------------------
    case 3:
    {
        cout << "Enter Roll no of Student:" << endl;
        int roll;
        cin >> roll;
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_r(roll);

            if (r == 0)
            {
                opt_ptr[i].get_stud();
            }
            else
            {
                continue;
            }
        }
        goto start2;
    }
        // DeleteData--------------------------------------------------------------------------
    case 4:
    {
        cout << "Enter Name" << endl;
        char p_name[10];
        cin >> p_name;
        for (int i = 0; i < strlen(p_name); i++)
        {
            p_name[i] = tolower(p_name[i]);
        }
        cout << "Enter Roll no" << endl;
        int roll;
        cin >> roll;
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_n(p_name);
            int p = opt_ptr[i].opt_r(roll);

            if (r == 0 && p == 0)
            {
                del_catch_stu(i);
            }
            else
            {
                continue;
            }
        }
        goto start2;
    }
    case 5:
    {
        for (int i = 0; i < opt_size; i++)
        {
            opt_ptr[i].show_stu();
        }
    default:
        break;
    }
    }
    cout << "Want to continue Press 1" << endl;
    int ch;
    if (ch == 1)
    {
        goto start2;
    }
    // else
    // {

    // }
}
// Search function for student and operator
void search_stu_opt()
{
man:
    cout << "Enter Option:\n1.Search by Roll no \n2.Search by Program Name \n 3. Search by Department  \n4.Search by Name\n 5.Status \n 6.Exit" << endl;
    int ch;
    cin >> ch;
    // By Roll No
    switch (ch)
    {
    case 1:
    {
        cout << "Enter Roll Number:" << endl;
        int roll;
        cin >> roll;
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_r(roll);

            if (r == 0)
            {
                opt_ptr[i].show_stu();
            }
            else
            {
                continue;
            }
        }
        goto man;
    }
    // By Program Name
    case 2:
    {
        cout << "Enter Program Name" << endl;
        char p_name[10];
        cin >> p_name;
        for (int i = 0; i < strlen(p_name); i++)
        {
            p_name[i] = tolower(p_name[i]);
        }
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_p(p_name);

            if (r == 0)
            {
                opt_ptr[i].show_stu();
            }
            else
            {
                continue;
            }
        }
        goto man;
    }
    // By Department
    case 3:
    {
        cout << "Enter Department Name" << endl;
        char d_name[20];
        cin >> d_name;
        for (int i = 0; i < strlen(d_name); i++)
        {
            d_name[i] = tolower(d_name[i]);
        }
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_d(d_name);

            if (r == 0)
            {
                opt_ptr[i].show_stu();
            }
            else
            {
                continue;
            }
        }
        goto man;
    }
    // by student name
    case 4:
    {
        cout << "Enter Student Name " << endl;
        char s_name[10];
        cin >> s_name;
        for (int i = 0; i < strlen(s_name); i++)
        {
            s_name[i] = tolower(s_name[i]);
        }
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_n(s_name);

            if (r == 0)
            {
                opt_ptr[i].show_stu();
            }
            else
            {
                continue;
            }
        }
        goto man;
    }
    // by status
    case 5:
    {
        cout << "Enter Fee Status (paid or unpaid)" << endl;
        char s_name[10];
        cin >> s_name;
        for (int i = 0; i < strlen(s_name); i++)
        {
            s_name[i] = tolower(s_name[i]);
        }
        for (int i = 0; i < opt_size; i++)
        {
            int r = opt_ptr[i].opt_st(s_name);
            if (r == 0)
            {
                opt_ptr[i].show_stu();
            }
            else
            {
                continue;
            }
        }
        goto man;
    }
    // terminate
    case 6:
    {
        break;
    }
    }
}
void reg_com(){
    for (int i = 0; i < 10; i++)
    {
        incre++;
        cout<<"Enter Name:"<<endl;
        cin>>pp[i].name;
        cout<<"Enter Roll no:"<<endl;
        cin>>pp[i].roll;
        cout<<"Describe Issue"<<endl;
        cin>>pp[i].comp;

        cout<<"Want to Exit press 0"<<endl;
        int ch;
        cin>>ch;
        if (ch==0)
        {
            break;
        }
        
    }   
}
void show_com(){
    for (int i = 0; i <=incre; i++)
    {
        cout<<"Name"<<pp[i].name<<endl;
        cout<<"Roll no"<<pp[i].roll<<endl;
        cout<<"Issue"<<pp[i].comp<<endl;
    }
    
}
// Info Student
void info_student()
{
    cout<<"\nEnter Choice:\n1.Search\n2.Register Complain\n3.Exit"<<endl;
    int ch;
    cin>>ch;
    switch (ch)
    {
    case 1:
        search_stu_opt();
        break;
    case 2:
        reg_com();
        break;
    default:
        break;
    }
    
}

void tofile()
{
    fstream migrate;
    migrate.open("adgo.txt", ios::out); // write data in admin.txt
    if (migrate.is_open())
    {
        for (int k = 0; k < ad_size; k++)
        {
            migrate << admin_ptr[k].d_name << endl;
            migrate << admin_ptr[k].program << endl;
            migrate << admin_ptr[k].b_card << endl;
            migrate << admin_ptr[k].com_f << endl;
            migrate << admin_ptr[k].dev << endl;
            migrate << admin_ptr[k].exam << endl;
            migrate << admin_ptr[k].tour << endl;
            migrate << admin_ptr[k].lab << endl;
            migrate << admin_ptr[k].tuition << endl;
        }
        migrate.close();
    }
    else
    {
        cout << "File Not Found" << endl;
    }
}
void studentdata()
{
    fstream migrate2;
    migrate2.open("optgo.txt", ios::out); // write data in optgo.txt
    if (migrate2.is_open())
    {
        for (int k = 0; k < opt_size; k++)
        {
            // Checking
            migrate2 << opt_ptr[k].o_name << endl;
            migrate2 << opt_ptr[k].o_prog << endl;
            // voucher
            migrate2 << opt_ptr[k].name << endl;
            migrate2 << opt_ptr[k].rollno << endl;
            migrate2 << opt_ptr[k].sess << endl;
            migrate2 << opt_ptr[k].fname << endl;
            migrate2 << opt_ptr[k].sems << endl;
            migrate2 << opt_ptr[k].s_r << endl;
            migrate2 << opt_ptr[k].f_type << endl;
            migrate2 << opt_ptr[k].duedate << endl;
            migrate2 << opt_ptr[k].status << endl;
            // Voucher columns
            migrate2 << opt_ptr[k].s_b_card << endl;
            migrate2 << opt_ptr[k].s_com_f << endl;
            migrate2 << opt_ptr[k].s_dev << endl;
            migrate2 << opt_ptr[k].s_exam << endl;
            migrate2 << opt_ptr[k].s_tour << endl;
            migrate2 << opt_ptr[k].s_lab << endl;
        }
        migrate2.close();
    }
    else
    {
        cout << "File Not Found" << endl;
    }
}
void getdata()
{
    fstream getting;
    getting.open("adgo.txt", ios::in);
    if (getting.is_open())
    {
        for (int h = 0; h < ad_size; h++)
        {
            getting >> admin_ptr[h].d_name;
            getting >> admin_ptr[h].program;
            getting >> admin_ptr[h].b_card;
            getting >> admin_ptr[h].com_f;
            getting >> admin_ptr[h].dev;
            getting >> admin_ptr[h].exam;
            getting >> admin_ptr[h].tour;
            getting >> admin_ptr[h].lab;
            getting >> admin_ptr[h].tuition;
        }
    }
}
void instudent()

{
    fstream getting2;
    getting2.open("optgo.txt", ios::in); // write data in admin.txt
    if (getting2.is_open())
    {
        for (int k = 0; k < opt_size; k++)
        {
            // Checking
            getting2 >> opt_ptr[k].o_name;
            getting2 >> opt_ptr[k].o_prog;
            // voucher
            getting2 >> opt_ptr[k].name;
            getting2 >> opt_ptr[k].rollno;
            getting2 >> opt_ptr[k].sess;
            getting2 >> opt_ptr[k].fname;
            getting2 >> opt_ptr[k].sems;
            getting2 >> opt_ptr[k].s_r;
            getting2 >> opt_ptr[k].f_type;
            getting2 >> opt_ptr[k].duedate;
            getting2 >> opt_ptr[k].status;
            // Voucher columns
            getting2 >> opt_ptr[k].s_b_card;
            getting2 >> opt_ptr[k].s_com_f;
            getting2 >> opt_ptr[k].s_dev;
            getting2 >> opt_ptr[k].s_exam;
            getting2 >> opt_ptr[k].s_tour;
            getting2 >> opt_ptr[k].s_lab;
        }
        getting2.close();
    }
}