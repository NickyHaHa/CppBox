//Program : 羅馬數字相減求絕對值後，再轉成羅馬數字
//Date : 2019 / 11 / 12
#include<iostream>
#include<string.h>
#include<cstdlib>									//for abs()
using namespace std;
#define SIZE 100

int sum_(char str[SIZE]);							//for sum of Roma number-1 or 2
int toRoma(int num);								//sum to Roma number

int main(){

	char str1[SIZE],str2[SIZE];
	while(1){
		cin >> str1;
		if(str1[0] == '#')break;					//input = '#',stop
		cin >> str2;
		toRoma(abs(sum_(str1) - sum_(str2)));
		//cout << abs(sum_(str1) - sum_(str2));
		//cout << sum_(str1) << " " << sum_(str2);
		cout << endl;
	}

}

int sum_(char str[SIZE]){
	int sum = 0;
	int len = strlen(str);							//Roma number's length
	for(int x = 0;x <= len-1;x++){
		switch(str[x]){								//from first number to check
			case 'I':
				if(str[x+1] == 'M'){				//not used
					sum += 999;
					x++;
				}
				else if(str[x+1] == 'D'){			//not used
					sum += 499;
					x++;
				}
				else if(str[x+1] == 'C'){			//not used
					sum += 99;
					x++;
				}
				else if(str[x+1] == 'L'){			//not used
					sum += 49;
					x++;
				}
				else if(str[x+1] == 'X'){			//IX = 10-1 = 9
					sum += 9;
					x++;
				}
				else if(str[x+1] == 'V'){			//IV = 5-1 = 4
					sum += 4;
					x++;
				}
				else{
					sum += 1;
				}
				break;

			case 'V':
				if(str[x+1] == 'M'){				//not used
					sum += 995;
					x++;
				}
				else if(str[x+1] == 'D'){			//not used
					sum += 495;
					x++;
				}
				else if(str[x+1] == 'C'){			//not used
					sum += 95;
					x++;
				}
				else if(str[x+1] == 'L'){			//not used
					sum += 45;
					x++;
				}
				else{
					sum += 5;
				}
				break;

			case 'X':
				if(str[x+1] == 'M'){				//not used
					sum += 990;
					x++;
				}
				else if(str[x+1] == 'D'){			//not used
					sum += 490;
					x++;
				}
				else if(str[x+1] == 'C'){			//XC = 100-10 = 90
					sum += 90;
					x++;
				}
				else if(str[x+1] == 'L'){			//XL = 50-10 = 40
					sum += 40;
					x++;
				}
				else{
					sum += 10;
				}
				break;

			case 'L':
				if(str[x+1] == 'M'){				//not used
					sum += 950;
					x++;
				}
				else if(str[x+1] == 'D'){			//not used
					sum += 450;
					x++;
				}
				else{
					sum += 50;
				}
				break;

			case 'C':
				if(str[x+1] == 'M'){				//CM = 1000-100 = 900
					sum += 900;
					x++;
				}
				else if(str[x+1] == 'D'){			//CD = 500-100 = 400
					sum += 400;
					x++;
				}
				else{
					sum += 100;
				}
				break;

			case 'D':
				sum += 500;
				break;

			case 'M':
				sum += 1000;
				break;
		}
	}
	return sum;
}

int toRoma(int num){
	if(num == 0)cout << "ZERO";						//sum = 0

	int i = 1, v = 5, x = 10, l = 50;
	int c = 100, d = 500, m = 1000;

	if(num / m > 0){								//ex : 2959(MMM - XLI)
		int count = 0;
		for(int t = 0;t < num/m;t++){
			count++;
			cout << "M";							//MM
		}											//count = 2
		num -= m*count;								//2959 - 1000*2 = 959
	}

	if(num / d > 0){
		int count = 0;
		for(int t = 0;t < num/d;t++){
			if(num / 900 > 0){						//959 / 900 > 0
				cout << "CM";						//MMCM
				num -= 900;							//959 - 900 = 59,break
				break;
			}
			count++;
			cout << "D";
		}
		num -= d*count;								//59 - 500*0 = 59
	}

	if(num / c > 0){
		int count = 0;
		for(int t = 0;t < num/c;t++){
			if(num / 400 > 0){
				cout << "CD";
				num -= 400;
				break;
			}
			count++;
			cout << "C";
		}
		num -= c*count;
	}

	if(num / l > 0){
		int count = 0;
		for(int t = 0;t < num/l;t++){
			if(num / 90 > 0){
				cout << "XC";
				num -= 90;
				break;
			}
			count++;
			cout << "L";							//MMCML
		}
		num -= l*count;								//59 - 50*1 = 9
	}

	if(num / x > 0){
		int count = 0;
		for(int t = 0;t < num/x;t++){
			if(num / 40 > 0){
				cout << "XL";
				num -= 40;
				break;
			}
			count++;
			cout << "X";
		}
		num -= x*count;
	}

	if(num / v > 0){
		int count = 0;
		for(int t = 0;t < num/v;t++){
			if(num / 9 > 0){						//9 / 9 > 0
				cout << "IX";						//MMCMLIX
				num -= 9;							//9 - 9 = 0,break
				break;
			}
			count++;
			cout << "V";
		}
		num -= v*count;
	}

	if(num / i > 0){
		int count = 0;
		for(int t = 0;t < num/i;t++){
			if(num / 4 > 0){
				cout << "IV";
				num -= 4;
				break;
			}
			count++;
			cout << "I";
		}
		num -= i*count;
	}
}