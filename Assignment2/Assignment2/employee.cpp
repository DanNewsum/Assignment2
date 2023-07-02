#include "employee.h"

// Definitions for Professional
Professional::Professional(float salary) : monthlySalary(salary), vacationDays(0) {}

float Professional::calculateWeeklySalary() {
    return monthlySalary / 4;
}

float Professional::calculateHealthcareContributions() {
    return monthlySalary * 0.03;
}

float Professional::calculateVacationDays() {
    return ++vacationDays;
}

// Definitions for NonProfessional
NonProfessional::NonProfessional(float rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

float NonProfessional::calculateWeeklySalary() {
    return hourlyRate * hoursWorked;
}

float NonProfessional::calculateHealthcareContributions() {
    return calculateWeeklySalary() * 0.01;
}

float NonProfessional::calculateVacationDays() {
    return hoursWorked / 40.0;
}
