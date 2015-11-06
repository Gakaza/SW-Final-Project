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
TEST_F(Term_Project_Test,maritalClassEquivalenceClassTesting)
{
	testmaritalClass("divorced","no",1,0,0,0);
	testmaritalClass("married","no",1,0,0,1);
	testmaritalClass("single","no",1,0,0,2);
	
	
}

TEST_F(Term_Project_Test,DefaultClassEquivalenceClassTesting)
{
	tessdefaultClass("no","no",1,0,0,0);
	tessdefaultClass("yes","no",1,0,0,1);
	
}

TEST_F(Term_Project_Test,loanClassEquivalenceClassTesting)
{
	testloanClass("no","no",1,0,0,0);
	testloanClass("yes","no",1,0,0,1);
	
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

void Term_Project_Test::testJobClass(char Job[30],char attr[30],int Job0,int Job1,int CIndexi,int CIndexj)
{

	num_job0 = 0;
	num_job1 = 0;
	memset(tempAttribute,0,sizeof(tempAttribute));
	strcpy(tempAttribute[4],Job);
	strcpy(tempAttribute[19],attr);
	memset(numPerDefault,0,sizeof(numPerDefault));
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




