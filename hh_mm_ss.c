//Define a structure called Time containing 3 members: integer hour, integer minute, and integer second. Write a C program to read the current time in terms of hours, minutes, and seconds (which are the structure members) and print the updated time which is incremented by 1 second in the following format hh : mm : ss by calling the function update() that would accept struct Time and return the new time.

//Hint: If the increment results in 60 seconds, then second member is set to zero and minute member is incremented by one. Then if the result is 60 minutes, the minute member is set to zero and the hour member is incremented by one. Finally, when the hour becomes 24 and incremented by 1, then it is set to 0.
#include <stdio.h>

// Define the structure
struct Time {
    int hour;
    int minute;
    int second;
};

// Function to update time by 1 second
struct Time update(struct Time t) {
    t.second++;  // increment second

    if (t.second == 60) {
        t.second = 0;
        t.minute++;  // increment minute
    }

    if (t.minute == 60) {
        t.minute = 0;
        t.hour++;  // increment hour
    }

    if (t.hour == 24) {
        t.hour = 0;
    }

    return t;  // return updated time
}

int main() {
    struct Time currentTime;

    // Read time from user
    printf("Enter current time (hh mm ss): ");
    scanf("%d %d %d", &currentTime.hour, &currentTime.minute, &currentTime.second);

    // Call update function
    struct Time newTime = update(currentTime);

    // Display updated time in hh : mm : ss format
    printf("Updated time: %02d : %02d : %02d\n", newTime.hour, newTime.minute, newTime.second);

    return 0;
}