# MAGNAR Robot Program

## Overview
The MAGNAR Robot Program is a multi-functional C++ application designed for the **Introduction to Programming for Engineers (SEP105)** course. It provides a variety of interactive features, including a calculator, joke generator, sports data analysis, and spacecraft sensor data management.

## Features
1. **C++ Calculator**:
   - Perform basic arithmetic operations (`+`, `-`, `*`, `/`).
   - Advanced mathematical functions like `sin`, `cos`, `tan`, `sqrt`, `exp`, `log`, and `pow`.
   - Handles invalid inputs (e.g., division by zero, invalid operators).

2. **Joke Generator**:
   - Randomly selects a joke from a predefined list.
   - Includes a delay to simulate "thinking" before delivering the punchline.

3. **2D Sport Array Output**:
   - Analyze basketball and soccer team performance data stored in 2D arrays.
   - Features include:
     - Displaying team data.
     - Calculating the minimum value, total sum, and row/column properties.
     - Highlighting even numbers and column maximums.

4. **Spacecraft Sensory Data**:
   - Allows users to input and manage sensor data for a spacecraft.
   - Validates sensor attributes such as accuracy (0.0–100.0) and range (0–1000).
   - Displays all sensor data in a formatted table.

5. **Exit Interaction**:
   - Gracefully exits the program with a farewell message.

## How to Run
### Prerequisites
- A C++ compiler (e.g., GCC, MinGW, or MSVC).
- A terminal or IDE that supports C++ compilation and execution.

### Steps
1. Clone or download the project to your local machine.
2. Open a terminal in the project directory.
3. Compile the program:
   ```bash
   g++ -o magnar magnar.cpp