#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"tetris.h"
using namespace std;

Tetris::Tetris(int w){
	width=w;
	heights=new int[width];
	data=new char*[width];
	
	for(int i=0;i<width;i++){
		heights[i]=0;
	}
	
	for(int i=0;i<width;i++){
		data[i]=NULL;
	}
	
}

void Tetris::add_piece(char mino, int rot, int place){
	if(mino=='O'){
		char *col1=new char[heights[place]+2];
		char *old_col1=data[place];
		for(int i=0;i<heights[place];i++){
			col1[i]=old_col1[i];
		}
		for(int i=0;i<2;i++){
			col1[i+heights[place]]='O';
		}
		data[place]=col1;
		delete old_col1;
		
		char *col2=new char[heights[place+1]+2];
		char *old_col2=data[place+1];
		for(int i=0;i<heights[place+1];i++){
			col2[i]=old_col2[i];
		}
		for(int i=0;i<2;i++){
			col2[i+heights[place+1]]='O';
		}
		data[place+1]=col2;
		delete old_col2;
		
		heights[place]+=2;
		heights[place+1]+=2;
		
		int maxh=0;
		for(int i=0;i<2;i++){
			if(heights[place+i]>maxh){
				maxh=heights[place+i];
			}
		}
		
		if(heights[place]!=maxh){
			char *newcol1=new char[maxh];
			for(int i=0;i<heights[place];i++){
				newcol1[i]=col1[i];
			}
			for(int i=heights[place]-2;i<maxh-2;i++){
				newcol1[i]=' ';
			}
			newcol1[maxh-2]='O';
			newcol1[maxh-1]='O';
			data[place]=newcol1;
			delete col1;
			heights[place]=maxh;
		}
		
		if(heights[place+1]!=maxh){
			char *newcol2=new char[maxh];
			for(int i=0;i<heights[place+1];i++){
				newcol2[i]=col2[i];
			}
			for(int i=heights[place+1]-2;i<maxh-2;i++){
				newcol2[i]=' ';
			}
			newcol2[maxh-2]='O';
			newcol2[maxh-1]='O';
			data[place+1]=newcol2;
			delete col2;
			heights[place+1]=maxh;
		}
		
	}
	
	if(mino=='I'){
		if(rot==90||rot==270){
			char *col1=new char[heights[place]+1];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='I';
			data[place]=col1;
			delete old_col1;	
			
			char *col2=new char[heights[place+1]+1];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='I';
			data[place+1]=col2;
			delete old_col2;
			
			char *col3=new char[heights[place+2]+1];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='I';
			data[place+2]=col3;
			delete old_col3;	
				
			char *col4=new char[heights[place+3]+1];
			char *old_col4=data[place+3];
			for(int i=0;i<heights[place+3];i++){
				col4[i]=old_col4[i];
			}
			col4[heights[place+3]]='I';
			data[place+3]=col4;
			delete old_col4;
			
			
			heights[place]+=1;
			heights[place+1]+=1;
			heights[place+2]+=1;
			heights[place+3]+=1;
			
			int maxh=0;
			for(int i=0;i<4;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place]-1;i<maxh-1;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh-1]='I';
				data[place]=newcol1;
				delete col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1]-1;i<maxh-1;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh-1]='I';
				data[place+1]=newcol2;
				delete col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2]-1;i<maxh-1;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh-1]='I';
				data[place+2]=newcol3;
				delete col3;
				heights[place+2]=maxh;
			}
			
			if(heights[place+3]!=maxh){
				char *newcol4=new char[maxh];
				for(int i=0;i<heights[place+3];i++){
					newcol4[i]=col4[i];
				}
				for(int i=heights[place+3]-1;i<maxh-1;i++){
					newcol4[i]=' ';
				}
				newcol4[maxh-1]='I';
				data[place+3]=newcol4;
				delete col4;
				heights[place+3]=maxh;
			}
			
		}
		
		else if(rot==0||rot==180){
			char *col1=new char[heights[place]+4];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			for(int i=0;i<4;i++){
				col1[i+heights[place]]='I';
			}
			data[place]=col1;
			delete old_col1;	
			
			heights[place]+=4;
			
		}
		
		
	}
}

int Tetris::get_max_height() const {
	int mh=0;
	for(int i=0;i<width;i++){
		if(heights[i]>mh){
			mh=heights[i];
		}
	}
	
	return mh;
}

int Tetris::count_squares() const {
	int cnt=0;
	for(int i=0;i<width;i++){
		for(int j=0;j<heights[i];j++){
			if(data[i][j]!=' '){
				cnt+=1;
			}
		}
	}
	
	return cnt;
}

int Tetris::remove_full_rows() const{
	int check=0;

	int maxh=0;
	for(int i=0;i<width;i++){
		if(heights[i]>maxh){
			maxh=heights[i];
		}
	}	
	
	int minh=maxh;
	for(int i=0;i<width;i++){
		if(heights[i]<minh){
			minh=heights[i];
		}
	}	
	
	vector<int> needdel;
	for(int i=0;i<minh;i++){
		for(int j=0;j<width;j++){
			if(data[j][i]!=' '){
				check+=1;
			}
		}
		
		if(check==6){
			needdel.push_back(i);
		}
		
		check=0;
	}
	
	for(int i=0;i<int(needdel.size());i++){
		for(int j=0;j<width;j++){
			char *newcol=new char[heights[j]-1];
			char *oldcol=data[j];
			for(int k=0;k<needdel[i];k++){
				newcol[k]=oldcol[k];
			}
			for(int l=needdel[i];l<heights[j]-1;l++){
				newcol[l]=oldcol[l+1];
			}
			data[j]=newcol;
			delete oldcol;
			delete newcol;
			heights[j]-=1;
		}
	}
	

	return needdel.size();
}

void Tetris::destroy(){
	for(int i=0;i<width;i++){
		delete [] data[i];
	}
	delete data;
}