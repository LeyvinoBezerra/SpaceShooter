/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "Space.h"
#include "Player.h"
#include "Pivot.h"
#include "Missile.h"
#include "Home.h"
#include "List"
#include "Engine.h"
#include "Level1.h"
#include "Level2.h"
#include "GameOver.h"

// ---------------------------------------------------------------------------------


Player::Player()
{
    sprite = new Sprite("Resources/Player.png");
    //missile = new Image("Resources/Missile.new.png");
    // imagem do pacman é 48x48 (com borda transparente de 4 pixels)
    //BBox(new Rect(-20, -10, 20, 20));
    
    Mixed* mixed = new Mixed();

    Circle* cLeft = new Circle(5.0f);
    cLeft->MoveTo(-20.0f, 0.0f);
    Circle* cRight = new Circle(5.0f);
    cRight->MoveTo(20.0f, 0.0f);
    Rect* rect = new Rect(-10.0f, -10.0f, 10.0f, 10.0f);

    mixed->Insert(cLeft);
    mixed->Insert(cRight);
    mixed->Insert(rect);

    BBox(mixed);


    //move o player na tela
    MoveTo(430.0f, 680.0f);
    
    // tipo do objeto
    type = PLAYER;

}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete sprite;
    //delete missile;
}

// ---------------------------------------------------------------------------------

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == PIVOT)
        PivotCollision(obj);

    if (obj->Type() == INIMIGO)
    {
        bateu = true;
        //Engine::Pause();
    }
}

// ---------------------------------------------------------------------------------

void Player::PivotCollision(Object * obj)
{
    Pivot * p = (Pivot*)obj;

    switch (currState)
    {
    case STOPED:
        // -----------------------
        // CurrentState == STOPED
        // -----------------------

        switch (nextState)
        {
        case LEFT:
            if (p->left)
            {
                currState = LEFT;
                Left();
            }
            break;
        case RIGHT:
            if (p->right)
            {
                currState = RIGHT;
                Right();
            }

            break;
        case UP:
            if (p->up)
            {
                currState = UP;
                Up();
            }
            break;
        case DOWN:
            if (p->down)
            {
                currState = DOWN;
                Down();
            }
            break;
        }
        break;

    case LEFT:
        // -----------------------
        // CurrentState == LEFT
        // -----------------------

        if (x < p->X())
        {
            if (!p->left)
            {
                MoveTo(p->X(), Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (x < p->X())
            {
                if (!p->left)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        case RIGHT:
            currState = RIGHT;
            Right();

            break;
        case UP:
            if (x < p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x < p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case RIGHT:
        // -----------------------
        // CurrentState == RIGHT
        // -----------------------

        if (x > p->X())
        {
            if (!p->right)
            {
                MoveTo(p->X(), Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            currState = LEFT;
            Left();
            break;
        case RIGHT:
            if (x > p->X())
            {
                if (!p->right)
                {
                    MoveTo(p->X(), Y());
                    currState = STOPED;
                    Stop();
                }
            }

            break;
        case UP:
            if (x > p->X())
            {
                if (p->up)
                {
                    MoveTo(p->X(), Y());
                    currState = UP;
                    Up();
                }
            }
            break;
        case DOWN:
            if (x > p->X())
            {
                if (p->down)
                {
                    MoveTo(p->X(), Y());
                    currState = DOWN;
                    Down();
                }
            }
            break;
        }
        break;

    case UP:
        // -----------------------
        // CurrentState == UP
        // -----------------------

        if (y < p->Y())
        {
            if (!p->up)
            {
                MoveTo(x, p->Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y < p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y < p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            if (y < p->Y())
            {
                if (!p->up)
                {
                    MoveTo(x, p->Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        case DOWN:
            currState = DOWN;
            Down();
            break;
        }
        break;

    case DOWN:
        // -----------------------
        // CurrentState == DOWN
        // -----------------------

        if (y > p->Y())
        {
            if (!p->down)
            {
                MoveTo(x, p->Y());
                currState = STOPED;
                Stop();
            }
        }

        switch (nextState)
        {
        case LEFT:
            if (y > p->Y())
            {
                if (p->left)
                {
                    MoveTo(x, p->Y());
                    currState = LEFT;
                    Left();
                }
            }
            break;
        case RIGHT:
            if (y > p->Y())
            {
                if (p->right)
                {
                    MoveTo(x, p->Y());
                    currState = RIGHT;
                    Right();
                }
            }
            break;
        case UP:
            currState = UP;
            Up();
            break;
        case DOWN:
            if (y > p->Y())
            {
                if (!p->down)
                {
                    MoveTo(x, p->Y());
                    currState = STOPED;
                    Stop();
                }
            }
            break;
        }
        break;
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    ////Disparar Missel
    if (window->KeyPress(VK_SPACE)) {
        Missile* missel = new Missile();
        missel->MoveTo(x, y - sprite->Height() / 2.0f, Layer::UPPER);
        Level1::scene->Add(missel, MOVING);

    }

    if (window->KeyDown(VK_LEFT))
    {
        Translate(-velX * gameTime, 0); 
    }
    
    if (window->KeyDown(VK_RIGHT))
    {
        Translate(velX * gameTime, 0);
    }


    // atualiza posição

    // mantém player dentro da tela
    if (x < sprite->Width() / 2.0f)
        MoveTo(sprite->Width()/ 2.0f, y);

    if (x + sprite->Width() / 2.0f > window->Width())
        MoveTo(float(window->Width() - sprite->Width() / 2.0f), y);


}

// ---------------------------------------------------------------------------------

void Player::Draw()
{ 
    switch(currState)
    {
    case LEFT:  sprite->Draw(x, y, Layer::UPPER); break;
    case RIGHT: sprite->Draw(x, y, Layer::UPPER); break;
    case UP:    sprite->Draw(x, y, Layer::UPPER); break;
    case DOWN:  sprite->Draw(x, y, Layer::UPPER); break;
    default: 
        switch(nextState)
        {
        case LEFT:  sprite->Draw(x, y, Layer::UPPER); break;
        case RIGHT: sprite->Draw(x, y, Layer::UPPER); break;
        case UP:    sprite->Draw(x, y, Layer::UPPER); break;
        case DOWN:  sprite->Draw(x, y, Layer::UPPER); break;
        default:    sprite->Draw(x, y, Layer::UPPER);
        }
    }
}

// ---------------------------------------------------------------------------------