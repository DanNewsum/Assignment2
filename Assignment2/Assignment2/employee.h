#pragma once

#include<iostream>

// Abstract class
class Employee {
public:
    virtual float calculateWeeklySalary() = 0; 
    virtual float calculateHealthcareContributions() = 0; 
    virtual float calculateVacationDays() = 0; 
};
//class
class Professional : public Employee {
private:
    float monthlySalary;
    int vacationDays;
public:
    Professional(float salary);
    float calculateWeeklySalary() override;
    float calculateHealthcareContributions() override;
    float calculateVacationDays() override;
};

//class
class NonProfessional : public Employee {

private:
    float hourlyRate;
    int hoursWorked;

public:
    NonProfessional(float rate, int hours);
    float calculateWeeklySalary() override;
    float calculateHealthcareContributions() override;
    float calculateVacationDays() override;
};
