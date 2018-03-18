#include<iostream>
#include<fstream>

using namespace std;

int main()
{
 ifstream shk;
 ofstream excel;
 char line[100];
 char time[100];
 
 int signal,prevsig=0;
 
 shk.open("shock.txt");		//INPUT LOG FILE
 excel.open("excel.txt",ios::app); //OUTPUT LOG FILE, APPENDS AT EVERY RUN

 cout<<"Title of the experiment";		//ADDS HEADING AT THE START OF OUTPUT FILE
 cin>>line;
 excel<<"\n\n"<<line<<"\n****************************\n";

 if(shk.good())
 {
  cout<<"Opened shock.txt..."<<endl;
  for(int i=0;shk;i++)
  {
   shk.getline(time,100,'\n');			//FOR GETTING TIME
   if(shk) shk.getline(line,100,'\n');
   if(shk) shk.getline(line,100,'\n');
   cout<<line;
   
   for(int j=22;j<30;j++)
     excel.put(time[j]);			//OUTPUTS TIME IN 1ST COLUMN
      
   signal=10*(int)line[1] + (int)line[2]-528;	//CONVERTS SIGNAL FROM CHAR -> INT
   cout<<'\t'<<signal<<'\n';
   if(signal<10)				//CHECK FOR ERROR 55
	{
	 excel<<'\t'<<signal<<endl;		//OUTPUTS SIGNAL IN 2ND COLUMN
	 prevsig=signal;			
	}
   else
	excel<<'\t'<<prevsig<<endl;		//IF ERROR = 55, OUTPUT PREVSIG

  }
 }
 else cout<<"Unable to open shock.txt"<<endl;

 cout<<"Closing file..."<<endl;
 excel.close();
 shk.close();

 return 0;
}


