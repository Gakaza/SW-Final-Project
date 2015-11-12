#ifndef TERM_PROJECT_H
#define TERM_PROJECT_H
//---------------------------------------------------------------
//Start of classification (learning) funtions w.r.t the attributes 0 ~ 19
//---------------------------------------------------------------
// 0 - age (numeric)
void ageClass(char tempAttribute[ ][30], int (&numPerAge)[2][5], int &num_Age0, int &num_Age1);
	
//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
void jobClass(char tempAttribute[ ][30], int (&numPerJob)[2][11], int &num_job0, int &num_job1);

//2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
void maritalClass(char tempAttribute[ ][30], int (&numPerMat)[2][3], int &num_Mat0, int &num_Mat1);

//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?')
void eduClass(char tempAttribute[ ][30], int (&numPerEdu)[2][7], int &num_Edu0, int &num_Edu1);

//4 - default: has credit in default? (categorical: 'no','yes','?') 
void defaultClass(char tempAttribute[ ][30], int (&numPerDefault)[2][2], int &num_Def0, int &num_Def1);

//5 - housing: has housing loan? (categorical: 'no','yes','?')
void houseClass(char tempAttribute[ ][30], int (&numPerHouse)[2][2], int &num_House0, int &num_House1);
	
//6 - loan: has personal loan? (categorical: 'no','yes','?') 
void loanClass(char tempAttribute[ ][30], int (&numPerLoan)[2][2], int &num_Loan0, int &num_Loan1);

//7 - contact: contact communication type (categorical: 'cellular','telephone') 
void contactClass(char tempAttribute[ ][30], int (&numPerCon)[2][2], int &num_Con0, int &num_Con1);
//8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec')
void monthClass(char tempAttribute[ ][30], int (&numPerMonth)[2][12], int &num_Month0, int &num_Month1);	
	
//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
void dayClass(char tempAttribute[ ][30], int (&numPerDay)[2][5], int &num_Day0, int &num_Day1);
/*10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
			- 3 intervals: (0 ~ 3), (4~6), (7+)	*/
void tempCampaignClass(char tempAttribute[ ][30], int (&numPerCampaign)[2][3], int &num_Campaign0, int &num_Campaign1);
	
//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
//			- 4 intervals: (0~11), (12~20), (21 ~ 27), (999) 
void tempPDaysClass(char tempAttribute[ ][30], int (&numPerPDays)[2][4], int &num_PDays0, int &num_PDays1);
	
//12 - previous: number of contacts performed before this campaign and for this client (numeric) 
//			- intervals: 0, (not 0)
void tempPreviousClass(char tempAttribute[ ][30], int (&numPerPrevious)[2][2], int &num_Previous0, int &num_Previous1);
	
//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
//			- intervals: shown as above.
void numPerPoutcomeClass(char tempAttribute[ ][30], int (&numPerPoutcome)[2][3], int &num_Poutcome0, int &num_Poutcome1);
	
//14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
//			- 4 intervals: (x>=1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
void tempEmpClass(char tempAttribute[ ][30], int (&numPerEmp)[2][6], int &num_Emp0, int &num_Emp1);

//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
//			- 3 intervals: (x>=94.45), (92.8 <= x < 94.45), (x < 92.8)
void tempPriceClass(char tempAttribute[ ][30], int (&numPerPrice)[2][5], int &num_Price0, int &num_Price1);
	
	
//16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
//			- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
void tempConfClass(char tempAttribute[ ][30], int (&numPerConf)[2][4], int &num_Conf0, int &num_Conf1);
//May 30th.
//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
//			- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
void tempEuribor3mClass(char tempAttribute[ ][30], int (&numPerEuribor3m)[2][4], int &num_Euribor3m0, int &num_Euribor3m1);

//18 - nr.employed: number of employees - quarterly indicator (numeric) 
//			- 2 intervals: (x > 5200.0), (x <= 5200.0)
void tempNrClass(char tempAttribute[ ][30], int (&numPerNr)[2][2], int &num_Nr0, int &num_Nr1);
	
//19 - y - has the client subscribed a term deposit? (binary: 'no','yes') 
//			- 2 intervals: yes or no
void numPerOutputClass(char tempAttribute[ ][30], int (&numPerOutput)[2]);
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
void  ageReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float AgePercentage[][5]);
	//1 - job : type of job (categorical: 'admin.','blue-collar','entrepreneur','housemaid','management','retired','self-employed','services','student','technician','unemployed','?') 
void  jobReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float JobPercentage[][11]);
//2 - marital : marital status (categorical: 'divorced','married','single','?'; note: 'divorced' means divorced or widowed) 
	//int numPerMat[2][3] = {0}, num_Mat0 = 0, num_Mat1 = 0;
void  materialReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float MaterialPercentage[][3]);
//3 - education (categorical: 'basic.4y','basic.6y','basic.9y','high.school','illiterate','professional.course','university.degree','?')
void  EduReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float EducationPercentage[][7]);
//4 - default: has credit in default? (categorical: 'no','yes','?') 
	//int numPerDefault[2][2] = {0}, num_Def0 = 0, num_Def1 = 0;
void  DefaultReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float DefaultPercentage[][2]);
//5 - housing: has housing loan? (categorical: 'no','yes','?') 
	//int numPerHouse[2][2] = {0}, num_House0 = 0, num_House1 = 0;
void  houseReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float HousePercentage[][2]);
	//6 - loan: has personal loan? (categorical: 'no','yes','?') 
	//int numPerLoan[2][2] = {0}, num_Loan0 = 0, num_Loan1 = 0;
void  loanReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float LoanPercentage[][2]);
//7 - contact: contact communication type (categorical: 'cellular','telephone') 
	//int numPerCon[2][2] = {0}, num_Con0 = 0, num_Con1 = 0;
void  contactReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float ContactPercentage[][2]);
//8 - month: last contact month of year (categorical: 'jan', 'feb', 'mar', ..., 'nov', 'dec') 
	//int numPerMonth[2][12] = {0}, num_Month0 = 0, num_Month1 = 0;
void  monthReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float MonthPercentage[][12]);

//9 - day_of_week: last contact day of the week (categorical: 'mon','tue','wed','thu','fri') 
	//int numPerDay[2][5] = {0}, num_Day0 = 0, num_Day1 = 0;
void  dayReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float DayPercentage[][5]);
/*10 - campaign: number of contacts performed during this campaign and for this client (numeric, includes last contact) 
			- 3 intervals: (0 ~ 3), (4~6), (7+)	*/
	//int tempCampaign, numPerCampaign[2][3] = {0}, num_Campaign0 = 0, num_Campaign1 = 0;
void  campaignReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float CampaignPercentage[][3]);
//11 - pdays: number of days that passed by after the client was last contacted from a previous campaign (numeric; 999 means client was not previously contacted) 
	//			- 4 intervals: (0~11), (12~20), (20 ~ 27), (999) 
	//int tempPDays, numPerPDays[2][5] = {0}, num_PDays0 = 0, num_PDays1 = 0;
void  pdaysReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PDaysPercentage[][4]);

//12 - previous: number of contacts performed before this campaign and for this client (numeric) 
	//			- intervals: 0, (not 0)
	//int tempPrevious, numPerPrevious[2][2] = {0}, num_Previous0 = 0, num_Previous1 = 0;
void  previousReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PreviousPercentage[][2]);

//13 - poutcome: outcome of the previous marketing campaign (categorical: 'failure','nonexistent','success') 
	//			- intervals: shown as above.
	//int numPerPoutcome[2][3] = {0}, num_Poutcome0 = 0, num_Poutcome1 = 0;
void  poutcomeReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PoutcomePercentage[][3]);

//14 - emp.var.rate: employment variation rate - quarterly indicator (numeric) 
	//			- 4 intervals: (x>1.0), (-1.0<= x < 1.0) , (-2.0<= x <-1.0) , (x < -2.0)
	//float tempEmp; int numPerEmp[2][6] = {0}, num_Emp0 = 0, num_Emp1 = 0;
void empReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float EmpPercentage[][4]);
//15 - cons.price.idx: consumer price index - monthly indicator (numeric)
	//			- 3 intervals: (x>94.45), (92.8 <= x < 94.45), (x < 92.8)
	//float tempPrice; int numPerPrice[2][5] = {0}, num_Price0 = 0, num_Price1 = 0;
void  priceReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float PricePercentage[][3]);
	
//16 - cons.conf.idx: consumer confidence index - monthly indicator (numeric) 
	//			- 4 intervals: (x>-30.0), (-35.0<= x < -30.0), (-45.0< = x < -35.0), ( x < -45.0)
	//float tempConf; int numPerConf[2][6] = {0}, num_Conf0 = 0, num_Conf1 = 0;
void  confReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float ConfPercentage[][4]);

//17 - euribor3m: euribor 3 month rate - daily indicator (numeric) 
	//			- 4 intervals: (x > 4.86), ( 4.0 <= x < 4.86), ( 1.0 <= x < 4.0), , ( x < 1.0)
	//float tempEuribor3m; int numPerEuribor3m[2][5] = {0}, num_Euribor3m0 = 0, num_Euribor3m1 = 0;
void  euribor3mReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float Euribor3mPercentage[][4]);
//18 - nr.employed: number of employees - quarterly indicator (numeric) 
	//			- 2 intervals: (x > 5200.0), (x <= 5200.0)
	//int tempNr, numPerNr[2][2] = {0}, num_Nr0 = 0, num_Nr1 = 0;
void  nrReadClass(char tempAttribute[][30], float (&tempAttPercentage)[2][20], float NrPercentage[][2]);

void finalPercentageCalculation(float tempAttPercentage[][20], double &NoOutput_Percentage, double &YesOutput_Percentage);

//---------------------------------------------------------------
//End of reading test data from the database
//---------------------------------------------------------------

#endif
