//
// Created by Raluca on 12.04.2022.
//

#ifndef LABORATORY8_RUSURALUCA_DATE_H
#define LABORATORY8_RUSURALUCA_DATE_H

#include <iostream>


class Date{
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;

public:
    Date();
    Date(unsigned int, unsigned int, unsigned int);

    std::string date_to_string() const;

    friend std::istream &operator>>(std::istream&, Date&);
    friend std::ostream &operator<<(std::ostream&, const Date&);
};

#endif //LABORATORY8_RUSURALUCA_DATE_H