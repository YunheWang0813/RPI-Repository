#include <fstream>
using namespace std;

int main()
{
	ofstream ofs( "test.txt" );
	ofs << "fstream" << 123 << endl;
	return 0;
}
