
#include<iostream>
#include<limits.h>

using namespace std;
const int n = 3; // number of columns
const int m = 4; // number of rows 
int Total[3];
int Total_UnitCamMod[4];

void maxi_col(int a[][3], int m, int n)
{
	int i, j;
	int sum = 0; 
	int unit_price = 0; 

	for (i = 0; i < n; i++)
	{
		
		for (j = 0; j < m; j++)
		{
			if (j == 0) {
				unit_price = a[j][i] * 730;
			}
			else if (j == 1) {
				unit_price = a[j][i] * 850;
			}
			else if (j == 2) {
				unit_price = a[j][i] * 150;
			}
			else if (j == 3) {
				unit_price = a[j][i] * 350;
			}
			sum += unit_price;
			Total[i] = sum; 
		}
		sum = 0;
		
		if (i == 0) {
			cout << "Total gross sales for Branch SJ is: RM " << Total[0] << endl;
		}
		else if (i == 1) {
			cout << "Total gross sales for Branch PJ is: RM " << Total[1] << endl;
		}
		else if (i == 2) {
			cout << "Total gross sales for Branch KL is: RM " << Total[2] << endl;
		}
		
	}

	cout << "\n" << endl;
}

void Find_max(int a[3], int n) {
	int max = a[0];
	string s; 
	int i = 0; 
	for (i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i]; 
		}
		if (i == 0) {
			s = "SJ";
		}
		else if (i == 1) {
			s = "PJ";
		}
		else if (i == 2) {
			s = "KL";
		}
	}
	
	cout << "The highest sales figure is RM " << max << " by Branch " << s << endl;
	
}

void Total_UnitSold(int a[][3], int m, int n) {
	int i, j, s;
	int sum = 0;
	string CamModName;
	
	for (i = 0; i < m; i++) {

		for (j = 0; j < n; j++) {
			sum += a[i][j];
		}
		Total_UnitCamMod[i] = sum;
		sum = 0; 
	}
	int max = Total_UnitCamMod[0];

	for (s = 0; s < m; s++) {
		if (Total_UnitCamMod[s] > max) {
			max = Total_UnitCamMod[s];
		}
		if (Total_UnitCamMod[0] == max) {
			CamModName = "RS Pro with GPS";
		}
		else if (Total_UnitCamMod[1] == max) {
			CamModName = "Transcend Drive Pro";
		}
		else if (Total_UnitCamMod[2] == max) {
			CamModName = "H203 1080P";
		}
		else if (Total_UnitCamMod[3] == max) {
			CamModName = "Pioneer";
		}
	}

	cout << "The most popular dash cam model is " << CamModName << " with unit sold of " << max << " units." << endl;

}

int main()
{
	int i, j;
	int UnitSold[m][n];
	
	cout << "The Unit Sold data table:" << endl;
	cout << endl; 
	cout << "Dash Cam model        SJ Branch       PJ Branch      PJ Branch  " << endl;
	cout << "RS Pro with GPS        [0][0]          [0][1]          [0][2]   " << endl;
	cout << "Transcend Drive Pro    [1][0]          [1][1]          [1][2]   " << endl;
	cout << "H203 1080P             [2][0]          [2][1]          [2][2]   " << endl;
	cout << "Pioneer                [3][0]          [3][1]          [3][2]   " << endl;
	cout << endl; 

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++) {
			cout << "Type data input of UnitSold[" << i << "][" << j << "] : " << endl;
			cin >> UnitSold[i][j];
		}
	}

	cout << endl;
	cout << "The Unit Sold data table:" << endl;
	cout << endl;

	cout << "Dash Cam model        SJ Branch       PJ Branch      PJ Branch  " << endl;
	cout << "RS Pro with GPS        " << UnitSold[0][0] << "                " << UnitSold[0][1] << "                " << UnitSold[0][2] << "   " << endl;
	cout << "Transcend Drive Pro    " << UnitSold[1][0] << "                " << UnitSold[1][1] << "                " << UnitSold[1][2] << "   " << endl;
	cout << "H203 1080P             " << UnitSold[2][0] << "                " << UnitSold[2][1] << "                " << UnitSold[2][2] << "   " << endl;
	cout << "Pioneer                " << UnitSold[3][0] << "                " << UnitSold[3][1] << "                " << UnitSold[3][2] << "   " << endl;

	cout << endl; 
	maxi_col(UnitSold, m, n);
	Find_max(Total, 3); 
	Total_UnitSold(UnitSold, m, n);
	return 0;
}