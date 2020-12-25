#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int hours;
    int minutes;
    int seconds;
} Time;

int main (void){
    int cnt = 1;
    char opt[20];
    char a[]="check";
    char b[]="quit";

    time_t timer;
    struct tm *t;

    Time *curr = (Time*) malloc (sizeof(Time)*1);
    Time *prev = (Time*) malloc (sizeof(Time)*1);
    Time *elap = (Time*) malloc (sizeof(Time)*1);

    timer = time(NULL);
    t = localtime(&timer);

    prev -> hours = t -> tm_hour;
    prev -> minutes = t -> tm_min;
    prev -> seconds = t -> tm_sec;

    while (1){
        printf("system > ");
        scanf("%s", opt);
        
        if(!strcmp(a, opt)){
            timer = time(NULL);
            t = localtime(&timer);

            curr -> hours = t -> tm_hour;
            curr -> minutes = t -> tm_min;
            curr -> seconds = t -> tm_sec;

            elap -> hours = (curr -> hours) - (prev -> hours);
            elap -> minutes = (curr -> minutes) - (prev -> minutes);
            elap -> seconds = (curr -> seconds) - (prev -> seconds);

            if ((elap -> seconds) < 0) {
                (elap -> seconds) += 60;
                (elap -> minutes) -= 1;
            }
            if ((elap -> minutes) < 0) {
                (elap -> minutes) += 60;
                (elap -> hours) -= 1;
            }

            printf("\n\tCheck Point #%02d\n", cnt);
            printf("\tCurrent Time = %2d : %2d : %2d\n", curr->hours, curr->minutes, curr->seconds);
            printf("\tPrevious Time = %2d : %2d : %2d\n", prev->hours, prev->minutes, prev->seconds);
            printf("\tElapsed Time = %2d : %2d : %2d\n", elap->hours, elap->minutes, elap->seconds);

            prev -> hours = curr -> hours;
            prev -> minutes = curr -> minutes;
            prev -> seconds = curr -> seconds;

            cnt++;
    }
    else if(!strcmp(b, opt))
        return 0;
        
    }
	free(curr); free(prev); free(elap);

    return 0;
}

