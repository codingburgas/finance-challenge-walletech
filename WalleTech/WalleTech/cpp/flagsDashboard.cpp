#include "../Include/Dashboad.h"

void flagsDashboard(Textures*t)
{
	bool hoverPlus = CheckCollisionPointRec(GetMousePosition(), { 598, 252, (float)t->blankPlusMinus.width, (float)t->blankPlusMinus.height });  // is true if you hover on plus, same for minus
	bool hoverMinus = CheckCollisionPointRec(GetMousePosition(), { 670, 252, (float)t->blankPlusMinus.width, (float)t->blankPlusMinus.height });

	if (hoverPlus && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		flagPlus = 1; // change the flag to true when you turn plus button on, same applies for flagMinus		
	}
	if (hoverMinus && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		flagMinus = 1;// change the flag to true when you turn minus button on
	}
}
// blankPlusMinus, 598, 252,  // plus
// blankPlusMinus, 670, 252,  // minus