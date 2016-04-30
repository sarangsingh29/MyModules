/*
	Kumar Saarang Singh
	psarang29@gmail.com

	This is a small program implementing my custom 
	brute force string generation algorithm.

	I/p: 
	1. Choose a starting character.
	2. Choose an ending character.
	3. Maximum length till which strings are to be 
	   generated.

	  ***
	  Note: Make sure the starting character is smaller
	  than the ending character.
	  ***


	If you find any bugs (I know it's a short program, but still),
	please feel free to provide input.

	Thank you!
*/


#include <iostream>

using namespace std;


int main()
{
	cout<<"Choose starting character: ";
	char schar;
	cin>>schar;

	cout<<"Choose ending character: ";
	char echar;
	cin>>echar;

	if(echar<schar)
	{
		cout<<"\n\nSorry! The starting character must be smaller than the ending charcter.\n";
		return 0;
	}

	cout<<"Maximum length of possible strings: ";
	int len;
	cin>>len;

	char buf[10]={schar,'\0'};
	int i=1;



	while(1)
	{
		if(i==len+1) break;
		cout<<buf<<endl;
		int j=0;

		while(buf[j]==echar)
		{
			buf[j]=schar;
			j++;
		}
		if(j==i)
		{
			i+=1;
			buf[j]=schar;
			buf[i]='\0';
		}
		else
			buf[j]+=1;
	}

	return 0;
}
