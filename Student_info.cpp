
#include <iostream>
#include <numeric> // accumulate
#include <stdexcept> // domain_error
#include <string>
#include <vector>

#include "Student_info.h"

// constructors
Student_info::Student_info() : midterm(0), final(0) { }; // default, no arguments
Student_info::Student_info(std::istream& is) { read(is); }; // with arguments



// member function "read"
std::istream& Student_info::read(std::istream& in){
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

// non-member function "read_hw" stores doubles in a vector container from istream
std::istream& read_hw(std::istream& is, std::vector<double>& homework){
    if (is){
        homework.clear();
        double x;
        while(is >> x)
            homework.push_back(x);
    is.clear();
    }
    return is;
}




// member function "grade" calls on nonmember function "average"
void Student_info::grade(){
    // implemented grade within this member function instead of calling an entire non-member function "grade"
    finalGrade = ((midterm * 0.2) + (final * 0.4) + (::average(homework) * 0.4));
}

// non-member function "average"
double average(const std::vector<double>& vec){
    return accumulate(vec.begin(), vec.end(), 0) / vec.size();
}


bool compare(const Student_info& x, const Student_info& y){
    return x.name() < y.name();
}

bool Student_info::valid() const{
    return homework.size() != 0;
}
