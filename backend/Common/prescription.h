#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include "patient.h"

class Prescription {

private: 
Patient* m_patient;
std::string m_drug;
std::string m_qty;
std::string m_sig;
std::string m_date;


public:
Prescription(Patient& patient, std::string drug, std::string qty, std::string sig);

private:
std::string getTimeStr();

};
