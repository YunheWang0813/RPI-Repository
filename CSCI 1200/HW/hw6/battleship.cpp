#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<string>
#include<iomanip>
#include"ship.h"
using namespace std;

class loc {
public:
  loc(int r=0, int c=0, int f=0) : row(r), col(c), flag(f){}
  int row, col, flag;
};

bool operator== (const loc& lhs, const loc& rhs) { 
  return lhs.row == rhs.row && lhs.col == rhs.col; 
}

bool check(vector<loc>& location, vector<int>& currentrow, vector<int>& currentcol, const vector<int> rows, const vector<int> cols, const vector<Ship> ships, vector<loc>& occupied, vector<vector<loc> >& allsols){
	if(location.size()==ships.size()){
		bool f=true;
		for(int i=0;i<int(allsols.size());i++){
			int number=0;
			for(int j=0;j<int(location.size());j++){
				loc check1=allsols[i][j];
				for(int k=0;k<int(location.size());k++){
					loc check2=location[k];
					if(check1==check2){
						number++;
						break;
					}
				}
			}
			if(number==int(location.size())){
				f=false;
				break;
			}
		}
		
		if(f){
		allsols.push_back(location);
		}		
		location.clear();	//reset all info related to the just identified answer
		occupied.clear();
		currentrow.clear();
		currentcol.clear();
		for(int i=0;i<int(rows.size());i++){
		currentrow.push_back(0);
	    }
		for(int i=0;i<int(cols.size());i++){
		currentcol.push_back(0);
	    }
		return true;
	}
	
	int r=rows.size();
	int c=cols.size();
	
	Ship temp=ships[location.size()];
	
		//horizontal situation
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				loc temploc(i,j,1);  //get the info of the current location
				bool judge0=true;  //check if the location is at the occupied locations
				for(int x=0;x<int(occupied.size());x++){
					if(temploc==occupied[x]){
						judge0=false;
						break;
					}
				}
				
				bool judge1=true;   //check if the ship exceed the boundry
				if(j+temp.getsize()>int(cols.size())){
					judge1=false;
				}
				
				if(judge0&&judge1){
					bool judge2=true;   //check if cols meet the requirement
					for(int x=0;x<temp.getsize();x++){
						if(currentcol[j+x]+1>cols[j+x]){
							judge2=false;
							break;
						}
					}
				
					if(judge2){
						if(temp.getsize()+currentrow[i]<=rows[i]){  //check if rows meet the requirement
							currentrow[i]+=temp.getsize();        //increment currentrow
							for(int x=0;x<temp.getsize();x++){
								currentcol[j+x]+=1;     //increment currentcol
							}
							
							location.push_back(temploc);  //introduce the location of the ship's head
							int countocu=0;
							for(int p=i-1;p<i+2;p++){
								for(int q=j-1;q<j+temp.getsize()+1;q++){
									if(p>=0&&q>=0&&p<r&&q<c){
										occupied.push_back(loc(p,q,0));  //update occupied info
										countocu+=1;
									}
								}
							}
							
							if(check(location, currentrow, currentcol, rows, cols, ships, occupied, allsols)){
								return true;
							}
							location.pop_back();  //if the answer doesn't find, delete the data of that temp ship
							for(int x=0;x<countocu;x++){  //also, delete the data of occupied area
								occupied.pop_back();
							}
							currentrow[i]-=temp.getsize();        //reset currentrow
							for(int x=0;x<temp.getsize();x++){
								currentcol[j+x]-=1;     //reset currentcol
							}
						}
					}
			    }
			}
		}
		
		//vertical situation
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				loc temploc(i,j,2);  //get the info of the current location
				bool judge0=true;  //check if the location is at the occupied locations
				for(int x=0;x<int(occupied.size());x++){
					if(temploc==occupied[x]){
						judge0=false;
						break;
					}
				}
				
				bool judge1=true;   //check if the ship exceed the boundry
				if(i+temp.getsize()>int(rows.size())){
					judge1=false;
				}
				
				if(judge0&&judge1){
					bool judge2=true;   //check if rows meet the requirement
					for(int x=0;x<temp.getsize();x++){
						if(currentrow[i+x]+1>rows[i+x]){
							judge2=false;
							break;
						}
					}
				
					if(judge2){
						if(temp.getsize()+currentcol[j]<=cols[j]){  //check if rows meet the requirement
							currentcol[j]+=temp.getsize();        //increment currentcol
							for(int x=0;x<temp.getsize();x++){
								currentrow[i+x]+=1;     //increment currentrow
							}
							
							location.push_back(temploc);  //introduce the location of the ship's head
							int countocu=0;
							for(int p=i-1;p<i+temp.getsize()+1;p++){
								for(int q=j-1;q<j+2;q++){
									if(p>=0&&q>=0&&p<r&&q<c){
										occupied.push_back(loc(p,q,0));  //update occupied info
										countocu+=1;
									}
								}
							}
							
							if(check(location, currentrow, currentcol, rows, cols, ships, occupied, allsols)){
								return true;
							}
							location.pop_back();  //if the answer doesn't find, delete the data of that temp ship
							for(int x=0;x<countocu;x++){  //also, delete the data of occupied area
								occupied.pop_back();
							}
							currentcol[j]-=temp.getsize();        //reset currentcol
							for(int x=0;x<temp.getsize();x++){
								currentrow[i+x]-=1;     //reset currentrow
							}
						}
					}
			    }
			}
		}
	
	
	
	
	return false;
}




int main(int argc, char* argv[]){
  if (argc != 2&&argc!=3) {
    std::cerr << "Usage: " << argv[0] << " grid-file\n";
    return 1;                                                       //flag True to check if there is the third argument
  }
  
  bool allcheck=false;
  if(argc==3&&string(argv[2])=="find_all_solutions"){
	allcheck=true;
  }

  ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "Couldn't open " << argv[1] << '\n';
    return 1;
  }
	
	string info;
	int r;
	int c;
	
	istr>>info;
	istr>>info;
	r=atoi(info.c_str());
	istr>>info;
	c=atoi(info.c_str());

	vector<int> rows;
	istr>>info;
	for(int i=0;i<r;i++){
		istr>>info;
		rows.push_back(atoi(info.c_str()));
	}
	
	vector<int> cols;
	istr>>info;
	for(int i=0;i<c;i++){
		istr>>info;
		cols.push_back(atoi(info.c_str()));
	}
	
    vector<Ship> ships;
	while(istr>>info&&info!="constraint"){
		Ship ship(info);
		ships.push_back(ship);
	}
	
	bool cons=false;   //check if there is a constraint
	loc constr;
	if(info=="constraint"){
		cons=true;
		istr>>info;
		int rex=atoi(info.c_str());
		istr>>info;
		int cex=atoi(info.c_str());
		istr>>info;
		int a;
		if(info=="<"){
			a=1;
		}
		else if(info=="^"){
			a=2;
		}
		else if(info=="X"){
			a=3;
		}
		else if(info==">"){
			a=4;
		}
		else if(info=="v"){
			a=5;
		}
		else if(info=="o"){
			a=6;
		}
		else if(info=="_"){
			a=0;
		}
		constr.row=rex;
		constr.col=cex;
		constr.flag=a;
	}
		
	vector<int> currentrow;
	for(int i=0;i<r;i++){
		currentrow.push_back(0);
	}
	vector<int> currentcol;
	for(int i=0;i<c;i++){
		currentcol.push_back(0);
	}
	
	bool found=false;
	vector<loc> location;
	vector<loc> occupied;
	vector<vector<loc> > allsols;  //store all solutions' info
	
		Ship temp=ships[0];  //get the info of the tested ship
	
		//horizontal situation
		for(int i=0;i<r;i++){
			if(!allcheck){
				if(found==true){
					break;
				}
			}
			for(int j=0;j<c;j++){
				loc temploc(i,j,1);  //get the info of the current location
				bool judge0=true;  //check if the location is at the occupied locations
				for(int x=0;x<int(occupied.size());x++){
					if(temploc==occupied[x]){
						judge0=false;
						break;
					}
				}
				
				bool judge1=true;   //check if the ship exceed the boundry
				if(j+temp.getsize()>int(cols.size())){
					judge1=false;
				}
				
				if(judge0&&judge1){
					bool judge2=true;   //check if cols meet the requirement
					for(int x=0;x<temp.getsize();x++){
						if(currentcol[j+x]+1>cols[j+x]){
							judge2=false;
							break;
						}
					}
				
					if(judge2){
						if(temp.getsize()+currentrow[i]<=rows[i]){  //check if rows meet the requirement
							currentrow[i]+=temp.getsize();        //increment currentrow
							for(int x=0;x<temp.getsize();x++){
								currentcol[j+x]+=1;     //increment currentcol
							}
							
							location.push_back(temploc);  //introduce the location of the ship's head
							int countocu=0;
							for(int p=i-1;p<i+2;p++){
								for(int q=j-1;q<j+temp.getsize()+1;q++){
									if(p>=0&&q>=0&&p<r&&q<c){
										occupied.push_back(loc(p,q,0));  //update occupied info
										countocu+=1;
									}
								}
							}
							
							if(check(location, currentrow, currentcol, rows, cols, ships, occupied, allsols)){
								found=true;
							}
							if(!found){
							location.pop_back();  //if the answer doesn't find, delete the data of that temp ship
							for(int x=0;x<countocu;x++){  //also, delete the data of occupied area
								occupied.pop_back();
							}
							currentrow[i]-=temp.getsize();        //reset currentrow
							for(int x=0;x<temp.getsize();x++){
								currentcol[j+x]-=1;     //reset currentcol
							}
							}
							found=false;   //reset found flag
						}
					}
			    }
			}
		}
		
		//vertical situation
		for(int i=0;i<r;i++){
			if(!allcheck){
				if(found==true){
					break;
				}
			}
			for(int j=0;j<c;j++){
				loc temploc(i,j,2);  //get the info of the current location
				bool judge0=true;  //check if the location is at the occupied locations
				for(int x=0;x<int(occupied.size());x++){
					if(temploc==occupied[x]){
						judge0=false;
						break;
					}
				}
				
				bool judge1=true;   //check if the ship exceed the boundry
				if(i+temp.getsize()>int(rows.size())){
					judge1=false;
				}
				
				if(judge0&&judge1){
					bool judge2=true;   //check if rows meet the requirement
					for(int x=0;x<temp.getsize();x++){
						if(currentrow[i+x]+1>rows[i+x]){
							judge2=false;
							break;
						}
					}
				
					if(judge2){
						if(temp.getsize()+currentcol[j]<=cols[j]){  //check if rows meet the requirement
							currentcol[j]+=temp.getsize();        //increment currentcol
							for(int x=0;x<temp.getsize();x++){
								currentrow[i+x]+=1;     //increment currentrow
							}
							
							location.push_back(temploc);  //introduce the location of the ship's head
							int countocu=0;
							for(int p=i-1;p<i+temp.getsize()+1;p++){
								for(int q=j-1;q<j+2;q++){
									if(p>=0&&q>=0&&p<r&&q<c){
										occupied.push_back(loc(p,q,0));  //update occupied info
										countocu+=1;
									}
								}
							}
							
							if(check(location, currentrow, currentcol, rows, cols, ships, occupied, allsols)){
								found=true;
							}
							if(!found){
							location.pop_back();  //if the answer doesn't find, delete the data of that temp ship
							for(int x=0;x<countocu;x++){  //also, delete the data of occupied area
								occupied.pop_back();
							}
							currentcol[j]-=temp.getsize();        //reset currentcol
							for(int x=0;x<temp.getsize();x++){
								currentrow[i+x]-=1;     //reset currentrow
							}
							}
							found=false;   //reset found flag
						}
					}
			    }
			}
		}
		
		bool finalcase=false;  //check if there is at least one solution (for check constraint)
		
		if(allsols.size()>=1){
			for(int n=0;n<int(allsols.size());n++){
						
			vector<loc> store;			//store all info
			
			for(int i=0;i<int(allsols[n].size());i++){
				if(ships[i].getname()=="submarine"){    //submarine situation
					store.push_back(loc(allsols[n][i].row,allsols[n][i].col,6));
				}
				else{
					if(allsols[n][i].flag==1){     //horizontal flag
						store.push_back(allsols[n][i]);
						for(int x=0;x<ships[i].getsize()-1;x++){
							if(x==int(ships[i].getsize()-2)){
								store.push_back(loc(allsols[n][i].row,allsols[n][i].col+x+1,4));
							}
							else{
								store.push_back(loc(allsols[n][i].row,allsols[n][i].col+x+1,3));
							}
						}
					}
					
					if(allsols[n][i].flag==2){     //vertical flag
						store.push_back(allsols[n][i]);
						for(int x=0;x<ships[i].getsize()-1;x++){
							if(x==int(ships[i].getsize()-2)){
								store.push_back(loc(allsols[n][i].row+x+1,allsols[n][i].col,5));
							}
							else{
								store.push_back(loc(allsols[n][i].row+x+1,allsols[n][i].col,3));
							}
						}
					}					
				}
			}
			
			if(cons){
				bool checkcons=false;
				for(int t=0;t<int(store.size());t++){
					if(store[t]==constr){
						if(store[t].flag==constr.flag){
							checkcons=true;
							break;
						}
					}
				}
				if(!checkcons){
					continue;
				}
			}
			
			finalcase=true;   //we can know there is at least one solution
			
			cout<<"Solution:"<<endl;
			int maxname=0;
			for(int i=0;i<int(ships.size());i++){
				if(maxname<int(ships[i].getname().length())){
					maxname=int(ships[i].getname().length());
				}
			}

			for(int i=0;i<int(allsols[n].size());i++){
				cout<<ships[i].getname()<<string(3+(maxname-ships[i].getname().length()),' ')<<allsols[n][i].row<<" "<<allsols[n][i].col;
				if(ships[i].getname()!="submarine"){
					if(allsols[n][i].flag==1){
						cout<<" horizontal"<<endl;
					}
					else if(allsols[n][i].flag==2){
						cout<<" vertical"<<endl;
					}
				}
				else{
					cout<<endl;
				}
			}
						
			cout<<"+"<<setw(c+1)<<setfill('-')<<"+"<<endl;
			for(int i=0;i<int(rows.size());i++){
				cout<<"|";
				for(int j=0;j<int(cols.size());j++){
					loc temploc(i,j,0);
					bool judge=false;
					for(int x=0;x<int(store.size());x++){
						if(temploc==store[x]){
							judge=true;
							if(store[x].flag==1){
								cout<<"<";
							}
							else if(store[x].flag==2){
								cout<<"^";
							}
							else if(store[x].flag==3){
								cout<<"X";
							}
							else if(store[x].flag==4){
								cout<<">";
							}
							else if(store[x].flag==5){
								cout<<"v";
							}
							else if(store[x].flag==6){
								cout<<"o";
							}					
							break;
						}
					}
					
					if(!judge){
						cout<<" ";
					}
				}
				
				cout<<"|"<<rows[i]<<endl;
			}
			cout<<"+"<<setw(c+1)<<setfill('-')<<"+"<<endl;
			cout<<" ";
			for(int i=0;i<c;i++){
				cout<<cols[i];
			}
			cout<<" "<<endl;
			cout<<endl;
			
			if(!allcheck){     //if we want to get only one solution, let the loop finish
				break;
			}
			
			}
			
			if(finalcase){
			if(allcheck){
				if(allsols.size()==1){
					cout<<"Found 1 solution"<<endl;
				}
				else{
					cout<<"Found "<<allsols.size()<<" solution(s)"<<endl;
				}
			}
			}
			
			if(!finalcase){
				cout<<"No solutions"<<endl;
			}
		}
		
		else{
			cout<<"No solutions"<<endl;
		}
	
	return 0;
}