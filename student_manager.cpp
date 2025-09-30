#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name,last_student_id,midterm,final);
    num_of_students++;
}

void StudentManager::deleteStudent(int id) {
    /* TODO */
    int idx = findStudentByID(id);
    if (idx >= 0) {
        for(int i = idx+1; i < num_of_students; i++){
            students[i-1] = students[i];
        }
        num_of_students--;
    }
}

void StudentManager::modifyStudent(const Student& student) {
    /* TODO */
    int idx = findStudentByID(student.getID());
    if(idx >= 0){
        students[idx] = student;
    } 

}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    for (int i =0; i < num_of_students; i++) {
        if (students[i].getID() == id) return i;
    }   
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    if(num_of_students == 0) return -1;
    int best_midterm_id = 0;
    float max = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        if(max < students[i].getRecord().getMidterm()){
            max =  students[i].getRecord().getMidterm();
            best_midterm_id = students[i].getID();
        }
    }
    return best_midterm_id;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    if(num_of_students == 0) return -1;
    int best_final_id = 0;
    float max = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        if(max < students[i].getRecord().getFinal()){
            max =  students[i].getRecord().getFinal();
            best_final_id = students[i].getID();
        }
    }
    return best_final_id;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    if(num_of_students == 0) return -1;
    int best_student_id = 0;
    float max = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        if(max < (students[i].getRecord().getFinal() + students[i].getRecord().getMidterm())){
            max =  students[i].getRecord().getFinal() + students[i].getRecord().getMidterm();
            best_student_id = students[i].getID();
        }
    }
    return best_student_id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += (float) students[i].getRecord().getMidterm();
    }
    return sum/(float)num_of_students;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    float sum = 0.0f;
    for(int i = 0; i < num_of_students; i++){
        sum += (float) students[i].getRecord().getFinal();
    }
    return sum/(float)num_of_students;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    if(num_of_students == 0) return 0.0f;
    return (getFinalAverage() + getMidtermAverage());
}

