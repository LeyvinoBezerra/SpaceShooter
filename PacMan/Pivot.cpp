/**********************************************************************************
// Pivot (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Ponto de mudança de direção para o jogador e fantasmas
//
**********************************************************************************/

#include "Space.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Pivot::Pivot(bool l, bool r, bool u, bool d)
{
    left  = l;
    right = r;
    up    = u;
    down  = d;

    BBox(new Rect(-300, -2, 700, 2));
    type = PIVOT;
}

void Pivot::OnCollision(Object* obj) { 
    if (obj->Type() == INIMIGO) {
        bateu = true;
    }
}


// ---------------------------------------------------------------------------------

Pivot::~Pivot()
{
}

// ---------------------------------------------------------------------------------

