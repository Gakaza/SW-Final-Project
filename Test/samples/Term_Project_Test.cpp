#include "term_project_II.h"
#include "gtest/gtest.h"
#include<cstring>

class Term_Project_Test : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
void testAgeClass(char age[30],char attr[30],int Age0,int Age1,int CIndexi,int CIndexj);
void testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj);
void testmaritalClass(char marital[30],char attr[30],int Mat0,int Mat1,int Cindexi,int Cindexj);
void tessdefaultClass(char Default[30],char attr[30],int Default0,int Default1,int CIndexi,int CIndexj);
void testloanClass(char loan[30], char attr[30],int Loan0, int Loan1,int CIndexi,int CIndexj);
void testmonthClass(char month[30], char attr[30],int Month0, int Month1,int CIndexi,int CIndexj);
void testCampaignClass(char campaign[30], char attr[30],int Campaign0,int Campaign1,int CIndexi,int CIndexj);
void testPreviousClass(char previous[30], char attr[30],int Previous0, int Previous1, int CIndexi, int CIndexj);
void testEmpClass(char emp[30], char attr[30],int Emp0, int Emp1, int CIndexi, int CIndexj);
void testConfClass(char conf[30], char attr[30],int Conf0, int Conf1, int CIndexi, int CIndexj);
void testNrClass(char nr[30], char attr[30],int Nr0, int Nr1, int CIndexi, int CIndexj);

char tempAttribute[20][30];
int num_Age0;
int num_Age1;
int numPerAge[2][5];

int num_job0;
int num_job1;
int numPerJob[2][11];

int num_Mat0;
int num_Mat1;
int numPerMat[2][3];

int num_Def0;
int num_Def1;
int numPerDefault[2][2];

int num_Loan0;
int num_Loan1;
int numPerLoan[2][2];

int num_Month0;
int num_Month1;
int numPerMonth[2][12];


int num_Campaign0;
int num_Campaign1;
int numPerCampaign[2][3];
	

int num_Previous0;
int num_Previous1;
int numPerPrevious[2][2];


int num_Emp0;
int num_Emp1;
int numPerEmp[2][6];


int num_Conf0; 
int num_Conf1;
int numPerConf[2][4];


int num_Nr0;
int num_Nr1;
int numPerNr[2][2];

};


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
		
}
TEST_F(Term_Project_Test,JobClassEquivalenceClassTesting)
{
	
}

TEST_F(Term_Project_Test,JobClassEdgeTesting)
{
	testAgeClass("Invalid_Input.","no",0,0,-1,-1);
	testAgeClass("admin.","no",1,0,0,0);
	testAgeClass("blue-collar","no",1,0,0,1);
	testAgeClass("entrepreneur","no",1,0,0,2);
	testAgeClass("housemaid","no",1,0,0,3);
	testAgeClass("management","no",1,0,0,4);
	testAgeClass("retired","no",1,0,0,5);
	testAgeClass("self-employed","no",1,0,0,6);
	testAgeClass("services","no",1,0,0,7);
	testAgeClass("student","no",1,0,0,8);
	testAgeClass("technician","no",1,0,0,9);
	testAgeClass("unemployed","no",1,0,0,10);
	testAgeClass("?","no",0,0,-1,-1);
	
}


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

//void testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj);
//int num_job0;
//int num_job1;
//int numPerJob[2][11];
void Term_Project_Test::testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj)
{

	num_job0 = 0;
	num_job1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[4],Job);
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
