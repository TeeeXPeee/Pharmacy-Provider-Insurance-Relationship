#include <string>
#include <chrono>
#include <ctime>
#include "patient.h"
#include "prescription.h"

Prescription::Prescription(Patient& patient, std::string drug, std::string qty, std::string sig)
    : m_patient{ &patient }
    , m_drug{ drug }
    , m_qty{ qty }
    , m_sig{ sig }
    , m_date{ getTimeStr() }
{
};

std::string Prescription::getTimeStr(){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return s;
}