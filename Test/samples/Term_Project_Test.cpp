#include "term_project_II.h"
#include "gtest/gtest.h"
#include<cstring>
#include <iostream>
using namespace std;

class Term_Project_Test : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
void testAgeClass(char age[30],char attr[30],int Age0,int Age1,int CIndexi,int CIndexj);
void testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj);
void testmaritalClass(char marital[30],char attr[30],int Mat0,int Mat1,int Cindexi,int Cindexj);
void testEduClass(char Edu[30],char attr[30],int Edu0,int Edu1,int CIndexi,int CIndexj);
void tessdefaultClass(char Default[30],char attr[30],int Default0,int Default1,int CIndexi,int CIndexj);
void testHouseClass(char House[30],char attr[30],int House0,int House1,int CIndexi,int CIndexj);
void testloanClass(char loan[30], char attr[30],int Loan0, int Loan1,int CIndexi,int CIndexj);
void testConctactClass(char Contact[30],char attr[30],int Contact0,int Contact1,int CIndexi,int CIndexj);
void testmonthClass(char month[30], char attr[30],int Month0, int Month1,int CIndexi,int CIndexj);
void testDayClass(char Day[30],char attr[30],int Day0,int Day1,int CIndexi,int CIndexj);
void testCampaignClass(char campaign[30], char attr[30],int Campaign0,int Campaign1,int CIndexi,int CIndexj);
void testPDaysClass(char PDays[30],char attr[30],int PDays0,int PDays1,int CIndexi,int CIndexj);
void testPreviousClass(char previous[30], char attr[30],int Previous0, int Previous1, int CIndexi, int CIndexj);
void testPOutcomeClass(char POutcome[30],char attr[30],int POutcome0,int POutcome1,int CIndexi,int CIndexj);
void testEmpClass(char emp[30], char attr[30],int Emp0, int Emp1, int CIndexi, int CIndexj);
void testPriceClass(char Price[30],char attr[30],int Price0,int Price1,int CIndexi,int CIndexj);
void testConfClass(char conf[30], char attr[30],int Conf0, int Conf1, int CIndexi, int CIndexj);
void testEuribor3mClass(char Euribor3m[30],char attr[30],int Euribor3m0,int Euribor3m1,int CIndexi,int CIndexj);
void testNrClass(char nr[30], char attr[30],int Nr0, int Nr1, int CIndexi, int CIndexj);
//void testOutputClass(char Output[30],int CIndexi);
//0
char tempAttribute[20][30];
int num_Age0;
int num_Age1;
int numPerAge[2][5];

//1
int num_job0;
int num_job1;
int numPerJob[2][11];

//2
int num_Mat0;
int num_Mat1;
int numPerMat[2][3];

//3
int num_edu0;
int num_edu1;
int numPerEdu[2][7];

//4
int num_Def0;
int num_Def1;
int numPerDefault[2][2];

//5
int numPerHouse[2][2];
int num_house0;
int num_house1;

//6
int num_Loan0;
int num_Loan1;
int numPerLoan[2][2];

//7
int num_contact0;
int num_contact1;
int numPerContact[2][2];

//8
int num_Month0;
int num_Month1;
int numPerMonth[2][12];

//9
int num_day0;
int num_day1;
int numPerDay[2][5];

//10
int num_Campaign0;
int num_Campaign1;
int numPerCampaign[2][3];
	
//11
int num_pdays0;
int num_pdays1;
int numPerPDays[2][4];

//12
int num_Previous0;
int num_Previous1;
int numPerPrevious[2][2];

//13
int num_poutcome0;
int num_poutcome1;
int numPerPOutcome[2][3];

//14
int num_Emp0;
int num_Emp1;
int numPerEmp[2][6];

//15
int num_price0;
int num_price1;
int numPerPrice[2][3];

//16
int num_Conf0; 
int num_Conf1;
int numPerConf[2][4];

//17
int num_euribor3m0;
int num_euribor3m1;
int numPerEuribor3m[2][4];

//18
int num_Nr0;
int num_Nr1;
int numPerNr[2][2];

//19
//int numPerOutput[2];
};

//0 - Age
TEST_F(Term_Project_Test,AgeClassBoundaryValueTesting)
{
	
	testAgeClass("0","no",0,0,-1,-1);
	testAgeClass("1","no",1,0,0,0);
	testAgeClass("139","no",1,0,0,4);
	testAgeClass("140","no",0,0,-1,-1);
	testAgeClass("35","no",1,0,0,1);
	
	
}
TEST_F(Term_Project_Test,AgeClassEquivalenceClassTesting)
{
	testAgeClass("-1","no",0,0,-1,-1);
	testAgeClass("15","no",1,0,0,0);
	testAgeClass("35","no",1,0,0,1);
	testAgeClass("45","no",1,0,0,2);
	testAgeClass("55","no",1,0,0,3);
	testAgeClass("80","no",1,0,0,4);
	testAgeClass("140","no",0,0,-1,-1);
	
}
TEST_F(Term_Project_Test,AgeClassEdgeTesting)
{
	
	testAgeClass("-1","no",0,0,-1,-1);
	testAgeClass("15","no",1,0,0,0);
	testAgeClass("29","no",1,0,0,0);
	testAgeClass("30","no",1,0,0,1);
	testAgeClass("35","no",1,0,0,1);
	testAgeClass("39","no",1,0,0,1);
	testAgeClass("40","no",1,0,0,2);
	testAgeClass("45","no",1,0,0,2);
	testAgeClass("49","no",1,0,0,2);
	testAgeClass("50","no",1,0,0,3);
	testAgeClass("55","no",1,0,0,3);
	testAgeClass("64","no",1,0,0,3);
	testAgeClass("65","no",1,0,0,4);
	testAgeClass("80","no",1,0,0,4);
	testAgeClass("140","no",0,0,-1,-1);
	
}

TEST_F(Term_Project_Test,AgeClassDecisionTableTesting)
{
	
	testAgeClass("-1","no",0,0,-1,-1);
	testAgeClass("15","no",1,0,0,0);
	testAgeClass("29","no",1,0,0,0);
	testAgeClass("30","no",1,0,0,1);
	testAgeClass("35","no",1,0,0,1);
	testAgeClass("39","no",1,0,0,1);
	testAgeClass("40","no",1,0,0,2);
	testAgeClass("45","no",1,0,0,2);
	testAgeClass("49","no",1,0,0,2);
	testAgeClass("50","no",1,0,0,3);
	testAgeClass("55","no",1,0,0,3);
	testAgeClass("64","no",1,0,0,3);
	testAgeClass("65","no",1,0,0,4);
	testAgeClass("80","no",1,0,0,4);
	testAgeClass("140","no",0,0,-1,-1);
	testAgeClass("-1","yes",0,0,-1,-1);
	testAgeClass("15","yes",0,1,1,0);
	testAgeClass("29","yes",0,1,1,0);
	testAgeClass("30","yes",0,1,1,1);
	testAgeClass("35","yes",0,1,1,1);
	testAgeClass("39","yes",0,1,1,1);
	testAgeClass("40","yes",0,1,1,2);
	testAgeClass("45","yes",0,1,1,2);
	testAgeClass("49","yes",0,1,1,2);
	testAgeClass("50","yes",0,1,1,3);
	testAgeClass("55","yes",0,1,1,3);
	testAgeClass("64","yes",0,1,1,3);
	testAgeClass("65","yes",0,1,1,4);
	testAgeClass("80","yes",0,1,1,4);
	testAgeClass("140","yes",0,0,-1,-1);
	
}

//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
TEST_F(Term_Project_Test,JobClassBoundaryValueTesting)
{
	testJobClass("Invalid_Input.","no",0,0,-1,-1);
	testJobClass("!!.","no",0,0,-1,-1);
	testJobClass("!???!.","no",0,0,-1,-1);
	testJobClass("admin.","no",1,0,0,0);
	testJobClass("blue-collar","no",1,0,0,1);
	testJobClass("entrepreneur","no",1,0,0,2);
	testJobClass("housemaid","no",1,0,0,3);
	testJobClass("management","no",1,0,0,4);
}

TEST_F(Term_Project_Test,JobClassEquivalenceClassTesting)
{
	testJobClass("Invalid_Input.","no",0,0,-1,-1);
	testJobClass("admin.","no",1,0,0,0);
	testJobClass("blue-collar","no",1,0,0,1);
	testJobClass("entrepreneur","no",1,0,0,2);
	testJobClass("housemaid","no",1,0,0,3);
	testJobClass("management","no",1,0,0,4);
	testJobClass("retired","no",1,0,0,5);
	testJobClass("self-employed","no",1,0,0,6);
	testJobClass("services","no",1,0,0,7);
	testJobClass("student","no",1,0,0,8);
	testJobClass("technician","no",1,0,0,9);
	testJobClass("unemployed","no",1,0,0,10);
	testJobClass("?","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test,JobClassEdgeTesting)
{
	testJobClass("Invalid_Input.","no",0,0,-1,-1);
	testJobClass("admin.","no",1,0,0,0);
	testJobClass("blue-collar","no",1,0,0,1);
	testJobClass("entrepreneur","no",1,0,0,2);
	testJobClass("housemaid","no",1,0,0,3);
	testJobClass("management","no",1,0,0,4);
	testJobClass("retired","no",1,0,0,5);
	testJobClass("self-employed","no",1,0,0,6);
	testJobClass("services","no",1,0,0,7);
	testJobClass("student","no",1,0,0,8);
	testJobClass("technician","no",1,0,0,9);
	testJobClass("unemployed","no",1,0,0,10);
	testJobClass("?","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test,JobClassDecisionTesting)
{
	testJobClass("Invalid_Input.","no",0,0,-1,-1);
	testJobClass("admin.","no",1,0,0,0);
	testJobClass("blue-collar","no",1,0,0,1);
	testJobClass("entrepreneur","no",1,0,0,2);
	testJobClass("housemaid","no",1,0,0,3);
	testJobClass("management","no",1,0,0,4);
	testJobClass("retired","no",1,0,0,5);
	testJobClass("self-employed","no",1,0,0,6);
	testJobClass("services","no",1,0,0,7);
	testJobClass("student","no",1,0,0,8);
	testJobClass("technician","no",1,0,0,9);
	testJobClass("unemployed","no",1,0,0,10);
	testJobClass("?","no",0,0,-1,-1);
	testJobClass("Invalid_Input.","yes",0,0,-1,-1);
	testJobClass("admin.","yes",0,1,1,0);
	testJobClass("blue-collar","yes",0,1,1,1);
	testJobClass("entrepreneur","yes",0,1,1,2);
	testJobClass("housemaid","yes",0,1,1,3);
	testJobClass("management","yes",0,1,1,4);
	testJobClass("retired","yes",0,1,1,5);
	testJobClass("self-employed","yes",0,1,1,6);
	testJobClass("services","yes",0,1,1,7);
	testJobClass("student","yes",0,1,1,8);
	testJobClass("technician","yes",0,1,1,9);
	testJobClass("unemployed","yes",0,1,1,10);
	testJobClass("?","yes",0,0,-1,-1);
}
//2- material
TEST_F(Term_Project_Test,maritalClassEquivalenceClassTesting)
{
	testmaritalClass("divorced","no",1,0,0,0);
	testmaritalClass("married","no",1,0,0,1);
	testmaritalClass("single","no",1,0,0,2);
}

TEST_F(Term_Project_Test,maritalClassDecisionTableTesting)
{
	testmaritalClass("divorced","no",1,0,0,0);
	testmaritalClass("married","no",1,0,0,1);
	testmaritalClass("single","no",1,0,0,2);
	testmaritalClass("divorced","yes",0,1,1,0);
	testmaritalClass("married","yes",0,1,1,1);
	testmaritalClass("single","yes",0,1,1,2);
	
	
}

//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?') 
TEST_F(Term_Project_Test,EduClassBoundaryValueTesting)
{
	testEduClass("illiterate","no",1,0,0,4);
	testEduClass("professional.course","no",1,0,0,5);
	testEduClass("university.degree","no",1,0,0,6);
}

TEST_F(Term_Project_Test,EduClassEquivalenceClassTesting)
{
	testEduClass("Invalid_Input.","no",0,0,-1,-1);
	testEduClass("basic.4y","no",1,0,0,0);
	testEduClass("basic.6y","no",1,0,0,1);
	testEduClass("basic.9y","no",1,0,0,2);
	testEduClass("high.school","no",1,0,0,3);
	testEduClass("illiterate","no",1,0,0,4);
	testEduClass("professional.course","no",1,0,0,5);
	testEduClass("university.degree","no",1,0,0,6);
}

TEST_F(Term_Project_Test,EduClassEdgeTesting)
{
	testEduClass("Invalid_Input.","no",0,0,-1,-1);
	testEduClass("basic.4y","no",1,0,0,0);
	testEduClass("basic.6y","no",1,0,0,1);
	testEduClass("basic.9y","no",1,0,0,2);
	testEduClass("high.school","no",1,0,0,3);
	testEduClass("illiterate","no",1,0,0,4);
	testEduClass("professional.course","no",1,0,0,5);
	testEduClass("university.degree","no",1,0,0,6);
}

TEST_F(Term_Project_Test,EduClassDecisionTesting)
{
	testEduClass("Invalid_Input.","yes",0,0,-1,-1);
	testEduClass("basic.4y","yes",0,1,1,0);
	testEduClass("basic.6y","yes",0,1,1,1);
	testEduClass("basic.9y","yes",0,1,1,2);
	testEduClass("high.school","yes",0,1,1,3);
	testEduClass("illiterate","yes",0,1,1,4);
	testEduClass("professional.course","yes",0,1,1,5);
	testEduClass("university.degree","yes",0,1,1,6);
}

//4 - Default
TEST_F(Term_Project_Test,DefaultClassEquivalenceClassTesting)
{
	tessdefaultClass("no","no",1,0,0,0);
	tessdefaultClass("yes","no",1,0,0,1);
	
}

TEST_F(Term_Project_Test,DefaultClassDecisionTableTesting)
{
	tessdefaultClass("no","no",1,0,0,0);
	tessdefaultClass("yes","no",1,0,0,1);
	tessdefaultClass("no","yes",0,1,1,0);
	tessdefaultClass("yes","yes",0,1,1,1);
	
}

//5 - housing: has housing loan? (categorical: 'no','yes','?') 
TEST_F(Term_Project_Test, HouseClassBoundaryValueTesting)
{
	testHouseClass("no","no",1,0,0,0);
	testHouseClass("yes","no",1,0,0,1);
	testHouseClass("Invalid_Input.","no",0,0,-1,-1);
	testHouseClass("???","no",0,0,-1,-1);
	testHouseClass("!!!","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test, HouseClassEquivalenceClassTesting)
{
	testHouseClass("no","no",1,0,0,0);
	testHouseClass("yes","no",1,0,0,1);
}

TEST_F(Term_Project_Test, HouseClassEdgeTesting)
{
	testHouseClass("Invalid_Input.","no",0,0,-1,-1);
	testHouseClass("no","no",1,0,0,0);
	testHouseClass("yes","no",1,0,0,1);
}

TEST_F(Term_Project_Test, HouseClassDecisionTesting)
{
	testHouseClass("Invalid_Input.","no",0,0,-1,-1);
	testHouseClass("no","no",1,0,0,0);
	testHouseClass("yes","no",1,0,0,1);
	testHouseClass("Invalid_Input.","yes",0,0,-1,-1);
	testHouseClass("no","yes",0,1,1,0);
	testHouseClass("yes","yes",0,1,1,1);
}

//6 - Loan
TEST_F(Term_Project_Test,loanClassEquivalenceClassTesting)
{
	testloanClass("no","no",1,0,0,0);
	testloanClass("yes","no",1,0,0,1);
	
}

TEST_F(Term_Project_Test,loanClassDecisionTableTesting)
{
	testloanClass("no","no",1,0,0,0);
	testloanClass("yes","no",1,0,0,1);
	testloanClass("no","yes",0,1,1,0);
	testloanClass("yes","yes",0,1,1,1);
	
}

//7 - contact: contact communication type (categorical: 'cellular','telephone') 
TEST_F(Term_Project_Test, ContactClassBoundaryValueTesting)
{
	testConctactClass("Invalid_Input.","no",0,0,-1,-1);
	testConctactClass("???","no",0,0,-1,-1);
	testConctactClass("!!!","no",0,0,-1,-1);
	testConctactClass("cellular","no",1,0,0,0);
	testConctactClass("telephone","no",1,0,0,1);
}

TEST_F(Term_Project_Test, ContactClassEquivalenceClassTesting)
{
	testConctactClass("cellular","no",1,0,0,0);
	testConctactClass("telephone","no",1,0,0,1);
}

TEST_F(Term_Project_Test, ContactClassEdgeTesting)
{
	testConctactClass("Invalid_Input.","no",0,0,-1,-1);
	testConctactClass("cellular","no",1,0,0,0);
	testConctactClass("telephone","no",1,0,0,1);
}

TEST_F(Term_Project_Test, ContactClassDecisionTesting)
{
	testConctactClass("Invalid_Input.","no",0,0,-1,-1);
	testConctactClass("cellular","no",1,0,0,0);
	testConctactClass("telephone","no",1,0,0,1);
	
	testConctactClass("Invalid_Input.","no",0,0,-1,-1);
	testConctactClass("cellular","yes",0,1,1,0);
	testConctactClass("telephone","yes",0,1,1,1);
}

//8 - month
TEST_F(Term_Project_Test,monthClassEquivalenceClassTesting)
{
	testmonthClass("jan","no",1,0,0,0);
	testmonthClass("feb","no",1,0,0,1);
	testmonthClass("mar","no",1,0,0,2);
	testmonthClass("apr","no",1,0,0,3);
	testmonthClass("may","no",1,0,0,4);
	testmonthClass("jun","no",1,0,0,5);
	testmonthClass("jul","no",1,0,0,6);
	testmonthClass("aug","no",1,0,0,7);
	testmonthClass("sep","no",1,0,0,8);
	testmonthClass("oct","no",1,0,0,9);
	testmonthClass("nov","no",1,0,0,10);
	testmonthClass("dec","no",1,0,0,11);
}

TEST_F(Term_Project_Test,monthClassDecisionTableTesting)
{
	testmonthClass("jan","no",1,0,0,0);
	testmonthClass("feb","no",1,0,0,1);
	testmonthClass("mar","no",1,0,0,2);
	testmonthClass("apr","no",1,0,0,3);
	testmonthClass("may","no",1,0,0,4);
	testmonthClass("jun","no",1,0,0,5);
	testmonthClass("jul","no",1,0,0,6);
	testmonthClass("aug","no",1,0,0,7);
	testmonthClass("sep","no",1,0,0,8);
	testmonthClass("oct","no",1,0,0,9);
	testmonthClass("nov","no",1,0,0,10);
	testmonthClass("dec","no",1,0,0,11);
	testmonthClass("jan","yes",0,1,1,0);
	testmonthClass("feb","yes",0,1,1,1);
	testmonthClass("mar","yes",0,1,1,2);
	testmonthClass("apr","yes",0,1,1,3);
	testmonthClass("may","yes",0,1,1,4);
	testmonthClass("jun","yes",0,1,1,5);
	testmonthClass("jul","yes",0,1,1,6);
	testmonthClass("aug","yes",0,1,1,7);
	testmonthClass("sep","yes",0,1,1,8);
	testmonthClass("oct","yes",0,1,1,9);
	testmonthClass("nov","yes",0,1,1,10);
	testmonthClass("dec","yes",0,1,1,11);
}

//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri')
TEST_F(Term_Project_Test, DayClassBoundaryValueTesting)
{
	testDayClass("Invalid_Input.","no",0,0,-1,-1);
	testDayClass("???","no",0,0,-1,-1);
	testDayClass("!!!","no",0,0,-1,-1);
	testDayClass("wed","no",1,0,0,2);
	testDayClass("thu","no",1,0,0,3);
	testDayClass("fri","no",1,0,0,4);
}

TEST_F(Term_Project_Test, DayClassEquivalenceClassTesting)
{
	testDayClass("cellular","no",0,0,-1,-1);
	testDayClass("mon","no",1,0,0,0);
	testDayClass("tue","no",1,0,0,1);
	testDayClass("wed","no",1,0,0,2);
	testDayClass("thu","no",1,0,0,3);
	testDayClass("fri","no",1,0,0,4);
}

TEST_F(Term_Project_Test, DayClassEdgeTesting)
{
	testDayClass("Invalid_Input.","no",0,0,-1,-1);
	testDayClass("mon","no",1,0,0,0);
	testDayClass("tue","no",1,0,0,1);
	testDayClass("wed","no",1,0,0,2);
	testDayClass("thu","no",1,0,0,3);
	testDayClass("fri","no",1,0,0,4);
}

TEST_F(Term_Project_Test, DayClassDecisionTesting)
{
	testDayClass("Invalid_Input.","no",0,0,-1,-1);
	testDayClass("mon","no",1,0,0,0);
	testDayClass("tue","no",1,0,0,1);
	testDayClass("wed","no",1,0,0,2);
	testDayClass("thu","no",1,0,0,3);
	testDayClass("fri","no",1,0,0,4);
	
	testDayClass("Invalid_Input.","yes",0,0,-1,-1);
	testDayClass("mon","yes",0,1,1,0);
	testDayClass("tue","yes",0,1,1,1);
	testDayClass("wed","yes",0,1,1,2);
	testDayClass("thu","yes",0,1,1,3);
	testDayClass("fri","yes",0,1,1,4);
}

//10 - Campaign
TEST_F(Term_Project_Test,CampaignClassBoundaryValueTesting)
{
	testCampaignClass("-1","no",0,0,-1,-1);
	testCampaignClass("0","no",1,0,0,0);
	testCampaignClass("7","no",1,0,0,2);
	testCampaignClass("8","no",1,0,0,2);
}

TEST_F(Term_Project_Test,CampaignClassEquivalenceClassTesting)
{
	testCampaignClass("-1","no",0,0,-1,-1);
	testCampaignClass("0","no",1,0,0,0);
	testCampaignClass("5","no",1,0,0,1);
	testCampaignClass("7","no",1,0,0,2);
}

TEST_F(Term_Project_Test,CampaignClassEdgeTesting)
{
	testCampaignClass("-1","no",0,0,-1,-1);
	testCampaignClass("0","no",1,0,0,0);
	testCampaignClass("3","no",1,0,0,0);
	testCampaignClass("4","no",1,0,0,1);
	testCampaignClass("5","no",1,0,0,1);
	testCampaignClass("6","no",1,0,0,1);
	testCampaignClass("7","no",1,0,0,2);
}

TEST_F(Term_Project_Test,CampaignClassDecisionTableTesting)
{
	testCampaignClass("-1","no",0,0,-1,-1);
	testCampaignClass("0","no",1,0,0,0);
	testCampaignClass("5","no",1,0,0,1);
	testCampaignClass("7","no",1,0,0,2);
	testCampaignClass("-1","yes",0,0,-1,-1);
	testCampaignClass("0","yes",0,1,1,0);
	testCampaignClass("5","yes",0,1,1,1);
	testCampaignClass("7","yes",0,1,1,2);
}

//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
//			- 4 intervals: (0~11), (12~20), (21 ~ 28), (999)
TEST_F(Term_Project_Test, PDaysClassBoundaryValueTesting)
{
	testPDaysClass("-1","no",0,0,-1,-1);
	testPDaysClass("0","no",1,0,0,0);
	testPDaysClass("5","no",1,0,0,0);
	testPDaysClass("11","no",1,0,0,0);
	testPDaysClass("12","no",1,0,0,1);
	testPDaysClass("15","no",1,0,0,1);
	testPDaysClass("20","no",1,0,0,1);
}

TEST_F(Term_Project_Test, PDaysClassEquivalenceClassTesting)
{
	testPDaysClass("-1","no",0,0,-1,-1);
	testPDaysClass("0","no",1,0,0,0);
	testPDaysClass("12","no",1,0,0,1);
	testPDaysClass("21","no",1,0,0,2);
	testPDaysClass("999","no",1,0,0,3);
}

TEST_F(Term_Project_Test, PDaysClassEdgeTesting)
{
	testPDaysClass("-1","no",0,0,-1,-1);
	testPDaysClass("0","no",1,0,0,0);
	testPDaysClass("5","no",1,0,0,0);
	testPDaysClass("11","no",1,0,0,0);
	testPDaysClass("12","no",1,0,0,1);
	testPDaysClass("15","no",1,0,0,1);
	testPDaysClass("20","no",1,0,0,1);
	testPDaysClass("21","no",1,0,0,2);
	testPDaysClass("25","no",1,0,0,2);
	testPDaysClass("28","no",1,0,0,2);
	testPDaysClass("29","no",0,0,-1,-1);
	testPDaysClass("999","no",1,0,0,3);
}

TEST_F(Term_Project_Test, PDaysClassDecisionTesting)
{
	testPDaysClass("-1","no",0,0,-1,-1);
	testPDaysClass("0","no",1,0,0,0);
	testPDaysClass("5","no",1,0,0,0);
	testPDaysClass("11","no",1,0,0,0);
	testPDaysClass("12","no",1,0,0,1);
	testPDaysClass("15","no",1,0,0,1);
	testPDaysClass("20","no",1,0,0,1);
	testPDaysClass("21","no",1,0,0,2);
	testPDaysClass("25","no",1,0,0,2);
	testPDaysClass("28","no",1,0,0,2);
	testPDaysClass("29","no",0,0,-1,-1);
	testPDaysClass("999","no",1,0,0,3);
	
	testPDaysClass("-1","yes",0,0,-1,-1);
	testPDaysClass("0","yes",0,1,1,0);
	testPDaysClass("5","yes",0,1,1,0);
	testPDaysClass("11","yes",0,1,1,0);
	testPDaysClass("12","yes",0,1,1,1);
	testPDaysClass("15","yes",0,1,1,1);
	testPDaysClass("20","yes",0,1,1,1);
	testPDaysClass("21","yes",0,1,1,2);
	testPDaysClass("25","yes",0,1,1,2);
	testPDaysClass("28","yes",0,1,1,2);
	testPDaysClass("29","no",0,0,-1,-1);
	testPDaysClass("999","yes",0,1,1,3);
}

//12 - Previous
TEST_F(Term_Project_Test,PreviousClassEquivalenceClassTesting)
{
	testPreviousClass("0","no",1,0,0,0);
	testPreviousClass("1","no",1,0,0,1);
}

TEST_F(Term_Project_Test,PreviousClassDecisionTableTesting)
{
	testPreviousClass("0","no",1,0,0,0);
	testPreviousClass("1","no",1,0,0,1);
	testPreviousClass("0","yes",0,1,1,0);
	testPreviousClass("1","yes",0,1,1,1);
}

//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
TEST_F(Term_Project_Test, POutcomeClassBoundaryValueTesting)
{
	testPOutcomeClass("-1","no",0,0,-1,-1);
	testPOutcomeClass("failure","no",1,0,0,0);
	testPOutcomeClass("nonexistent","no",1,0,0,1);
	testPOutcomeClass("success","no",1,0,0,2);
	testPOutcomeClass("999","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test, POutcomeClassEquivalenceClassTesting)
{
	testPOutcomeClass("-1","no",0,0,-1,-1);
	testPOutcomeClass("failure","no",1,0,0,0);
	testPOutcomeClass("nonexistent","no",1,0,0,1);
	testPOutcomeClass("success","no",1,0,0,2);
	testPOutcomeClass("999","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test, POutcomeClassEdgeTesting)
{
	testPOutcomeClass("-1","no",0,0,-1,-1);
	testPOutcomeClass("failure","no",1,0,0,0);
	testPOutcomeClass("nonexistent","no",1,0,0,1);
	testPOutcomeClass("success","no",1,0,0,2);
	testPOutcomeClass("999","no",0,0,-1,-1);
}

TEST_F(Term_Project_Test, POutcomeClassDecisionTesting)
{
	testPOutcomeClass("-1","no",0,0,-1,-1);
	testPOutcomeClass("failure","no",1,0,0,0);
	testPOutcomeClass("nonexistent","no",1,0,0,1);
	testPOutcomeClass("success","no",1,0,0,2);
	testPOutcomeClass("999","no",0,0,-1,-1);
	
	testPOutcomeClass("-1","yes",0,0,-1,-1);
	testPOutcomeClass("failure","yes",0,1,1,0);
	testPOutcomeClass("nonexistent","yes",0,1,1,1);
	testPOutcomeClass("success","yes",0,1,1,2);
	testPOutcomeClass("999","yes",0,0,-1,-1);
}

//14 - EMP
TEST_F(Term_Project_Test,EmpClassBoundaryValueTesting)
{
	testEmpClass("-2.1","no",1,0,0,3);
	testEmpClass("-2","no",1,0,0,2);
	testEmpClass("1.0","no",1,0,0,0);
}

TEST_F(Term_Project_Test,EmpClassEquivalenceClassTesting)
{
	testEmpClass("-2.1","no",1,0,0,3);
	testEmpClass("-1.5","no",1,0,0,2);
	testEmpClass("0.0","no",1,0,0,1);
	testEmpClass("1.0","no",1,0,0,0);
}

TEST_F(Term_Project_Test,EmpClassEdgeTesting)
{
	testEmpClass("-2.1","no",1,0,0,3);
	testEmpClass("-2.0","no",1,0,0,2);
	testEmpClass("-1.5","no",1,0,0,2);
	testEmpClass("-1.0","no",1,0,0,1);
	testEmpClass("0","no",1,0,0,1);
	testEmpClass("1.0","no",1,0,0,0);
	
}

TEST_F(Term_Project_Test,EmpClassDecisionTableTesting)
{
	testEmpClass("-2.1","no",1,0,0,3);
	testEmpClass("-1.5","no",1,0,0,2);
	testEmpClass("0.0","no",1,0,0,1);
	testEmpClass("1.0","no",1,0,0,0);
	testEmpClass("-2.1","yes",0,1,1,3);
	testEmpClass("-1.5","yes",0,1,1,2);
	testEmpClass("0.0","yes",0,1,1,1);
	testEmpClass("1.0","yes",0,1,1,0);
}

//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
//			- 3 intervals: (2000 > x>=94.45), (92.8 < x < 94.45), (0 <= x <= 92.8)
//					- x = 92.7, 92.8, 93.0, 94.45, invalid
TEST_F(Term_Project_Test, PriceClassBoundaryValueTesting)
{
	testPriceClass("-1","no",0,0,-1,-1);	
	testPriceClass("94.45","no",1,0,0,0);
	testPriceClass("94.44","no",1,0,0,1);
	testPriceClass("92.9","no",1,0,0,1);
	testPriceClass("92.8","no",1,0,0,2);
}

TEST_F(Term_Project_Test, PriceClassEquivalenceClassTesting)
{
	testPriceClass("-1","no",0,0,-1,-1);
	testPriceClass("94.45","no",1,0,0,0);
	testPriceClass("93.0","no",1,0,0,1);
	testPriceClass("92.7","no",1,0,0,2);
}

TEST_F(Term_Project_Test, PriceClassEdgeTesting)
{
	testPriceClass("-1","no",0,0,-1,-1);
	testPriceClass("94.45","no",1,0,0,0);
	testPriceClass("94.44","no",1,0,0,1);
	testPriceClass("93.0","no",1,0,0,1);
	testPriceClass("92.8","no",1,0,0,2);
	testPriceClass("92.7","no",1,0,0,2);
	testPriceClass("91.9","no",1,0,0,2);
}

TEST_F(Term_Project_Test, PriceClassDecisionTesting)
{
	testPriceClass("-1","no",0,0,-1,-1);
	testPriceClass("94.45","no",1,0,0,0);
	testPriceClass("94.44","no",1,0,0,1);
	testPriceClass("93.0","no",1,0,0,1);
	testPriceClass("92.8","no",1,0,0,2);
	testPriceClass("92.7","no",1,0,0,2);
	testPriceClass("91.9","no",1,0,0,2);
	
	testPriceClass("-1","yes",0,0,-1,-1);
	testPriceClass("94.45","yes",0,1,1,0);
	testPriceClass("94.44","yes",0,1,1,1);
	testPriceClass("93.0","yes",0,1,1,1);
	testPriceClass("92.8","yes",0,1,1,2);
	testPriceClass("92.7","yes",0,1,1,2);
	testPriceClass("91.9","yes",0,1,1,2);
}

//16 - Conf
TEST_F(Term_Project_Test,ConfClassBoundaryValueTesting)
{
	testConfClass("-46.0","no",1,0,0,3);
	testConfClass("-45.0","no",1,0,0,2);
	testConfClass("-30.0","no",1,0,0,0);
}

TEST_F(Term_Project_Test,ConfClassEquivalenceClassTesting)
{
	testConfClass("-46.0","no",1,0,0,3);
	testConfClass("-40.0","no",1,0,0,2);
	testConfClass("-32.0","no",1,0,0,1);
	testConfClass("-30.0","no",1,0,0,0);
}

TEST_F(Term_Project_Test,ConfClassEdgeTesting)
{
	testConfClass("-46.0","no",1,0,0,3);
	testConfClass("-45.0","no",1,0,0,2);
	testConfClass("-40.0","no",1,0,0,2);
	testConfClass("-35.0","no",1,0,0,1);
	testConfClass("-32.0","no",1,0,0,1);
	testConfClass("-30.0","no",1,0,0,0);
}

TEST_F(Term_Project_Test,ConfClassDecisionTableTesting)
{
	testConfClass("-46.0","no",1,0,0,3);
	testConfClass("-40.0","no",1,0,0,2);
	testConfClass("-32.0","no",1,0,0,1);
	testConfClass("-30.0","no",1,0,0,0);
	testConfClass("-46.0","yes",0,1,1,3);
	testConfClass("-40.0","yes",0,1,1,2);
	testConfClass("-32.0","yes",0,1,1,1);
	testConfClass("-30.0","yes",0,1,1,0);
}

//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
//			- 4 intervals: (x >= 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( 0 < x < 1.0)
//					- x = 0.9, 1.0, 4.0, 4.6, 4.86, invalid
TEST_F(Term_Project_Test, Euribor3mClassBoundaryValueTesting)
{
	testEuribor3mClass("-1","no",0,0,-1,-1);	
	testEuribor3mClass("4.86","no",1,0,0,0);
	testEuribor3mClass("4.85","no",1,0,0,1);
	testEuribor3mClass("4.0","no",1,0,0,1);
	testEuribor3mClass("3.9","no",1,0,0,2);
	testEuribor3mClass("1.0","no",1,0,0,2);
	testEuribor3mClass("0.99","no",1,0,0,3);
}

TEST_F(Term_Project_Test, Euribor3mClassEquivalenceClassTesting)
{
	testEuribor3mClass("-1","no",0,0,-1,-1);
	testEuribor3mClass("-1","no",0,0,-1,-1);
	testEuribor3mClass("4.87","no",1,0,0,0);
	testEuribor3mClass("4.86","no",1,0,0,0);
	testEuribor3mClass("4.6","no",1,0,0,1);
	testEuribor3mClass("3.9","no",1,0,0,2);
	testEuribor3mClass("1.0","no",1,0,0,2);
	testEuribor3mClass("0.99","no",1,0,0,3);
}

TEST_F(Term_Project_Test, Euribor3mClassEdgeTesting)
{
	testEuribor3mClass("-1","no",0,0,-1,-1);
	testEuribor3mClass("4.87","no",1,0,0,0);
	testEuribor3mClass("4.86","no",1,0,0,0);
	testEuribor3mClass("4.85","no",1,0,0,1);
	testEuribor3mClass("4.6","no",1,0,0,1);
	testEuribor3mClass("4.0","no",1,0,0,1);
	testEuribor3mClass("3.9","no",1,0,0,2);
	testEuribor3mClass("1.5","no",1,0,0,2);
	testEuribor3mClass("1.0","no",1,0,0,2);
	testEuribor3mClass("0.99","no",1,0,0,3);
	testEuribor3mClass("0.9","no",1,0,0,3);
}

TEST_F(Term_Project_Test, Euribor3mClassDecisionTesting)
{
	testEuribor3mClass("-1","no",0,0,-1,-1);
	testEuribor3mClass("4.87","no",1,0,0,0);
	testEuribor3mClass("4.86","no",1,0,0,0);
	testEuribor3mClass("4.85","no",1,0,0,1);
	testEuribor3mClass("4.6","no",1,0,0,1);
	testEuribor3mClass("4.0","no",1,0,0,1);
	testEuribor3mClass("3.9","no",1,0,0,2);
	testEuribor3mClass("1.5","no",1,0,0,2);
	testEuribor3mClass("1.0","no",1,0,0,2);
	testEuribor3mClass("0.99","no",1,0,0,3);
	testEuribor3mClass("0.9","no",1,0,0,3);
	
	testEuribor3mClass("-1","yes",0,0,-1,-1);
	testEuribor3mClass("4.87","yes",0,1,1,0);
	testEuribor3mClass("4.86","yes",0,1,1,0);
	testEuribor3mClass("4.85","yes",0,1,1,1);
	testEuribor3mClass("4.6","yes",0,1,1,1);
	testEuribor3mClass("4.0","yes",0,1,1,1);
	testEuribor3mClass("3.9","yes",0,1,1,2);
	testEuribor3mClass("1.5","yes",0,1,1,2);
	testEuribor3mClass("1.0","yes",0,1,1,2);
	testEuribor3mClass("0.99","yes",0,1,1,3);
	testEuribor3mClass("0.9","yes",0,1,1,3);
}

//18 - Nr
TEST_F(Term_Project_Test,NrClassBoundaryValueTesting)
{
	testNrClass("5200","no",1,0,0,1);
	testNrClass("5201","no",1,0,0,0);
	
}

TEST_F(Term_Project_Test,NrClassDecisionTableTesting)
{
	testNrClass("5200","no",1,0,0,1);
	testNrClass("5201","no",1,0,0,0);
	testNrClass("5200","yes",0,1,1,1);
	testNrClass("5201","yes",0,1,1,0);
	
}

//19 - y - has the client subscribed a term deposit? (binary: 'no','yes') 
TEST_F(Term_Project_Test, OutputClassBoundaryValueTesting)
{
	//since there are only one variable with two acceptable values, there isn't much to test with Output
	char attribute[20][30] = {0};
	int numPerOutput[2];
	strcpy(attribute[19],"yes");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[1]);
	
	strcpy(attribute[19],"no");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[0]);
	
	//invalid input
	strcpy(attribute[19],"??");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(0,numPerOutput[0]);
	EXPECT_EQ(0,numPerOutput[1]);
}

TEST_F(Term_Project_Test, OutputClassEquivalenceClassTesting)
{
	//since there are only one variable with two acceptable values, there isn't much to test with Output
	char attribute[20][30] = {0};
	int numPerOutput[2];
	strcpy(attribute[19],"yes");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(0,numPerOutput[0]);
	EXPECT_EQ(1,numPerOutput[1]);
	
	
	strcpy(attribute[19],"no");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[0]);
	EXPECT_EQ(0,numPerOutput[1]);
	
	//invalid input
	strcpy(attribute[19],"?!!?");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(0,numPerOutput[0]);
	EXPECT_EQ(0,numPerOutput[1]);
}

TEST_F(Term_Project_Test, OutputClassEdgeTesting)
{
	//since there are only one variable with two acceptable values, there isn't much to test with Output
	char attribute[20][30] = {0};
	int numPerOutput[2];
	strcpy(attribute[19],"yes");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[1]);
	
	strcpy(attribute[19],"no");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[0]);
	
	//invalid input
	strcpy(attribute[19],"??");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(0,numPerOutput[0]);
	EXPECT_EQ(0,numPerOutput[1]);
}

TEST_F(Term_Project_Test, OutputClassDecisionTesting)
{
	//since there are only one variable with two acceptable values, there isn't much to test with Output
	char attribute[20][30] = {0};
	int numPerOutput[2];
	strcpy(attribute[19],"yes");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[1]);
	
	strcpy(attribute[19],"no");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(1,numPerOutput[0]);
	
	//invalid input
	strcpy(attribute[19],"??");
	memset(numPerOutput,0,sizeof(numPerOutput));
	numPerOutputClass(attribute, numPerOutput);
	EXPECT_EQ(0,numPerOutput[0]);
	EXPECT_EQ(0,numPerOutput[1]);
}

//-----------------------------------------------------------------------------
//Class
//-----------------------------------------------------------------------------
void  Term_Project_Test::testAgeClass(char age[30],char attr[30],int Age0,int Age1,int CIndexi,int CIndexj)
{
	num_Age0 = 0;
	num_Age1 = 0;
    memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[0],age);
	strcpy(tempAttribute[19],attr);
	memset(numPerAge,0,sizeof(numPerAge));
	ageClass(tempAttribute, numPerAge, num_Age0, num_Age1);
	EXPECT_EQ(Age0,num_Age0);
	EXPECT_EQ(Age1,num_Age1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<5;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerAge[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerAge[i][j]);
		}
	
}

void Term_Project_Test::testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj)
{
	//void testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj);
	//int num_job0;
	//int num_job1;
	//int numPerJob[2][11];
	num_job0 = 0;
	num_job1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[1],Job);
	strcpy(tempAttribute[19],attr);
	memset(numPerJob,0,sizeof(numPerJob));
	jobClass(tempAttribute, numPerJob, num_job0, num_job1);
	EXPECT_EQ(Job0,num_job0);
	EXPECT_EQ(Job1,num_job1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<11;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerJob[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerJob[i][j]);
		}
}

void Term_Project_Test::testmaritalClass(char marital[30],char attr[30],int Mat0,int Mat1,int CIndexi,int CIndexj)
{
	num_Mat0 = 0;
    num_Mat1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[2],marital);
	strcpy(tempAttribute[19],attr);
	memset(numPerMat,0,sizeof(numPerMat));
	maritalClass(tempAttribute, numPerMat, num_Mat0, num_Mat1);
	EXPECT_EQ(Mat0,num_Mat0);
	EXPECT_EQ(Mat1,num_Mat1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<3;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerMat[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerMat[i][j]);
		}
}

void Term_Project_Test::testEduClass(char Edu[30],char attr[30],int Edu0,int Edu1,int CIndexi,int CIndexj)
{
	//void testJobClass(char Edu[30],char attr[30],int Edu0,int Edu1,int CIndexi,int CIndexj);
	//int num_edu0;
	//int num_edu1;
	//int numPerEdu[2][7];
	num_edu0 = 0;
	num_edu1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[3],Edu);
	strcpy(tempAttribute[19],attr);
	memset(numPerEdu,0,sizeof(numPerEdu));
	eduClass(tempAttribute, numPerEdu, num_edu0, num_edu1);
	EXPECT_EQ(Edu0,num_edu0);
	EXPECT_EQ(Edu1,num_edu1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<7;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerEdu[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerEdu[i][j]);
		}
}

void Term_Project_Test::tessdefaultClass(char Default[30],char attr[30],int Default0,int Default1,int CIndexi,int CIndexj)
{
	num_Def0 = 0;
	num_Def1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[4],Default);
	strcpy(tempAttribute[19],attr);
	memset(numPerDefault,0,sizeof(numPerDefault));
	defaultClass(tempAttribute, numPerDefault, num_Def0, num_Def1);
	EXPECT_EQ(Default0,num_Def0);
	EXPECT_EQ(Default1,num_Def1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerDefault[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerDefault[i][j]);
		}
}

void Term_Project_Test::testHouseClass(char House[30],char attr[30],int House0,int House1,int CIndexi,int CIndexj)
{
	//void testHouseClass(char House[30],char attr[30],int House0,int House1,int CIndexi,int CIndexj);
	//int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
	num_house0 = 0;
	num_house1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[5],House);
	strcpy(tempAttribute[19],attr);
	memset(numPerHouse,0,sizeof(numPerHouse));
	houseClass(tempAttribute, numPerHouse, num_house0, num_house1);
	EXPECT_EQ(House0,num_house0);
	EXPECT_EQ(House1,num_house1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerHouse[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerHouse[i][j]);
		}
}

void Term_Project_Test::testloanClass(char loan[30], char attr[30],int Loan0, int Loan1,int CIndexi,int CIndexj)
{
	num_Loan0 = 0;
	num_Loan1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[6],loan);
	strcpy(tempAttribute[19],attr);
	memset(numPerLoan,0,sizeof(numPerLoan));
	loanClass(tempAttribute, numPerLoan, num_Loan0, num_Loan1);
	EXPECT_EQ(Loan0,num_Loan0);
	EXPECT_EQ(Loan1,num_Loan1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerLoan[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerLoan[i][j]);
		}

}

void Term_Project_Test::testConctactClass(char Contact[30],char attr[30],int Contact0,int Contact1,int CIndexi,int CIndexj)
{
	//void contactClass(char tempAttribute[ ][30], int (&numPerCon)[2][2], int &num_Con0, int &num_Con1){
	num_contact0 = 0;
	num_contact1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[7],Contact);
	strcpy(tempAttribute[19],attr);
	memset(numPerContact,0,sizeof(numPerContact));
	contactClass(tempAttribute, numPerContact, num_contact0, num_contact1);
	EXPECT_EQ(Contact0,num_contact0);
	EXPECT_EQ(Contact1,num_contact1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerContact[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerContact[i][j]);
		}
}

void Term_Project_Test::testmonthClass(char month[30], char attr[30],int Month0, int Month1,int CIndexi,int CIndexj)
{
	num_Month0 = 0;
	num_Month1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[8],month);
	strcpy(tempAttribute[19],attr);
	memset(numPerMonth,0,sizeof(numPerMonth));
	monthClass(tempAttribute, numPerMonth, num_Month0, num_Month1);
	EXPECT_EQ(Month0,num_Month0);
	EXPECT_EQ(Month1,num_Month1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<12;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerMonth[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerMonth[i][j]);
		}

}

void Term_Project_Test::testDayClass(char Day[30],char attr[30],int Day0,int Day1,int CIndexi,int CIndexj)
{
	//void dayClass(char tempAttribute[ ][30], int (&numPerDay)[2][5], int &num_Day0, int &num_Day1){
	//int num_day0;
	//int num_day1;
	//int numPerDay[2][5];
	num_day0 = 0;
	num_day1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[9],Day);
	strcpy(tempAttribute[19],attr);
	memset(numPerDay,0,sizeof(numPerDay));
	dayClass(tempAttribute, numPerDay, num_day0, num_day1);
	EXPECT_EQ(Day0,num_day0);
	EXPECT_EQ(Day1,num_day1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<5;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerDay[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerDay[i][j]);
		}
}

void Term_Project_Test::testCampaignClass(char campaign[30], char attr[30],int Campaign0,int Campaign1,int CIndexi,int CIndexj)
{
	num_Campaign0 = 0;
	num_Campaign1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[10],campaign);
	strcpy(tempAttribute[19],attr);
	memset(numPerCampaign,0,sizeof(numPerCampaign));
	tempCampaignClass(tempAttribute, numPerCampaign, num_Campaign0, num_Campaign1);
	EXPECT_EQ(Campaign0,num_Campaign0);
	EXPECT_EQ(Campaign1,num_Campaign1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<3;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerCampaign[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerCampaign[i][j]);
		}
}

void Term_Project_Test::testPDaysClass(char PDays[30],char attr[30],int PDays0,int PDays1,int CIndexi,int CIndexj)
{
	//void tempPDaysClass(char tempAttribute[ ][30], int (&numPerPDays)[2][4], int &num_PDays0, int &num_PDays1)
	////int tempPDays, numPerPDays[2][4] = {0}, num_PDays0 = 0, num_PDays1 = 0;
	//int num_pdays0;
	//int num_pdays1;
	//int numPerPDays[2][4];
	num_pdays0 = 0;
	num_pdays1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[11],PDays);
	strcpy(tempAttribute[19],attr);
	memset(numPerPDays,0,sizeof(numPerPDays));
	tempPDaysClass(tempAttribute, numPerPDays, num_pdays0, num_pdays1);
	EXPECT_EQ(PDays0,num_pdays0);
	EXPECT_EQ(PDays1,num_pdays1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<4;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerPDays[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerPDays[i][j]);
		}
}

void Term_Project_Test::testPreviousClass(char previous[30], char attr[30],int Previous0, int Previous1, int CIndexi, int CIndexj)
{
	num_Previous0 = 0;
	num_Previous1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[12],previous);
	strcpy(tempAttribute[19],attr);
	memset(numPerPrevious,0,sizeof(numPerPrevious));
	tempPreviousClass(tempAttribute, numPerPrevious, num_Previous0, num_Previous1);
	EXPECT_EQ(Previous0,num_Previous0);
	EXPECT_EQ(Previous1,num_Previous1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerPrevious[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerPrevious[i][j]);
		}
}

void Term_Project_Test::testPOutcomeClass(char POutcome[30],char attr[30],int POutcome0,int POutcome1,int CIndexi,int CIndexj)
{
	//void numPerPoutcomeClass(char tempAttribute[ ][30], int (&numPerPoutcome)[2][3], int &num_Poutcome0, int &num_Poutcome1){			
	//int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
	//int num_poutcome0;
	//int num_poutcome1;
	//int numPerPOutcome[2][3];
	num_poutcome0 = 0;
	num_poutcome1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[13],POutcome);
	strcpy(tempAttribute[19],attr);
	memset(numPerPOutcome,0,sizeof(numPerPOutcome));
	numPerPoutcomeClass(tempAttribute, numPerPOutcome, num_poutcome0, num_poutcome1);
	EXPECT_EQ(POutcome0,num_poutcome0);
	EXPECT_EQ(POutcome1,num_poutcome1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<3;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerPOutcome[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerPOutcome[i][j]);
		}
}

void Term_Project_Test::testEmpClass(char emp[30], char attr[30],int Emp0, int Emp1, int CIndexi, int CIndexj)
{
	num_Emp0 = 0;
	num_Emp1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[14],emp);
	strcpy(tempAttribute[19],attr);
	memset(numPerEmp,0,sizeof(numPerEmp));
	tempEmpClass(tempAttribute, numPerEmp, num_Emp0, num_Emp1);
	EXPECT_EQ(Emp0,num_Emp0);
	EXPECT_EQ(Emp1,num_Emp1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<6;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerEmp[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerEmp[i][j]);
		}
}

void Term_Project_Test::testPriceClass(char Price[30],char attr[30],int Price0,int Price1,int CIndexi,int CIndexj)
{
	//void tempPriceClass(char tempAttribute[ ][30], int (&numPerPrice)[2][3], int &num_Price0, int &num_Price1){
	//float tempPrice; int numPerPrice[2][3] = {0}, num_Price0 = 0, num_Price1 = 0;
	//int num_price0;
	//int num_price1;
	//int numPerPrice[2][3];
	num_price0 = 0;
	num_price1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[15],Price);
	strcpy(tempAttribute[19],attr);
	memset(numPerPrice,0,sizeof(numPerPrice));
	tempPriceClass(tempAttribute, numPerPrice, num_price0, num_price1);
	EXPECT_EQ(Price0,num_price0);
	EXPECT_EQ(Price1,num_price1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<3;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerPrice[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerPrice[i][j]);
		}
}

void Term_Project_Test::testConfClass(char conf[30], char attr[30],int Conf0, int Conf1, int CIndexi, int CIndexj)
{
	
	num_Conf0 = 0;
	num_Conf1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[16],conf);
	strcpy(tempAttribute[19],attr);
	memset(numPerConf,0,sizeof(numPerConf));
	tempConfClass(tempAttribute, numPerConf, num_Conf0, num_Conf1);
	EXPECT_EQ(Conf0,num_Conf0);
	EXPECT_EQ(Conf1,num_Conf1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<4;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerConf[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerConf[i][j]);
		}

}

void Term_Project_Test::testEuribor3mClass(char Euribor3m[30],char attr[30],int Euribor3m0,int Euribor3m1,int CIndexi,int CIndexj)
{
	//void tempEuribor3mClass(char tempAttribute[ ][30], int (&numPerEuribor3m)[2][4], int &num_Euribor3m0, int &num_Euribor3m1){
	//float tempEuribor3m; int numPerEuribor3m[2][4] = {0}, num_Euribor3m0 = 0, num_Euribor3m1 = 0;
	//int num_euribor3m0;
	//int num_euribor3m1;
	//int numPerEuribor3m[2][4];
	num_euribor3m0 = 0;
	num_euribor3m1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[17],Euribor3m);
	strcpy(tempAttribute[19],attr);
	memset(numPerEuribor3m,0,sizeof(numPerEuribor3m));
	tempEuribor3mClass(tempAttribute, numPerEuribor3m, num_euribor3m0, num_euribor3m1);
	EXPECT_EQ(Euribor3m0,num_euribor3m0);
	EXPECT_EQ(Euribor3m1,num_euribor3m1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<4;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerEuribor3m[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerEuribor3m[i][j]);
		}
}

void Term_Project_Test::testNrClass(char nr[30], char attr[30],int Nr0, int Nr1, int CIndexi, int CIndexj)
{

	
	num_Nr0 = 0;
	num_Nr1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[18],nr);
	strcpy(tempAttribute[19],attr);
	memset(numPerNr,0,sizeof(numPerNr));
	tempNrClass(tempAttribute, numPerNr, num_Nr0, num_Nr1);
	EXPECT_EQ(Nr0,num_Nr0);
	EXPECT_EQ(Nr1,num_Nr1);
	for(int i = 0;i<2;i++)
		for(int j = 0;j<2;j++)
		if(i==CIndexi&&j==CIndexj)
		{
			EXPECT_EQ(1,numPerNr[i][j]);
		}
		else
		{
			EXPECT_EQ(0,numPerNr[i][j]);
		}
}

//void Term_Project_Test::testOutputClass(char Output[30],int expectedOutput)

