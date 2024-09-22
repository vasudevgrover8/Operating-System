#include <iostream>
using namespace std;

int main() {
    int reference_string[14] = {7,6,3,1,6,1,2,3};
    int frame[4] = {-1, -1, -1, -1}; 
    int miss = 0;
    int hit = 0;
    int n = 8; 
    int m = 4;  

    for (int i = 0; i < n; i++) {
        int search = reference_string[i];
        bool found = false;

        for (int j = 0; j < m; j++) {
            if (frame[j] == search) {
                found = true;
                hit++;
                break;
            }
        }

        if (!found) {
            // Check for an empty frame
            bool empty_frame = false;
            for (int j = 0; j < m; j++) {
                if (frame[j] == -1) {
                    frame[j] = search; 
                    empty_frame = true;
                    miss++;
                    break;
                }
            }

          
            if (!empty_frame) {
                int replace_index = -1;
                int farthest = -1;

               
                for (int j = 0; j < m; j++) {
                    int future_use = -1; 

                  
                    for (int k = i + 1; k < n; k++) {
                        if (frame[j] == reference_string[k]) {
                            future_use = k;
                            break;
                        }
                    }

                    
                    if (future_use == -1) {
                        replace_index = j;
                        break;
                    }

                   
                    if (future_use > farthest) {
                        farthest = future_use;
                        replace_index = j;
                    }
                }

                
                frame[replace_index] = search;
                miss++;
            }
        }
    }

    
    cout << "Total Page Hits: " << hit << endl;
    cout << "Total Page Misses: " << miss << endl;

    return 0;
}
