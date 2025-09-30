#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final): midterm(midterm), final(final)
/* TODO: Initializer list 사용해 초기화 해보기 */
{};

float StudentRecord::getTotal() const {
    /* TODO */
    return (this->midterm + this->final)/2.0f;
}

void StudentRecord::updateScores(float midterm, float final) {
    /* TODO: this keyword 사용해 보기 */
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student() : name(""), id(0), record(StudentRecord(0.0f,0.0f))
/* TODO: Initializer list 사용해 초기화 해보기 */
{};

Student::Student(const char *name, int id, float midterm, float final): name(name), id(id), record(StudentRecord(midterm,final))
/* TODO: Initializer list 사용해 초기화 해보기 */
{};

void Student::updateRecord(const char *name, float midterm, float final) {
    /* TODO */
    this->name = name;
    this->record = StudentRecord(midterm,final);
}

