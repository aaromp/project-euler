/******************************************************************************
 * File: MegaInt.hh
 *
 * 
 */
#ifndef MegaInt_Included
#define MegaInt_Included

#include <string>
#include <cctype>

using namespace std;


/**
 * 
 */

class MegaInt {
public:
    // constructor
    MegaInt(string number = "");
    
    // overloaded + and += operators.  supports addition between strings and mega ints
    MegaInt& operator+ (const MegaInt& rhs);
    MegaInt& operator+ (const string& rhs);
    MegaInt& operator+= (const MegaInt& rhs);
    MegaInt& operator+= (const string& rhs);
    // ++ missing and doesn't support sign issues yet.
    
    
    // overloaded * and *= operators.  supports multiplication between strings and mega ints
    MegaInt& operator* (const MegaInt& rhs);
    MegaInt& operator* (const string& rhs);
    MegaInt& operator*= (const MegaInt& rhs);
    MegaInt& operator*= (const string& rhs);

    
    // need to overload << cout and >> cin operators
    string toString();
    
private:
    string number;
};

/* ------------------------------ implementation ------------------------------ */

bool isValid(string str) {
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i])) return false;
    
    return true;
}

string MegaInt::toString() {
    return number;
}

MegaInt::MegaInt(string number) {
    if (isValid(number)) this->number = number;
}


void recAdd(string &soFar, string longer, string shorter, int carry) {
    // base case: shorter is completely spent; append longer's remaining digits to the front of soFar
    if (shorter.length() == 0 && carry == 0) soFar = longer + soFar;
    
    // recursive case: add up the last digit and carry, add the final digit of the sum to soFar and recurse
    else {
        int sum = atoi(&longer[longer.length() - 1]) + atoi(&shorter[shorter.length() - 1]) + carry;
    
        soFar = (char) ('0' + sum % 10) + soFar;
        recAdd(soFar, longer.substr(0, longer.length() - 1), shorter.substr(0, shorter.length() - 1), sum / 10);
    }
}


string add(string lhs, string rhs) {
    string result = "";
    
    lhs.length() > rhs.length() ?
        recAdd(result, lhs, rhs, 0) : recAdd(result, rhs, lhs, 0);
    
    return result;
}


string multiply(string lhs, string rhs) {
    string result = "";
    
    lhs.length() > rhs.length() ?
    recAdd(result, lhs, rhs, 0) : recAdd(result, rhs, lhs, 0);
    
    return result;
}


MegaInt& MegaInt::operator+ (const string& rhs) {
    if(isValid(rhs)) this->number = add(this->number, rhs);
    
    return *this;
}
MegaInt& MegaInt::operator+ (const MegaInt& rhs) {
    this->number = add(this->number, rhs.number);

    return *this;
}
MegaInt& MegaInt::operator+= (const string& rhs) {
    if(isValid(rhs)) this->number = add(this->number, rhs);
    
    return *this;
}
MegaInt& MegaInt::operator+= (const MegaInt& rhs) {
    this->number = add(this->number, rhs.number);
    
    return *this;
}


MegaInt& MegaInt::operator* (const string& rhs) {
    if(isValid(rhs)) this->number = multiply(this->number, rhs);
    
    return *this;
}
MegaInt& MegaInt::operator* (const MegaInt& rhs) {
    this->number = multiply(this->number, rhs.number);
    
    return *this;
}
MegaInt& MegaInt::operator*= (const string& rhs) {
    if(isValid(rhs)) this->number = multiply(this->number, rhs);
    
    return *this;
}
MegaInt& MegaInt::operator*= (const MegaInt& rhs) {
    this->number = multiply(this->number, rhs.number);
    
    return *this;
}

//std::ostream& operator<<(std::ostream& os, const MegaInt& number)
//{
//    // write obj to stream
//    return os;
//}

//std::istream& operator>>(std::istream& is, T& obj)
//{
//    // read obj from stream
//    if( /* no valid object of T found in stream */ )
//        is.setstate(std::ios::failbit);
//    return is;
//}


#endif