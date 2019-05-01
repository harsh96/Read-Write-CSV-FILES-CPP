#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	int i,j;
	string value;
	vector<string> row;
	vector<vector<string> > data;

	ifstream file( "input.csv" );
	while ( file.good() )
	{
		row.clear();
     	getline ( file, value);
     	stringstream check1(value); 
      
		string intermediate; 
      
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}


	/*--------WORK ON DATA HERE---------*/


	//DO NOTHING AS WE ARE JUST MAKING A COPY HERE




	/*---------------------------------*/	



	ofstream outfile;
	outfile.open("output.csv");
	for(i=0;i<data.size();i++){
		for(j=0;j<data[i].size();j++){
			outfile<<data[i][j];
			if(i!=data[i].size()-1) cout<<",";
		}
		outfile<<endl;
	} 

	cout<<"FILE COPIED"<<endl;
}