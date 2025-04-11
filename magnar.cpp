/*
    MAGNAR Robot Program
    Introduction to Programming for Engineers (SEP105)
    Assignment Two

    This program implements multiple functionalities for the MAGNAR robot:
    0. Exit interaction
    1. C++ Calculator
    2. Joke Generator
    3. 2D Sport Array Output
    4. Space Craft Sensory data

    The program continues to prompt the user for input until they select option 0.
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <ctime>

// Define the Sensor struct
struct Sensor {
    std::string name;
    std::string dataType;
    float accuracy;  // between 0.0 and 100.0
    int range;       // between 0 and 1000
    bool status;     // true = active, false = inactive
};

// Function prototype for displaying sensor data
void displaySensorData(const std::vector<struct Sensor>& sensors);

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));
    
    int choice = -1;
    
    // Main loop to keep prompting the user until they choose to exit
    while (choice != 0) {
        // Display main menu
        std::cout << "\n=== MAGNAR COMMAND INTERFACE ===\n" << std::endl;
        std::cout << "Select an option:" << std::endl;
        std::cout << "0. Exit interaction" << std::endl;
        std::cout << "1. C++ Calculator" << std::endl;
        std::cout << "2. Joke" << std::endl;
        std::cout << "3. 2D Sport Array Output" << std::endl;
        std::cout << "4. Space Craft Sensory data" << std::endl;
        std::cout << "\nEnter your choice (0-4): ";
        std::cin >> choice;
        
        // Clear the input buffer
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        
        // Process user choice
        switch (choice) {
            case 0: {
                // Exit interaction - display goodbye message
                std::cout << "Goodbye Fellow Conscious Being! Hope your future travels are great, our interaction was very pleasant. I hope we see each other again!" << std::endl;
                break;
            }
            case 1: {
                // C++ Calculator
                std::cout << "\n=== C++ CALCULATOR ===\n" << std::endl;
                
                // Variables to store the operands and operator
                float num1, num2;
                std::string op;
                bool continueCalculating = true;
                
                while (continueCalculating) {
                    // Prompt user for input
                    std::cout << "Enter first number: ";
                    std::cin >> num1;
                    
                    std::cout << "Enter operator (+, -, *, /, sin, cos, tan, sqrt, exp, log, pow): ";
                    std::cin >> op;
                    
                    // For operators that require a second number
                    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "pow") {
                        std::cout << "Enter second number: ";
                        std::cin >> num2;
                    }
                    
                    // Perform calculation based on operator
                    if (op == "+") {
                        std::cout << "Result: " << num1 + num2 << std::endl;
                    } else if (op == "-") {
                        std::cout << "Result: " << num1 - num2 << std::endl;
                    } else if (op == "*") {
                        std::cout << "Result: " << num1 * num2 << std::endl;
                    } else if (op == "/") {
                        if (num2 != 0) {
                            std::cout << "Result: " << num1 / num2 << std::endl;
                        } else {
                            std::cout << "Error: Division by zero is not allowed." << std::endl;
                        }
                    } else if (op == "sin") {
                        std::cout << "Result: " << sin(num1) << std::endl;
                    } else if (op == "cos") {
                        std::cout << "Result: " << cos(num1) << std::endl;
                    } else if (op == "tan") {
                        std::cout << "Result: " << tan(num1) << std::endl;
                    } else if (op == "sqrt") {
                        if (num1 >= 0) {
                            std::cout << "Result: " << sqrt(num1) << std::endl;
                        } else {
                            std::cout << "Error: Cannot calculate square root of a negative number." << std::endl;
                        }
                    } else if (op == "exp") {
                        std::cout << "Result: " << exp(num1) << std::endl;
                    } else if (op == "log") {
                        if (num1 > 0) {
                            std::cout << "Result: " << log(num1) << std::endl;
                        } else {
                            std::cout << "Error: Cannot calculate logarithm of a non-positive number." << std::endl;
                        }
                    } else if (op == "pow") {
                        std::cout << "Result: " << pow(num1, num2) << std::endl;
                    } else {
                        std::cout << "Error: Invalid operator." << std::endl;
                    }
                    
                    // Ask if the user wants to continue with the calculator
                    char continueChoice;
                    std::cout << "Continue calculating? (y/n): ";
                    std::cin >> continueChoice;
                    
                    if (continueChoice != 'y' && continueChoice != 'Y') {
                        continueCalculating = false;
                    }
                    
                    // Clear the input buffer
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2: {
                // Joke Generator
                std::cout << "\n=== JOKE GENERATOR ===\n" << std::endl;
                
                // Define jokes as a 2D array of strings (setups and punchlines)
                std::string jokes[5][2] = {
                    {"Why don't scientists trust atoms?", "Because they make up everything!"},
                    {"Why did the scarecrow win an award?", "Because he was outstanding in his field!"},
                    {"What do you call a fake noodle?", "An impasta!"},
                    {"How does NASA organize a party?", "They planet!"},
                    {"Why couldn't the bicycle stand up by itself?", "It was two tired!"}
                };
                
                // Generate a random index to select a joke
                int jokeIndex = rand() % 5;
                
                // Display the setup
                std::cout << "Setup: " << jokes[jokeIndex][0] << std::endl;
                
                // Generate a random delay between 1 and 3 seconds
                int delaySeconds = (rand() % 3) + 1;
                std::cout << "Thinking..." << std::endl;
                
                // Implement the delay
                clock_t startTime = clock();
                clock_t endTime = startTime + (delaySeconds * CLOCKS_PER_SEC);
                
                while (clock() < endTime) {
                    // Wait until the delay time has passed
                }
                
                // Display the punchline
                std::cout << "Punchline: " << jokes[jokeIndex][1] << std::endl;
                break;
            }
            case 3: {
                // 2D Sport Array Output
                std::cout << "\n=== 2D SPORT ARRAY OUTPUT ===\n" << std::endl;
                
                // Define the 2D arrays for each team's performance data
                // Basketball data
                std::array<std::array<int, 5>, 5> lakersBasketball = {{
                    {92, 87, 105, 96, 100},
                    {90, 92, 88, 94, 98},
                    {95, 100, 92, 101, 98},
                    {96, 99, 92, 89, 95},
                    {85, 95, 90, 92, 96}
                }};
                
                std::array<std::array<int, 5>, 5> bullsBasketball = {{
                    {89, 92, 86, 88, 82},
                    {85, 80, 88, 92, 86},
                    {84, 88, 90, 85, 92},
                    {86, 90, 84, 92, 91},
                    {91, 95, 89, 86, 88}
                }};
                
                std::array<std::array<int, 5>, 5> knicksBasketball = {{
                    {88, 84, 92, 86, 91},
                    {91, 92, 89, 95, 97},
                    {86, 88, 84, 90, 86},
                    {84, 89, 92, 94, 89},
                    {91, 87, 84, 85, 87}
                }};
                
                std::array<std::array<int, 5>, 5> celticsBasketball = {{
                    {82, 87, 89, 85, 90},
                    {86, 85, 92, 89, 91},
                    {88, 89, 85, 92, 88},
                    {90, 92, 91, 89, 90},
                    {85, 86, 90, 92, 89}
                }};
                
                // Soccer data
                std::array<std::array<int, 5>, 8> realMadridSoccer = {{
                    {3, 1, 0, 2, 2},
                    {2, 1, 2, 1, 1},
                    {1, 1, 1, 2, 2},
                    {2, 2, 1, 1, 1},
                    {0, 2, 1, 1, 1},
                    {1, 1, 1, 1, 2},
                    {3, 0, 2, 2, 1},
                    {2, 1, 2, 2, 2}
                }};
                
                std::array<std::array<int, 5>, 8> barcelonaSoccer = {{
                    {2, 1, 1, 3, 3},
                    {3, 2, 0, 2, 1},
                    {1, 1, 1, 2, 2},
                    {1, 2, 2, 2, 1},
                    {2, 0, 1, 1, 1},
                    {1, 1, 1, 2, 2},
                    {2, 2, 2, 1, 1},
                    {1, 1, 1, 1, 2}
                }};
                
                std::array<std::array<int, 5>, 8> bayernMunichSoccer = {{
                    {1, 3, 2, 2, 3},
                    {3, 2, 2, 2, 1},
                    {1, 1, 1, 2, 2},
                    {2, 2, 2, 2, 1},
                    {0, 1, 1, 2, 2},
                    {2, 1, 1, 2, 1},
                    {1, 1, 0, 2, 2},
                    {2, 2, 2, 1, 1}
                }};
                
                std::array<std::array<int, 5>, 8> manchesterUnitedSoccer = {{
                    {1, 2, 2, 2, 3},
                    {2, 1, 1, 2, 2},
                    {1, 0, 1, 2, 1},
                    {1, 1, 2, 1, 1},
                    {0, 2, 2, 2, 2},
                    {1, 1, 1, 1, 1},
                    {1, 1, 1, 1, 2},
                    {1, 1, 0, 2, 2}
                }};
                
                // Prompt user to select a sport
                int sportChoice;
                std::cout << "Select a sport:" << std::endl;
                std::cout << "1. Basketball" << std::endl;
                std::cout << "2. Soccer" << std::endl;
                std::cout << "\nEnter your choice: ";
                std::cin >> sportChoice;
                
                // Validate sport choice
                if (sportChoice != 1 && sportChoice != 2) {
                    std::cout << "Invalid choice. Returning to main menu." << std::endl;
                    break;
                }
                
                // Prompt user to select a team
                int teamChoice;
                if (sportChoice == 1) {  // Basketball
                    std::cout << "Select a team:" << std::endl;
                    std::cout << "1. Lakers" << std::endl;
                    std::cout << "2. Bulls" << std::endl;
                    std::cout << "3. Knicks" << std::endl;
                    std::cout << "4. Celtics" << std::endl;
                    std::cout << "\nEnter your choice: ";
                    std::cin >> teamChoice;
                    
                    // Process based on team selection for basketball
                    if (teamChoice >= 1 && teamChoice <= 4) {
                        // Determine which array to use based on team selection
                        std::array<std::array<int, 5>, 5>* teamArray = nullptr;
                        std::string teamName;
                        
                        switch (teamChoice) {
                            case 1:
                                teamArray = &lakersBasketball;
                                teamName = "Lakers";
                                break;
                            case 2:
                                teamArray = &bullsBasketball;
                                teamName = "Bulls";
                                break;
                            case 3:
                                teamArray = &knicksBasketball;
                                teamName = "Knicks";
                                break;
                            case 4:
                                teamArray = &celticsBasketball;
                                teamName = "Celtics";
                                break;
                        }
                        
                        // Display team data with properties
                        std::cout << "\n" << teamName << " Basketball Performance Data:" << std::endl;
                        
                        // Find minimum value of the 2D array
                        int minValue = (*teamArray)[0][0];
                        for (int i = 0; i < 5; i++) {
                            for (int j = 0; j < 5; j++) {
                                if ((*teamArray)[i][j] < minValue) {
                                    minValue = (*teamArray)[i][j];
                                }
                            }
                        }
                        std::cout << "Minimum value: " << minValue << std::endl;
                        
                        // Calculate sum of the 2D array
                        int totalSum = 0;
                        for (int i = 0; i < 5; i++) {
                            for (int j = 0; j < 5; j++) {
                                totalSum += (*teamArray)[i][j];
                            }
                        }
                        std::cout << "Sum of the array: " << totalSum << std::endl << std::endl;
                        
                        // Display column headers using printf
                        printf("    ");
                        for (int j = 0; j < 5; j++) {
                            printf("%5s", ("Col" + std::to_string(j)).c_str());
                        }
                        printf("%12s%12s\n", "Row Sum", "Even Count");
                        
                        // Display the array data with row properties
                        for (int i = 0; i < 5; i++) {
                            printf("Row%d ", i);
                            
                            int rowSum = 0;
                            int evenCount = 0;
                            
                            for (int j = 0; j < 5; j++) {
                                printf("%5d", (*teamArray)[i][j]);
                                rowSum += (*teamArray)[i][j];
                                
                                if ((*teamArray)[i][j] % 2 == 0) {
                                    evenCount++;
                                }
                            }
                            
                            printf("%12d%12d\n", rowSum, evenCount);
                        }
                        
                        // Display column properties
                        printf("Max  ");
                        for (int j = 0; j < 5; j++) {
                            int colMax = (*teamArray)[0][j];
                            for (int i = 1; i < 5; i++) {
                                if ((*teamArray)[i][j] > colMax) {
                                    colMax = (*teamArray)[i][j];
                                }
                            }
                            printf("%5d", colMax);
                        }
                        printf("\n");
                    } else {
                        std::cout << "Invalid team choice. Returning to main menu." << std::endl;
                    }
                } else if (sportChoice == 2) {  // Soccer
                    std::cout << "Select a team:" << std::endl;
                    std::cout << "1. Real Madrid" << std::endl;
                    std::cout << "2. Barcelona" << std::endl;
                    std::cout << "3. Bayern Munich" << std::endl;
                    std::cout << "4. Manchester United" << std::endl;
                    std::cout << "\nEnter your choice: ";
                    std::cin >> teamChoice;
                    
                    // Process based on team selection for soccer
                    if (teamChoice >= 1 && teamChoice <= 4) {
                        // Determine which array to use based on team selection
                        std::array<std::array<int, 5>, 8>* teamArray = nullptr;
                        std::string teamName;
                        
                        switch (teamChoice) {
                            case 1:
                                teamArray = &realMadridSoccer;
                                teamName = "Real Madrid";
                                break;
                            case 2:
                                teamArray = &barcelonaSoccer;
                                teamName = "Barcelona";
                                break;
                            case 3:
                                teamArray = &bayernMunichSoccer;
                                teamName = "Bayern Munich";
                                break;
                            case 4:
                                teamArray = &manchesterUnitedSoccer;
                                teamName = "Manchester United";
                                break;
                        }
                        
                        // Display team data with properties
                        std::cout << "\n" << teamName << " Soccer Performance Data:" << std::endl;
                        
                        // Find minimum value of the 2D array
                        int minValue = (*teamArray)[0][0];
                        for (int i = 0; i < 8; i++) {
                            for (int j = 0; j < 5; j++) {
                                if ((*teamArray)[i][j] < minValue) {
                                    minValue = (*teamArray)[i][j];
                                }
                            }
                        }
                        std::cout << "Minimum value: " << minValue << std::endl;
                        
                        // Calculate sum of the 2D array
                        int totalSum = 0;
                        for (int i = 0; i < 8; i++) {
                            for (int j = 0; j < 5; j++) {
                                totalSum += (*teamArray)[i][j];
                            }
                        }
                        std::cout << "Sum of the array: " << totalSum << std::endl << std::endl;
                        
                        // Display column headers using printf
                        printf("    ");
                        for (int j = 0; j < 5; j++) {
                            printf("%5s", ("Col" + std::to_string(j)).c_str());
                        }
                        printf("%12s%12s\n", "Row Sum", "Even Count");
                        
                        // Display the array data with row properties
                        for (int i = 0; i < 8; i++) {
                            printf("Row%d ", i);
                            
                            int rowSum = 0;
                            int evenCount = 0;
                            
                            for (int j = 0; j < 5; j++) {
                                printf("%5d", (*teamArray)[i][j]);
                                rowSum += (*teamArray)[i][j];
                                
                                if ((*teamArray)[i][j] % 2 == 0) {
                                    evenCount++;
                                }
                            }
                            
                            printf("%12d%12d\n", rowSum, evenCount);
                        }
                        
                        // Display column properties
                        printf("Max  ");
                        for (int j = 0; j < 5; j++) {
                            int colMax = (*teamArray)[0][j];
                            for (int i = 1; i < 8; i++) {
                                if ((*teamArray)[i][j] > colMax) {
                                    colMax = (*teamArray)[i][j];
                                }
                            }
                            printf("%5d", colMax);
                        }
                        printf("\n");
                    } else {
                        std::cout << "Invalid team choice. Returning to main menu." << std::endl;
                    }
                }
                break;
            }
            case 4: {
                // Space Craft Sensory data
                std::cout << "\n=== SPACE CRAFT SENSORY DATA ===" << std::endl;
                
                // Create a vector to store sensor data
                std::vector<Sensor> sensors;
                
                // Prompt user to enter sensor data
                char addMore = 'y';
                while (addMore == 'y' || addMore == 'Y') {
                    Sensor newSensor;
                    
                    std::cout << "Enter sensor name: ";
                    getline(std::cin, newSensor.name);
                    
                    std::cout << "Enter sensor data type: ";
                    getline(std::cin, newSensor.dataType);
                    
                    // Validate accuracy input (0.0 to 100.0)
                    do {
                        std::cout << "Enter accuracy (0.0 to 100.0): ";
                        std::cin >> newSensor.accuracy;
                        
                        if (newSensor.accuracy < 0.0 || newSensor.accuracy > 100.0) {
                            std::cout << "Error: Accuracy must be between 0.0 and 100.0." << std::endl;
                        }
                    } while (newSensor.accuracy < 0.0 || newSensor.accuracy > 100.0);
                    
                    // Validate range input (0 to 1000)
                    do {
                        std::cout << "Enter range (0 to 1000): ";
                        std::cin >> newSensor.range;
                        
                        if (newSensor.range < 0 || newSensor.range > 1000) {
                            std::cout << "Error: Range must be between 0 and 1000." << std::endl;
                        }
                    } while (newSensor.range < 0 || newSensor.range > 1000);
                    
                    // Get status input
                    char statusInput;
                    std::cout << "Is the sensor active? (y/n): ";
                    std::cin >> statusInput;
                    newSensor.status = (statusInput == 'y' || statusInput == 'Y');
                    
                    // Add the new sensor to the vector
                    sensors.push_back(newSensor);
                    
                    // Ask if the user wants to add another sensor
                    std::cout << "Add another sensor? (y/n): ";
                    std::cin >> addMore;
                    
                    // Clear the input buffer
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                
                // Display all sensor data using the custom function
                displaySensorData(sensors);
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 0 and 4." << std::endl;
                break;
            }
        }
    }
    
    return 0;
}

// Function to display all sensor data
void displaySensorData(const std::vector<struct Sensor>& sensors) {
    std::cout << "\n=== SPACECRAFT SENSORS ===\n" << std::endl;
    
    // Print table headers using printf for formatting
    printf("%-20s %-15s %-15s %-10s %s\n", 
           "Sensor Name", "Data Type", "Accuracy", "Range", "Status");
    
    // Print a divider line
    printf("%s\n", std::string(70, '-').c_str());
    
    // Print each sensor's data
    for (const auto& sensor : sensors) {
        printf("%-20s %-15s %-15.1f %-10d %s\n", 
               sensor.name.c_str(), 
               sensor.dataType.c_str(), 
               sensor.accuracy, 
               sensor.range, 
               (sensor.status ? "Active" : "Inactive"));
    }
}