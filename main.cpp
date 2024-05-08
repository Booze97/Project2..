#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Structure to store linear motion commands
struct LinearMotionCommand {
    float startX, startY, startZ;
    float endX, endY, endZ;
};

// Function to parse the input file and extract linear motion commands
std::vector<LinearMotionCommand> parseFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<LinearMotionCommand> commands;

    if (file.is_open()) {
        std::string line;
        // Read each line of the file
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string commandType;
            iss >> commandType;
            // Check if the command is a linear motion command
            if (commandType == "linear") {
                LinearMotionCommand command;
                // Extract start and end points from the line
                iss >> command.startX >> command.startY >> command.startZ;
                iss >> command.endX >> command.endY >> command.endZ;
                // Store the command in the vector
                commands.push_back(command);
            }
            // Parse rotational commands similarly if present
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }

    return commands;
}
