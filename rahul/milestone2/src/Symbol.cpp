#include "Symbol.h"

Symbol::Symbol(string symName, string Type, int Width = 0, string BaseType = "simple", int Offset = 0,string Token="Identifier", vector<int> Line = {})
{
	string newName="_"+symName;
	name = newName;
	type = Type;
	isKeyword = false;
	width  = Width; 
	offset = Offset;
	baseType = BaseType;
	token = Token;
	line = Line;
}