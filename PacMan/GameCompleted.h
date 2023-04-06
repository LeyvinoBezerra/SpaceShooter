/**********************************************************************************
// Home (Arquivo de Cabe�alho)

//
// Descri��o:   Tela de Game
//
**********************************************************************************/

#ifndef _SPACESHIP_GAMECOMPLETED_H_
#define _SPACESHIP_GAMECOMPLETED_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameCompleted : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};

// -----------------------------------------------------------------------------

#endif
