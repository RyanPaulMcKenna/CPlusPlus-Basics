#define LINEOUT(str)cout << #str << endl // Macro function to output string.
#define GLUEOUT(a,b )cout << a##b << endl // Macro function to merge strings.

#include <string>
#include <iostream>
using namespace std;

int main()
{
	string buildingstrings = "They carried a net ";
	buildingstrings += "and their hearts were set";
	LINEOUT(In a bowl to sea went wise men three);
	LINEOUT(On a brilliant night in             june);
	GLUEOUT(building, strings);
	LINEOUT(On fishing up the moon.);
	
	
	
return 0;
}