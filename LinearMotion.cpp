#include <cmath>

// Function to calculate positions for linear motion commands
void calculateLinearMotion(const LinearMotionCommand& command) {
    // Calculate differences in coordinates
    float deltaX = command.endX - command.startX;
    float deltaY = command.endY - command.startY;
    float deltaZ = command.endZ - command.startZ;

    // Determine the number of steps based on the longest axis
    int steps = std::max({std::abs(deltaX), std::abs(deltaY), std::abs(deltaZ)});

    // Calculate and print positions for each step
    for (int i = 0; i <= steps; ++i) {
        float posX = command.startX + (deltaX / steps) * i;
        float posY = command.startY + (deltaY / steps) * i;
        float posZ = command.startZ + (deltaZ / steps) * i;
        // Output positions with two decimal places
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Position " << i+1 << ": " << posX << ", " << posY << ", " << posZ << std::endl;
    }
}
