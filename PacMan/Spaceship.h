/**********************************************************************************
// Ghost (Arquivo de Cabe�alho)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Fantasmas do PacMan
//
**********************************************************************************/

#ifndef _PACMAN_GHOST_H_
#define _PACMAN_GHOST_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Player.h"                     // jogador do PacMan
#include "Space.h"

// ---------------------------------------------------------------------------------

class Spaceship : public Object
{
private:
    Sprite * sprite = nullptr;          // sprite do player
    Player * player = nullptr;          // ponteiro para jogador

public:
    float velX = 0;                     // velocidade horizontal
    float velY = 0;                     // velocidade vertical

    bool saiu = false;

    Spaceship();                  // construtor
    ~Spaceship();                           // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto

    void OnCollision(Object* obj); // para tratameto de colis�o

};

// ---------------------------------------------------------------------------------

inline void Spaceship::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif