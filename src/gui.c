#include <raylib.h>
#include "../include/solve.h"
#include "math.h"
#include <stdio.h>

bool eqDoubleGui(double a, double b, double zoom) {
    return fabsl(a - b) < 1 * zoom;
}

void drawTexture(double a, double b, double c, double midX, double midY, double zoom, int WIDTH, int HEIGHT);

void readKeyboard(double *midX, double *midY, double *zoom, bool *reDraw);

void drawGraphic(double a, double b, double c) {
    const int HEIGHT = 800;
    const int WIDTH = 800;
    double zoom = 1;
    bool reDraw = true;
    double midX = 0;
    double midY = 0;

    SetTraceLogLevel(0);
    InitWindow(WIDTH, HEIGHT, "Graphic");
    SetTargetFPS(60);
    RenderTexture2D target = LoadRenderTexture(WIDTH, HEIGHT);

    while (!WindowShouldClose()) {
        readKeyboard(&midX, &midY, &zoom, &reDraw);
        if (reDraw) {
            BeginTextureMode(target);
            drawTexture(a, b, c, midX, midY, zoom, WIDTH, HEIGHT);
            EndTextureMode();
            reDraw = false;
        }

        BeginDrawing();
        DrawTextureRec(target.texture, (Rectangle) {0, 0, (float) WIDTH, (float) -HEIGHT},
                       (Vector2) {0, 0}, WHITE);
        EndDrawing();
    }

    CloseWindow();
}


void drawTexture(double a, double b, double c, double midX, double midY, double zoom, int WIDTH, int HEIGHT) {
    ClearBackground(WHITE);
    int pred_screen_x = -1;
    int pred_screen_y = -1;
    for (int screen_x = 0; screen_x < WIDTH; ++screen_x) {

        double x = ((double) screen_x - (double) WIDTH / 2) * zoom + midX;
        double maybeY = a * x * x + b * x + c;
        int screen_yy = -((maybeY - midY) / zoom - HEIGHT / 2);

        for (int screen_y = 0; screen_y < HEIGHT; ++screen_y) {
            double y = ((double) -screen_y + (double) HEIGHT / 2) * zoom + midY;
            if (eqDoubleGui(x, 0, zoom) || eqDoubleGui(y, 0, zoom)) {
                DrawPixel(screen_x, screen_y, BLACK);
            }
        }
        if (pred_screen_x == -1) {
            pred_screen_x = screen_x;
            pred_screen_y = screen_yy;
        } else {
            DrawLine(screen_x, screen_yy, pred_screen_x, pred_screen_y, BLUE);
            pred_screen_x = screen_x;
            pred_screen_y = screen_yy;
        }
    }

}


void readKeyboard(double *midX, double *midY, double *zoom, bool *reDraw) {
    if (IsKeyDown(KEY_S)) {
        (*midY) -= 2. * (*zoom);
        (*reDraw) = true;
    }
    if (IsKeyDown(KEY_W)) {
        (*midY) += 2. * (*zoom);
        (*reDraw) = true;
    }
    if (IsKeyDown(KEY_A)) {
        (*midX) -= 2. * (*zoom);
        (*reDraw) = true;
    }
    if (IsKeyDown(KEY_D)) {
        (*midX) += 2. * (*zoom);
        (*reDraw) = true;
    }
    if (IsKeyDown(KEY_Q)) {
        (*zoom) /= 1.01;
        (*reDraw) = true;
    }
    if (IsKeyDown(KEY_E)) {
        (*zoom) *= 1.01;
        (*reDraw) = true;
    }
}