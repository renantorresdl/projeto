#include "raylib.h"
#include <stdbool.h>

int main()
{
    InitWindow(800, 600, "Jogo");

    int jogadorX = 100;
    int jogadorY = 100;
    
    int objetivoX = 600;
    int objetivoY = 400;

    int inimigoX = 300;
    int inimigoY = 300;
    int velocidadeInimigo = 2;


    int pontos = 0;
    int recorde = 0;
    int velocidade = 1;
    int vidas = 3;

    float tempo = 60.0f;

    bool jogoAtivo = false;
    bool menu = true;
    int dificuldade = 0;
    float tempoInvuneravel = 0.0f;

    while (!WindowShouldClose())
    {
        // Menu
        if (menu)
        {
            if (IsKeyPressed(KEY_ONE))
            {
                dificuldade = 1;
                tempo = 90.0f;
                velocidade = 1;
                vidas = 6;
                tempoInvuneravel = 0;

                menu = false;
                jogoAtivo = true;
            }

            if (IsKeyPressed(KEY_TWO))
            {
                dificuldade = 2;
                tempo = 60.0f;
                velocidade = 1;
                vidas = 5;
                tempoInvuneravel = 0;

                menu = false;
                jogoAtivo = true;
            }

            if (IsKeyPressed(KEY_THREE))
            {
                dificuldade = 3;
                tempo = 30.0f;
                velocidade = 4;
                vidas = 3;
                tempoInvuneravel = 0;

                menu = false;
                jogoAtivo = true;
            }
        }

        // Tempo
        if (jogoAtivo)
        {
            tempo -= GetFrameTime();

            if (tempo <= 0)
            {
                tempo = 0;
                jogoAtivo = false;
            }
        }
        // Reiniciar o jogo
        if (!jogoAtivo && IsKeyPressed(KEY_R))
        {
            jogadorX = 100;
            jogadorY = 100;

            objetivoX = 600;
            objetivoY = 400;

            pontos = 0;
            velocidade = 1;

            jogoAtivo = false;
            menu = true;

            tempoInvuneravel = 0;
        }

        // Movimento jogador
        if (jogoAtivo)
        {
            if (IsKeyDown(KEY_D) && jogadorX < 750)
            {
                jogadorX += velocidade;
            }

            if (IsKeyDown(KEY_A) && jogadorX > 0)
            {
                jogadorX -= velocidade;
            }

            if (IsKeyDown(KEY_W) && jogadorY > 0)
            {
                jogadorY -= velocidade;
            }

            if (IsKeyDown(KEY_S) && jogadorY < 550)
            {
                jogadorY += velocidade;
            }
    }    

        // Movimento Inimigo
        if (jogoAtivo)
        {
            inimigoX += velocidadeInimigo;

            if (inimigoX >= 750 || inimigoX <= 0)
            {
                velocidadeInimigo *= -1;
            }
        }

        if (tempoInvuneravel > 0)
        {
            tempoInvuneravel -= GetFrameTime();
        }
        // Colisão
        if (jogoAtivo)
        {
            if (CheckCollisionRecs(
                (Rectangle){jogadorX, jogadorY, 50, 50},
                (Rectangle){objetivoX, objetivoY, 50, 50}
            ))
            {
                pontos++;

                if (dificuldade > 1 && pontos % 5 == 0)
                {
                    velocidade++;
                }
                
                if (pontos > recorde)
                {
                    recorde = pontos;
                }
                objetivoX = GetRandomValue(0, 750);
                objetivoY = GetRandomValue(0, 550);
            }
        }
        if (jogoAtivo)
{
    if (tempoInvuneravel <= 0 &&
    CheckCollisionRecs(
        (Rectangle){jogadorX, jogadorY, 50, 50},
        (Rectangle){inimigoX, inimigoY, 50, 50}
    ))
    {
        vidas--;

        jogadorX = 100;
        jogadorY = 100;

        tempoInvuneravel = 1.5f;
    }

    if (vidas <= 0)
    {
        jogoAtivo = false;
    }
}

// Desenho
BeginDrawing();

ClearBackground(RAYWHITE);

if (menu)
{
    DrawText("ESCOLHA A DIFICULDADE", 180, 150, 30, BLACK);

    DrawText("1 - FACIL (90s)", 250, 250, 25, GREEN);

    DrawText("2 - MEDIO (60s)", 250, 300, 25, ORANGE);

    DrawText("3 - DIFICIL (30s)", 250, 350, 25, RED);
}
else if (jogoAtivo)
{
    if (tempoInvuneravel <= 0 || ((int)(tempoInvuneravel * 10) % 2 == 0))
    {
        DrawRectangle(jogadorX, jogadorY, 50, 50, BLUE);
    }

    DrawRectangle(objetivoX, objetivoY, 50, 50, RED);

    DrawRectangle(inimigoX, inimigoY, 50, 50, BLACK);

    DrawText(TextFormat("Pontos: %d", pontos), 10, 10, 20, BLACK);

    DrawText(TextFormat("Recorde: %d", recorde), 10, 35, 20, BLACK);

    DrawText(TextFormat("Tempo: %.0f", tempo), 10, 60, 20, BLACK);

    for (int i = 0; i < vidas; i++)
{
    int x = 20 + (i * 35);
    int y = 95;

    DrawCircle(x - 6, y - 5, 6, RED);
    DrawCircle(x + 6, y - 5, 6, RED);

    DrawTriangle(
        (Vector2){x - 12, y - 2},
        (Vector2){x + 12, y - 2},
        (Vector2){x, y + 12},
        RED
    );
}
}
else
{
    DrawText("GAME OVER", 270, 250, 40, RED);

    DrawText(TextFormat("Pontos: %d", pontos), 330, 310, 20, BLACK);

    DrawText("Pressione R para voltar ao menu", 240, 360, 20, BLACK);
}

EndDrawing();
    }
    CloseWindow();

    return 0;
}