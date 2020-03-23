#include<iostream>  
#include<string>  
#include<cctype>
#include<iomanip>
using namespace std;  
  
class HugeInt{  
  
   friend ostream &operator<<( ostream &, const HugeInt & );  
     
public:  
   static const int digits = 40; // maximum digits in a HugeInt  
     
   HugeInt( long = 0 ); // conversion/default constructor 1.  
  
   HugeInt( const string & ); // conversion constructor 2.  
     
  
   HugeInt operator+( const HugeInt & ) const;// addition operator; HugeInt + HugeInt 3.  
  
   HugeInt operator+( int ) const;// addition operator; HugeInt + int 4.   
  
   HugeInt operator+( const string & ) const;// HugeInt + string that represents large integer value 5.  
  
private:  
    short integer[ digits ];  
};  

HugeInt::HugeInt( long value )//1.  
{  
   for ( int i = 0; i < digits; ++i ){// initialize array to zero  
        integer[i]=0;  
   }      
   for ( int j = digits - 1; value != 0 && j >= 0; --j ){// place digits of argument into array  
        integer[j]=value%10;  
        value=value/10;  
   } // end for  
} // end 1.  
  
HugeInt::HugeInt( const string &number )//2.  
{  
   for ( int i = 0; i < digits; ++i ){// initialize array to zero  
        integer[i]=0;  
   }  
  
   int length=number.size();  
     
   for ( int j = digits - length, k = 0; j < digits; ++j, ++k ){// place digits of argument into array  
       // ensure that character is a digit 
		if(isdigit(number[k]))
        integer[j]=number[k]-'0';//ASCII code 裡面，'0'=48         
   }  
} // end 2.  
  
HugeInt HugeInt::operator+( const HugeInt &op2 ) const//3.  
{  
	HugeInt temp; // temporary result  
  
	for ( int i = digits - 1; i >= 0; --i ){  
      // determine whether to carry a 1  
        temp.integer[i]=integer[i]+op2.integer[i];  
          
		if ( temp.integer[ i ] > 9 ){  
			temp.integer[i]=temp.integer[i]-10;
			temp.integer[i-1]+=1;
		}// end if        
   }  
   return temp;// return copy of temporary object  
} // end 3.  
  
HugeInt HugeInt::operator+( int op2 ) const//4.  
{  
   return *this+HugeInt(op2);// convert op2 to a HugeInt     
} // end 4.  
  
HugeInt HugeInt::operator+( const string &op2 ) const//5.  
{  
   return *this+HugeInt(op2);// convert op2 to a HugeInt   
} // end 5.  
  
ostream& operator<<( ostream &output, const HugeInt &num )// overloaded output operator  
{  
   int i;  
  
   for (i=0;(num.integer[i]==0) && (i < HugeInt::digits);i++) ;	// skip leading zeros
          
	if ( i >= HugeInt::digits)output << 0; 
	else{  
		for ( ; i < HugeInt::digits; ++i ){
				output << num.integer[i];
		}
	}
   return output;  
}  
  
int main()
{  
	string n1,n2;
	int stop=0;
	
	cin.ignore();
	
	while(1){		
		cin >> n1;
			if(n1=="-1")break;
		cin.ignore(3);
		cin >> n2;
					
		HugeInt ans1(n1);
		HugeInt ans2(n2);
		cout << ans1+ans2 << endl;	
	}
}