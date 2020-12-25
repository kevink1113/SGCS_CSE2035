#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __SUBJECT__ {
    char number[8];
    int credit;
    double grade;
} subject;

typedef struct __STUDENT__ {
    int id;
    int number_of_course;
    subject *courses;
} student;

double calcCGPA(student s);

int main() {
    int nofst;
    scanf("%d", &nofst);
    student *stu=(student*)malloc(sizeof(student)*nofst);
    
    for(int i=0; i<nofst; i++){
        scanf("%d%d", &(stu[i].id), &(stu[i].number_of_course));
        stu[i].courses=(subject*)malloc(sizeof(subject)*stu[i].number_of_course);//빼먹지 않게 주의!!!
        
        for(int j=0; j<stu[i].number_of_course; j++){
            scanf("%s%d%lf", &(stu[i].courses[j].number), &(stu[i].courses[j].credit), &(stu[i].courses[j].grade));
        }
    }

    double res;
    printf("=============\n");
    for(int i=0; i<nofst; i++){
        res=calcCGPA(stu[i]);
        printf("%d / %lf\n", stu[i].id, res);
    }
    
    free(stu);
    
    return 0;
}


double calcCGPA(student s){
    int allhac=0;
    double all=0;
    for(int i=0; i<s.number_of_course; i++){
        allhac += s.courses[i].credit;
        all += s.courses[i].credit*s.courses[i].grade;
    }
    return all/allhac;
}

