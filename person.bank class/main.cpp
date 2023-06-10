#include <iostream>
#include <string>
class person {
    std::string name = "", surename = "", id_number = "";
    int age0 = 21, income0 = 1, closed_loans0 = 0;
    double trust_indicator = 20.0;
public:
    person(std::string name, std::string surename, std::string id_number, int age, int income, int closed_loans)
    {
        trust_indicator = trust_indicator * 2000 + income;
        if (closed_loans > 10 && age >= 30) trust_indicator += 20.0;
        trust_indicator /= 2000;
        if (income > 0)income0 = income;
        else std::cerr << "wrong income value";
        if (age > 21) age0 = age;
        else { std::cerr << "underaged" << std::endl; trust_indicator = 0; }
        closed_loans0 = closed_loans;
    }
    bool credit(int size)
    {
        if ((size / income0) < trust_indicator) return true;
        return false;
    }
};

int main() {
    person K1("Kevin", "Heart", "123456", 4, 67000, 32);
    std::cout << K1.credit(67000);
    return 0;
}