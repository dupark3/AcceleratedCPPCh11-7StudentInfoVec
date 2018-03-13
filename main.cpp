#include <algorithm> // max, sort
#include <iomanip> // streamsize, setprecision
#include <iostream>
#include <string>

#include "Student_info.h"

int main()
{
    Vec<Student_info> students;
    Student_info record;
    std::string::size_type maxLen = 0;

    // read using member function read and store the data as class objects into vector students
    while(record.read(std::cin)) {
        maxLen = std::max(maxLen, record.name().size());
        if (record.valid()){
            record.grade();
            students.push_back(record);
        }
    }

    // alphabetize students by name
    std::sort(students.begin(), students.end(), compare);

    // write the names and grades of students
    for (Vec<Student_info>::size_type i = 0; i != students.size(); ++i){
        std::streamsize prec = std::cout.precision();
        std::cout << students[i].name() << std::string(maxLen + 1 - students[i].name().size(), ' ')
                  << std::setprecision(3) << students[i].showFinalGrade()
                  << std::setprecision(prec) << std::endl;
    }

    return 0;
}
