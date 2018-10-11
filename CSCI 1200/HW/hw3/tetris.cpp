#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"tetris.h"
using namespace std;

Tetris::Tetris(int w){ //constructor for future use
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
		char *col1=new char[heights[place]+2]; //make a new column
		char *old_col1=data[place];
		for(int i=0;i<heights[place];i++){
			col1[i]=old_col1[i]; //copy the old information to new column
		}
		for(int i=0;i<2;i++){
			col1[i+heights[place]]='O';
		}
		data[place]=col1;
		delete [] old_col1;
		
		char *col2=new char[heights[place+1]+2];
		char *old_col2=data[place+1];
		for(int i=0;i<heights[place+1];i++){
			col2[i]=old_col2[i];
		}
		for(int i=0;i<2;i++){
			col2[i+heights[place+1]]='O';
		}
		data[place+1]=col2;
		delete [] old_col2;
		
		int maxh=0; //find the maximum height
		for(int i=0;i<2;i++){
			if(heights[place+i]>maxh){
				maxh=heights[place+i];
			}
		}
		
		if(heights[place]!=maxh){ //update the information if it is required
			char *newcol1=new char[maxh+2];
			for(int i=0;i<heights[place];i++){
				newcol1[i]=col1[i];
			}
			for(int i=heights[place];i<maxh;i++){
				newcol1[i]=' ';
			}
			newcol1[maxh]='O';
			newcol1[maxh+1]='O';
			data[place]=newcol1;
			delete [] col1;
			heights[place]=maxh;
		}
		
		if(heights[place+1]!=maxh){
			char *newcol2=new char[maxh+2];
			for(int i=0;i<heights[place+1];i++){
				newcol2[i]=col2[i];
			}
			for(int i=heights[place+1];i<maxh;i++){
				newcol2[i]=' ';
			}
			newcol2[maxh]='O';
			newcol2[maxh+1]='O';
			data[place+1]=newcol2;
			delete [] col2;
			heights[place+1]=maxh;
		}
			
		heights[place]+=2;
		heights[place+1]+=2;		
		
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
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+1];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='I';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+1];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='I';
			data[place+2]=col3;
			delete [] old_col3;	
				
			char *col4=new char[heights[place+3]+1];
			char *old_col4=data[place+3];
			for(int i=0;i<heights[place+3];i++){
				col4[i]=old_col4[i];
			}
			col4[heights[place+3]]='I';
			data[place+3]=col4;
			delete [] old_col4;
						
			int maxh=0;
			for(int i=0;i<4;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='I';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+1];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='I';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+1];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='I';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			if(heights[place+3]!=maxh){
				char *newcol4=new char[maxh+1];
				for(int i=0;i<heights[place+3];i++){
					newcol4[i]=col4[i];
				}
				for(int i=heights[place+3];i<maxh;i++){
					newcol4[i]=' ';
				}
				newcol4[maxh]='I';
				data[place+3]=newcol4;
				delete [] col4;
				heights[place+3]=maxh;
			}
			
			heights[place]+=1;
			heights[place+1]+=1;
			heights[place+2]+=1;
			heights[place+3]+=1;			
			
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
			delete [] old_col1;	
			
			heights[place]+=4;
			
		}
		
	}
	
	if(mino=='T'){
		if(rot==180){
			char *col1=new char[heights[place]+1];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='T';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='T';
			col2[heights[place+1]+1]='T';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+1];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='T';
			data[place+2]=col3;
			delete [] old_col3;	
						
			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='T';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='T';
				newcol2[maxh+1]='T';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+1];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='T';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=1;
			heights[place+1]+=2;
			heights[place+2]+=1;
			
		}
		
		if(rot==270){
			char *col1=new char[heights[place]+3];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='T';
			col1[heights[place]+1]='T';
			col1[heights[place]+2]='T';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]=' ';
			col2[heights[place+1]+1]='T';
			data[place+1]=col2;
			delete [] old_col2;	
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}			
			
			if(heights[place]==maxh){			
				if(heights[place+1]!=maxh){
					char *newcol2=new char[maxh+2];
					for(int i=0;i<heights[place+1];i++){
						newcol2[i]=col2[i];
					}
					for(int i=heights[place+1];i<maxh;i++){
						newcol2[i]=' ';
					}
					newcol2[maxh]=' ';
					newcol2[maxh+1]='T';
					data[place+1]=newcol2;
					delete [] col2;
					heights[place+1]=maxh;
				}
			
				heights[place]+=3;
				heights[place+1]+=2;
			}
			
			if(heights[place+1]==maxh && heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh-1;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh-1]='T';
				newcol1[maxh]='T';
				newcol1[maxh+1]='T';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			
				heights[place]+=2;
				heights[place+1]+=1;
			}
		}
			
		if(rot==0){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]='T';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='T';
			col2[heights[place+1]+1]='T';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+2];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]=' ';
			col3[heights[place+2]+1]='T';
			data[place+2]=col3;
			delete [] old_col3;	
			
			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]='T';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='T';
				newcol2[maxh+1]='T';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+2];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]=' ';
				newcol3[maxh+1]='T';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=2;
			heights[place+2]+=2;			
			
		}
			
		if(rot==90){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]='T';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+3];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='T';
			col2[heights[place+1]+1]='T';
			col2[heights[place+1]+2]='T';
			data[place+1]=col2;
			delete [] old_col2;
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]='T';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+3];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='T';
				newcol2[maxh+1]='T';
				newcol2[maxh+2]='T';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=3;			
			
		}
		
	}
	
	if(mino=='S'){
		if(rot==0||rot==180){
			char *col1=new char[heights[place]+1];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='S';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='S';
			col2[heights[place+1]+1]='S';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+2];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]=' ';
			col1[heights[place+2]+1]='S';
			data[place+2]=col3;
			delete [] old_col3;	
			
			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='S';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='S';
				newcol2[maxh+1]='S';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+2];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]=' ';
				newcol3[maxh+1]='S';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=1;
			heights[place+1]+=2;
			heights[place+2]+=2;			
			
		}
		
		if(rot==90||rot==270){
			char *col1=new char[heights[place]+3];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]='S';
			col1[heights[place]+2]='S';
			data[place]=col1;
			delete [] old_col1;
		
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='S';
			col2[heights[place+1]+1]='S';
			data[place+1]=col2;
			delete [] old_col2;
		
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
		
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+3];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]='S';
				newcol1[maxh+2]='S';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
		
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='S';
				newcol2[maxh+1]='S';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=3;
			heights[place+1]+=2;
			
		}
	}
	
	if(mino=='Z'){
		if(rot==0||rot==180){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]='Z';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='Z';
			col2[heights[place+1]+1]='Z';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+1];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='Z';
			data[place+2]=col3;
			delete [] old_col3;	
			
			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]='Z';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='Z';
				newcol2[maxh+1]='Z';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+1];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='Z';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=2;
			heights[place+2]+=1;
		}
		
		if(rot==90||rot==270){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='Z';
			col1[heights[place]+1]='Z';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+3];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]=' ';
			col2[heights[place+1]+1]='Z';
			col2[heights[place+1]+2]='Z';
			data[place+1]=col2;
			delete [] old_col2;	
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}			
			
			if(heights[place]==maxh){			
				if(heights[place+1]!=maxh){
					char *newcol2=new char[maxh+3];
					for(int i=0;i<heights[place+1];i++){
						newcol2[i]=col2[i];
					}
					for(int i=heights[place+1];i<maxh;i++){
						newcol2[i]=' ';
					}
					newcol2[maxh]=' ';
					newcol2[maxh+1]='Z';
					newcol2[maxh+2]='Z';
					data[place+1]=newcol2;
					delete [] col2;
					heights[place+1]=maxh;
				}
			
				heights[place]+=2;
				heights[place+1]+=3;
			}
			
			if(heights[place+1]==maxh && heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh-1;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh-1]='Z';
				newcol1[maxh]='Z';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
				
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				newcol2[maxh]='Z';
				newcol2[maxh+1]='Z';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
				
				
				heights[place]+=1;
				heights[place+1]+=2;
			}
			
		}
		
	}
	
	if(mino=='L'){
		if(rot==0){
			char *col1=new char[heights[place]+3];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='L';
			col1[heights[place]+1]='L';
			col1[heights[place]+2]='L';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+1];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='L';
			data[place+1]=col2;
			delete [] old_col2;
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+3];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='L';
				newcol1[maxh+1]='L';
				newcol1[maxh+2]='L';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+1];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='L';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=3;
			heights[place+1]+=1;
			
		}
		
		if(rot==90){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='L';
			col1[heights[place]+1]='L';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]=' ';
			col2[heights[place+1]]='L';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+2];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]=' ';
			col3[heights[place+2]]='L';
			data[place+2]=col3;
			delete [] old_col3;	

			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='L';
				newcol1[maxh+1]='L';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]=' ';
				newcol2[maxh+1]='L';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+2];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]=' ';
				newcol3[maxh+1]='L';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=2;
			heights[place+2]+=2;
		}
		
		if(rot==180){
			char *col1=new char[heights[place]+3];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]=' ';
			col1[heights[place]+2]='L';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+3];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='L';
			col2[heights[place+1]+1]='L';
			col2[heights[place+1]+2]='L';
			data[place+1]=col2;
			delete [] old_col2;
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+3];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]=' ';
				newcol1[maxh+2]='L';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+3];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='L';
				newcol2[maxh+1]='L';
				newcol2[maxh+2]='L';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=3;
			heights[place+1]+=3;
			
		}
		
		if(rot==270){
			char *col1=new char[heights[place]+1];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='L';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+1];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='L';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+2];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='L';
			col3[heights[place+2]]='L';
			data[place+2]=col3;
			delete [] old_col3;	

			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='L';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+1];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='L';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+2];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='L';
				newcol3[maxh+1]='L';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=1;
			heights[place+1]+=1;
			heights[place+2]+=2;
		}
	}
	
	if(mino=='J'){
		if(rot==0){
			char *col1=new char[heights[place]+1];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='J';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+3];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='J';
			col2[heights[place+1]+1]='J';
			col2[heights[place+1]+2]='J';
			data[place+1]=col2;
			delete [] old_col2;
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+1];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='J';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+3];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='J';
				newcol2[maxh+1]='J';
				newcol2[maxh+2]='J';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=1;
			heights[place+1]+=3;
			
		}
		
		if(rot==90){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='J';
			col1[heights[place]+1]='J';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+1];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]='J';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+1];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='J';
			data[place+2]=col3;
			delete [] old_col3;	

			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='J';
				newcol1[maxh+1]='J';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+1];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]='J';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+1];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='J';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=1;
			heights[place+2]+=1;
		}
		
		if(rot==180){
			char *col1=new char[heights[place]+3];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]='J';
			col1[heights[place]+1]='J';
			col1[heights[place]+2]='J';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+3];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]=' ';
			col2[heights[place+1]+1]=' ';
			col2[heights[place+1]+2]='J';
			data[place+1]=col2;
			delete [] old_col2;
						
			int maxh=0;
			for(int i=0;i<2;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+3];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]='J';
				newcol1[maxh+1]='J';
				newcol1[maxh+2]='J';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+3];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]=' ';
				newcol2[maxh+1]=' ';
				newcol2[maxh+2]='J';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			heights[place]+=3;
			heights[place+1]+=3;
			
		}
		
		if(rot==270){
			char *col1=new char[heights[place]+2];
			char *old_col1=data[place];
			for(int i=0;i<heights[place];i++){
				col1[i]=old_col1[i];
			}
			col1[heights[place]]=' ';
			col1[heights[place]+1]='J';
			data[place]=col1;
			delete [] old_col1;	
			
			char *col2=new char[heights[place+1]+2];
			char *old_col2=data[place+1];
			for(int i=0;i<heights[place+1];i++){
				col2[i]=old_col2[i];
			}
			col2[heights[place+1]]=' ';
			col2[heights[place+1]+1]='J';
			data[place+1]=col2;
			delete [] old_col2;
			
			char *col3=new char[heights[place+2]+2];
			char *old_col3=data[place+2];
			for(int i=0;i<heights[place+2];i++){
				col3[i]=old_col3[i];
			}
			col3[heights[place+2]]='J';
			col3[heights[place+2]+1]='J';
			data[place+2]=col3;
			delete [] old_col3;	

			int maxh=0;
			for(int i=0;i<3;i++){
				if(heights[place+i]>maxh){
					maxh=heights[place+i];
				}
			}
			
			if(heights[place]!=maxh){
				char *newcol1=new char[maxh+2];
				for(int i=0;i<heights[place];i++){
					newcol1[i]=col1[i];
				}
				for(int i=heights[place];i<maxh;i++){
					newcol1[i]=' ';
				}
				newcol1[maxh]=' ';
				newcol1[maxh+1]='J';
				data[place]=newcol1;
				delete [] col1;
				heights[place]=maxh;
			}
			
			if(heights[place+1]!=maxh){
				char *newcol2=new char[maxh+2];
				for(int i=0;i<heights[place+1];i++){
					newcol2[i]=col2[i];
				}
				for(int i=heights[place+1];i<maxh;i++){
					newcol2[i]=' ';
				}
				newcol2[maxh]=' ';
				newcol2[maxh+1]='J';
				data[place+1]=newcol2;
				delete [] col2;
				heights[place+1]=maxh;
			}
			
			if(heights[place+2]!=maxh){
				char *newcol3=new char[maxh+2];
				for(int i=0;i<heights[place+2];i++){
					newcol3[i]=col3[i];
				}
				for(int i=heights[place+2];i<maxh;i++){
					newcol3[i]=' ';
				}
				newcol3[maxh]='J';
				newcol3[maxh+1]='J';
				data[place+2]=newcol3;
				delete [] col3;
				heights[place+2]=maxh;
			}
			
			heights[place]+=2;
			heights[place+1]+=2;
			heights[place+2]+=2;
		}
	}
	
}

int Tetris::get_max_height() const { //use for loop to search the maximum height
	int mh=0;
	for(int i=0;i<width;i++){
		if(heights[i]>mh){
			mh=heights[i];
		}
	}
	
	return mh;
}

int Tetris::count_squares() const { //use nest loop to count the all charactors
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
		
		if(check==width){
			needdel.push_back(i);
		}
		
		check=0;
	}
	
	for(int i=0;i<int(needdel.size());i++){
		for(int j=0;j<width;j++){
			char *newcol=new char[heights[j]-1];
			char *oldcol=data[j];
			for(int k=0;k<needdel[i];k++){ //copy old column data to new column (below full row)
				newcol[k]=oldcol[k];
			}
			for(int l=needdel[i];l<heights[j]-1;l++){ //
				newcol[l]=oldcol[l+1];
			}
			data[j]=newcol;
			delete [] oldcol; //cannot delete newcol because I just assigned it to data column
			heights[j]-=1;
			}
			
		for(int m=0;m<int(needdel.size());m++){
				needdel[m]-=1;			
		}
	}
	
	for(int i=0;i<width;i++){
		for(int j=0;j<heights[i];j++){
			if(data[i][j]==' '){
				check+=1;
			}
		}
		if(check==heights[i]){
			heights[i]=0;
		}
		
		check=0;
	}
	
	
	return needdel.size();
}

void Tetris::destroy(){ //delete all dynamic arraies that I created
	for(int i=0;i<width;i++){
		delete [] data[i];
	}
	delete [] data;
	delete [] heights;
}

void Tetris::add_left_column(){
	int *heights_temp=new int[width+1]; //create copies of constructor's data
	char **data_temp=new char*[width+1];
	heights_temp[0]=0;
	data_temp[0]=NULL;
	
	for (int i=0;i<width;i++) {
		data_temp[i+1]=data[i];
		heights_temp[i+1]=heights[i];
	}
	
	width+=1;
	delete [] data; //memory leak here????
	delete [] heights;
	
	data=data_temp;
	heights=heights_temp;
}

void Tetris::add_right_column(){
	int *heights_temp=new int[width+1];
	char **data_temp=new char*[width+1];
	heights_temp[width]=0;
	data_temp[width]=NULL;
	
	for (int i=0;i<width;i++) {
		data_temp[i]=data[i];
		heights_temp[i]=heights[i];
	}
	
	width+=1;
	delete [] data;
	delete [] heights;
	
	data=data_temp;
	heights=heights_temp;
}

void Tetris::remove_left_column(){
	int *heights_temp=new int[width-1];
	char **data_temp=new char*[width-1];
	
	for (int i=0;i<width-1;i++) {
		data_temp[i]=data[i+1];
		heights_temp[i]=heights[i+1];
	}
	
	width-=1;
	delete [] data;
	delete [] heights;
	
	data=data_temp;
	heights=heights_temp;
}

void Tetris::remove_right_column(){
	int *heights_temp=new int[width-1];
	char **data_temp=new char*[width-1];
	
	for (int i=0;i<width-1;i++) {
		data_temp[i]=data[i];
		heights_temp[i]=heights[i];
	}
	
	width-=1;
	delete [] data;
	delete [] heights;
	
	data=data_temp;
	heights=heights_temp;
}