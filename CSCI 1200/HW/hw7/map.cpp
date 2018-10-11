#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;

int main(){	
	string info;
	cin>>info>>info;		//now info is the genome txt file		
	ifstream istr2(info.c_str());		//introduce genome txt file
	cin>>info>>info;	//get k-mer
	int kmer=atoi(info.c_str());
	
	vector<int> mismatch;
	vector<string> recgenome;
	
	while(cin>>info&&info!="quit"){
		if(info=="query"){
			continue;
		}
		int temp=atoi(info.c_str());
		if(temp==0&&info[0]!='0'){		//atoi() return 0 if it is not a number, and make sure number '0' case
			recgenome.push_back(info);
		}
		else{
			mismatch.push_back(temp);
		}
	}

	string allgenome;	
	while(istr2>>info){			//make a tremendouly long string that store the whole info of the genome txt file
		allgenome+=info;
	}
	
	map<string,vector<int> > genomeindex;
	int maxlen=allgenome.size();
	for(int i=0;i<maxlen-kmer+1;i++){
		vector<int> locgenome;
		string partgenome=allgenome.substr(i,kmer);
		map<string,vector<int> >::iterator it=genomeindex.find(partgenome);		//use Map Find method which covered in the lecture
		if(it!=genomeindex.end()){		//fail to find will return m.end()
			it->second.push_back(i);		//directly chenge the contents of the map
		}
		else{
			locgenome.push_back(i);
			genomeindex[partgenome]=locgenome;		//add new contents to the map
		}
	}

	for(int i=0;i<int(recgenome.size());i++){		//start outputing
		cout<<"Query: "<<recgenome[i]<<endl;
		string temp=recgenome[i].substr(0,kmer);
		map<string,vector<int> >::iterator it=genomeindex.find(temp);
		if(it==genomeindex.end()){		//use find method to find required genome (match first kmer sequence)
			cout<<"No Match"<<endl;
		}
		else{
			bool atleastone=false;
			for(int j=0;j<int(it->second.size());j++){		//loop over the vector inside the map, and find if there are genomes that match the requirement
				int miss=0;
				bool judge=true;
				int num=it->second[j];
				for(int k=kmer;k<int(recgenome[i].size());k++){
					if(recgenome[i][k]!=allgenome[num+k]){		//check if the mismatches of the sequence is less than the requirement.
						miss++;
					}
				}
				if(miss>mismatch[i]){
					judge=false;
				}
				if(judge){
					cout<<num<<" "<<miss<<" "<<allgenome.substr(num,int(recgenome[i].size()))<<endl;
					atleastone=true;
				}
			}
			if(!atleastone){		//if there is no sequence match the requirement, output this
				cout<<"No Match"<<endl;
			}
		}
	}
	
	return 0;
}