#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int counter=0;
int counter2=0;
int counter3=0;
int r=0,c=0;
int counter4=0;
bool ifalpha(char alpha);
bool ifdig(char digit);
bool isValidCourseCode(string courseCode);
bool isValidCreditHours(int creditHours);
bool isValidSemester(int semester);
bool isValidCourseName(string courseName);
void handleInputfailure();
bool loadCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[]);
void AddCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode,string courseName,int creditH,int semNo);
void EditCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode,string courseName,int creditH,int semNo,string newCourse);
void DeleteCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode);
void ViewCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[]);
void ViewSemesterCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],int semNo);
void saveCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[]);
bool loadUsers(string usersList[],string passwordsList[]);
bool isValidRegistrationNumber(string regNo);
bool isValidStudentName(string studentName);
void addStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo); 
void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo, string regNo2);
void deleteStudent (string stdNamesList[], string stdRegNoList[], string stdCourseList[][100] , string regNo );
void registerCourse(string stdRegNoList[], string stdCourseList[][100], string courseCodeList[],string regNo,string courseCode); 
void unRegisterCourse(string stdRegNoList[],string stdCourseList[][100],string regNo,string courseCode); 
void viewAllStudents(string stdRegNoList[], string stdNamesList[],string stdCourseList[][100] );
void  saveStudents( string stdRegNoList[], string stdNameList[], string stdCourseList[][100]) 
{
	int i;
	ofstream output;
	output.open("Students.txt");
	if(output.is_open())
	{
		for(i=0;i<counter3;i++)
		{
			output<<stdRegNoList[i]<<","<<stdNameList[i]<<endl;
			
			for(int j=0;j<counter4;j++)
			{
				if(stdRegNoList[i]==stdCourseList[j][0])
				{
					output<<stdCourseList[j][1];
					if(j!=counter4-1)
					{
						output<<",";
					}
				}
				if(j==counter4-1)
				{
					output<<endl;
				}
				
			}
		}
	}
	else
	{
		cout<<"Unable to open 'Students' file"<<endl;
	}
	output.close();
}
void LoadStudents(string stdRegNoList[], string stdNamesList[],string stdCourseList[][100])
{
	string line,line1;
	ifstream input;
	input.open("Students.txt");
	if(input.is_open())
	{
		for(int i=0;!input.eof();i++)
		{
			getline(input,line,',');
			stdRegNoList[i]=line;
			getline(input,line);
			stdNamesList[i]=line;
			input>>line;
			for(int j=0;line[j]!='\0';j++)
			{
			while(line[j]!=',' && line[j]!='\0')
			{
			stdCourseList[counter4][0]=stdRegNoList[i];
			stdCourseList[counter4][1]+=line[j];
			j++;
			}}counter4++;
			if(!input.eof())
			{
				counter3++;
			}
			//input.ignore(1,'\0');
		}
		input.close();
	}
	else
	{
		cout<<"Unable to open 'Students' file"<<endl;
	}	
} 
//Main Part
int main ()
{
	
	string courseCode , courseName,newCourse,courseCodeList[100],courseNameList[100],courseList,nameList ,usersList[100],passwordsList[100],userName,password,password1,stdNamesList[100],stdRegNoList[100],studentName,regNo,regNo2,stdCourseList[100][100];
	int option ,option1, semNo , creditH,creditHourList[100],semesterNumberList[100],crdHourList,semesterList ;
	loadCourses( courseCodeList, courseNameList, creditHourList, semesterNumberList);
	LoadStudents( stdRegNoList, stdNamesList, stdCourseList);
	loadUsers( usersList,passwordsList);
	lable5:
	cout<<"Choose the option for Login\n";
	cout<<"1	for Admin\n";
	cout<<"2	for Student\n";
	cout<<"Choose the option:";
	cin>>option1;
	switch(option1)
	{
		case 1:
	{
	lable:
	cout<<"** Welcome to University Learning Management System **\n";
	cout<<"Dear User, current software is intended for authorized users only.\n Login to the system to get access. \n"<<endl;
	lable2:
	cout<<"Username: ";
	cin>>userName;
	cout<<"Password: ";
	cin>>password;
		bool valid=false;
	for(int i=0;i<counter2;i++)
	{
		if(usersList[i]==userName && passwordsList[i]==password)
		{
			valid=true;
		}
	}
	
	
	if(valid)
{
	cout<<"You have successfully logged into the system\n";
	lable1:
	cout<<"Choose the following option\n";
	cout<<"1     Add Course\n";
	cout<<"2     Update Course\n";
	cout<<"3     Delete Course\n";
	cout<<"4     View All Course\n";
	cout<<"5     View Courses of a Semester\n";
	cout<<"6     Add New Student\n";
	cout<<"7     Update Student\n";
	cout<<"8     Delete Student\n";
	cout<<"9     View All Students\n";
	cout<<"10    Register The Course For Student\n";
	cout<<"11    Unregister The Course For Student\n";
	cout<<"12    Logout of the system\n";
	cout<<"13    Exit Program\n\n";

	cout<<"Choose the option: ";
	cin>>option;
	switch (option)
	{
		case 1:
			{
			
				AddCourse( courseCodeList,courseNameList, creditHourList, semesterNumberList,courseCode,courseName,creditH,semNo);
			
				goto lable1;
				break;
			}
		case 2:
			{
				EditCourse(courseCodeList,courseNameList, creditHourList, semesterNumberList,courseCode,courseName,creditH,semNo,newCourse);
				goto lable1;
				break;
			}

		case 3:
			{
				DeleteCourse(courseCodeList,courseNameList, creditHourList, semesterNumberList,courseCode);
				
				goto lable1;
				break;
			}
		case 4:	
			{
				 ViewCourses(courseCodeList,courseNameList, creditHourList, semesterNumberList);
				 
				 
				goto lable1;
				break;
			}
		case 5:
			{
				ViewSemesterCourses(courseCodeList,courseNameList, creditHourList, semesterNumberList,semNo);
				goto lable1;
				break;
			}
		case 6:
			{
				addStudent( stdNamesList, stdRegNoList, studentName,  regNo);
				goto lable1; 
				break;
			}
		case 7:
			{
				updateStudent(stdNamesList, stdRegNoList, studentName, regNo,regNo2);
				goto lable1;
				break;
			}
		case 8:
			{
				deleteStudent ( stdNamesList, stdRegNoList, stdCourseList,  regNo);
				goto lable1;
				break;
			}
		case 9:
			{
				viewAllStudents( stdRegNoList, stdNamesList,stdCourseList);
				goto lable1;
				break;
			}
		case 10:
			{
				registerCourse(stdRegNoList, stdCourseList, courseCodeList, regNo, courseCode);
				goto lable1;
				break;
			}
		case 11:
			{
				unRegisterCourse( stdRegNoList, stdCourseList, regNo, courseCode);
				goto lable1;
				break;
			}
		case 12:
			{
				goto lable5;
				break;	
			}
		case 13:
			{
				saveCourses(courseCodeList,courseNameList, creditHourList, semesterNumberList);
				saveStudents( stdRegNoList,  stdNamesList,  stdCourseList);
				break;
			}
		default:
			{
				cout<<"Your input is invalid.Enter the option again.\n";
				 handleInputfailure();
				goto lable1;
				break;
			}
	}
	
	
}
	else
		{
			cout<<"Dear User, Username/password is incorrect.\n Enter the username/password again to get access to the system \n"<<endl;
			goto lable2;
		}
		break;
	}
	case 2:
		{
			
			lable3:
			cout<<"** Welcome to University Learning Management System **\n";
			cout<<"Dear User, current software is intended for authorized users only.\n Login to the system to get access. \n"<<endl;
			cout<<"Enter registration Number:";
			cin>>regNo;
			cout<<"Enter password:";
			cin>>password1;
			string name;
			int a;
			bool valid=false,valid1=false;
			for(int i=0;i<counter3;i++)
			{
				if(stdRegNoList[i]==regNo )
				{
					valid1=true;
					name=stdNamesList[i];
					a=i;
				}
			}
			if(valid1)
			{
					int n=name.length();
					char arr[n+1];
					strcpy(arr, name.c_str());
					for(int k=0;k<n;k++)
					{
					if(password1[0]==arr[k])
					{
						if(password1[1]==arr[k+1])
						{
							if(password1[2]==arr[k+2])
							{	cout<<"You have successfully login to LMS\n\n";
								lable4:
								cout<<"Enter 1 to view registered courses\n";
								cout<<"Enter 2 to logout of the system\n";
								cout<<"Enter 3 to exit \n";
								cout<<"Choose option:";
								cin>>option;
								switch(option)
								{
									case 1:
										{
											cout<<"Courses\n";
											if(stdRegNoList[a]==stdCourseList[a][0])
											{
											for(int j=0;j<counter4;j++)
											{
												cout<<stdCourseList[j][1]<<endl;
											}
											}
											else
											{
												cout<<"Courses not added yet\n";
											}
											goto lable4;
											break;
										}
									case 2:
										{
											goto lable5;
											break;
										}
									case 3:
										{
											break;
										}
									default :
									{
										cout<<"Your input is Invalid. Enter the option again\n\n";
										handleInputfailure();
										goto lable4;
									}
								}
							}
							else
							{
								cout<<"Your user name or password is incorrect\n\n";
								goto lable3;
							}
						}
			
					}
						}
				}
				else
				{
					cout<<"Your registeration number '"<<regNo<<"' does not exist\n\n";
					goto lable3;
				}
			}
			default:
				{
					cout<<"Your input is Invalid. Enter the option again\n\n";
					handleInputfailure();
					goto lable5;
				}
			
			
}
	return 0;
}

bool ifalpha(char alpha)
{
	if((alpha>='A' && alpha<='Z') || (alpha>='a' && alpha<='z'))
	return true;
	else
	return false;
}
bool ifdig(char digit)
{
	if(digit=='1' || digit=='2' || digit=='3' || digit=='4' || digit=='5' || digit=='6' || digit=='7' || digit=='8' || digit=='9' || digit=='0')
	return true;
	else
	return false;
}
bool isValidCourseCode(string courseCode)
{
	bool Code=false;

		if (ifalpha(courseCode[0]))
		{
		 if(ifalpha(courseCode[1]))
		 {
		 if(ifdig(courseCode[2]))
		 {
		 if(ifdig(courseCode[3]))
		 {
		 if(ifdig(courseCode[4]))
			Code=true;
	}}}}
		return Code;
}
bool isValidCreditHours(int creditHours)
{
	if(creditHours>0 && creditHours<=3)
	return true;
	else
	return false;
}

bool isValidSemester(int semester)
{
	if(semester<=8 && semester>0)
	return true;
	else
	return false;
}

bool isValidCourseName(string courseName)
{
	int a,count=0;
	for(int i=0;courseName[i]!='\0';i++)
	{
	    a=i;
		if(courseName[i]==' ' || ifalpha(courseName[i]))
		count++;
	}
	if(count==(a+1))
            return true;
		else
		return false;
}


void AddCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode,string courseName,int creditH,int semNo)
{

    
	cout<<"Enter the details of course: ";
				cin>>courseCode>>creditH>>semNo;
				getline(cin,courseName);
				if(isValidCourseCode(courseCode))
				{
					if(isValidCreditHours(creditH))
					{
						if(isValidSemester(semNo))
						{
							if(isValidCourseName(courseName))
		                      {
		
                           		courseCodeList[counter]=courseCode;
                          		creditHourList[counter]=creditH;
                            	semesterNumberList[counter]=semNo;
                            	courseNameList[counter]=courseName;
                            	counter++;
								cout<<"Course is added successfully\n";
						
						   	}
						   	else
						   	{
						   		cout<<"Your course name '"<<courseName<<"' is not valid\n";
						   	}
							 
						}
						else
						{
							cout<<"Your semester number '"<<semNo<<"' is not valid\n";
						}
					}
					else
					{
						cout<<"Your credit hours '"<<creditH<<"' is not valid\n";
					}
				}
				else
				{
					cout<<"Your course code '"<<courseCode<<"' is not valid\n";
				}
				 handleInputfailure();
				
				cout<<endl<<endl;
}


	


void EditCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode,string courseName,int creditH,int semNo,string newCourse)
{
    
    	bool valid=false;
    	int a;
		cout<<"Enter the course code to edit: ";
				cin>>courseCode;
		
					if(isValidCourseCode(courseCode))
					{
						cout<<"Enter the new details of course: ";
						cin>>newCourse>>creditH>>semNo;
						getline(cin,courseName);
						if(isValidCourseCode(newCourse))
				   		{
							if(isValidCreditHours(creditH))
								{
									if(isValidSemester(semNo))
									{
										if(isValidCourseName(courseName))
										{
										
											for (int i =0;i<counter;i++)
											{
												if (courseCodeList[i]==courseCode)
												{
													valid=true;
													a=i;
												}
											}
											if(valid==true)
											{
										
												courseCodeList[a]=newCourse;
                            	 				creditHourList[a]=creditH;
                            					semesterNumberList[a]=semNo;
                            					courseNameList[a]=courseName;
                            					 
                            					 cout<<"Course has been edited successfully\n";
											}
											else
											{
												cout<<"Course does '"<<courseCode<<"' NOT exist"<<endl;
											}
								 		}
										else
										{
											cout<<"Your course name '"<<courseName<<"' is not valid\n";
										}
					
									}
									else
									{
										cout<<"Your semester number '"<<semNo<<"' is not valid\n";
									}
								}
								else
								{
									cout<<"Your credit hours '"<<creditH<<"' is not valid\n";
								}
							}
							else
							{
								cout<<"Your new course code '"<<newCourse<<"' is not valid\n";
							}
					}
					
				else
				{
				cout<<"Your course code '"<<courseCode<<"' is not valid\n";
				}
				 handleInputfailure();
		cout<<endl<<endl;
}




void DeleteCourse(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],string courseCode)
{  
		bool valid = false;
		int a;
		cout<<"Enter the course code to delete: ";
		cin>>courseCode;
		if(isValidCourseCode(courseCode))
		{
			for(int i=0;i<counter;i++)
			{
				if(courseCodeList[i]== courseCode)
				{
					valid=true;
					a=i;
				}
			}
			if(valid)
			{
				courseCodeList[a] = courseCodeList[a+1];
				creditHourList[a] = creditHourList[a+1];
				semesterNumberList[a] = semesterNumberList[a+1];
				courseNameList[a] = courseNameList[a+1];
				cout<<"Course has been deleted successfully."<<endl;
				counter--;
			
			}
			else
			{
				cout<<"Course has not been deleted successfully."<<endl;
			}
		}
		else
		{
			cout<<"Your course code '"<<courseCode<<"'is no valid"<<endl;
		}
		 handleInputfailure();
		
		

		
			cout<<endl<<endl;
}

void ViewCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[])
{       
		cout<< "Course code"<<setw(28)<<"Name"<<setw(22)<<"Credit Hour"<<setw(10)<<"Semester"<<endl; 
		           
		for(int i=0;i<counter;i++)
			{
				cout<<courseCodeList[i]<<setw(30)<<courseNameList[i]<<setw(22)<<creditHourList[i]<<setw(10)<<semesterNumberList[i]<<endl;
			}	
			cout<<endl<<endl;
}

void ViewSemesterCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[],int semNo)
{
	cout<<"Enter the semester number:";
	cin>>semNo;
	if(isValidSemester(semNo))
	{
		
				cout<<"Course Code\t"<<"Name\t\t\t"<<"Credit Hours\n";
				for(int i=0;i<counter;i++)
				{
					if(semNo == semesterNumberList[i])
					{
						cout<<courseCodeList[i]<<"\t"<<courseNameList[i]<<"\t\t\t"<<creditHourList[i]<<"\n";
					}
				}
	}
	
	else
	{
		cout<<"Enter a valid semester number"<<endl;
	}
	 handleInputfailure();
					cout<<endl<<endl;
}
void saveCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[])
{
	ofstream output;
	output.open("Courses.txt");
	if(output.is_open())
	{
		for(int i=0;i<counter;i++)
		{
			output<<courseCodeList[i]<<","<<courseNameList[i]<<","<<creditHourList[i]<<","<<semesterNumberList[i]<<endl;
		}
			output.close();
	}
	else
	{
		cout<<"Error in  loading 'Courses' file"<<endl;
	}
}
bool loadCourses(string courseCodeList[],string courseNameList[],int creditHourList[],int semesterNumberList[])
{
	int a;
	string line;
	ifstream input;	
	input.open("Courses.txt");
	if(input.is_open())
	{
		cout<<"Data Accessed Successfuly\n";
		for(int i=0;!input.eof();i++)
		{
			getline(input,line,',');
			courseCodeList[i]=line;
			getline(input,line,',');
			courseNameList[i]=line;
			input>>a;
			creditHourList[i]=a;
			input.ignore(100,',');
			input>>a;
			semesterNumberList[i]=a;
			input.ignore(1,'\n');
			if(!input.eof())
			{
				counter++;
			}
		}
	}
	else
	{
		cout<<"Error in loading 'Courses' file"<<endl;
	}
	input.close();
}
bool loadUsers(string usersList[],string passwordsList[])
{
	string line;
	ifstream input;
	input.open("Users.txt");
		if(input.is_open())
	{	
		for(int i=0;!input.eof();i++)
		{
			getline(input,line,',');
			usersList[i] = line;
			getline(input,line);
			passwordsList[i] = line;
			counter2++;
		}
		input.close();
	}
	else
	{
			cout<<"Error in loading 'Users' file"<<endl;
	}
}
bool isValidRegistrationNumber(string regNo)
{
bool Code=false;

		if (ifdig(regNo[0]))
		{
		 if(ifdig(regNo[1]))
		 {
		 if(ifdig(regNo[2]))
		 {
		 if(ifdig(regNo[3]))
		 {
		 if(ifalpha(regNo[5]))
		 {
		 if(ifalpha(regNo[6]))
		 {
		 if (ifdig(regNo[8]))
		 {
	    if(ifdig(regNo[9]))
		 {
			Code=true;
	}}}}}}}}
		return Code;
	
}
bool isValidStudentName(string studentName)
  {
  	int a,count=0;
	for(int i=0;studentName[i]!='\0';i++)
	{
	    a=i;
		if(studentName[i]==' ' || ifalpha(studentName[i]))
		count++;
	}
	if(count==(a+1))
            return true;
		else
		return false;
  	
  }
void addStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo) 
{
	cout<<"Enter details of Student:";
	cin>>regNo;
	getline(cin,studentName);
	if(isValidRegistrationNumber(regNo))
	{
		if(isValidStudentName(studentName))
		{
			stdNamesList[counter3]=studentName;
			stdRegNoList[counter3]=regNo;
			cout<<"Student has been added successfully "<<endl;
			counter3++;
		}
		else
		{
			cout<<"Enter the correct detail "<<endl;
		}
	}
	else
	{
		cout<<"Your Registeration number '"<<regNo<<"' is Invalid"<<endl;
	}
	void handleInputFailure();
	cout<<endl<<endl;
}
 void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName, string regNo, string regNo2)
 {
 	bool valid=false;
 	int a;
 	cout<<"Enter registration Number of the student to edit: ";
 	cin>>regNo;
 	if(isValidRegistrationNumber(regNo))
 	{
 		cout<<"Enter details of Student:";
		cin>>regNo2;
		getline(cin,studentName);
		if(isValidRegistrationNumber(regNo2))
		{
			if(isValidStudentName(studentName))
			{
				for(int i=0;i<counter3;i++)
				{
					if(stdRegNoList[i]==regNo)
					{
						valid=true;
						a=i;
					}
				
				}
				if(valid)
				{
					stdRegNoList[a]=regNo2;
					stdNamesList[a]=studentName;
					cout<<"Student has been edited successfully "<<endl;
				}	
				else
				{
					cout<<"Your registeration number "<<regNo<<" does NOT exist"<<endl;
				}
			}
			else
 			{
 				cout<<"Your student name '"<<studentName<<"' is invalid"<<endl;
 			}
		}
		else
 		{
 			cout<<"Your New registeration number '"<<regNo2<<"' is invalid"<<endl;
 		}
 	}
 	else
 	{
 		cout<<"Your registeration number '"<<regNo<<"' is invalid"<<endl;
 	}
 	 void handleInputFailure();
	cout<<endl<<endl;
 } 
 void deleteStudent (string stdNamesList[], string stdRegNoList[], string stdCourseList[][100] , string regNo )
 {
 	int a;
 	bool valid=false;
 	cout<<"Enter registration Number of the student to delete: ";
 	cin>>regNo;
 	if(isValidRegistrationNumber(regNo))
 	{
 		for(int i=0;i<counter3;i++)
 		{
 			if(stdRegNoList[i]==(regNo))
 			{
 				valid=true;
 				a=i;
 			}
 		
 		}
 		if(valid)
 		{
 				stdNamesList[a]=stdNamesList[a+1];
 				stdRegNoList[a]=stdRegNoList[a+1];
 				stdCourseList[a][a]=stdCourseList[a+1][a];
 				cout<<"Student has been deleted successfully "<<endl;
 				counter3--;
 		}
 			else
 			{
 				cout<<"Your registeration number "<<regNo<<" does not exist"<<endl;	
 			}
 	}
 	else
 	{
 		cout<<"Your Registeration Number '"<<regNo<<"' is Invalid"<<endl;
 	}
 	void handleInputFailure();
 	cout<<endl<<endl;
 }
void registerCourse( string stdRegNoList[], string stdCourseList[][100], string courseCodeList[], string regNo, string courseCode) 
{
	int a;
	bool valid1=false;
	bool valid=false;
	cout<<"Enter registration Number of the student for course registration: ";
	cin>>regNo;
		cout<<"Enter Course Code to register: ";
		cin>>courseCode;
		if(isValidCourseCode(courseCode))
		{
			for(int i=0;i<counter3;i++)
			{
				if(stdRegNoList[i]==regNo)
				{
					valid=true;
					
				}
			}
			if(valid)
			{
				for(int i=0;i<counter;i++)
				{
					if(courseCodeList[i]==courseCode)
					{
						valid1=true;
						break;
					}
				}
					if(valid1)
					{
					
						stdCourseList[counter4][0]=regNo;
						
						stdCourseList[counter4][1]=courseCode;
						
						cout<<"Course has been registered for student "<<endl;
						counter4++;	
					}
					else
					{
						cout<<"Your course "<<courseCode<<" does not exist"<<endl;
					}
				
			}
			else
				{
					cout<<"Student of "<<regNo<<" does NOT exist"<<endl;	
				}
		}
		else
		{
			cout<<"Your course code '"<<courseCode<<"' is Invalid\n";
		}
	void handleInputFailure();
	cout<<endl<<endl;
}
void unRegisterCourse(string stdRegNoList[],string stdCourseList[][100],string regNo,string courseCode) 
{
	int a;
	bool valid =false, found= false;
	cout<<"Enter registration Number of the student: ";
	cin>>regNo;
	if(isValidRegistrationNumber(regNo))
	{
		cout<<"Enter Course Code to unregister: ";
		cin>>courseCode;
		if(isValidCourseCode(courseCode))
		{
			for(int i=0;i<counter3;i++)
			{
				if(stdRegNoList[i]==regNo)
				{
						valid=true;
					break;
				}
			
			}
			if(valid)
			{
				for(int i=0;i<r;i++)
				{
					if(stdCourseList[i][0]==regNo && stdCourseList[i][1]==courseCode)
					{
						found = true;
						a=i;
						break;
					}
				}
				if(found)
				{
					for(int i=a;i<r;i++)
					{
						stdCourseList[i][0]=stdCourseList[i+1][0];
						stdCourseList[i][1]=stdCourseList[i+1][1];
						cout<<"Course has been unregistered "<<endl;
						r--;
						counter4--;
					}
					
				}
				else
				{
					cout<<"Your course code does not esixt"<<endl;
				}	
			}
			else
			{
				cout<<"Your '"<<regNo<<"' does not exist"<<endl;
			}	
		}
		else
		{
			cout<<"Your course code "<<courseCode<<" is Invalid"<<endl;
		}
	}
	else
	{
		cout<<"Your Registeration Number "<<regNo<<" is Invalid"<<endl;
	}
	void handleInputFailure();
	cout<<endl<<endl;
}
void viewAllStudents(string stdRegNoList[], string stdNamesList[],string stdCourseList[][100])
{
	bool valid =false;
	cout<<"Registeration Number"<<"\t\t"<<"Name"<<"\t\t\t\t"<<"Courses"<<endl;
	for(int i=0;i<=counter3;i++)
	{
		for(int k=0;k<counter4;k++)
		{
		if(stdRegNoList[i]==stdCourseList[k][0])
		{
			valid=true;
		}}
		if(valid)
		{
			cout<<stdRegNoList[i]<<"\t\t\t"<<stdNamesList[i]<<"\t\t\t";
			for(int j=0;j<counter4;j++)
			{
				if(stdRegNoList[i]==stdCourseList[j][0])
				{
				cout<<stdCourseList[j][1];
				if(j!=counter4-1)
				{
					cout<<",";
				}
				if(j==counter4-1)
				{
					cout<<endl;
				}
				}
			}
		}
		else
		{
			cout<<stdRegNoList[i]<<"\t\t\t"<<stdNamesList[i]<<endl;	
		}
	}
	cout<<endl<<endl;
} 
void handleInputfailure()
{
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1000,'\n');
	}
}
void  saveStudents( string stdRegNoList[], string stdNameList[], string stdCourseList[][100]) 
{
	int i;
	ofstream output;
	output.open("Students.txt");
	if(output.is_open())
	{
		for(i=0;i<counter3;i++)
		{
			output<<stdRegNoList[i]<<","<<stdNameList[i]<<endl;
			
			for(int j=0;j<counter4;j++)
			{
				if(stdRegNoList[i]==stdCourseList[j][0])
				{
					output<<stdCourseList[j][1];
					if(j!=counter4-1)
					{
						output<<",";
					}
				}
				if(j==counter4-1)
				{
					output<<endl;
				}
				
			}
		}
	}
	else
	{
		cout<<"Unable to open 'Students' file"<<endl;
	}
	output.close();
}
void LoadStudents(string stdRegNoList[], string stdNamesList[],string stdCourseList[][100])
{
	string line,line1;
	ifstream input;
	input.open("Students.txt");
	if(input.is_open())
	{
		for(int i=0;!input.eof();i++)
		{
			getline(input,line,',');
			stdRegNoList[i]=line;
			getline(input,line);
			stdNamesList[i]=line;
			input>>line;
			for(int j=0;line[j]!='\0';j++)
			{
			while(line[j]!=',' && line[j]!='\0')
			{
			stdCourseList[counter4][0]=stdRegNoList[i];
			stdCourseList[counter4][1]+=line[j];
			j++;
			}}counter4++;
			if(!input.eof())
			{
				counter3++;
			}
			//input.ignore(1,'\0');
		}
		input.close();
	}
	else
	{
		cout<<"Unable to open 'Students' file"<<endl;
	}	
} 
