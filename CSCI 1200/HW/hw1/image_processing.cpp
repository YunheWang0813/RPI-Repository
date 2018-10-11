#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
using namespace std;

string repl(string str,char ch1,char ch2){ //the function of replacing a character
  for(int i=0;i<int(str.length());i++){
    if(str[i]==ch1){
      str[i]=ch2;}
    }
  return str;
}
    
int main(int argc,char *argv[]){
    ifstream ifs(argv[1]); //introduce the input.txt file
	
    string s;
    vector<string> imagev;
    while (ifs>>s){ 
    imagev.push_back(s);} //store the information of the input.txt file
	
	int xmax=int(imagev.size());
	int ymax=int(imagev[0].length());
	
	ofstream ofs(argv[2]); //create an out.txt file when call ofs()
	
    if(string(argv[3])==string("replace")){
        for(int i=0;i<xmax;i++){  //simply use the repl function to work
            s=repl(imagev[i],argv[4][0],argv[5][0]);
            ofs<<s<<endl;}
    }

               
    if(string(argv[3])==string("dilation")){ //find all characters that need to be dilated, and change each of them to ' ' to prevent loop of 'X'
        for(int i=0;i<xmax;i++){
            for(int j=0;j<ymax;j++){
                if(i!=xmax-1){
                    if(imagev[i+1][j]=='X'&&
                       imagev[i][j]=='.'){
                        imagev[i][j]=' ';}
                    }
                    
                if(i!=0){
                    if(imagev[i-1][j]=='X'&&
                       imagev[i][j]=='.'){
                        imagev[i][j]=' ';}
                    }   
            }
        }
        
        for(int i=0;i<xmax;i++){
            for(int j=0;j<ymax;j++){
                if(imagev[i][j+1]=='X'||
                   imagev[i][j-1]=='X'){
                        imagev[i][j]=' ';}
                    }
                }
                
        for(int i=0;i<xmax;i++){ //finally, replace ' ' to the specific character
            s=repl(imagev[i],' ',argv[4][0]);
            ofs<<s<<endl;}
              
    }
    
    if(string(argv[3])==string("erosion")){ //similar as dilation, but this time, I store the x coordinate of each character that need not to be eroded to x vector,
	                                        //and y coordinate of that to y vector.
        vector<int> xline;
        vector<int> yline;
        for(int i=1;i<xmax-1;i++){
            for(int j=1;j<ymax-1;j++){
                if(imagev[i+1][j]==argv[4][0]&&
                   imagev[i-1][j]==argv[4][0]&&
                   imagev[i][j-1]==argv[4][0]&&
                   imagev[i][j+1]==argv[4][0]){
                        xline.push_back(i);
                        yline.push_back(j);}
                    }
                }
                        
        for(int i=0;i<int(xline.size());i++){
            imagev[xline[i]][yline[i]]=' ';}
        
        vector<string> vnew; //erode the characters
        for(int i=0;i<xmax;i++){
            s=repl(imagev[i],argv[4][0],argv[5][0]);
            vnew.push_back(s);}
            
        for(int i=0;i<int(vnew.size());i++){ //recover the characters from ' ' to original.
            s=repl(vnew[i],' ',argv[4][0]);
            ofs<<s<<endl;}
                        
    }
    
	if(string(argv[3])==string("floodfill")){ //I use the if statement to continuously judge if the cordinate can be floodfilled, 
											  //and every time push_back the new coordinates to the x or y vector, meanwhile change the judged character to ' ', 
											  //until all of the coordinates inside the x or y vector is judged.
		vector<int> xline;
		vector<int> yline;
		const char inic=imagev[atoi(argv[4])][atoi(argv[5])];
		int x=atoi(argv[4]);
		int y=atoi(argv[5]);
		xline.push_back(x);
		yline.push_back(y);
		
		for(int i=0;i<int(xline.size());i++){
				imagev[xline[i]][yline[i]]=' ';
				
				if(xline[i]+1<xmax){
				if(imagev[xline[i]+1][yline[i]]==inic){
					xline.push_back(xline[i]+1);
					yline.push_back(yline[i]);
				}
				}
				
				if(xline[i]>=1){
				if(imagev[xline[i]-1][yline[i]]==inic){
					xline.push_back(xline[i]-1);
					yline.push_back(yline[i]);
				}
				}
				
				if(yline[i]+1<ymax){
				if(imagev[xline[i]][yline[i]+1]==inic){
					xline.push_back(xline[i]);
					yline.push_back(yline[i]+1);
				}
				}
				
				if(yline[i]>=1){
				if(imagev[xline[i]][yline[i]-1]==inic){
					xline.push_back(xline[i]);
					yline.push_back(yline[i]-1);
				}
				}
			}
			
        for(int i=0;i<xmax;i++){  //finally change all ' ' to the required character
            s=repl(imagev[i],' ',argv[6][0]);
            ofs<<s<<endl;}
			
	}
	
    return 0;
    
}

