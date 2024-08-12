#include <graphics.h>  // Include the WinBGIm library

void drawCar(int x, int y) {
    // Draw the body of the car
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(x, y, x + 150, y + 50); // Draw the body of the car
    floodfill(x + 75, y + 25, WHITE);  // Fill the body of the car

    // Draw the roof of the car
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(x + 40, y - 20, x + 110, y); // Draw the roof of the car
    floodfill(x + 75, y - 10, WHITE);      // Fill the roof of the car

    // Draw the wheels of the car
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 40, y + 50, 15); // Draw left wheel
    floodfill(x + 40, y + 50, WHITE);

    circle(x + 110, y + 50, 15); // Draw right wheel
    floodfill(x + 110, y + 50, WHITE);
}

int main() {
    // Initialize the graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    // Set the background color
    setbkcolor(WHITE);

    // Draw the car at position (100, 200)
    drawCar(100, 200);

    // Wait for user to press a key
    getch();

    // Close the graphics mode
    closegraph();

    return 0;
}
