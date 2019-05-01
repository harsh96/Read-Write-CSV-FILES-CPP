#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	int i,j,y;
	string value;
	vector <string> row,countries; 
	vector<vector<string> > data;
	unordered_map <string,int> countryIdx,countryArea;
	vector<vector<vector<string> > > sData(17,vector<vector<string> >(30,vector<string>(30," ")));
	vector<vector<string> > gdp(30,vector<string>(17," ")),inflation(30,vector<string>(17," ")),language(30,vector<string>(30," ")),distance(30,vector<string>(30," "));

	ifstream file1( "Panel Data.csv" );
	while ( file1.good() )
	{
		row.clear();
     	getline ( file1, value);
     	stringstream check1(value); 
      
		string intermediate; 
      
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}
	for(i=1;i<data.size();i++){
		if(countries.size()==0) countries.push_back(data[i][0]);
		else{
			int x;
			x = countries.size();
			if(data[i][0]!=countries[x-1]) countries.push_back(data[i][0]);
		}
	} 
	for(i=0;i<countries.size();i++) {

		countryIdx.insert({countries[i],i});
	}
	
	for(i=1;i<data.size();i++){
		int year = stoi(data[i][2]);
		int a,b;
		a = countryIdx[data[i][0]];
		b = countryIdx[data[i][1]];
		sData[year-2000][a][b] = data[i][3].substr(0,data[i][3].length()-1);
	}

	data.clear();
	ifstream file2 ( "Area.csv" );
	while ( file2.good() )
	{
		row.clear();
     	getline ( file2, value); 
     	stringstream check1(value); 
      
		string intermediate; 
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}
	for(i=1;i<data.size();i++){
		countryArea.insert({data[i][0],stoi(data[i][1])});
	}

	data.clear();
	ifstream file3 ( "Distance.csv" );
	while ( file3.good() )
	{
		row.clear();
     	getline ( file3, value); 
     	stringstream check1(value); 
      
		string intermediate; 
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}
	for(i=1;i<data.size();i++){
		distance[countryIdx[data[i][0]]][countryIdx[data[i][1]]] = data[i][3].substr(0,data[i][3].length()-1);;
		language[countryIdx[data[i][0]]][countryIdx[data[i][1]]] = data[i][2];
	}

	data.clear();
	ifstream file4 ( "GDP.csv" );
	while ( file4.good() )
	{
		row.clear();
     	getline ( file4, value);
     	stringstream check1(value); 
      
		string intermediate; 
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}
	for(i=1;i<data.size();i++){
		for(j=1;j<=17;j++){
			gdp[countryIdx[data[i][0]]][j-1] = data[i][j];
		}
	}

	ifstream file5 ( "Inflation.csv" );
	while ( file5.good() )
	{
		row.clear();
     	getline ( file5, value); 
     	stringstream check1(value); 
      
		string intermediate; 
	    while(getline(check1, intermediate, ',')) 
	    { 
	        row.push_back(intermediate); 
	    } 
	    data.push_back(row);
	}
	for(i=1;i<data.size();i++){
		for(j=1;j<=17;j++){
			inflation[countryIdx[data[i][0]]][j-1] = data[i][j];
		}
	}

	ofstream myfile;
	myfile.open("Panel Data Output.csv");
	
	myfile<<"Country (i),Country (j),Year,X (ij) in 1000 USD,GDP (i),GDP (j),Dist (ij),Lang (ij),Area (i),Area (j),Inflation (i),Inflation (j)"<<endl;
	for(i=0;i<30;i++){
		for(j=0;j<30;j++){
			if(i!=j){
				for(y=0;y<17;y++){
					myfile<<countries[i]<<","<<countries[j]<<","<<(y+2000)<<","<<sData[y][i][j]<<","<<gdp[i][y]<<","<<gdp[j][y]<<","<<distance[i][j]<<","<<language[i][j]<<","<<countryArea[countries[i]]<<","<<countryArea[countries[j]]<<","<<inflation[i][y]<<","<<inflation[j][y]<<endl;
				}
			}
			
		}
	}
	cout<<"FILES COMBINED"<<endl;
	return 0;
}