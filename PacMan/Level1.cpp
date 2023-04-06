/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
#include "Spaceship.h"
#include "GameOver.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "Missile.h"
#include <random>
#include "GameCompleted.h"



using namespace std::this_thread;

using std::ifstream;
using std::string;
using namespace std;

// ------------------------------------------------------------------------------

Scene* Level1::scene = nullptr;

float line1 = 62.0f;
float line2 = 92.0f;
float line3 = 122.0f;
float line4 = 152.0f;
float line5 = 182.0f;


// define um número pseudoaleatório que será a posX do meteoro na tela
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> dis(0, 450);


void Level1::Init()
{
    

    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Level1.jpg");

    // cria jogador
    player = new Player();
    scene->Add(player, MOVING);


    //-----------------------------------------------

    // cria relógio com contagem regressiva
    countdown = new Font("Resources/CourierNew32.png");
    countdown->Spacing(20);


    // posição dos meteoros
    

    //Spaceship* meteoro;
    meteoro = new Spaceship();
    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    scene->Add(meteoro, MOVING);

   
    //--------------------------------------------------




    // ----------------------------------------------------
    pivot = new Pivot(0, 1, 1, 0);
    pivot->MoveTo(300, 720);
    scene->Add(pivot, MOVING);
       
    //-------------------------------------------------------

    roundTime.Start();
    roundTime2.Start();
    roundTime3.Start();
    roundTime4.Start();


    roundTimeGamer.Start();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
    //delete meteoro;
    delete countdown;

}

// ------------------------------------------------------------------------------

void Level1::Update()
{

    
    // condição para nascer 3 meteoros a cada 2 segundos
    if (roundTime.Elapsed(tempo1)) {

        meteoro = new Spaceship();
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship();
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 100;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship();
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 100;
        scene->Add(meteoro, MOVING);

        roundTime.Reset();
    }

    //// condição para nascer +4 meteoros a cada 5 segundos
    //if (roundTime2.Elapsed(tempo2)) {
    //    Spaceship* meteoro;
    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() + dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);


    //    roundTime2.Reset();

    //}

    //condição para nascer +5 meteoros a cada 8 segundos
    //if (roundTime3.Elapsed(tempo3)) {
    //    Spaceship* meteoro;
    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() + dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() + dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);


    //    roundTime3.Reset();
    //}

    //condição para nascer +6 meteoros a cada 15 segundos
    //if (roundTime4.Elapsed(tempo4)) {
    //    Spaceship* meteoro;
    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() + dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() + dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);

    //    meteoro = new Spaceship();
    //    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
    //    meteoro->velY = 200;
    //    scene->Add(meteoro, MOVING);


    //    roundTime4.Reset();
    //}


    // habilita/desabilita bounding box
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (window->KeyPress('P')) {
        Engine::Next<GameOver>();
    }
    else if (pivot->bateu == true) {
        //Sleep(1000);
        Engine::Next<GameOver>();
    }
    else if (player->bateu == true) {
        Sleep(1000);
        Engine::Next<GameOver>();
    }
    else if (roundTimeGamer.Elapsed(tempoGame)) {
        Sleep(1000);
        Engine::Next<GameCompleted>();
    } else {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha relógio com contagem regressiva
    int intCountdown = static_cast<int>(tempoGame - roundTimeGamer.Elapsed());

    if (intCountdown <= 15)
    {
        countdown->Draw(
            940,
            23,
            std::to_string(intCountdown),
            Color(1.0f, 0.0f, 0.0f, 1.0f)
        );
    }
    else
    {
        countdown->Draw(
            940,
            23,
            std::to_string(intCountdown),
            Color(1.0f, 1.0f, 1.0f, 1.0f)
        );
    }

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}



// ------------------------------------------------------------------------------