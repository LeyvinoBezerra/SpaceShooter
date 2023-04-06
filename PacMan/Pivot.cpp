/**********************************************************************************
// Pivot (C�digo Fonte)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Ponto de mudan�a de dire��o para o jogador e fantasmas
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

