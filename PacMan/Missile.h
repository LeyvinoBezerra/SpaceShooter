// Descri��o:   M�sseis do jogo

#ifndef _SPACE_MISSILE_H_
#define _SPACE_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "Image.h"
#include "Player.h"

class Missile : public Object {
private:

	//Player* player;
	Sprite* sprite;
	//float velocidade;

public:
	float velocidade;

	Missile();
	~Missile();
	float Width();	//largura
	float Height();	//altura

	void OnCollision(Object* obj); // para tratameto de colis�o
	void Update();
	void Draw();
};


inline float Missile::Width()
{
	return float(sprite->Width());
}

inline float Missile::Height()
{
	return float(sprite->Height());
}

inline void Missile::Draw() {
	sprite->Draw(x, y, z);
}

#endif