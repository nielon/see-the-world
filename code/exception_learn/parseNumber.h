
class NumberParseException 
{
  //NumberParseException(NumberParseException& e) = delete;
};

class Overflow : public NumberParseException
{

};

int parseNumber(char * str) throw(NumberParseException);
