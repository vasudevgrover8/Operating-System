#include<iostream>
using namespace std;

typedef struct process
{
    int at;
    int et;
    int ct;
} process;

int main()
{ 
    process p[5];
    int time = 0;
    int i=0;
    int j=0;

    p[0].at = 3;
    p[0].et = 1;

    p[1].at = 1;
    p[1].et = 4;

    p[2].at = 4;
    p[2].et = 2;

    p[3].at = 0;
    p[3].et = 6;

    p[4].at = 2;
    p[4].et = 3;
    
   for(i=0;i<5;i++)
   {
        for(j=i+1;j<5;j++)
        {
            if(p[i].at>p[j].at)
            {
               process arrival = p[i];
                p[i] = p[j];
                p[j] = arrival;
            }
        }
   }

   for(i=0;i<5;i++)
   {    if(time < p[i].at)
        {
            time = p[i].at;
        }
          p[i].ct = time + p[i].et;
          time = p[i].ct; 
          cout << p[i].ct << endl;
   }
   return 0;
}