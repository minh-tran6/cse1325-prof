#include <iostream>
#include <exception>

enum class Month {Jan, Feb, Mar, Apr, May, Jun,
                  Jul, Aug, Sep, Oct, Nov, Dec};

std::string to_string(Month m) {
    switch(m) {
        case Month::Jan: return "January"; break;
        case Month::Feb: return "February"; break;
        case Month::Mar: return "March"; break;
        case Month::Apr: return "April"; break;
        case Month::May: return "May"; break;
        case Month::Jun: return "June"; break;
        case Month::Jul: return "July"; break;
        case Month::Aug: return "August"; break;
        case Month::Sep: return "September"; break;
        case Month::Oct: return "October"; break;
        case Month::Nov: return "November"; break;
        case Month::Dec: return "December"; break;
        default: throw std::runtime_error{"Invalid month"};
    }
}

class Date {
  public:
    void print_date() {
        // This no longer works - month is no longer an int!
        // std::cout << month << '/' << day << '/' << year << std::endl;
       std::cout << _day << ' ' << to_string(_month) << ", " << _year << std::endl;
    }
  private:
    int _year;
    Month _month;
    int _day;
};

int main() {
    // Date birthday{1950, 12, 30};  // ERROR: 12 isn't a Month!
    Date birthday;  // WARNING: No Constructor!
    birthday.print_date();
}
