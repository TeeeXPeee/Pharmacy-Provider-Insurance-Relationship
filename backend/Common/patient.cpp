#include <string>

class Patient
{

public:
std::string m_name;
std::string m_dob;
std::string m_address;

public:
Patient(std::string name, std::string dob, std::string m_address)
{
    this->m_name = name;
    this->m_dob = dob;
    this->m_address = m_address;
};

};