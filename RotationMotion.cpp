#include <iomanip>

// Structure to store rotational motion commands
struct RotationalMotionCommand {
    float centerX, centerY;
    float radius;
    bool clockwise;
    float stopAngle;
};

// Function to calculate positions for rotational motion commands
void calculateRotationalMotion(const RotationalMotionCommand& command) {
    float angle = 0.0f;
    float stepSize = 5.0f;

    // Iterate over angles up to the stop angle
    while (angle <= command.stopAngle) {
        // Calculate position using trigonometric functions
        float posX = command.centerX + command.radius * cos(angle * M_PI / 180.0f);
        float posY = command.centerY + command.radius * sin(angle * M_PI / 180.0f);
        // Output positions with two decimal places
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Position at angle " << angle << " degrees: " << posX << ", " << posY << std::endl;

        // Update angle based on rotation direction
        if (command.clockwise)
            angle -= stepSize;
        else
            angle += stepSize;
    }
}
