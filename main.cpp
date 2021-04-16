#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class nie_do_skrocenia{
ifstream in;
ofstream ex;
vector <string> obraz;
int l_podane_w_zadaniu, m_podane_w zaddaniu;


	
public:
nie_do_skrocenia();
~nie_do_skrocenia();
void load();
vector <int> rozklad(int);
void do_skrocenia(vector <int>, vector<int>);
};

nie_do_skrocenia::nie_do_skrocenia() {
in.open("dane_ulamki.txt");
ex.open("wyniki_ulamki.txt");
}

void nie_do_skrocenia::load() {
vector <int> czynniki_l;
vector <int> czynniki_m;

int sum_l=0;
				
				if(in.good()) {
					
					
					
					while(!in.eof()) {
						in>>l_podane_w_zadaniu;
						czynniki_l = rozklad(l_podane_w_zadaniu);
						in>>m_podane_w zaddaniu;
						czynniki_m = rozklad(m_podane_w zaddaniu);	
						this->do_skrocenia(czynniki_l, czynniki_m);
						sum_l += l_podane_w_zadaniu;
		}
		ex<<sum_l;
		cout<<sum_l;
}
}
	
vector <int> nie_do_skrocenia::rozklad(int liczba) {
vector <int> czynniki;


for (int i=2; i<=liczba; i++) {
	
	
	
	while (liczba%i == 0) {
	liczba/=i;
	czynniki.push_back(i);
	    	}
	 	}
	return czynniki;
}




void nie_do_skrocenia::do_skrocenia(vector <int> czynniki_l, vector <int> czynniki_m) {


	for (int i=0; i<czynniki_l.size(); i++) {



		for (int j=0; j<czynniki_m.size(); j++) {





if(czynniki_l[i]==czynniki_m[j] && czynniki_m[j]!=0) {
	l_podane_w_zadaniu/=czynniki_l[i];
	m_podane_w zaddaniu/=czynniki_m[j];
	czynniki_l[i]=0;
	czynniki_m[j]=0;
}
}
}
}



nie_do_skrocenia::~nie_do_skrocenia() {
	in.close();
	ex.close();
}




int main(int argc, char** argv) {
	nie_do_skrocenia x;
	x.load();
	
	return 0;
}
