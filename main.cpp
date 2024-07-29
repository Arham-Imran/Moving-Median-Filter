#include <iostream>
#include <cstdlib>
#include <algorithm>

#define BUFFER_SIZE 100
#define WINDOW_SIZE 20

using namespace std;

int median(int arr[])
{
    sort(arr, arr + WINDOW_SIZE - 1);
    if(WINDOW_SIZE % 2 == 0)
        return ((arr[WINDOW_SIZE / 2] + arr[(WINDOW_SIZE / 2) - 1]) / 2);
    else
        return arr[WINDOW_SIZE / 2];
}

int main(void)
{
    srand(0);
    int buffer[BUFFER_SIZE];
    int window[WINDOW_SIZE] = {};
    int filtered_buffer[BUFFER_SIZE - WINDOW_SIZE] = {};
    int current_index = WINDOW_SIZE - 1;

    for(int i = 0; i < BUFFER_SIZE; i++)
        buffer[i] = rand()%50;

    while(current_index < BUFFER_SIZE)
    {
        for(int i = 0; i < WINDOW_SIZE; i++)
            window[i] = buffer[current_index - i];
        
        filtered_buffer[current_index - WINDOW_SIZE + 1] = median(window);
        current_index++;
    }

    for(int i = 0; i < BUFFER_SIZE; i++)
        cout << buffer[i] << ", ";
    cout << endl << endl << endl;

     for(int i = 0; i < BUFFER_SIZE - WINDOW_SIZE; i++)
        cout << filtered_buffer[i] << ", ";
    cout << endl;
}
