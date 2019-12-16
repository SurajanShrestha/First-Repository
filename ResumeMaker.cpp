/* Hello surajan, this comment is added by kamal
    And I think it is now good to start some good stuffs
 */
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
//int nameN=30,N=50,D=100;
//We have to pass adress of file obj for sucessful passing of arguments
string Intro(fstream &fw,string name,string email,string address,string phNum);
void AcaDetails(fstream &fw,string schoolName,string colgName,string bachName,string majSub,string faculty,string seePer,string plus2Per,string bachPer,string yearSchool,string yearColg,string yearBach);
void foiCurri(fstream &fw,int n);
void skiAchStr(fstream &fw,int n);
void decDatPla(fstream &fw);
void covLet(fstream &flett,char ch,string name);
int main()
{
    char ch,loopch;
    int n;
    string AtLastName;
    string name,email,address,phNum,schoolName,majSub,colgName,seePer,plus2Per,yearSchool,yearColg,bachName,faculty,bachPer,yearBach;
    fstream fw,flett;
    cout<<"Welcome to Your Resume and/or CV Maker.\n"<<endl;
    do
    {
        char docName[15];
        cout<<"Name your resume file where your details will be printed(Eg:resume.txt i.e.with extension like .txt or .docx):";
        cin.getline(docName,15);
        cout<<"\nEnter your details below:"<<endl;
        fw.open(docName,ios::out);
        fw<<setw(88)<<"RESUME\n\n"<<endl;
        AtLastName=Intro(fw,name,email,address,phNum);
        AcaDetails(fw,schoolName,colgName,bachName,majSub,faculty,seePer,plus2Per,bachPer,yearSchool,yearColg,yearBach);
        foiCurri(fw,n);
        skiAchStr(fw,n);
        decDatPla(fw);
        covLet(flett,ch,AtLastName);
        fw<<"\n\nTHANKING YOU!!!"<<endl;
        fw<<AtLastName<<endl;
        fw.close();
        cout<<"\nDo you want to make another resume?\n"<<"Press 'Y' for Yes and 'N' or anything else for No:";
        cin>>loopch;
        cin.ignore();
        cout<<"\n[Please note that your next resume file should not have the same name as the previous one.]\n"<<endl;
    }while(loopch=='y'||loopch=='Y');
    return 0;
}
string Intro(fstream &fw,string name,string email,string address,string phNum)
{
    cout<<"Enter Name:";
    getline(cin,name);
    cout<<"Enter Email:";
    getline(cin,email);
    cout<<"Enter Address:";
    getline(cin,address);
    cout<<"Enter Phone Number:";
    getline(cin,phNum);
    fw<<"Name: "<<name<<endl;
    fw<<"Email: "<<email<<endl;
    fw<<"Address: "<<address<<endl;
    fw<<"Phone Number: "<<phNum<<"\n"<<endl;
    return name;
}
void AcaDetails(fstream &fw,string schoolName,string colgName,string bachName,string majSub,string faculty,string seePer,string plus2Per,string bachPer,string yearSchool,string yearColg,string yearBach)
{
    cout<<"\nEnter Your Academic Details"<<endl;
    cout<<"Enter Your SLC/SEE Details:"<<endl;
    cout<<"Enter School Name:";
    getline(cin,schoolName);
    cout<<"Enter Obtained percentage:";
    getline(cin,seePer);
    cout<<"Enter Passed Year:";
    getline(cin,yearSchool);
    cout<<"\nEnter Your Intermediate Level Details:"<<endl;
    cout<<"Enter College Name:";
    getline(cin,colgName);
    cout<<"Enter Aggregate Obtained percentage:";
    getline(cin,plus2Per);
    cout<<"Enter Passed Year:";
    getline(cin,yearColg);
    cout<<"Enter Major Subject in Intermediate Level(Science/Commerce,etc):";
    getline(cin,majSub);
    cout<<"\nEnter Your Bachelor Level Details:"<<endl;
    cout<<"Enter College Name:";
    getline(cin,bachName);
    cout<<"Enter Obtained Aggregate percentage:";
    getline(cin,bachPer);
    cout<<"Enter Passed Year:";
    getline(cin,yearBach);
    cout<<"Enter Faculty in Bachelor Level(BE/BIT/BCA,etc):";
    getline(cin,faculty);
    fw<<"\nACADEMIC DETAILS.\n"<<endl;
    fw<<"1) SLC/SEE:"<<endl;
    fw<<"School Name: "<<schoolName<<endl;
    fw<<"Obtained Percentage: "<<seePer<<endl;
    fw<<"Passed Year: "<<yearSchool<<"\n"<<endl;
    fw<<"2) Intermediate Level:"<<endl;
    fw<<"College Name: "<<colgName<<endl;
    fw<<"Obtained Aggregate Percentage: "<<plus2Per<<endl;
    fw<<"Passed Year: "<<yearColg<<endl;
    fw<<"Major Subject: "<<majSub<<"\n"<<endl;
    fw<<"3) Bachelor Level:"<<endl;
    fw<<"College Name: "<<bachName<<endl;
    fw<<"Obtained Aggregate Percentage: "<<bachPer<<endl;
    fw<<"Passed Year: "<<yearBach<<endl;
    fw<<"Faculty: "<<faculty<<endl;
}
void foiCurri(fstream &fw,int n)
{
    cout<<"\nState the number of Field of Interests so you can list them out:";
    cin>>n;
    //We have to do this to ignore buffered characters so that we can use getline next
    cin.ignore();
    string foi[n];
    fw<<"\n\nField of Interests."<<"\n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Interest number "<<i<<":";
        getline(cin,foi[i-1]);
        fw<<i<<") "<<foi[i-1]<<endl;
    }
    cout<<"\nState the number of Curricular Activities that you are involved in:";
    cin>>n;
    cin.ignore();
    string curr[n];
    fw<<"\n\nCurricular Activities."<<"\n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Activity number "<<i<<":";
        getline(cin,curr[i-1]);
        fw<<i<<") "<<curr[i-1]<<endl;
    }
}
void skiAchStr(fstream &fw,int n)
{
    cout<<"\nState the number of Skills you have so you can list them out:";
    cin>>n;
    cin.ignore();
    string ski[n];
    fw<<"\n\nSkills."<<"\n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Skill number "<<i<<":";
        getline(cin,ski[i-1]);
        fw<<i<<") "<<ski[i-1]<<endl;
    }
    cout<<"\nState the number of Achievements that you have acquired:";
    cin>>n;
    cin.ignore();
    string ach[n];
    fw<<"\n\nAchievements."<<"\n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Achievement number "<<i<<":";
        getline(cin,ach[i-1]);
        fw<<i<<") "<<ach[i-1]<<endl;
    }
    cout<<"\nState the number of Strengths you have that make you a convincing employee:";
    cin>>n;
    cin.ignore();
    string stre[n];
    fw<<"\n\nStrengths."<<"\n"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Strength number "<<i<<":";
        getline(cin,stre[i-1]);
        fw<<i<<") "<<stre[i-1]<<endl;
    }
}
void decDatPla(fstream &fw)
{
    fw<<"\n\nDeclaration."<<"\n"<<"I herby declare that the above mentioned details are true to the best of my knowledge."<<endl;
    string dat,pla;
    cout<<"\n\nEnter the date of resume submission(YY/MM/DD):";
    getline(cin,dat);
    fw<<"\nDate(YY/MM/DD): "<<dat<<endl;
    cout<<"Enter the place where this resume was written:";
    getline(cin,pla);
    fw<<"Place: "<<pla<<endl;
}
void covLet(fstream &flett,char ch,string name)
{
    cout<<"\nDo you want to write a Cover Letter?\n"<<"Press 'Y' for Yes and 'N' or anything else for No:";
    cin>>ch;
    cin.ignore();
    string namLett,datLett,compLett,addLett,ptftLett,infoLett;
    if(ch=='y'||ch=='Y')
    {
        char docName[25];
        cout<<"\nName your cover letter file where your details will be printed(Eg:coverletter.txt i.e.with extension like .txt or .docx):";
        cin.getline(docName,25);
        flett.open(docName,ios::out);
        flett<<setw(85)<<"COVER LETTER\n\n"<<endl;
        flett<<name<<"\n"<<endl;
        cout<<"\nSpecify the date of submission of this letter(YY/MM/DD):";
        getline(cin,datLett);
        flett<<"Date: "<<datLett<<"\n"<<endl;
        cout<<"\nSpecify Name/Job Position of the person you are sending this letter(Eg:HR manager,CEO,etc.):";
        getline(cin,namLett);
        flett<<namLett<<","<<endl;
        cout<<"\nSpecify Name of the Company you are sending this letter(Eg:Apple INC.,Google LLC,etc.):";
        getline(cin,compLett);
        flett<<compLett<<","<<endl;
        cout<<"\nSpecify Address of the Company you are sending this letter:";
        getline(cin,addLett);
        flett<<addLett<<","<<"\n\n\n"<<endl;
        flett<<"Dear "<<namLett<<","<<endl;
        cout<<"\nAre you applying Part Time or Full Time? Please Mention:";
        getline(cin,ptftLett);
        cout<<"\nFrom where did you get information about the job vacancy? Please Mention(Eg:Facebook,Online Job Portal,etc.):";
        getline(cin,infoLett);
        flett<<"I'm applying for a "<<ptftLett<<" employee at your company. I found out about this job from "<<infoLett<<" and came to realize that this job is perfect for me."<<endl;
        flett<<"Based on the posted description, I'm confident that I am fully qualified for the position and will be a strong addition to your team. I would appreciate a job "<<endl;
        flett<<"interview at your earliest convenience."<<endl;
        flett<<"Thank You for giving your precious time."<<"\n"<<endl;
        flett<<"Please find my resume attatched."<<"\n"<<endl;
        flett<<"I can be reached at the number or at my email address provided at my resume."<<"\n"<<endl;
        flett<<"Sincerely."<<"\n"<<endl;
        flett<<name<<"."<<endl;
    }
    flett.close();
}
