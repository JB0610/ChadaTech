#include <iostream>
#include <string>

// Global variables to store the current time.
int hour = 0, minute = 0, second = 0;

// Function declarations for getting and setting the time.
int getHour();
int getMinute();
int getSecond();
void setHour(int h);
void setMinute(int m);
void setSecond(int s);
void addOneHour();
void addOneMinute();
void addOneSecond();

// Convert a single digit number to two digit string format, e.g., '7' to '07'.
std::string twoDigitString(unsigned int n) {
    if (n > 59) {
        std::cout << "Error, wrong input";
        return "invalid input";
    }
    if (n <= 9) {
        return "0" + std::to_string(n);
    } else {
        return std::to_string(n);
    }
}

// Generate a string composed of n repetitions of character c.
std::string nCharString(size_t n, char c) {
    return std::string(n, c);
}

// Format time to 24-hour format: HH:MM:SS.
std::string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Format time to 12-hour format with AM/PM: HH:MM:SS AM/PM.
std::string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    std::string ampm;
    if (h == 0 || h == 12) {
        if (h == 0) ampm = "A M";
        else ampm = "P M";
        h = 12;
    } else if (h < 12) {
        ampm = "A M";
    } else {
        ampm = "P M";
        h -= 12;
    }
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + ampm;
}

// Print a menu using strings provided, formatted within a box of asterisks.
void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {
    std::cout << nCharString(width, '*') << std::endl;
    for (unsigned int i = 0; i < numStrings; i++) {
        std::string start = "* " + std::to_string(i + 1) + " - ";
        int padding = width - std::string(strings[i]).length() - start.length() - 3;
        std::cout << start << strings[i] << nCharString(padding, ' ') << " *" << std::endl;
    }
    std::cout << nCharString(width, '*') << std::endl;
}

// Ask user to select a menu choice until they provide a valid input.
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int i = 0;
    while (i < 1 || i > maxChoice) {
        std::string s;
        std::getline(std::cin, s);
        i = std::stoi(s);
    }
    return i;
}

// Display both 12-hour and 24-hour format clocks side by side.
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    std::cout << nCharString(28, '*') << "   " << nCharString(28, '*') << std::endl;
    std::cout << "*      12-HOUR CLOCK       *   *      24-HOUR CLOCK       *" << std::endl;
    std::cout << "*      " << formatTime12(h, m, s) << "        *   *      " << formatTime24(h, m, s) << "            *" << std::endl;
    std::cout << nCharString(28, '*') << "   " << nCharString(28, '*') << std::endl;
}

// Setters and getters for global time variables.
void setHour(int h) { hour = h; }
void setMinute(int m) { minute = m; }
void setSecond(int s) { second = s; }
int getHour() { return hour; }
int getMinute() { return minute; }
int getSecond() { return second; }

// Increase the current time by one hour/minute/second.
void addOneHour() {
    if (hour >= 0 && hour <= 22) {
        setHour(hour + 1);
    } else if (hour == 23) {
        setHour(0);
    }
}
void addOneMinute() {
    if (minute >= 0 && minute <= 58) {
        setMinute(minute + 1);
    } else if (minute == 59) {
        setMinute(0);
        addOneHour();
    }
}
void addOneSecond() {
    if (second >= 0 && second <= 58) {
        setSecond(second + 1);
    } else if (second == 59) {
        setSecond(0);
        addOneMinute();
    }
}

// Main menu logic for the application.
void mainMenu() {
    const char* options[] = {"Add one hour", "Add one minute", "Add one second", "Exit"};
    printMenu(options, 4, 27);
    while (true) {
        unsigned int choice = getMenuChoice(4);
        switch (choice) {
            case 1:
                addOneHour();
                break;
            case 2:
                addOneMinute();
                break;
            case 3:
                addOneSecond();
                break;
            case 4:
                return;
        }
        displayClocks(hour, minute, second);
    }
}

// Main function: initializes the time and starts the menu.
int main() {
    hour = 12;
    minute = 52;
    second = 26;
    displayClocks(hour, minute, second);
    mainMenu();
    return 0;
}
