/**********************************************************************************
// Ghost (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Fantasmas do PacMan
//
**********************************************************************************/

#include "Space.h"
#include "Player.h"
#include "Spaceship.h"
#include "Level1.h"
#include "Object.h"

// ---------------------------------------------------------------------------------

Spaceship::Spaceship()
{
    // tamanho do bloco é 40x60
    BBox(new Rect(-20, -30, 19, 29));

    // sprite do bloco
    sprite = new Sprite("Resources/Meteoro.png");

    // velocidades iniciais
    velX = 0.0f;
    velY = 50.0f;

    // tipo do objeto
    type = INIMIGO;

}

// ---------------------------------------------------------------------------------

Spaceship::~Spaceship()
{
    delete sprite;
}


void Spaceship::OnCollision(Object* obj) {
    if (obj->Type() == PIVOT) {
       saiu = true;
       
    }
    if(obj->Type() == MISSEL) {
        Level1::scene->Delete(obj, MOVING);
    }

}




// ---------------------------------------------------------------------------------

void Spaceship::Update()
{
    // desloca o bloco
    Translate(velX * gameTime, velY * gameTime);


    // destrói ao sair da janela
    if (y > window->Height())
        //saiu = true;
        Level1::scene->Delete();
}

// ---------------------------------------------------------------------------------
