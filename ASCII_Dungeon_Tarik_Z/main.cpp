#include <stdlib.h>
#include "GameCore.h"

using namespace TextGame;

int main()
{
	PlayerState playerState = {};
	WorldState worldState = {};

	InitializeGame(playerState, worldState);

	while (!playerState.WantsToExit)
	{
		RenderGame(playerState, worldState);
		UpdateGame(playerState, worldState);
		GetInput(playerState, worldState);
	}

	CleanupGame(playerState, worldState);

	system("pause");

	return 0;
}