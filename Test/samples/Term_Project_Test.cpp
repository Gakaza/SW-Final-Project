#include "term_project_II.h"
#include "gtest/gtest.h"
#include<cstring>

class Term_Project_Test : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
};

TEST_F(Term_Project_Test,TEST)
{
	char tempAttribute[20][30];
        int num_Age0 = 0;
	int num_Age1 = 0;
        int numPerAge[2][5];
	strcpy(tempAttribute[0],"29");
	strcpy(tempAttribute[19],"no");
	memset(numPerAge,0,sizeof(numPerAge));
	ageClass(tempAttribute, numPerAge, num_Age0, num_Age1);
		
	EXPECT_EQ(1,num_Age0);
}
