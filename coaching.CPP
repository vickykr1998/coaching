/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//COACHING INSTITUTE MANAGEMENT SYSTEM

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Headers inclusion


#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include<cstdlib>



using namespace std;

int rec_flag_student=0,no_student=0;
char rec_ind_student[5];

int rec_flag_teacher=0,no_teacher=0;
char rec_ind_teacher[5];

//Structure defining

//For students
struct student
{
 char fname[20];//for student first name
 char lname[20];//for student last name
 char registrationid[20];//for Registration No number
 char age[5];//student phone
 char feestatus[10];//fee status of students
 char cel_no[20];//Phone number
 char batch[20];//for class info
 char ind[5];//for index

}studentData[20];//Variable of student type

//For teachers
struct teacher
{
 char fst_name[20];//first name of teacher
 char lst_name[20];//last name of teacher
 char teacherid[20];//id for teacher
 char qualification[20];//Qualification of teacher
 char pay[10];//Pay of the Teacher
 char batch[20];//subject which he/she teach
 char cel_no[20];//Phone number
 char ind[5];//for index


}teacherData[20];//Variable of teacher type

struct index
{
	char registrationid[20],indstudent[20];
}instudent[20],tempstudent;

struct index1
{
	char teacherid[20],indteacher[20];
}inteacher[20],tempteacher;

void sort_index_student()
{
	int i,j;

	for(i=0;i<no_student-1;i++)
	for(j=0;j<no_student-i-1;j++)
	if(strcmp(instudent[j].registrationid,instudent[j+1].registrationid)>0)
	{
		tempstudent=instudent[j];
		instudent[j]=instudent[j+1];
		instudent[j+1]=tempstudent;
	}
}

void sort_index_teacher()
{

	int i,j;

	for(i=0;i<no_teacher-1;i++)
	for(j=0;j<no_teacher-i-1;j++)
	if(strcmp(inteacher[j].teacherid,inteacher[j+1].teacherid)>0)
	{
		tempteacher=inteacher[j];
		inteacher[j]=inteacher[j+1];
		inteacher[j+1]=tempteacher;
	}
}

void retrive_record_student(char *ind)
{
	for(int i=0;i<no_student;i++)
	{
		if(strcmp(studentData[i].ind,ind)==0)
		{
			strcpy(rec_ind_student,ind);
			rec_flag_student=1;
			cout<<"Record found:\n";
			cout<<studentData[i].ind<<"\t"<<studentData[i].fname<<"\t"<<studentData[i].lname<<"\t"<<studentData[i].registrationid<<"\t"<<studentData[i].age<<"\t"<<studentData[i].cel_no<<"\t"<<studentData[i].batch<<"\n";
            return;
		}
	}

	cout<<"Press any key to continue\n";
    getch();
}

void retrive_record_teacher(char *ind)
{
	for(int i=0;i<no_teacher;i++)
	{
		if(strcmp(teacherData[i].ind,ind)==0)
		{
			strcpy(rec_ind_teacher,ind);
			rec_flag_teacher=1;
			cout<<"Record found:\n";
			cout<<teacherData[i].ind<<"\t"<<teacherData[i].fst_name<<"\t"<<teacherData[i].lst_name<<"\t"<<teacherData[i].teacherid<<"\t"<<teacherData[i].qualification<<"\t"<<teacherData[i].pay<<"\t"<<teacherData[i].batch<<"\t"<<teacherData[i].cel_no<<"\n";
			return;
		}
	}
	cout<<"Press any key to continue\n";
    getch();
}

int search_index_student(char *registrationid)
{
	int flag=0;
	for(int i=0;i<no_student;i++)
	{
		if(strcmp(instudent[i].registrationid,registrationid)==0)
		{
			retrive_record_student(instudent[i].indstudent);
			flag=1;
		}
	}
	if(flag)
		return 1;
	else
		return -1;
}

int search_index_teacher(char *teacherid)
{
	int flag=0;
	for(int i=0;i<no_teacher;i++)
	{
		if(strcmp(inteacher[i].teacherid,teacherid)==0)
		{
			retrive_record_teacher(inteacher[i].indteacher);
			flag=1;
		}
	}
	if(flag)
		return 1;
	else
		return -1;
}

int search_id_student(char *registrationid,int j)
{
	int flag=0;
	for(int i=0;i<j;i++)
	{
		if(strcmp(studentData[i].registrationid,registrationid)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		return 1;
	else
		return -1;
}

int search_id_teacher(char *teacherid,int j)
{
	int flag=0;
	for(int i=0;i<j;i++)
	{
		if(strcmp(teacherData[i].teacherid,teacherid)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		return 1;
	else
		return -1;
}


void delet_student(char *st_registrationid)
{
	rec_flag_student=0;
	int fr=0;
	search_index_student(st_registrationid);
	if(!rec_flag_student)
	{
		cout<<"Deletion failed.Record not found\n";
		cout<<"Press any key to continue\n";
		getch();
		return;

	}
	for(int i=0;i<no_student;i++)
	{
		if(strcmp(studentData[i].ind,rec_ind_student)==0)
		{
			fr=i;
			break;
		}
	}
	for(int i=fr;i<no_student-1;i++)
	{
		studentData[i]=studentData[i+1];
		char str[3];
		sprintf(str,"%d",i);
		strcpy(studentData[i].ind,str);
	}
	no_student--;
	fstream f1,f2;
	f1.open("record_student.txt",ios::out);
	f2.open("index_student.txt",ios::out);
	for(int i=0;i<no_student;i++)
	{
		strcpy(instudent[i].registrationid,studentData[i].registrationid);
		strcpy(instudent[i].indstudent,studentData[i].ind);
	}
	sort_index_student();
	for(int i=0;i<no_student;i++)
	{
	    f1<<studentData[i].ind<<"|"<<studentData[i].fname<<"|"<<studentData[i].lname<<"|"<<studentData[i].registrationid<<"|"<<studentData[i].feestatus<<"|"<<studentData[i].age<<"|"<<studentData[i].cel_no<<"|"<<studentData[i].batch<<"\n";
		f2<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
	}
	f1.close();
	f2.close();
	cout<<"Deletion successful\n";
	cout<<"Press any key to continue\n";
	getch();
}


void delet_teacher(char *st_teacherid)
{
	rec_flag_teacher=0;
	int fr=0;
	search_index_teacher(st_teacherid);
	if(!rec_flag_teacher)
	{
		cout<<"Deletion failed.Record not found\n";
		cout<<"Press any key to continue\n";
		getch();
		return;
	}
	for(int i=0;i<no_teacher;i++)
	{
		if(strcmp(teacherData[i].ind,rec_ind_teacher)==0)
		{
			fr=i;
			break;
		}
	}
	for(int i=fr;i<no_teacher-1;i++)
	{
		teacherData[i]=teacherData[i+1];
		char str[3];
		sprintf(str,"%d",i);
		strcpy(teacherData[i].ind,str);
	}
	no_teacher--;
	fstream f1,f2;
	f1.open("record_teacher.txt",ios::out);
	f2.open("index_teacher.txt",ios::out);
	for(int i=0;i<no_teacher;i++)
	{
		strcpy(inteacher[i].teacherid,teacherData[i].teacherid);
		strcpy(inteacher[i].indteacher,teacherData[i].ind);
	}
	sort_index_teacher();
	for(int i=0;i<no_teacher;i++)
	{
	    f1<<teacherData[i].ind<<"|"<<teacherData[i].fst_name<<"|"<<teacherData[i].lst_name<<"|"<<teacherData[i].teacherid<<"|"<<teacherData[i].qualification<<"|"<<teacherData[i].pay<<"|"<<teacherData[i].batch<<"|"<<teacherData[i].cel_no<<"\n";
		f2<<inteacher[i].teacherid<<"|"<<inteacher[i].indteacher<<"\n";
	}
	f1.close();
	f2.close();
	cout<<"Deletion successful\n";
	cout<<"Press any key to continue\n";
	getch();
}

void update_status(char *id)
{

    for (int k = 0;k<no_student;k++)
    {
        if(strcmp(studentData[k].registrationid,id)==0)
        {
            if (strcmp(studentData[k].feestatus,"Unpaid")==0)
            {
                strcpy(studentData[k].feestatus,"Paid");
            }
        }
    }
    fstream f1;
	f1.open("record_student.txt",ios::out);
    for(int k = 0;k<no_student;k++ )
    {

        f1<<studentData[k].ind<<"|"<<studentData[k].fname<<"|"<<studentData[k].lname<<"|"<<studentData[k].registrationid<<"|"<<studentData[k].feestatus<<"|"<<studentData[k].age<<"|"<<studentData[k].cel_no<<"|"<<studentData[k].batch<<"\n";
    }
    f1.close();
    cout<<"Updation successful";
    cout<<"Press any key to continue";
    getch();
}







///////////////////////////////////////////////////
//Main function

int main()
{

    char fname[20];//for student first name
    char lname[20];//for student last name
    char registrationid[20];//for Registration No number
    char st_registrationid[20];
    char age[5];//student phone
    char feestatus[10];//fee status of student
    char cel_no_student[20];//Phone number
    char batch_student[20];//for class info
    char ind_student[5];//for index

    char fst_name[20];//first name of teacher
    char lst_name[20];//last name of teacher
    char teacherid[20];//id for teacher
    char st_teacherid[20];
    char qualification[20];//Qualification of teacher
    char pay[10];//Pay of the Teacher
    char batch_teacher[20];//subject which he/she teach
    char cel_no_teacher[20];//Phone number
    char ind_teacher[5];//for index

    fstream file1;
    int i=0,j;//for processing usage
    char choice;//for getting choice


					fstream file2;
					file1.open("record_student.txt",ios::in);
					file2.open("index_student.txt",ios::out);
					for(int i=0;i<100;i++)
					{
						file1.getline(studentData[i].ind,5,'|');
						file1.getline(studentData[i].fname,20,'|');
						file1.getline(studentData[i].lname,20,'|');
						file1.getline(studentData[i].registrationid,20,'|');
						file1.getline(studentData[i].feestatus,10,'|');
						file1.getline(studentData[i].age,5,'|');
						file1.getline(studentData[i].cel_no,20,'|');
						file1.getline(studentData[i].batch,20,'\n');
						strcpy(instudent[i].registrationid,studentData[i].registrationid);
						strcpy(instudent[i].indstudent,studentData[i].ind);
						int m=atoi(studentData[i].ind);
						if(i==m)
							no_student++;
						else
							break;

					}
					sort_index_student();
					for(int i=0;i<no_student;i++)
					{
						file2<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
					}
					file1.close();
					file2.close();
                      fstream f11,f21;
					f11.open("record_teacher.txt",ios::in);
					f21.open("index_teacher.txt",ios::out);
					for(int i=0;i<100;i++)
					{
						f11.getline(teacherData[i].ind,5,'|');
						f11.getline(teacherData[i].fst_name,20,'|');
						f11.getline(teacherData[i].lst_name,20,'|');
						f11.getline(teacherData[i].teacherid,20,'|');
						f11.getline(teacherData[i].qualification,20,'|');
						f11.getline(teacherData[i].pay,10,'|');
						f11.getline(teacherData[i].batch,20,'|');
						f11.getline(teacherData[i].cel_no,10,'\n');
						strcpy(inteacher[i].teacherid,teacherData[i].teacherid);
						strcpy(inteacher[i].indteacher,teacherData[i].ind);
						int m=atoi(teacherData[i].ind);
						if(i==m)
							no_teacher++;
						else
							break;
					}
					sort_index_teacher();
					for(int i=0;i<no_teacher;i++)
					{
						f21<<inteacher[i].teacherid<<"|"<<inteacher[i].indteacher<<"\n";
					}
					f11.close();
					f21.close();




while(1)//outer loop
{
 system("cls");//Clear screen
//Level 1-Display process
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\t\t\tCOACHING INSTITUTE MANAGEMENT SYSTEM\n\n";
 cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";
 cout<<"\n\n\t\t\t\t\t\tHOME PAGE\n\n";
 cout<<"This is a Coaching institute management system,used to maintain the records of students and teachers in the Coaching\n";
 cout<<"\t\t\tThe two basic sections on the software are: \n";
 cout<<"\t\t\t1.Student Section\n";
 cout<<"\t\t\t2.Teachers Section\n\n";
 cout<<"Which section do you want to enter? Choose an option from the menu.\n";
 cout<<"1.Students information"<<endl;
 cout<<"2.Teacher information"<<endl;
 cout<<"3.Exit program"<<endl;
 cin>>choice;

system("cls");//Clear screen


switch(choice)//First switch
{

case '1': //Student
{
     int n;
while(1)//inner loop-1
{
system("cls");//Clear screen
//Level-2 display
cout<<"\n\n\t\t\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.New Admission\n";
cout<<"2.Find Student\n";
cout<<"3.Check fee status\n";
cout<<"4.Remove Student\n";
cout<<"5.Display Students Batch-wise\n";
cout<<"6.Display all Students\n";
cout<<"7.Update Fee status\n";
cout<<"8.Jump to Main Menu\n";
cin>>choice;

switch (choice)//Second switch

{
    case '1'://Insert data
    {
        file1.open("record_student.txt",ios::app|ios::out);

        while(choice!='n')
        {

            if((choice=='y')||(choice=='Y')||(choice=='1'))
            {

                cout<<"enter the no of students:\t";
                cin>>n;
                cout<<"enter the details\n";
                for(i = no_student;i<no_student+n;i++)
				{
					label: cout<<"enter "<<i+1<<" student details:\n";
					cout<<"First name : ";
					cin>>studentData[i].fname;
					cout<<"Last name : ";
					cin>>studentData[i].lname;
					cout<<"Registration Id : ";
					cin>>studentData[i].registrationid;
					cout<<"Fee Status : ";
					cin>>studentData[i].feestatus;
					cout<<"Age : ";
					cin>>studentData[i].age;
					cout<<"Batch Allotted : ";
					cin>>studentData[i].batch;
					cout<<"Contact Number : ";
					cin>>studentData[i].cel_no;
					int q = search_id_student(studentData[i].registrationid,i);
					if(q==1)
					{
						cout<<"Duplicate value\n";
						cout<<"enter again:\n";
						goto label;
					}
					file1<<i<<"|"<<studentData[i].fname<<"|"<<studentData[i].lname<<"|"<<studentData[i].registrationid<<"|"<<studentData[i].feestatus<<"|"<<studentData[i].age<<"|"<<studentData[i].cel_no<<"|"<<studentData[i].batch<<"\n";

				}
				no_student=no_student+n;
				cout<<"Do you want to enter more data?\n ";
                cout<<"Press Y for Continue and N to Finish:  ";
                cin>>choice;

            }
        }
                file1.close();

					fstream file1,file2;
					file1.open("record_student.txt",ios::in);
					file2.open("index_student.txt",ios::out);
					for(int i=0;i<no_student;i++)
					{
						file1.getline(ind_student,5,'|');
						file1.getline(fname,20,'|');
						file1.getline(lname,20,'|');
						file1.getline(registrationid,20,'|');
						file1.getline(feestatus,10,'|');
						file1.getline(age,5,'|');
						file1.getline(cel_no_student,20,'|');
						file1.getline(batch_student,20,'\n');
						strcpy(studentData[i].ind,ind_student);
						strcpy(instudent[i].registrationid,registrationid);
						strcpy(instudent[i].indstudent,ind_student);
					}
					sort_index_student();
					for(int i=0;i<no_student;i++)
					{
						file2<<instudent[i].registrationid<<"|"<<instudent[i].indstudent<<"\n";
					}
					file1.close();
					file2.close();
    }
continue;//control back to inner loop -1

case '2'://search data
{
                cout<<"Enter the Id of the student whose record is to be searched:\t";
				cin>>st_registrationid;
				int q=search_index_student(st_registrationid);
				if(q==1){
					cout<<"Search successful\n";
					cout<<"Press any key to continue\n";
                    getch();
				}
				else{
					cout<<"Search unsuccessful\n";
					cout<<"Press any key to continue\n";
                    getch();
				}

}
continue;//control back to inner loop -1

case '3'://print fee status
    {
        char ch;
        cout<<"Choose the kind of status\n";
        cout<<"1.Paid\n";
        cout<<"2.Unpaid\n";
        cin>>ch;
        if(ch== '1')
        {
            cout<<"Students who have paid the fees\n";
            for (int k=0;k<no_student;k++)
            {
                if (strcmp(studentData[k].feestatus,"Paid")==0)
                {
                   cout<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }

        }

        else if(ch == '2'){

                cout<<"Students who have not paid the fees\n";
            for (int k=0;k<no_student;k++)
            {
                if (strcmp(studentData[k].feestatus,"Unpaid")==0)
                {
                   cout<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }


        }
        cout<<"Press any key to continue";
        getch();

    }

    continue;

case '4'://delete data

    {
                cout<<"Enter the Id of the student whose record is to be deleted:\t";
				cin>>st_registrationid;
				delet_student(st_registrationid);
    }
    continue;//control back to inner loop -1

case '5'://display students batch-wise
    {
        char bat[10];
        cout<<"Enter the batch whose record you want to display\n";
        cin>>bat;
        for(int k = 0;k<no_student;k++)
        {
            if(strcmp(studentData[k].batch,bat)==0)
            {
                cout<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;

            }
        }

        cout<<"Press any key to continue\n";
        getch();
    }
    continue;



case '6'://display all data
			{
				fstream f1;
				f1.open("record_student.txt",ios::in);
				if(!f1)
				{
					cout<<"Error!!!";
					exit(0);
				}
				int i=0;
				while(i!=no_student)
				{
				    cout<<studentData[i].ind<<"\t"<<studentData[i].fname<<"\t"<<studentData[i].lname<<"\t"<<studentData[i].registrationid<<"\t"<<studentData[i].age<<"\t"<<studentData[i].cel_no<<"\t"<<studentData[i].batch<<"\n";
				    i++;
				}
				f1.close();
				cout<<"Press any key to continue\n";
				getch();
			}
			continue;

case '7': {
            char id[20];
            cout<<"Students who have not paid the fees\n";
            for (int k=0;k<no_student;k++)
            {
                if (strcmp(studentData[k].feestatus,"Unpaid")==0)
                {
                   cout<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].feestatus<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<"\t"<<studentData[k].batch<<endl;
                }


            }

            cout<<"Enter the Id of the student whose status you want to update\n";
            cin>>id;
            update_status(id);


        }
        continue;

case '8'://Jump to main
{
break;//inner switch breaking
}
}

break;//inner loop-1 breaking
}
continue;//Control pass to 1st loop
}

case '2'://Teachers biodata
{
     int n;
while(1)//inner loop-1
{
system("cls");//Clear screen
//Level-2 display
cout<<"\n\n\t\t\t\t\tTEACHERS INFORMATION AND BIO DATA SECTION\n\n\n";
cout<<"Enter your choice: "<<endl;
cout<<"1.Create new entry\n";
cout<<"2.Find Teacher\n";
cout<<"3.Remove Teacher\n";
cout<<"4.Batches-wise display\n";
cout<<"5.Students assigned\n";
cout<<"6.Display all Teachers\n";
cout<<"7.Jump to Main Menu\n";
cin>>choice;

switch (choice)//Second switch

{
    case '1'://Insert data
    {
        file1.open("record_teacher.txt",ios::app|ios::out);

        for( i=0;choice!='n';i++)
        {

            if((choice=='y')||(choice=='Y')||(choice=='1'))
            {

                cout<<"Enter the no of Teachers:\t";
                cin>>n;
                cout<<"enter the Details\n";
                for(int i=no_teacher;i<no_teacher+n;i++)
				{
					label1: cout<<"enter "<<i+1<<" teacher details:\n";
					cout<<"First name : ";
					cin>>teacherData[i].fst_name;
					cout<<"Last name : ";
					cin>>teacherData[i].lst_name;
					cout<<"Qualification : ";
					cin>>teacherData[i].qualification;
					cout<<"Teacher Id : ";
					cin>>teacherData[i].teacherid;
					cout<<"Pay=";
					cin>>teacherData[i].pay;
					cout<<"Batch Allotted : ";
					cin>>teacherData[i].batch;
					cout<<"Contact Number : ";
					cin>>teacherData[i].cel_no;
					int q=search_id_teacher(teacherData[i].teacherid,i);
					if(q==1)
					{
						cout<<"duplicate value\n";
						cout<<"enter again:\n";
						goto label1;
					}
					file1<<i<<"|"<<teacherData[i].fst_name<<"|"<<teacherData[i].lst_name<<"|"<<teacherData[i].teacherid<<"|"<<teacherData[i].qualification<<"|"<<teacherData[i].pay<<"|"<<teacherData[i].batch<<"|"<<teacherData[i].cel_no<<"\n";


				}
				no_teacher=no_teacher+n;
				cout<<"Do you want to enter data?\n ";
                cout<<"Press Y for Continue and N to Finish:  ";
                cin>>choice;

            }
        }
                file1.close();

					fstream file1,file2;
					file1.open("record_teacher.txt",ios::in);
					file2.open("index_teacher.txt",ios::out);
					for(int i=0;i<no_teacher;i++)
					{
						file1.getline(ind_teacher,5,'|');
						file1.getline(fst_name,20,'|');
						file1.getline(lst_name,20,'|');
						file1.getline(teacherid,20,'|');
						file1.getline(qualification,20,'|');
						file1.getline(pay,10,'|');
						file1.getline(batch_teacher,20,'|');
						file1.getline(cel_no_teacher,10,'\n');
						strcpy(teacherData[i].ind,ind_teacher);
						strcpy(inteacher[i].teacherid,teacherid);
						strcpy(inteacher[i].indteacher,ind_teacher);
					}

					sort_index_teacher();
					for(int i=0;i<no_teacher;i++)
					{
						file2<<inteacher[i].teacherid<<"|"<<inteacher[i].indteacher<<"\n";
					}
					file1.close();
					file2.close();
    }
continue;//control back to inner loop -1

case '2'://Display data
{
                cout<<"Enter the Id of the teacher whose record is to be searched:\t";
				cin>>st_teacherid;
				int q=search_index_teacher(st_teacherid);
				if(q==1){
					cout<<"Search successful\n";
					cout<<"Press any key to continue\n";
                        getch();
				}
				else{
					cout<<"Search unsuccessful\n";
					cout<<"Press any key to continue\n";
                        getch();
				}

}
continue;//control back to inner loop -1

case '3':

    {
                cout<<"Enter the Id of the teacher whose record is to be deleted:\t";
				cin>>st_teacherid;
				delet_teacher(st_teacherid);
    }
    continue;//control back to inner loop -1


case '4':
    {
        char bat[20];
        cout<<"See the teachers assigned to the batch, Enter the Batch name\n";
        cin>>bat;
        for(int k = 0;k<no_teacher;k++)
        {
            if(strcmp(studentData[k].batch,bat)==0)
            {
                cout<<teacherData[k].fst_name<<"\t"<<teacherData[k].lst_name<<"\t"<<teacherData[k].teacherid<<"\t"<<teacherData[k].batch<<endl;
            }
        }

        cout<<"Press any key to continue\n";
        getch();

    }
    continue;


case '5':

    {
        char id[20];
        cout<<"Enter id of the teacher to see the students assigned\n";
        cin>>id;
        char bat[20];

        for(int i = 0;i<no_teacher;i++)
        {
            if(strcmp(teacherData[i].teacherid,id)==0)
            {
                strcpy(bat,teacherData[i].batch);

            }
        }

        for(int k=0;k<no_teacher;k++)
        {

            if(strcmp(studentData[k].batch,bat)==0)
            {
                cout<<studentData[k].fname<<"\t"<<studentData[k].lname<<"\t"<<studentData[k].registrationid<<"\t"<<studentData[k].age<<"\t"<<studentData[k].cel_no<<endl;
            }

        }
        cout<<"Press any key to continue";
        getch();

    }
    continue;



case '6':
			{
				fstream f1;
				f1.open("record_teacher.txt",ios::in);
				if(!f1)
				{
					cout<<"Error!!!";
					exit(0);
				}
				int i=0;
				while(i!=no_teacher)
				{
				    cout<<teacherData[i].ind<<"\t"<<teacherData[i].fst_name<<"\t"<<teacherData[i].lst_name<<"\t"<<teacherData[i].teacherid<<"\t"<<teacherData[i].qualification<<"\t"<<teacherData[i].pay<<"\t"<<teacherData[i].batch<<"\t"<<teacherData[i].cel_no<<"\n";
				    i++;

				}
				f1.close();
				cout<<"Press any key to continue\n";
                getch();
			}
			continue;


case '7'://Jump to main
{
break;//inner switch breaking
}
}

break;//inner loop-1 breaking
}
continue;//Control pass to 1st loop
}


case '3':
{
break;//outer case 3
}//outer case 3
}
break;//outer loop
}


}
