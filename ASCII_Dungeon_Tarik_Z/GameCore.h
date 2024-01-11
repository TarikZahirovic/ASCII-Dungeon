#pragma once
#include <string>
#include <vector> 

namespace TextGame
{
	struct PlayerState
	{
		bool WantsToExit;
		bool WantsDescription;
		bool WantsInventoryListed;
		bool bone, potion, sneakers, phone;
		bool bell1, bell2, escape;
		int x, y;
		int CurrentRoomIndex;
	};

	struct RoomData
	{
		std::string Name;
		std::string Description;
		std::string layout;
		int length, width;
		int northID, eastID;
		int southID, westID;
	};

	struct WorldState
	{
		std::vector<RoomData> rooms;
	};

	void InitializeGame(PlayerState& playerState, WorldState& worldState);
	void GetInput(PlayerState& playerState, const WorldState& worldState);
	void RenderGame(const PlayerState& playerState, const WorldState& worldState);
	void UpdateGame(PlayerState& playerState, WorldState& worldState);
	void CleanupGame(PlayerState& playerState, WorldState& worldState);
}