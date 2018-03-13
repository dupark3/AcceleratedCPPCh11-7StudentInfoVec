#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

class Student_info {
public:
    // interface
    Student_info();
    Student_info(std::istream&);
    bool valid() const;
    void grade();
    std::istream& read(std::istream&);
    std::string name() const { return n; };
    double showFinalGrade() const { return finalGrade; };

private:
    // implementation
    std::string n;
    double midterm;
    double final;
    double finalGrade;
    std::vector<double> homework;


};

std::istream& read_hw(std::istream&, std::vector<double>&);
double average(const std::vector<double>&);
bool compare(const Student_info& x, const Student_info& y);
#endif // GUARD_Student_info_h


