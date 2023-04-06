/**********************************************************************************
// Level1 (Arquivo de Cabe�alho)
// 
// Cria��o:     18 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   N�vel 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Timer.h"
#include "Player.h"
#include "Spaceship.h"
#include "Pivot.h"
#include "Font.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
public:
    Sprite * backg = nullptr;       // background
    bool viewBBox = false;          // habilita visualiza��o da bounding box
    Image* tile1 = nullptr;

    Player* player = nullptr;								// jogador
    Spaceship* meteoro = nullptr;                       // meteoro
    Pivot* pivot = nullptr;

    Font* countdown = nullptr;


    Timer roundTime;                // contador do game
    float tempo1 = 2.0f;
    Timer roundTime2;
    float tempo2 = 5.0f;
    Timer roundTime3;
    float tempo3 = 8.0f;
    Timer roundTime4;
    float tempo4 = 15.0f;

    Timer roundTimeGamer;
    float tempoGame = 30.0f;         // tempo limite do game

public:
    static Scene* scene;         // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif