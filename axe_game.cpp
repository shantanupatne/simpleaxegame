#include <iostream>
#include "raylib.h"


int main() {

    // Window
    int width(640);
    int height(480);

    // Circle
    int centreX( 100 );
    int centreY( 100);
    float radius{ 25 };

    int l_circle_x{centreX - (int)radius};
    int r_circle_x{centreX + (int)radius};
    int u_circle_y{centreY - (int)radius};
    int b_circle_y{centreY + (int)radius};

    // Axe
    int posX(300);
    int posY(0);
    int ax_len(50);

    int l_axe_x{posX};
    int r_axe_x{posX + ax_len};
    int u_axe_y{posY};
    int b_axe_y{posY + ax_len};

    bool collision = (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) &&
                        (l_axe_x <= r_circle_x);

    int direction(10);

    // Show window
    InitWindow(width, height, "Axe Game");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(collision) {
            DrawText("Game Over!", 400, 200, 20, RED);
        } else {

            // collision detection
            l_circle_x = centreX - radius;
            r_circle_x = centreX + radius;
            u_circle_y = centreY - radius;
            b_circle_y = centreY + radius;

            l_axe_x = posX;
            r_axe_x = posX + ax_len;
            u_axe_y = posY;
            b_axe_y = posY + ax_len;

            collision = (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) &&
                        (l_axe_x <= r_circle_x);

            // draw shapes
            DrawCircle(centreX, centreY, radius, BLUE);
            DrawRectangle(posX, posY, ax_len, ax_len, RED);

            // position and movement
            posY += direction;
            if(posY > height - ax_len || posY < 0) {
                direction = -direction;
            }
            
            if( IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {            
                if (centreX >= width + radius) {
                    centreX = 0;
                } else centreX += 10;
            }
            if( IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {            
                if (centreX <= 0-radius) {
                    centreX = width;
                } else centreX -= 10;
            }
            if( IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {            
                if (centreY >= height + radius) {
                    centreY = 0;
                } else centreY += 10;
            }
            if( IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {            
                if (centreY <= 0 - radius) {
                    centreY = height;
                } else centreY -= 10;
            }
        }

        EndDrawing();
    }
    return 0;
}