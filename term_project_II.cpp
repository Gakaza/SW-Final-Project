/*
Project Name: A.I. Term Porject II. NAÏVE BAYES
Name: 張書晧 Shu-Hao Chang
Student ID: 9917276
Goal: 
	To predict the output by the given input using Naïve Bayes Algorithm.
Requirement:
	1.	You are required to implement Naïve Bayes to handle the given data sets, where the bank folder and adult folder are the two given data sets.
	2.	The program MUST be written in C or C++ Language and can be compiled with Dev C++, Visual Studio  or Code Block.
	3.	The program is required to handle missing values and continuous attributes.
	4.	The output result MUST contain your prediction of each instance.
	5.	You MUST output five results with each data set (i.e. totally 10 results)
*/

#include "term_project_II.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h> 
using namespace std;



			
int main(){
	int chooseData = 0;
	FILE *pFile, *pTs, *pOutputFile;	//Tr, Ts, and Output text ptr. for bank
	int numData = 0, col, row;
	int CorrRate = 0;	//to test how many I predict correct.
	char tempAttribute[20][30];	//tempAttribute stores the attribute value for the current line.
	int numLine = 0; //for testing data.
	int numDataSet = 0;
	
	//-------------------Start of "BANK" Attribute related variables-----------------------
	float AgePercentage[2][5] = {0};	//the row is 0 = percentage base on output being 'no', 1 = output being 'yes'; 
										//the col is 5 different age intervals.
	int tempAge, numPerAge[2][5] = {0}, num_Age0=0, num_Age1=0; //five intervals: <30, >=30 && <40, >=40 && <50, >50 && <65, and >=65.
									//num_Age0 = 0 means te number of output being zero, where as the opposite (num_Age1) will be output being 1.
	float JobPercentage[2][11] = {0};
	int numPerJob[2][11] = {0}, num_job0 = 0, num_job1 = 0;
	float MaterialPercentage[2][3] = {0};
	int numPerMat[2][3] = {0}, num_Mat0 = 0, num_Mat1 = 0;
	float EducationPercentage[2][7] = {0};
	int numPerEdu[2][7] = {0}, num_Edu0 = 0, num_Edu1 = 0;
	float DefaultPercentage[2][2] = {0};
	int numPerDefault[2][2] = {0}, num_Def0 = 0, num_Def1 = 0;
	float HousePercentage[2][2] = {0};
	int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
	float LoanPercentage[2][2] = {0};
	int numPerLoan[2][2] = {0}, num_Loan0 = 0, num_Loan1 = 0;
	float ContactPercentage[2][2] = {0};
	int numPerCon[2][2] = {0}, num_Con0 = 0, num_Con1 = 0;
	float MonthPercentage[2][12] = {0};
	int numPerMonth[2][12] = {0}, num_Month0 = 0, num_Month1 = 0;
	float DayPercentage[2][5] = {0};
	int numPerDay[2][5] = {0}, num_Day0 = 0, num_Day1 = 0;
	float CampaignPercentage[2][3] = {0};		//Numeric, need to decide what the intervals are...
	int tempCampaign, numPerCampaign[2][3] = {0}, num_Campaign0 = 0, num_Campaign1 = 0;
	float PDaysPercentage[2][4] = {0};			//Numeric, need to decide what the intervals are...
	int tempPDays, numPerPDays[2][4] = {0}, num_PDays0 = 0, num_PDays1 = 0;
	float PreviousPercentage[2][2] = {0};		
	int tempPrevious, numPerPrevious[2][2] = {0}, num_Previous0 = 0, num_Previous1 = 0;
	float PoutcomePercentage[2][3] = {0};
	int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
	float EmpPercentage[2][4] = {0}, tempEmp;
	int num_Emp0 = 0, num_Emp1 = 0, numPerEmp[2][6] = {0};
	float PricePercentage[2][3] = {0}, tempPrice;
	int num_Price0 = 0, num_Price1 = 0, numPerPrice[2][5] = {0};
	float ConfPercentage[2][4] = {0}, tempConf;
	int num_Conf0 = 0, num_Conf1 = 0, numPerConf[2][4] = {0};
	float Euribor3mPercentage[2][4] = {0}, tempEuribor3m;
	int num_Euribor3m0 = 0, num_Euribor3m1 = 0, numPerEuribor3m[2][4] = {0};
	float NrPercentage[2][2] = {0}, tempNr;
	int num_Nr0 = 0, num_Nr1 = 0, numPerNr[2][2] = {0};
	
	
	float OutputPercentage[2] = {0};
	int numPerOutput[2] = {0};
	//-------------------End of BANK Attribute related variables-----------------------
	
	//The percentage of No output and the percentage of Yes output in the testing data.
	double NoOutput_Percentage = 0, YesOutput_Percentage = 0;
	float tempAttPercentage [2][20] = {0}; //row = 0 is percentage of output being zero
          //with respect to each inteveral (the columns); similarly row = 1 is percentage of output being one.
	float perdictedOutput = 0;
	while(numDataSet < 5){
		//----------------------------------------------------------
		//-------------------Start of Bank Data base------------------
		//----------------------------------------------------------
		switch(numDataSet){
			case 0:
					pFile = fopen ("./bank/testing-training 01/training01.txt", "r");
					pTs = fopen ("./bank/testing-training 01/testing01.txt", "r");
					pOutputFile = fopen ("./bank/testing-training 01/OutputFile_01.txt","w");
					break;
			case 1:
					pFile = fopen ("./bank/testing-training 02/training02.txt", "r");
					pTs = fopen ("./bank/testing-training 02/testing02.txt", "r");
					pOutputFile = fopen ("./bank/testing-training 02/OutputFile_02.txt","w");
					break;		
			case 2:
					pFile = fopen ("./bank/testing-training 03/training03.txt", "r");
					pTs = fopen ("./bank/testing-training 03/testing03.txt", "r");
					pOutputFile = fopen ("./bank/testing-training 03/OutputFile_03.txt","w");
					break;
			case 3:
					pFile = fopen ("./bank/testing-training 04/training04.txt", "r");
					pTs = fopen ("./bank/testing-training 04/testing04.txt", "r");
					pOutputFile = fopen ("./bank/testing-training 04/OutputFile_04.txt","w");
					break;
			case 4:
					pFile = fopen ("./bank/testing-training 05/training05.txt", "r");
					pTs = fopen ("./bank/testing-training 05/testing05.txt", "r");
					pOutputFile = fopen ("./bank/testing-training 05/OutputFile_05.txt","w");
					break;
		};
		
		if(pFile == NULL){ 
		cout<<"Error opening the pFile txt file"<<endl;
		//system("PAUSE");
		return 1;
		}
		if(pTs == NULL){ 
			cout<<"Error opening the pTs txt file"<<endl;
			//system("PAUSE");
			return 1;
		}
		//check for not equal to EOF, Reading from Trainning Data
		//a dumb way to read a line from files, total of 20 attributes to read per line.
		while(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^,],%[^,\n]",
							tempAttribute[0], tempAttribute[1], tempAttribute[2], tempAttribute[3], tempAttribute[4]
						, tempAttribute[5], tempAttribute[6], tempAttribute[7], tempAttribute[8], tempAttribute[9], tempAttribute[10]
						, tempAttribute[11], tempAttribute[12], tempAttribute[13], tempAttribute[14], tempAttribute[15], tempAttribute[16] 
						, tempAttribute[17], tempAttribute[18], tempAttribute[19]) != EOF)				
		{
			numData++; //numData = numPerOutput[0] + numPerOutput[1]; which is the total number of output for "yes" and "no" combined.
			/* With respect to the tempAttribute[i], row number.
			# bank client data: 
				0 - age (numeric) 
				1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
				2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
				3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?') 
				4 - default: has credit in default? (categorical: 'no','yes','?') 
				5 - housing: has housing loan? (categorical: 'no','yes','?') 
				6 - loan: has personal loan? (categorical: 'no','yes','?') 
			# related with the last contact of the current campaign: 
				7 - contact: contact communication type (categorical: 'cellular','telephone') 
				8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec') 
				9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
			# other attributes: 
				10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
					- 3 intervals: (0 ~ 3), (4~6), (7+)
				11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
						- 4 intervals: (0~11), (12~20), (20 ~ 27), (999) 
				12 - previous: number of contacts performed before this campaign and for this client (numeric) 
						- intervals: 0, (not 0)
				13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
						- intervals: shown as above.
			# social and economic context attributes 
				14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
						- 4 intervals: (x>1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
				15 - cons.price.idx: consumer price index - monthly indicator (numeric)
						- 3 intervals: (x>94.45), (92.8 <= x < 94.45), (x < 92.8)
				16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
						- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
				17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
						- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
				18 - nr.employed: number of employees - quarterly indicator (numeric) 
						- 2 intervals: (x > 5200.0), (x <= 5200.0)
				Output variable (desired target): 
				19 - y - has the client subscribed a term deposit? (binary: 'no','yes') 
						- 2 intervals: yes or no
			*/
			// 0 - age (numeric)
			ageClass(tempAttribute, numPerAge, num_Age0, num_Age1);
			
			//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
			jobClass(tempAttribute, numPerJob, num_job0, num_job1);
			
			
			//2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
			//int numPerMat[2][3] = {0}, num_Mat0 = 0, num_Mat1 = 0;
			maritalClass(tempAttribute, numPerMat, num_Mat0, num_Mat1);
			
			//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?')
			eduClass(tempAttribute, numPerEdu, num_Edu0, num_Edu1);
			
			//4 - default: has credit in default? (categorical: 'no','yes','?') 
			//int numPerDefault[2][2] = {0}, num_Def0 = 0, num_Def1 = 0;
			defaultClass(tempAttribute, numPerDefault, num_Def0, num_Def1);
			
			//5 - housing: has housing loan? (categorical: 'no','yes','?') 
			//int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
			houseClass(tempAttribute, numPerHouse, num_House0, num_House1);
			
			
			//6 - loan: has personal loan? (categorical: 'no','yes','?') 
			//int numPerLoan[2][2] = {0}, num_Loan0 = 0, num_Loan1 = 0;
			loanClass(tempAttribute, numPerLoan, num_Loan0, num_Loan1);
			
			//7 - contact: contact communication type (categorical: 'cellular','telephone') 
			//int numPerCon[2][2] = {0}, num_Con0 = 0, num_Con1 = 0;
			contactClass(tempAttribute, numPerCon, num_Con0, num_Con1);
			
			//8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec') 
			//int numPerMonth[2][12] = {0}, num_Month0 = 0, num_Month1 = 0;
			monthClass(tempAttribute, numPerMonth, num_Month0, num_Month1);
			
			
			//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
			//int numPerDay[2][5] = {0}, num_Day0 = 0, num_Day1 = 0;
			dayClass(tempAttribute, numPerDay, num_Day0, num_Day1);
			
			/*10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
					- 3 intervals: (0 ~ 3), (4~6), (7+)	*/
			//int tempCampaign, numPerCampaign[2][3] = {0}, num_Campaign0 = 0, num_Campaign1 = 0;
			tempCampaignClass(tempAttribute, numPerCampaign, num_Campaign0, num_Campaign1);
			
			
			//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
			//			- 4 intervals: (0~11), (12~20), (21 ~ 27), (999) 
			//int tempPDays, numPerPDays[2][5] = {0}, num_PDays0 = 0, num_PDays1 = 0;
			tempPDaysClass(tempAttribute, numPerPDays, num_PDays0, num_PDays1);
			
			
			//12 - previous: number of contacts performed before this campaign and for this client (numeric) 
			//			- intervals: 0, (not 0)
			//int tempPrevious, numPerPrevious[2][2] = {0}, num_Previous0 = 0, num_Previous1 = 0;
			tempPreviousClass(tempAttribute, numPerPrevious, num_Previous0, num_Previous1);
						
			//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
			//			- intervals: shown as above.
			//int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
			numPerPoutcomeClass(tempAttribute, numPerPoutcome, num_Poutcome0, num_Poutcome1);
			
			
			//14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
			//			- 4 intervals: (x>1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
			//float tempEmp; int numPerEmp[2][6] = {0}, num_Emp0 = 0, num_Emp1 = 0;
			tempEmpClass(tempAttribute, numPerEmp, num_Emp0, num_Emp1);
			
			//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
			//			- 3 intervals: (x>94.45), (92.8 <= x < 94.45), (x < 92.8)
			//float tempPrice; int numPerPrice[2][5] = {0}, num_Price0 = 0, num_Price1 = 0;
			tempPriceClass(tempAttribute, numPerPrice, num_Price0, num_Price1);
			
			//16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
			//			- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
			//float tempConf; int numPerConf[2][6] = {0}, num_Conf0 = 0, num_Conf1 = 0;
			tempConfClass(tempAttribute, numPerConf, num_Conf0, num_Conf1);
			
			//May 30th.
			//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
			//			- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
			//float tempEuribor3m; int numPerEuribor3m[2][5] = {0}, num_Euribor3m0 = 0, num_Euribor3m1 = 0;
			tempEuribor3mClass(tempAttribute, numPerEuribor3m, num_Euribor3m0, num_Euribor3m1);
			
			//18 - nr.employed: number of employees - quarterly indicator (numeric) 
			//			- 2 intervals: (x > 5200.0), (x <= 5200.0)
			//int tempNr, numPerNr[2][2] = {0}, num_Nr0 = 0, num_Nr1 = 0;
			tempNrClass(tempAttribute, numPerNr, num_Nr0, num_Nr1);
			
			//19 - y - has the client subscribed a term deposit? (binary: 'no','yes') 
			//			- 2 intervals: yes or no
			//int numPerOutput[2] = {0};
			numPerOutputClass(tempAttribute, numPerOutput);
			
			//----------------------Debug part--------------------------------------
			//for(;;)
		}
		
		//----------------------------------------------------------------
		//----------------------Start of Calculation part-----------------
		//----------------------------------------------------------------
		//0- Calculating the Age percentage and store it in AgePercentag[row][col], with respect to numPerAge[row][col] and num_Age0 and num_Age1.
		for(row = 0;row<2;row++){
			for(col = 0;col<5;col++){
				if(row==0)
					AgePercentage[row][col] = (float) numPerAge[row][col] / num_job0;
				else
					AgePercentage[row][col] = (float) numPerAge[row][col] / num_job1;
			}
		}
		
		//1- Calculate the Job percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<11;col++){
				if(row==0)
					JobPercentage[row][col] = (float) numPerJob[row][col] / num_Age0;
				else
					JobPercentage[row][col] = (float) numPerJob[row][col] / num_Age1;
			}
		}
		
		//2- Calculate the Material percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<3;col++){
				if(row==0)
					MaterialPercentage[row][col] = (float) numPerMat[row][col] / num_Mat0;
				else
					MaterialPercentage[row][col] = (float) numPerMat[row][col] / num_Mat1;
			}
		}
		
		//3- Calculate the Education Percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<7;col++){
				if(row==0)
					EducationPercentage[row][col] = (float) numPerEdu[row][col] / num_Edu0;
				else
					EducationPercentage[row][col] = (float) numPerEdu[row][col] / num_Edu1;
			}
		}

		
		//4- Calculate the Default percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					DefaultPercentage[row][col] = (float) numPerDefault[row][col] / num_Def0;
				else
					DefaultPercentage[row][col] = (float) numPerDefault[row][col] / num_Def1;
			}
		}
		
		//5- Calculate the housing percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					HousePercentage[row][col] = (float) numPerHouse[row][col] / num_House0;
				else
					HousePercentage[row][col] = (float) numPerHouse[row][col] / num_House1;
			}
		}
		
		//6- Calculate the loan percentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					LoanPercentage[row][col] = (float) numPerLoan[row][col] / num_Loan0;
				else
					LoanPercentage[row][col] = (float) numPerLoan[row][col] / num_Loan1;
			}
		}
		
		//7- Calculate the ContactPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					ContactPercentage[row][col] = (float) numPerCon[row][col] / num_Con0;
				else
					ContactPercentage[row][col] = (float) numPerCon[row][col] / num_Con1;
			}
		}
		
		//8- Calculate the MonthPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<12;col++){
				if(row==0)
					MonthPercentage[row][col] = (float) numPerMonth[row][col] / num_Month0;
				else
					MonthPercentage[row][col] = (float) numPerMonth[row][col] / num_Month1;
			}
		}
		
		//9- Calculate the DayPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<5;col++){
				if(row==0)
					DayPercentage[row][col] = (float) numPerDay[row][col] / num_Day0;
				else
					DayPercentage[row][col] = (float) numPerDay[row][col] / num_Day1;
			}
		}
		
		//10- Calculate the CampaignPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<3;col++){
				if(row==0)
					CampaignPercentage[row][col] = (float) numPerCampaign[row][col] / num_Campaign0;
				else
					CampaignPercentage[row][col] = (float) numPerCampaign[row][col] / num_Campaign1;
			}
		}
		
		//11- Calculate the PDaysPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<4;col++){
				if(row==0)
					PDaysPercentage[row][col] = (float) numPerPDays[row][col] / num_PDays0;
				else
					PDaysPercentage[row][col] = (float) numPerPDays[row][col] / num_PDays1;
			}
		}
		
		//12- Calculate the PreviousPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					PreviousPercentage[row][col] = (float) numPerPrevious[row][col] / num_Previous0;
				else
					PreviousPercentage[row][col] = (float) numPerPrevious[row][col] / num_Previous1;
			}
		}
		
		//13- Calculate the PoutcomePercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<3;col++){
				if(row==0)
					PoutcomePercentage[row][col] = (float) numPerPoutcome[row][col] / num_Poutcome0;
				else
					PoutcomePercentage[row][col] = (float) numPerPoutcome[row][col] / num_Poutcome1;
			}
		}

		//14- Calculate the EmpPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<4;col++){
				if(row==0)
					EmpPercentage[row][col] = (float) numPerEmp[row][col] / num_Emp0;
				else
					EmpPercentage[row][col] = (float) numPerEmp[row][col] / num_Emp1;
			}
		}
		
		//15- Calculate the PricePercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<3;col++){
				if(row==0)
					PricePercentage[row][col] = (float) numPerPrice[row][col] / num_Price0;
				else
					PricePercentage[row][col] = (float) numPerPrice[row][col] / num_Price1;
			}
		}
		
		//16- Calculate the ConfPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<4;col++){
				if(row==0)
					ConfPercentage[row][col] = (float) numPerConf[row][col] / num_Conf0;
				else
					ConfPercentage[row][col] = (float) numPerConf[row][col] / num_Conf1;
			}
		}
		
		//17- Calculate the Euribor3mPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<4;col++){
				if(row==0)
					Euribor3mPercentage[row][col] = (float) numPerEuribor3m[row][col] / num_Euribor3m0;
				else
					Euribor3mPercentage[row][col] = (float) numPerEuribor3m[row][col] / num_Euribor3m1;
			}
		}
		
		//18- Calculate the NrPercentage
		for(row = 0;row<2;row++){
			for(col = 0;col<2;col++){
				if(row==0)
					NrPercentage[row][col] = (float) numPerNr[row][col] / num_Nr0;
				else
					NrPercentage[row][col] = (float) numPerNr[row][col] / num_Nr1;
			}
		}
		
		
		//19- Calculate the OutputPercentage
		//cout<<"\nnumber of data: "<<numData<<"; "<<numPerOutput[0]<<"; "<<numPerOutput[1]<<endl;
		OutputPercentage[0] =  (float) numPerOutput[0] / numData;
		OutputPercentage[1] =  (float) numPerOutput[1] / numData;
		
		//---------------------------------------------------------------
		//-----------------Start to read Testing data 01----------------------
		//---------------------------------------------------------------
		
		while(fscanf(pTs, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,], %[^,],%[^,],%[^,],%[^,\n]",
							tempAttribute[0], tempAttribute[1], tempAttribute[2], tempAttribute[3], tempAttribute[4]
						, tempAttribute[5], tempAttribute[6], tempAttribute[7], tempAttribute[8], tempAttribute[9], tempAttribute[10]
						, tempAttribute[11], tempAttribute[12], tempAttribute[13], tempAttribute[14], tempAttribute[15], tempAttribute[16] 
						, tempAttribute[17], tempAttribute[18], tempAttribute[19]) != EOF /*&& numTest < 5 */)
		{
			//for testing a limited number of data set.
			numLine++;
			
			//0- Calculating the Age percentage and store it in AgePercentage[row][col], with respect to numPerAge[row][col] along with num_Age0 and num_Age1.
			ageReadClass(tempAttribute,tempAttPercentage,  AgePercentage);
			
			//1- Calculate the Job percentage
			jobReadClass(tempAttribute, tempAttPercentage, JobPercentage);
			
			//2- Calculate the Material percentage
			materialReadClass(tempAttribute, tempAttPercentage, MaterialPercentage);
			
			//3- Calculate the Education Percentage
			EduReadClass(tempAttribute, tempAttPercentage, EducationPercentage);
	
			
			//4- Calculate the Default percentage
			DefaultReadClass(tempAttribute, tempAttPercentage, DefaultPercentage);
			
			//5- Calculate the housing percentage
			houseReadClass(tempAttribute, tempAttPercentage, HousePercentage);
			
			//6- Calculate the loan percentage
			loanReadClass(tempAttribute, tempAttPercentage, LoanPercentage);
			
			//7- Calculate the ContactPercentage
			contactReadClass(tempAttribute, tempAttPercentage, ContactPercentage);
			
			//8- Calculate the MonthPercentage
			monthReadClass(tempAttribute, tempAttPercentage, MonthPercentage);
			
			//9- Calculate the DayPercentage
			dayReadClass(tempAttribute, tempAttPercentage, DayPercentage);
			
			//10- Calculate the CampaignPercentage
			campaignReadClass(tempAttribute, tempAttPercentage, CampaignPercentage);
			
			//11- Calculate the PDaysPercentage
			pdaysReadClass(tempAttribute, tempAttPercentage, PDaysPercentage);
			
			//12- Calculate the PreviousPercentage
			previousReadClass(tempAttribute, tempAttPercentage, PreviousPercentage);
			
			//13- Calculate the PoutcomePercentage
			poutcomeReadClass(tempAttribute, tempAttPercentage, PoutcomePercentage);
	
			//14- Calculate the EmpPercentage
			empReadClass(tempAttribute, tempAttPercentage, EmpPercentage);
			
			//15- Calculate the PricePercentage
			priceReadClass(tempAttribute, tempAttPercentage, PricePercentage);
			
			//16- Calculate the ConfPercentage
			confReadClass(tempAttribute, tempAttPercentage, ConfPercentage);
			
			//17- Calculate the Euribor3mPercentage
			euribor3mReadClass(tempAttribute, tempAttPercentage, Euribor3mPercentage);
			
			//18- Calculate the NrPercentage
			nrReadClass(tempAttribute, tempAttPercentage, NrPercentage);
		
			if(NoOutput_Percentage >= YesOutput_Percentage){
				if(strcmp(tempAttribute[19], "no") == 0)	
					CorrRate++;
				fprintf(pOutputFile, "no\n");
			}else{
				if(strcmp(tempAttribute[19], "yes") == 0)	
					CorrRate++;
				fprintf(pOutputFile, "yes\n");
			}
			
			
			/*for dubugging
			for(row = 0; row < 2; row ++){
				for(col = 0; col < 18; col ++){
					cout<< "The percentage of the tempAttPercentage table[" << row << "][" << col << "]: " << tempAttPercentage[row][col] <<endl;
				}
			}
			cout<<endl;
			cout<<"Predict No: " << NoOutput_Percentage << endl;
			cout<<"Predict Yes: " << YesOutput_Percentage << endl;
			cout<<endl;
			*/
			
			
		}
		
		//----------------------------------------------------------
		//-------------------End of Bank Data base------------------
		//----------------------------------------------------------
		cout<< "Correct Rate For bank " << numDataSet+1 << " : " << CorrRate / numLine << endl;
		numDataSet++;
		fclose (pFile);
		fclose (pTs);
		fclose (pOutputFile);
	}
	
	//system("PAUSE");
	return 0;
}

//---------------------------------------------------------------
//Start of classification (learning) funtions w.r.t the attributes 0 ~ 19
//---------------------------------------------------------------
// 0 - age (numeric)
void ageClass(char tempAttribute[ ][30], int (&numPerAge)[2][5], int &num_Age0, int &num_Age1){
	int tempAge = atoi(tempAttribute[0]);
	if(tempAge < 30 && tempAge > 0){
		if(strcmp(tempAttribute[19],"no") == 0){	
			numPerAge[0][0]++;	//Label 1	
			num_Age0++;
		}else{
			numPerAge[1][0]++;	//Label 2
			num_Age1++;
		}
	}else if(tempAge >= 30 && tempAge < 40){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerAge[0][1]++;	//Label 3	
			num_Age0++;
		}else{
			numPerAge[1][1]++;	//Label 4		
			num_Age1++;
		}
	}else if(tempAge >=40 && tempAge <50){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerAge[0][2]++;	//Label 5		
			num_Age0++;
		}else{
			numPerAge[1][2]++;	//Label 6		
			num_Age1++;
		}
	}else if(tempAge >=50 && tempAge<65 ){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerAge[0][3]++;	//Label 7		
			num_Age0++;
		}else{
			numPerAge[1][3]++;	//Label 8
			num_Age1++;
		}
	}else if(tempAge >65 && tempAge < 140){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerAge[0][4]++;	//Label 9
			num_Age0++;
		}else{
			numPerAge[1][4]++;	//Label 10
			num_Age1++;
		}
	}
}	
	
//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
void jobClass(char tempAttribute[ ][30], int (&numPerJob)[2][11], int &num_job0, int &num_job1){
	if(strcmp(tempAttribute[1],"admin.") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][0]++;			
			num_job0++;
		}else{
			numPerJob[1][0]++;			
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"blue-collar") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][1]++;			
			num_job0++;
		}else{
			numPerJob[1][1]++;			
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"entrepreneur") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][2]++;			
			num_job0++;
		}else{
			numPerJob[1][2]++;			
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"housemaid") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][3]++;			
			num_job0++;
		}else{
			numPerJob[1][3]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"management") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][4]++;
			num_job0++;
		}else{
			numPerJob[1][4]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"retired") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][5]++;
			num_job0++;
		}else{
			numPerJob[1][5]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"self-employed") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][6]++;
			num_job0++;
		}else{
			numPerJob[1][6]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"services") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][7]++;
			num_job0++;
		}else{
			numPerJob[1][7]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"student") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][8]++;
			num_job0++;
		}else{
			numPerJob[1][8]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"technician") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][9]++;
			num_job0++;
		}else{
			numPerJob[1][9]++;
			num_job1++;
		}
	}else if(strcmp(tempAttribute[1],"unemployed") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerJob[0][10]++;
			num_job0++;
		}else{
			numPerJob[1][10]++;
			num_job1++;
		}
	}
}

//2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
void maritalClass(char tempAttribute[ ][30], int (&numPerMat)[2][3], int &num_Mat0, int &num_Mat1){
	//int numPerMat[2][3] = {0}, num_Mat0 = 0, num_Mat1 = 0;
	if(strcmp(tempAttribute[2],"divorced") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMat[0][0]++;
			num_Mat0++;
		}else{
			numPerMat[1][0]++;		
			num_Mat1++;
		}
	}else if(strcmp(tempAttribute[2],"married") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMat[0][1]++;			
			num_Mat0++;
		}else{
			numPerMat[1][1]++;			
			num_Mat1++;
		}
	}else if(strcmp(tempAttribute[2],"single") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMat[0][2]++;			
			num_Mat0++;
		}else{
			numPerMat[1][2]++;			
			num_Mat1++;
		}
	}
}	

//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?')
void eduClass(char tempAttribute[ ][30], int (&numPerEdu)[2][7], int &num_Edu0, int &num_Edu1){
	if(strcmp(tempAttribute[3],"basic.4y") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][0]++;
			num_Edu0++;
		}else{
			numPerEdu[1][0]++;		
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"basic.6y") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][1]++;			
			num_Edu0++;
		}else{
			numPerEdu[1][1]++;			
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"basic.9y") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][2]++;			
			num_Edu0++;
		}else{
			numPerEdu[1][2]++;			
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"high.school") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][3]++;			
			num_Edu0++;
		}else{
			numPerEdu[1][3]++;
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"illiterate") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][4]++;
			num_Edu0++;
		}else{
			numPerEdu[1][4]++;
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"professional.course") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][5]++;
			num_Edu0++;
		}else{
			numPerEdu[1][5]++;
			num_Edu1++;
		}
	}else if(strcmp(tempAttribute[3],"university.degree") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEdu[0][6]++;
			num_Edu0++;
		}else{
			numPerEdu[1][6]++;
			num_Edu1++;
		}
	}
}	

//4 - default: has credit in default? (categorical: 'no','yes','?') 
void defaultClass(char tempAttribute[ ][30], int (&numPerDefault)[2][2], int &num_Def0, int &num_Def1){
	//int numPerDefault[2][2] = {0}, num_Def0 = 0, num_Def1 = 0;
	if(strcmp(tempAttribute[4],"no") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDefault[0][0]++;
			num_Def0++;
		}else{
			numPerDefault[1][0]++;		
			num_Def1++;
		}
	}else if(strcmp(tempAttribute[4],"yes") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDefault[0][1]++;			
			num_Def0++;
		}else{
			numPerDefault[1][1]++;			
			num_Def1++;
		}
	}
}

//5 - housing: has housing loan? (categorical: 'no','yes','?')
void houseClass(char tempAttribute[ ][30], int (&numPerHouse)[2][2], int &num_House0, int &num_House1){
	//int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
	if(strcmp(tempAttribute[5],"no") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerHouse[0][0]++;
			num_House0++;
		}else{
			numPerHouse[1][0]++;		
			num_House1++;
		}
	}else if(strcmp(tempAttribute[5],"yes") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerHouse[0][1]++;			
			num_House0++;
		}else{
			numPerHouse[1][1]++;			
			num_House1++;
		}
	}
}
	
//6 - loan: has personal loan? (categorical: 'no','yes','?') 
void loanClass(char tempAttribute[ ][30], int (&numPerLoan)[2][2], int &num_Loan0, int &num_Loan1){
	//int numPerLoan[2][2] = {0}, num_Loan0 = 0, num_Loan1 = 0;
	if(strcmp(tempAttribute[6],"no") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerLoan[0][0]++;
			num_Loan0++;
		}else{
			numPerLoan[1][0]++;		
			num_Loan1++;
		}
	}else if(strcmp(tempAttribute[6],"yes") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerLoan[0][1]++;			
			num_Loan0++;
		}else{
			numPerLoan[1][1]++;			
			num_Loan1++;
		}
	}
}	

//7 - contact: contact communication type (categorical: 'cellular','telephone') 
void contactClass(char tempAttribute[ ][30], int (&numPerCon)[2][2], int &num_Con0, int &num_Con1){
	//int numPerCon[2][2] = {0}, num_Con0 = 0, num_Con1 = 0;
	if(strcmp(tempAttribute[7],"cellular") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerCon[0][0]++;
			num_Con0++;
		}else{
			numPerCon[1][0]++;		
			num_Con1++;
		}
	}else if(strcmp(tempAttribute[7],"telephone") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerCon[0][1]++;			
			num_Con0++;
		}else{
			numPerCon[1][1]++;			
			num_Con1++;
		}
	}
}	
//8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec')
void monthClass(char tempAttribute[ ][30], int (&numPerMonth)[2][12], int &num_Month0, int &num_Month1){
	//int numPerMonth[2][12] = {0}, num_Month0 = 0, num_Month1 = 0;
	if(strcmp(tempAttribute[8],"jan") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][0]++;
			num_Month0++;
		}else{
			numPerMonth[1][0]++;		
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"feb") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][1]++;			
			num_Month0++;
		}else{
			numPerMonth[1][1]++;			
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"mar") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][2]++;			
			num_Month0++;
		}else{
			numPerMonth[1][2]++;			
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"apr") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][3]++;			
			num_Month0++;
		}else{
			numPerMonth[1][3]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"may") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][4]++;
			num_Month0++;
		}else{
			numPerMonth[1][4]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"jun") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][5]++;
			num_Month0++;
		}else{
			numPerMonth[1][5]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"jul") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][6]++;
			num_Month0++;
		}else{
			numPerMonth[1][6]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"aug") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][7]++;
			num_Month0++;
		}else{
			numPerMonth[1][7]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"sep") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][8]++;
			num_Month0++;
		}else{
			numPerMonth[1][8]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"oct") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][9]++;
			num_Month0++;
		}else{
			numPerMonth[1][9]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"nov") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][10]++;
			num_Month0++;
		}else{
			numPerMonth[1][10]++;
			num_Month1++;
		}
	}else if(strcmp(tempAttribute[8],"dec") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerMonth[0][11]++;
			num_Month0++;
		}else{
			numPerMonth[1][11]++;
			num_Month1++;
		}
	}
}	
	
//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
void dayClass(char tempAttribute[ ][30], int (&numPerDay)[2][5], int &num_Day0, int &num_Day1){
	//int numPerDay[2][5] = {0}, num_Day0 = 0, num_Day1 = 0;
	if(strcmp(tempAttribute[9],"mon") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDay[0][0]++;
			num_Day0++;
		}else{
			numPerDay[1][0]++;		
			num_Day1++;
		}
	}else if(strcmp(tempAttribute[9],"tue") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDay[0][1]++;			
			num_Day0++;
		}else{
			numPerDay[1][1]++;			
			num_Day1++;
		}
	}else if(strcmp(tempAttribute[9],"wed") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDay[0][2]++;			
			num_Day0++;
		}else{
			numPerDay[1][2]++;			
			num_Day1++;
		}
	}else if(strcmp(tempAttribute[9],"thu") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDay[0][3]++;			
			num_Day0++;
		}else{
			numPerDay[1][3]++;
			num_Day1++;
		}
	}else if(strcmp(tempAttribute[9],"fri") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerDay[0][4]++;
			num_Day0++;
		}else{
			numPerDay[1][4]++;
			num_Day1++;
		}
	}
}

/*10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
			- 3 intervals: (0 ~ 3), (4~6), (7+)	*/
void tempCampaignClass(char tempAttribute[ ][30], int (&numPerCampaign)[2][3], int &num_Campaign0, int &num_Campaign1){	
	//int tempCampaign, numPerCampaign[2][3] = {0}, num_Campaign0 = 0, num_Campaign1 = 0;
	int tempCampaign = atoi(tempAttribute[10]);
	if(tempCampaign <= 3 && tempCampaign >= 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerCampaign[0][0]++;			
			num_Campaign0++;
		}else{
			numPerCampaign[1][0]++;			
			num_Campaign1++;
		}
	}else if(tempCampaign >= 4 && tempCampaign <= 6){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerCampaign[0][1]++;			
			num_Campaign0++;
		}else{
			numPerCampaign[1][1]++;			
			num_Campaign1++;
		}
	}else if(tempCampaign >= 7){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerCampaign[0][2]++;			
			num_Campaign0++;
		}else{
			numPerCampaign[1][2]++;			
			num_Campaign1++;
		}
	}
}	
	
//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
//			- 4 intervals: (0~11), (12~20), (21 ~ 27), (999) 
void tempPDaysClass(char tempAttribute[ ][30], int (&numPerPDays)[2][4], int &num_PDays0, int &num_PDays1){		
	//int tempPDays, numPerPDays[2][5] = {0}, num_PDays0 = 0, num_PDays1 = 0;
	int tempPDays = atoi(tempAttribute[11]);
	if(tempPDays <= 11 && tempPDays >= 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPDays[0][0]++;			
			num_PDays0++;
		}else{
			numPerPDays[1][0]++;			
			num_PDays1++;
		}
	}else if(tempPDays >= 12 && tempPDays <= 20){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPDays[0][1]++;			
			num_PDays0++;
		}else{
			numPerPDays[1][1]++;			
			num_PDays1++;
		}
	}else if(tempPDays >= 21 && tempPDays <= 28){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPDays[0][2]++;			
			num_PDays0++;
		}else{
			numPerPDays[1][2]++;			
			num_PDays1++;
		}
	}else if(tempPDays == 999){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPDays[0][3]++;			
			num_PDays0++;
		}else{
			numPerPDays[1][3]++;			
			num_PDays1++;
		}
	}
}	
	
//12 - previous: number of contacts performed before this campaign and for this client (numeric) 
//			- intervals: 0, (not 0)
void tempPreviousClass(char tempAttribute[ ][30], int (&numPerPrevious)[2][2], int &num_Previous0, int &num_Previous1){			
	//int tempPrevious, numPerPrevious[2][2] = {0}, num_Previous0 = 0, num_Previous1 = 0;
	int tempPrevious = atoi(tempAttribute[12]);
	if(tempPrevious == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPrevious[0][0]++;			
			num_Previous0++;
		}else{
			numPerPrevious[1][0]++;			
			num_Previous1++;
		}
	}else if(tempPrevious != 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPrevious[0][1]++;			
			num_Previous0++;
		}else{
			numPerPrevious[1][1]++;			
			num_Previous1++;
		}
	}
}	
	
//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
//			- intervals: shown as above.
void numPerPoutcomeClass(char tempAttribute[ ][30], int (&numPerPoutcome)[2][3], int &num_Poutcome0, int &num_Poutcome1){			
	//int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
	if(strcmp(tempAttribute[13],"failure") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPoutcome[0][0]++;
			num_Poutcome0++;
		}else{
			numPerPoutcome[1][0]++;		
			num_Poutcome1++;
		}
	}else if(strcmp(tempAttribute[13],"nonexistent") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPoutcome[0][1]++;			
			num_Poutcome0++;
		}else{
			numPerPoutcome[1][1]++;			
			num_Poutcome1++;
		}
	}else if(strcmp(tempAttribute[13],"success") == 0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPoutcome[0][2]++;			
			num_Poutcome0++;
		}else{
			numPerPoutcome[1][2]++;			
			num_Poutcome1++;
		}
	}
}	
	
//14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
//			- 4 intervals: (x>=1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
void tempEmpClass(char tempAttribute[ ][30], int (&numPerEmp)[2][6], int &num_Emp0, int &num_Emp1){			
	//float tempEmp; int numPerEmp[2][6] = {0}, num_Emp0 = 0, num_Emp1 = 0;
	float tempEmp = atof(tempAttribute[14]);
	if(tempEmp >= 1.00){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEmp[0][0]++;			
			num_Emp0++;
		}else{
			numPerEmp[1][0]++;			
			num_Emp1++;
		}
	}else if(tempEmp >= -1.0 && tempEmp < 1.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEmp[0][1]++;			
			num_Emp0++;
		}else{
			numPerEmp[1][1]++;			
			num_Emp1++;
		}
	}else if(tempEmp >= -2.0 && tempEmp < -1.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEmp[0][2]++;			
			num_Emp0++;
		}else{
			numPerEmp[1][2]++;			
			num_Emp1++;
		}
	}else if(tempEmp < -2.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEmp[0][3]++;			
			num_Emp0++;
		}else{
			numPerEmp[1][3]++;			
			num_Emp1++;
		}
	}
}

//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
//			- 3 intervals: (x>=94.45), (92.8 <= x < 94.45), (x < 92.8)
void tempPriceClass(char tempAttribute[ ][30], int (&numPerPrice)[2][5], int &num_Price0, int &num_Price1){
	//float tempPrice; int numPerPrice[2][5] = {0}, num_Price0 = 0, num_Price1 = 0;
	float tempPrice = atof(tempAttribute[15]);
	if(tempPrice >= 94.45){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPrice[0][0]++;			
			num_Price0++;
		}else{
			numPerPrice[1][0]++;			
			num_Price1++;
		}
	}else if(tempPrice > 92.8 && tempPrice < 94.45){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPrice[0][1]++;			
			num_Price0++;
		}else{
			numPerPrice[1][1]++;			
			num_Price1++;
		}
	}else if(tempPrice <= 92.8){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerPrice[0][2]++;			
			num_Price0++;
		}else{
			numPerPrice[1][2]++;			
			num_Price1++;
		}
	}
}	
	
	
//16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
//			- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
void tempConfClass(char tempAttribute[ ][30], int (&numPerConf)[2][4], int &num_Conf0, int &num_Conf1){
	//float tempConf; int numPerConf[2][6] = {0}, num_Conf0 = 0, num_Conf1 = 0;
	float tempConf = atof(tempAttribute[16]);
	if(tempConf >= -30.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerConf[0][0]++;			
			num_Conf0++;
		}else{
			numPerConf[1][0]++;			
			num_Conf1++;
		}
	}else if(tempConf >= -35.0 && tempConf < -30.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerConf[0][1]++;			
			num_Conf0++;
		}else{
			numPerConf[1][1]++;			
			num_Conf1++;
		}
	}else if(tempConf >= -45.0 && tempConf < -35.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerConf[0][2]++;			
			num_Conf0++;
		}else{
			numPerConf[1][2]++;			
			num_Conf1++;
		}
	}else if(tempConf < -45.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerConf[0][3]++;			
			num_Conf0++;
		}else{
			numPerConf[1][3]++;			
			num_Conf1++;
		}
	}
}

//May 30th.
//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
//			- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
void tempEuribor3mClass(char tempAttribute[ ][30], int (&numPerEuribor3m)[2][4], int &num_Euribor3m0, int &num_Euribor3m1){
	//float tempEuribor3m; int numPerEuribor3m[2][5] = {0}, num_Euribor3m0 = 0, num_Euribor3m1 = 0;
	float tempEuribor3m = atof(tempAttribute[17]);
	if(tempEuribor3m >= 4.86){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEuribor3m[0][0]++;			
			num_Euribor3m0++;
		}else{
			numPerEuribor3m[1][0]++;			
			num_Euribor3m1++;
		}
	}else if(tempEuribor3m >= 4.0 && tempEuribor3m < 4.86){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEuribor3m[0][1]++;			
			num_Euribor3m0++;
		}else{
			numPerEuribor3m[1][1]++;			
			num_Euribor3m1++;
		}
	}else if(tempEuribor3m >= 1.0 && tempEuribor3m < 4.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEuribor3m[0][2]++;			
			num_Euribor3m0++;
		}else{
			numPerEuribor3m[1][2]++;			
			num_Euribor3m1++;
		}
	}else if(tempEuribor3m < 1.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerEuribor3m[0][3]++;			
			num_Euribor3m0++;
		}else{
			numPerEuribor3m[1][3]++;			
			num_Euribor3m1++;
		}
	}
}

//18 - nr.employed: number of employees - quarterly indicator (numeric) 
//			- 2 intervals: (x > 5200.0), (x <= 5200.0)
void tempNrClass(char tempAttribute[ ][30], int (&numPerNr)[2][2], int &num_Nr0, int &num_Nr1){
	//int tempNr, numPerNr[2][2] = {0}, num_Nr0 = 0, num_Nr1 = 0;
	float tempNr = atof(tempAttribute[18]);
	if(tempNr > 5200.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerNr[0][0]++;			
			num_Nr0++;
		}else{
			numPerNr[1][0]++;			
			num_Nr1++;
		}
	}else if(tempNr <= 5200.0){
		if(strcmp(tempAttribute[19],"no") == 0){
			numPerNr[0][1]++;			
			num_Nr0++;
		}else{
			numPerNr[1][1]++;			
			num_Nr1++;
		}
	}
}
	
//19 - y - has the client subscribed a term deposit? (binary: 'no','yes') 
//			- 2 intervals: yes or no
void numPerOutputClass(char tempAttribute[ ][30], int (&numPerOutput)[2]){	
	//int numPerOutput[2] = {0};
	if(strcmp(tempAttribute[19],"no") == 0){
		numPerOutput[0]++;			
	}else if(strcmp(tempAttribute[19],"yes") == 0){
		numPerOutput[1]++;
	}
}	
//---------------------------------------------------------------
//End of classification (learning) funtions w.r.t the attributes 0 ~ 19
//---------------------------------------------------------------
//---------------------------------------------------------------
//Start of calculation for training data 
//---------------------------------------------------------------
/*
	//0- Calculating the Age percentage and store it in AgePercentage[row][col], with respect to numPerAge[row][col] along with num_Age0 and num_Age1.
	for(row = 0;row<2;row++){
		for(col = 0;col<5;col++){
			if(row==0)
				AgePercentage[row][col] = (float) numPerAge[row][col] / num_job0;
			else
				AgePercentage[row][col] = (float) numPerAge[row][col] / num_job1;
		}
	}
	
	//1- Calculate the Job percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<11;col++){
			if(row==0)
				JobPercentage[row][col] = (float) numPerJob[row][col] / num_Age0;
			else
				JobPercentage[row][col] = (float) numPerJob[row][col] / num_Age1;
		}
	}
	
	//2- Calculate the Material percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<3;col++){
			if(row==0)
				MaterialPercentage[row][col] = (float) numPerMat[row][col] / num_Mat0;
			else
				MaterialPercentage[row][col] = (float) numPerMat[row][col] / num_Mat1;
		}
	}
	
	//3- Calculate the Education Percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<7;col++){
			if(row==0)
				EducationPercentage[row][col] = (float) numPerEdu[row][col] / num_Edu0;
			else
				EducationPercentage[row][col] = (float) numPerEdu[row][col] / num_Edu1;
		}
	}

	
	//4- Calculate the Default percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				DefaultPercentage[row][col] = (float) numPerDefault[row][col] / num_Def0;
			else
				DefaultPercentage[row][col] = (float) numPerDefault[row][col] / num_Def1;
		}
	}
	
	//5- Calculate the housing percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				HousePercentage[row][col] = (float) numPerHouse[row][col] / num_House0;
			else
				HousePercentage[row][col] = (float) numPerHouse[row][col] / num_House1;
		}
	}
	
	//6- Calculate the loan percentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				LoanPercentage[row][col] = (float) numPerLoan[row][col] / num_Loan0;
			else
				LoanPercentage[row][col] = (float) numPerLoan[row][col] / num_Loan1;
		}
	}
	
	//7- Calculate the ContactPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				ContactPercentage[row][col] = (float) numPerCon[row][col] / num_Con0;
			else
				ContactPercentage[row][col] = (float) numPerCon[row][col] / num_Con1;
		}
	}
	
	//8- Calculate the MonthPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<12;col++){
			if(row==0)
				MonthPercentage[row][col] = (float) numPerMonth[row][col] / num_Month0;
			else
				MonthPercentage[row][col] = (float) numPerMonth[row][col] / num_Month1;
		}
	}
	
	//9- Calculate the DayPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<5;col++){
			if(row==0)
				DayPercentage[row][col] = (float) numPerDay[row][col] / num_Day0;
			else
				DayPercentage[row][col] = (float) numPerDay[row][col] / num_Day1;
		}
	}
	
	//10- Calculate the CampaignPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<3;col++){
			if(row==0)
				CampaignPercentage[row][col] = (float) numPerCampaign[row][col] / num_Campaign0;
			else
				CampaignPercentage[row][col] = (float) numPerCampaign[row][col] / num_Campaign1;
		}
	}
	
	//11- Calculate the PDaysPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<4;col++){
			if(row==0)
				PDaysPercentage[row][col] = (float) numPerPDays[row][col] / num_PDays0;
			else
				PDaysPercentage[row][col] = (float) numPerPDays[row][col] / num_PDays1;
		}
	}
	
	//12- Calculate the PreviousPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				PreviousPercentage[row][col] = (float) numPerPrevious[row][col] / num_Previous0;
			else
				PreviousPercentage[row][col] = (float) numPerPrevious[row][col] / num_Previous1;
		}
	}
	
	//13- Calculate the PoutcomePercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<3;col++){
			if(row==0)
				PoutcomePercentage[row][col] = (float) numPerPoutcome[row][col] / num_Poutcome0;
			else
				PoutcomePercentage[row][col] = (float) numPerPoutcome[row][col] / num_Poutcome1;
		}
	}

	//14- Calculate the EmpPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<4;col++){
			if(row==0)
				EmpPercentage[row][col] = (float) numPerEmp[row][col] / num_Emp0;
			else
				EmpPercentage[row][col] = (float) numPerEmp[row][col] / num_Emp1;
		}
	}
	
	//15- Calculate the PricePercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<3;col++){
			if(row==0)
				PricePercentage[row][col] = (float) numPerPrice[row][col] / num_Price0;
			else
				PricePercentage[row][col] = (float) numPerPrice[row][col] / num_Price1;
		}
	}
	
	//16- Calculate the ConfPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<4;col++){
			if(row==0)
				ConfPercentage[row][col] = (float) numPerConf[row][col] / num_Conf0;
			else
				ConfPercentage[row][col] = (float) numPerConf[row][col] / num_Conf1;
		}
	}
	
	//17- Calculate the Euribor3mPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<4;col++){
			if(row==0)
				Euribor3mPercentage[row][col] = (float) numPerEuribor3m[row][col] / num_Euribor3m0;
			else
				Euribor3mPercentage[row][col] = (float) numPerEuribor3m[row][col] / num_Euribor3m1;
		}
	}
	
	//18- Calculate the NrPercentage
	for(row = 0;row<2;row++){
		for(col = 0;col<2;col++){
			if(row==0)
				NrPercentage[row][col] = (float) numPerNr[row][col] / num_Nr0;
			else
				NrPercentage[row][col] = (float) numPerNr[row][col] / num_Nr1;
		}
	}
	
	//19- Calculate the OutputPercentage
	//cout<<"\nnumber of data: "<<numData<<"; "<<numPerOutput[0]<<"; "<<numPerOutput[1]<<endl;
	OutputPercentage[0] =  (float) numPerOutput[0] / numData;
	OutputPercentage[1] =  (float) numPerOutput[1] / numData;
*/
//---------------------------------------------------------------
//End of calculation for training data 
//---------------------------------------------------------------
//---------------------------------------------------------------
//Start of reading test data from the database
//---------------------------------------------------------------
void  ageReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float AgePercentage[][5]){
	int tempAge = atoi(tempAttribute[0]);
	if(tempAge < 30){
		tempAttPercentage[0][0] = AgePercentage[0][0];
		tempAttPercentage[1][0] = AgePercentage[1][0];
	}else if(tempAge >= 30 && tempAge < 40){
		tempAttPercentage[0][0] = AgePercentage[0][1];
		tempAttPercentage[1][0] = AgePercentage[1][1];
	}else if(tempAge >=40 && tempAge <50){
		tempAttPercentage[0][0] = AgePercentage[0][2];
		tempAttPercentage[1][0] = AgePercentage[1][2];
	}else if(tempAge >=50 && tempAge<65 ){
		tempAttPercentage[0][0] = AgePercentage[0][3];
		tempAttPercentage[1][0] = AgePercentage[1][3];
	}else if(tempAge >65){
		tempAttPercentage[0][0] = AgePercentage[0][4];
		tempAttPercentage[1][0] = AgePercentage[1][4];
	}
}	
	
void  jobReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float JobPercentage[][11]){
	//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
	if(strcmp(tempAttribute[1],"admin.") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][0];
		tempAttPercentage[1][1] = JobPercentage[1][0];
	}else if(strcmp(tempAttribute[1],"blue-collar") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][1];
		tempAttPercentage[1][1] = JobPercentage[1][1];
	}else if(strcmp(tempAttribute[1],"entrepreneur") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][2];
		tempAttPercentage[1][1] = JobPercentage[1][2];
	}else if(strcmp(tempAttribute[1],"housemaid") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][3];
		tempAttPercentage[1][1] = JobPercentage[1][3];
	}else if(strcmp(tempAttribute[1],"management") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][4];
		tempAttPercentage[1][1] = JobPercentage[1][4];
	}
	else if(strcmp(tempAttribute[1],"retired") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][5];
		tempAttPercentage[1][1] = JobPercentage[1][5];
	}
	else if(strcmp(tempAttribute[1],"self-employed") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][6];
		tempAttPercentage[1][1] = JobPercentage[1][6];
	}
	else if(strcmp(tempAttribute[1],"services") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][7];
		tempAttPercentage[1][1] = JobPercentage[1][7];
	}
	else if(strcmp(tempAttribute[1],"student") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][8];
		tempAttPercentage[1][1] = JobPercentage[1][8];
	}
	else if(strcmp(tempAttribute[1],"technician") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][9];
		tempAttPercentage[1][1] = JobPercentage[1][9];
	}
	else if(strcmp(tempAttribute[1],"unemployed") == 0){
		tempAttPercentage[0][1] = JobPercentage[0][10];
		tempAttPercentage[1][1] = JobPercentage[1][10];
	}
}	

void  materialReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float MaterialPercentage[][3]){
	//2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
	//int numPerMat[2][3] = {0}, num_Mat0 = 0, num_Mat1 = 0;
	if(strcmp(tempAttribute[2],"divorced") == 0){
		tempAttPercentage[0][2] = MaterialPercentage[0][0];
		tempAttPercentage[1][2] = MaterialPercentage[1][0];
	}else if(strcmp(tempAttribute[2],"married") == 0){
		tempAttPercentage[0][2] = MaterialPercentage[0][1];
		tempAttPercentage[1][2] = MaterialPercentage[1][1];
	}else if(strcmp(tempAttribute[2],"single") == 0){
		tempAttPercentage[0][2] = MaterialPercentage[0][2];
		tempAttPercentage[1][2] = MaterialPercentage[1][2];
	}
}	

void  EduReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float EducationPercentage[][7]){
	//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?')
	if(strcmp(tempAttribute[3],"basic.4y") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][0];
		tempAttPercentage[1][3] = EducationPercentage[1][0];
	}else if(strcmp(tempAttribute[3],"basic.6y") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][1];
		tempAttPercentage[1][3] = EducationPercentage[1][1];
	}else if(strcmp(tempAttribute[3],"basic.9y") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][2];
		tempAttPercentage[1][3] = EducationPercentage[1][2];
	}else if(strcmp(tempAttribute[3],"high.school") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][3];
		tempAttPercentage[1][3] = EducationPercentage[1][3];
	}else if(strcmp(tempAttribute[3],"illiterate") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][4];
		tempAttPercentage[1][3] = EducationPercentage[1][4];
	}
	else if(strcmp(tempAttribute[3],"professional.course") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][5];
		tempAttPercentage[1][3] = EducationPercentage[1][5];
	}
	else if(strcmp(tempAttribute[3],"university.degree") == 0){
		tempAttPercentage[0][3] = EducationPercentage[0][6];
		tempAttPercentage[1][3] = EducationPercentage[1][6];
	}
}

void  DefaultReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float DefaultPercentage[][2]){
	//4 - default: has credit in default? (categorical: 'no','yes','?') 
	//int numPerDefault[2][2] = {0}, num_Def0 = 0, num_Def1 = 0;
	if(strcmp(tempAttribute[4],"no") == 0){
		tempAttPercentage[0][4] = DefaultPercentage[0][0];
		tempAttPercentage[1][4] = DefaultPercentage[1][0];
	}else if(strcmp(tempAttribute[4],"yes") == 0){
		tempAttPercentage[0][4] = DefaultPercentage[0][1];
		tempAttPercentage[1][4] = DefaultPercentage[1][1];
	}
}

void  houseReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float HousePercentage[][2]){
	//5 - housing: has housing loan? (categorical: 'no','yes','?') 
	//int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
	if(strcmp(tempAttribute[5],"no") == 0){
		tempAttPercentage[0][5] = HousePercentage[0][0];
		tempAttPercentage[1][5] = HousePercentage[1][0];
	}else if(strcmp(tempAttribute[5],"yes") == 0){
		tempAttPercentage[0][5] = HousePercentage[0][1];
		tempAttPercentage[1][5] = HousePercentage[1][1];
	}
}
	
void  loanReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float LoanPercentage[][2]){	
	//6 - loan: has personal loan? (categorical: 'no','yes','?') 
	//int numPerLoan[2][2] = {0}, num_Loan0 = 0, num_Loan1 = 0;
	if(strcmp(tempAttribute[6],"no") == 0){
		tempAttPercentage[0][6] = LoanPercentage[0][0];
		tempAttPercentage[1][6] = LoanPercentage[1][0];
	}else if(strcmp(tempAttribute[6],"yes") == 0){
		tempAttPercentage[0][6] = LoanPercentage[0][1];
		tempAttPercentage[1][6] = LoanPercentage[1][1];
	}
}

void  contactReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float ContactPercentage[][2]){		
	//7 - contact: contact communication type (categorical: 'cellular','telephone') 
	//int numPerCon[2][2] = {0}, num_Con0 = 0, num_Con1 = 0;
	if(strcmp(tempAttribute[7],"cellular") == 0){
		tempAttPercentage[0][7] = ContactPercentage[0][0];
		tempAttPercentage[1][7] = ContactPercentage[1][0];
	}else if(strcmp(tempAttribute[7],"telephone") == 0){
		tempAttPercentage[0][7] = ContactPercentage[0][1];
		tempAttPercentage[1][7] = ContactPercentage[1][1];
	}
}

void  monthReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float MonthPercentage[][12]){		
	//8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec') 
	//int numPerMonth[2][12] = {0}, num_Month0 = 0, num_Month1 = 0;
	if(strcmp(tempAttribute[8],"jan") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][0];
		tempAttPercentage[1][8] = MonthPercentage[1][0];
	}else if(strcmp(tempAttribute[8],"feb") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][1];
		tempAttPercentage[1][8] = MonthPercentage[1][1];
	}else if(strcmp(tempAttribute[8],"mar") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][2];
		tempAttPercentage[1][8] = MonthPercentage[1][2];
	}else if(strcmp(tempAttribute[8],"apr") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][3];
		tempAttPercentage[1][8] = MonthPercentage[1][3];
	}else if(strcmp(tempAttribute[8],"may") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][4];
		tempAttPercentage[1][8] = MonthPercentage[1][4];
	}else if(strcmp(tempAttribute[8],"jun") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][5];
		tempAttPercentage[1][8] = MonthPercentage[1][5];
	}else if(strcmp(tempAttribute[8],"jul") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][6];
		tempAttPercentage[1][8] = MonthPercentage[1][6];
	}else if(strcmp(tempAttribute[8],"aug") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][7];
		tempAttPercentage[1][8] = MonthPercentage[1][7];
	}else if(strcmp(tempAttribute[8],"sep") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][8];
		tempAttPercentage[1][8] = MonthPercentage[1][8];
	}else if(strcmp(tempAttribute[8],"oct") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][9];
		tempAttPercentage[1][8] = MonthPercentage[1][9];
	}else if(strcmp(tempAttribute[8],"nov") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][10];
		tempAttPercentage[1][8] = MonthPercentage[1][10];
	}else if(strcmp(tempAttribute[8],"dec") == 0){
		tempAttPercentage[0][8] = MonthPercentage[0][11];
		tempAttPercentage[1][8] = MonthPercentage[1][11];
	}
}	


void  dayReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float DayPercentage[][5]){		
	//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
	//int numPerDay[2][5] = {0}, num_Day0 = 0, num_Day1 = 0;
	if(strcmp(tempAttribute[9],"mon") == 0){
		tempAttPercentage[0][9] = DayPercentage[0][0];
		tempAttPercentage[1][9] = DayPercentage[1][0];
	}else if(strcmp(tempAttribute[9],"tue") == 0){
		tempAttPercentage[0][9] = DayPercentage[0][1];
		tempAttPercentage[1][9] = DayPercentage[1][1];
	}else if(strcmp(tempAttribute[9],"wed") == 0){
		tempAttPercentage[0][9] = DayPercentage[0][2];
		tempAttPercentage[1][9] = DayPercentage[1][2];
	}else if(strcmp(tempAttribute[9],"thu") == 0){
		tempAttPercentage[0][9] = DayPercentage[0][3];
		tempAttPercentage[1][9] = DayPercentage[1][3];
	}else if(strcmp(tempAttribute[9],"fri") == 0){
		tempAttPercentage[0][9] = DayPercentage[0][4];
		tempAttPercentage[1][9] = DayPercentage[1][4];
	}
}

void  campaignReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float CampaignPercentage[][3]){		
	/*10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
			- 3 intervals: (0 ~ 3), (4~6), (7+)	*/
	//int tempCampaign, numPerCampaign[2][3] = {0}, num_Campaign0 = 0, num_Campaign1 = 0;
	int tempCampaign = atoi(tempAttribute[10]);
	if(tempCampaign <= 3 && tempCampaign >= 0){
		tempAttPercentage[0][10] = CampaignPercentage[0][0];
		tempAttPercentage[1][10] = CampaignPercentage[1][0];
	}else if(tempCampaign >= 4 && tempCampaign <= 6){
		tempAttPercentage[0][10] = CampaignPercentage[0][1];
		tempAttPercentage[1][10] = CampaignPercentage[1][1];
	}else if(tempCampaign >= 7){
		tempAttPercentage[0][10] = CampaignPercentage[0][2];
		tempAttPercentage[1][10] = CampaignPercentage[1][2];
	}
}

void  pdaysReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PDaysPercentage[][4]){	
	//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
	//			- 4 intervals: (0~11), (12~20), (20 ~ 27), (999) 
	//int tempPDays, numPerPDays[2][5] = {0}, num_PDays0 = 0, num_PDays1 = 0;
	int tempPDays = atoi(tempAttribute[11]);
	if(tempPDays <= 11 && tempPDays >= 0){
		tempAttPercentage[0][11] = PDaysPercentage[0][0];
		tempAttPercentage[1][11] = PDaysPercentage[1][0];
	}else if(tempPDays >= 12 && tempPDays <= 20){
		tempAttPercentage[0][11] = PDaysPercentage[0][1];
		tempAttPercentage[1][11] = PDaysPercentage[1][1];
	}else if(tempPDays >= 20 && tempPDays <= 27){
		tempAttPercentage[0][11] = PDaysPercentage[0][2];
		tempAttPercentage[1][11] = PDaysPercentage[1][2];
	}else if(tempPDays == 999){
		tempAttPercentage[0][11] = PDaysPercentage[0][3];
		tempAttPercentage[1][11] = PDaysPercentage[1][3];
	}
}	

void  previousReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PreviousPercentage[][2]){	
	//12 - previous: number of contacts performed before this campaign and for this client (numeric) 
	//			- intervals: 0, (not 0)
	//int tempPrevious, numPerPrevious[2][2] = {0}, num_Previous0 = 0, num_Previous1 = 0;
	int tempPrevious = atoi(tempAttribute[12]);
	if(tempPrevious == 0){
		tempAttPercentage[0][12] = PreviousPercentage[0][0];
		tempAttPercentage[1][12] = PreviousPercentage[1][0];
	}else if(tempPrevious != 0){
		tempAttPercentage[0][12] = PreviousPercentage[0][1];
		tempAttPercentage[1][12] = PreviousPercentage[1][1];
	}
}	

void  poutcomeReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PoutcomePercentage[][3]){		
	//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
	//			- intervals: shown as above.
	//int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
	if(strcmp(tempAttribute[13],"failure") == 0){
		tempAttPercentage[0][13] = PoutcomePercentage[0][0];
		tempAttPercentage[1][13] = PoutcomePercentage[1][0];
	}else if(strcmp(tempAttribute[13],"nonexistent") == 0){
		tempAttPercentage[0][13] = PoutcomePercentage[0][1];
		tempAttPercentage[1][13] = PoutcomePercentage[1][1];
	}else if(strcmp(tempAttribute[13],"success") == 0){
		tempAttPercentage[0][13] = PoutcomePercentage[0][2];
		tempAttPercentage[1][13] = PoutcomePercentage[1][2];
	}
}	


void empReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float EmpPercentage[][4]){		
	//14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
	//			- 4 intervals: (x>1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
	//float tempEmp; int numPerEmp[2][6] = {0}, num_Emp0 = 0, num_Emp1 = 0;
	float tempEmp = atof(tempAttribute[14]);
	if(tempEmp >= 1.00){
		tempAttPercentage[0][14] = EmpPercentage[0][0];
		tempAttPercentage[1][14] = EmpPercentage[1][0];
	}else if(tempEmp >= -1.0 && tempEmp < 1.0){
		tempAttPercentage[0][14] = EmpPercentage[0][1];
		tempAttPercentage[1][14] = EmpPercentage[1][1];
	}else if(tempEmp >= -2.0 && tempEmp < -1.0){
		tempAttPercentage[0][14] = EmpPercentage[0][2];
		tempAttPercentage[1][14] = EmpPercentage[1][2];
	}else if(tempEmp < -2.0){
		tempAttPercentage[0][14] = EmpPercentage[0][3];
		tempAttPercentage[1][14] = EmpPercentage[1][3];
	}
}

void  priceReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PricePercentage[][3]){			
	//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
	//			- 3 intervals: (x>94.45), (92.8 <= x < 94.45), (x < 92.8)
	//float tempPrice; int numPerPrice[2][5] = {0}, num_Price0 = 0, num_Price1 = 0;
	float tempPrice = atof(tempAttribute[15]);
	if(tempPrice >= 94.45){
		tempAttPercentage[0][15] = PricePercentage[0][0];
		tempAttPercentage[1][15] = PricePercentage[1][0];
	}else if(tempPrice >= 92.8 && tempPrice < 94.45){
		tempAttPercentage[0][15] = PricePercentage[0][1];
		tempAttPercentage[1][15] = PricePercentage[1][1];
	}else if(tempPrice < 92.8){
		tempAttPercentage[0][15] = PricePercentage[0][2];
		tempAttPercentage[1][15] = PricePercentage[1][2];
	}
}
	
void  confReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float ConfPercentage[][4]){				
	//16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
	//			- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
	//float tempConf; int numPerConf[2][6] = {0}, num_Conf0 = 0, num_Conf1 = 0;
	float tempConf = atof(tempAttribute[16]);
	if(tempConf >= -30.0){
		tempAttPercentage[0][16] = ConfPercentage[0][0];
		tempAttPercentage[1][16] = ConfPercentage[1][0];
	}else if(tempConf >= -35.0 && tempConf < -30.0){
		tempAttPercentage[0][16] = ConfPercentage[0][1];
		tempAttPercentage[1][16] = ConfPercentage[1][1];
	}else if(tempConf >= -45.0 && tempConf < -35.0){
		tempAttPercentage[0][16] = ConfPercentage[0][2];
		tempAttPercentage[1][16] = ConfPercentage[1][2];
	}else if(tempConf < -45.0){
		tempAttPercentage[0][16] = ConfPercentage[0][3];
		tempAttPercentage[1][16] = ConfPercentage[1][3];
	}
}

void  euribor3mReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float Euribor3mPercentage[][4]){				
	//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
	//			- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
	//float tempEuribor3m; int numPerEuribor3m[2][5] = {0}, num_Euribor3m0 = 0, num_Euribor3m1 = 0;
	float tempEuribor3m = atof(tempAttribute[17]);
	if(tempEuribor3m >= 4.86){
		tempAttPercentage[0][17] = Euribor3mPercentage[0][0];
		tempAttPercentage[1][17] = Euribor3mPercentage[1][0];
	}else if(tempEuribor3m >= 4.0 && tempEuribor3m < 4.86){
		tempAttPercentage[0][17] = Euribor3mPercentage[0][1];
		tempAttPercentage[1][17] = Euribor3mPercentage[1][1];
	}else if(tempEuribor3m >= 1.0 && tempEuribor3m < 4.0){
		tempAttPercentage[0][17] = Euribor3mPercentage[0][2];
		tempAttPercentage[1][17] = Euribor3mPercentage[1][2];
	}else if(tempEuribor3m < 1.0){
		tempAttPercentage[0][17] = Euribor3mPercentage[0][3];
		tempAttPercentage[1][17] = Euribor3mPercentage[1][3];
	}
}
void  nrReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float NrPercentage[][2]){	
	//18 - nr.employed: number of employees - quarterly indicator (numeric) 
	//			- 2 intervals: (x > 5200.0), (x <= 5200.0)
	//int tempNr, numPerNr[2][2] = {0}, num_Nr0 = 0, num_Nr1 = 0;
	float tempNr = atof(tempAttribute[18]);
	if(tempNr > 5200.0){
		tempAttPercentage[0][18] = NrPercentage[0][0];
		tempAttPercentage[1][18] = NrPercentage[1][0];
	}else if(tempNr <= 5200.0){
		tempAttPercentage[0][18] = NrPercentage[0][1];
		tempAttPercentage[1][18] = NrPercentage[1][1];
	}
}

void finalPercentageCalculation(float tempAttPercentage[][20], double &NoOutput_Percentage, double &YesOutput_Percentage){
	int col;
	for(col = 0; col < 18; col ++){
		if(tempAttPercentage[0][col] != 0){
			//cout<<"NO percentage: "<<tempAttPercentage[0][col]<<endl;
			NoOutput_Percentage += log(tempAttPercentage[0][col]);
		}
		if(tempAttPercentage[1][col] != 0){
			//cout<<"Yes percentage: "<<tempAttPercentage[1][col]<<endl;
			YesOutput_Percentage += log(tempAttPercentage[1][col]);
		}
	}
}

//---------------------------------------------------------------
//End of reading test data from the database
//---------------------------------------------------------------
