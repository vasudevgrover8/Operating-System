#include <iostream>
using namespace std;

typedef struct process {
    int at;
    int et;
    int ct; 
} process;

int main() {
    process p[5];
    int time = 0;

    p[0].at = 3; p[0].et = 1; 
    p[1].at = 1; p[1].et = 4; 
    p[2].at = 4; p[2].et = 2; 
    p[3].at = 0; p[3].et = 6; 
    p[4].at = 2; p[4].et = 3; 

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (p[i].at > p[j].at) {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    bool completed[5] = {false}; 
    int completed_count = 0;

    while (completed_count < 5) {
        int index = -1;
        int min_et = INT_MAX;

        for (int i = 0; i < 5; i++) {
            if (p[i].at <= time && !completed[i] && p[i].et < min_et) {
                min_et = p[i].et;
                index = i;
            }
        }

        if (index != -1) {
            time += p[index].et; 
            p[index].ct = time;  
            completed[index] = true; 
            completed_count++;
        } else {
            time++;
        }
    }

        cout << "Completion Times:" << endl;
        for (int i = 0; i < 5; i++) {
        cout << "Process " << i + 1 << ": " << p[i].ct << endl;
    }

    return 0;
}
