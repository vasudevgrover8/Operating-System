#include <iostream>
using namespace std;

int main()
{
    int reference_string[20] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int frame[3]={-1,-1,-1};
    int miss = 0;
    int hit = 0;
    int *rear;
    int i = 0;
    int search;
    int index = 0;

    int j = 0;
    int k = 0;

    /*while (i <= 2)
    {
        frame[i] = reference_string[i];
        rear = &frame[0];
        cout << "The value of frame[" << i << "] is " << frame[i] << endl;
        cout << "The value in rear is " << *rear << endl;
        miss = miss + 1;
        i = i + 1;
    }*/

    for (i = 0; i <= 20; i++)
    {
        search = reference_string[i];
        int count = 0;
        int flag = 0;
        while (count <= 2)
        {
            if(search==frame[count])
            {
                flag = 1;
            }
            count = count + 1;
        }
        if(flag==0)
        {
            miss = miss + 1;
            frame[index] = search;
            index = (index + 1)%3;
        }

    }


    for (k = 0; k <= 2; k++)
    {
        cout << frame[k] << endl;
    }
    cout << miss;
    return 0;
}