// Copyright (c) 2026 Kamche All rights reserved.
// .
// Created by: Your Kamche
// Date: Nov 12, 2026
// his program asks the user for a number between 0 and 9
// and checks if the input is valid or not.If the input is valid,
// it will display the number back to the user in a loop and break.
#include <iostream>
#include <string>
#include <random>

int main() {
    // A number between 0 and 9
    int RandomVariables;
    int valid_entry = 1;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
    RandomVariables = idist(rgen);

    while (valid_entry == 1) {
        std::string user_number_str;
        std::cout << "Enter a number between 0 and 9: ";
        std::cin >> user_number_str;

        try {
            int user_number_int = stoi(user_number_str);
            if (user_number_int < 0) {
                std::cout << user_number_str
                          << " is a negative integer"
                             "that is not between 0 and 9."
                          << std::endl;
                std::cout << "Please enter a valid integer between 0 and 9."
                          << std::endl;

                valid_entry = 0;
            } else if (user_number_int == RandomVariables) {
                std::cout << "You guessed the correct answer "
                          << RandomVariables << std::endl;
                std::cout << "GOOD JOB!!" << std::endl;

                valid_entry = 0;
            } else {
                std::cout << "You got it wrong." << std::endl;
                std::cout << "The correct answer is "
                          << RandomVariables << std::endl;

                valid_entry = 0;
            }
        } catch (std::invalid_argument) {
                std::cout << user_number_str
                          << " is not an integer."
                          << std::endl;
                valid_entry = 0;
        }
    }
