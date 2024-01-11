#include "GameCore.h"
#include "CommandParser.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <conio.h>

namespace TextGame
{

	RoomData CreateRoom(int length, int width, int northID, int eastID, int southID, int westID,
		const std::string& inName, const std::string& inDescription)
	{
		RoomData room = {};
		room.Name = inName;
		room.Description = inDescription;
		room.length = length;
		room.width = width;
		room.layout = "";
		room.northID = northID;
		room.eastID = eastID;
		room.southID = southID;
		room.westID = westID;

		return room;
	}

	void InitializeGame(PlayerState& playerState, WorldState& worldState)
	{
		printf("You have entered...\n");
		printf("The Slumbering Crypt by Tarik Zahirovic\n\n");
		printf("Ring the two Sacred Bells, but beware, you are probably not alone...\n\n");

		playerState.WantsDescription = true;
		playerState.CurrentRoomIndex = 0;
		playerState.bone = true;
		playerState.potion = false;
		playerState.sneakers = false;
		playerState.phone = false;
		playerState.bell1 = false;
		playerState.bell2 = false;
		playerState.escape = false;
		playerState.x = 4;
		playerState.y = 5;

		worldState.rooms.push_back(CreateRoom(7, 10, 3, 20, 20, 20, "Entrance", 
			"This is where you entered the crypt, "
			"the door you came in through is closed and seems impossible to open.\nA cheerful undead is in the corner, calling you over."));

		worldState.rooms.push_back(CreateRoom(7, 14, 20, 2, 20, 20, "Potion Room",
			"A room filled with dusty bookcases and, more importantly,\n"
			"a wide variety of potions and magical concoctions."));

		worldState.rooms.push_back(CreateRoom(6, 10, 20, 3, 20, 1, "Undead Chamber",
			"The walls around you are full of holes in them, and "
			"upon closer inspection you realize each has a corpse inside of it.\nIn the corner of the room, a pile of bones "
			"that clearly used to be a human skeleton, with a rusted sword next to it.\nYou might be imagining things but "
			"you could've sworn you saw one of the bones moving. Best not get too close."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 5, 20, 0, 2, "Dusty Hallway",
			"An otherwise unremarkable room, with three doors on each side "
			"except the east, where a blank, unassuming wall sits.\nNothing to see here."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 7, 20, 20, 20, "Undead Merchant",
			"Surely the most nicely decorated chamber in the entire crypt, "
			"which isn't saying much, but still!\nThe floor and walls are relatively clean and various items are strewn across "
			"a table on the opposite side from the door.\nA skeleton merchant sits behind the table and glares at you menacingly."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 10, 6, 3, 20, "Crumbling Chamber",
			"Everything is falling apart here in every sense of the word!\n"
			"There are gaps in the floor, leading to unknown depths, and a few bone piles are found scattered here and there..."));
		
		worldState.rooms.push_back(CreateRoom(5, 14, 20, 7, 20, 5, "Empty Hallway",
			"An otherwise unremarkable room, merely connecting two other ones."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 11, 20, 4, 6, "Torchlit Chamber",
			"Hard to believe there are still torches burning down here, but then "
			"again, it's probably not the weirdest thing in this place.\nThere a relatively well-preserved draugr in the middle of the room, "
			"and with the light shining on him, you can clearly see his chest breathing.\nThe breaths are raspy and dusty..."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 13, 9, 20, 20, "Embalming Room",
			"A rancid smells enters your nose the moment you come into this place, "
			"smelling of rotting flesh and dried blood.\nYou can make out a few tables in the darkness, some of them with a body "
			"on top.\nThis was clearly a room designated for preparing the deceased to be put to eternal rest.\nThe undead are bound to be "
			"aplenty in here..."));
		
		worldState.rooms.push_back(CreateRoom(5, 14, 20, 10, 20, 8, "Empty Hallway",
			"An otherwise unremarkable room, merely connecting two other ones."));
		
		worldState.rooms.push_back(CreateRoom(7, 12, 14, 20, 5, 9, "Storage Room",
			"Floor to ceiling this place is loaded with boxes and barrels!\nYou pick "
			"one to investigate, but the moment it opens you nearly vomit from the intense stench coming from it.\nYou've lost "
			"your appetite so you move on, the stench still stuck in your nose..."));
		
		worldState.rooms.push_back(CreateRoom(7, 8, 16, 20, 7, 20, "Empty Hallway",
			"An otherwise unremarkable room, merely connecting two other ones."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 18, 20, 20, 20, "Southern Bell Room",
			"The room looks like the average crypt room you've come to expect by now,\n"
			"with the exception of a giant bronze bell in the middle of it."));
		
		worldState.rooms.push_back(CreateRoom(6, 10, 20, 20, 8, 20, "Altar Room",
			"A gory scene awaits you here. Blood lines every surface of this room, "
			"even the ceiling.\nThere doesn't seem to be any undead in here, but a sacrificial altar is found at the northern end of the room."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 20, 15, 10, 20, "Cage Room",
			"Littered across this chamber are cages of various sizes, some of them holding "
			"what you can only assume are unfortunate souls that were brought here to be sacrificed.\nAlthough probably once locked, "
			"the cages have completely rusted and the doors of them now sit ajar, waiting for the captors within to escape after so much time."));
		
		worldState.rooms.push_back(CreateRoom(3, 14, 20, 16, 20, 14, "Empty Hallway",
			"An otherwise unremarkable room, merely connecting two other ones."));
		
		worldState.rooms.push_back(CreateRoom(7, 10, 20, 17, 11, 15, "Gateway Chamber",
			"A tall, imposing doorway stands in the eastern end of the room, the skeleton "
			"merchant smoking his pipe next to it."));
		
		worldState.rooms.push_back(CreateRoom(5, 14, 20, 18, 20, 16, "Undead Army",
			"An otherwise unremarkable room, merely connecting two other ones, except\n"
			"this one is lined with undead soldiers from front to back. All are unmoving... for now."));
		
		worldState.rooms.push_back(CreateRoom(5, 14, 19, 20, 12, 17, "Undead Barracks",
			"Seemingly what used to be a campsite has overtime turned into a sort of "
			"outpost manned by the undead skeletons and draugrs in this place.\nTwo doors on opposite sides of the room, going north and south."));
		
		worldState.rooms.push_back(CreateRoom(7, 14, 20, 20, 18, 20, "Northern Bell Room",
			"The room looks like the average crypt room you've come to expect by now,\n"
			"with the exception of a giant bronze bell in the middle of it."));

		//Room layouts							This is the map of the dungeon
		worldState.rooms[0].layout =			// 							  19
			"\t____..____\n"					//13	  14 - 15 - 16 - 17 - 18
			"\t|........|\n"					//8 - 9 - 10		11		  12
			"\t|.......Y|\n"					//		  5 - 6  -  7
			"\t|........|\n"					//1 - 2 - 3			4
			"\t|........|\n"					//		  0
			"\t|........|\n"
			"\t|___~~___|\n"; //Entrance

		worldState.rooms[1].layout =
			"\t______________\n"
			"\t|.OOOOOOOO...|\n"
			"\t|.O.i....O...|\n"
			"\t|.OOO..OOO....\n"
			"\t|............|\n"
			"\t|............|\n"
			"\t|____________|\n"; //Potion Room

		worldState.rooms[2].layout =
			"\t__________\n"
			"\t|X.......|\n"
			"\t|........|\n"
			"\t..........\n"
			"\t|........|\n"
			"\t|________|\n"; //Undead Chamber

		worldState.rooms[3].layout =
			"\t______..______\n"
			"\t|............|\n"
			"\t|............|\n"
			"\t.............|\n"
			"\t|............|\n"
			"\t|............|\n"
			"\t|_____.._____|\n"; //Dusty Hallway

		worldState.rooms[4].layout =
			"\t______..______\n"
			"\t|O..........O|\n"
			"\t|............|\n"
			"\t|.......OOOOO|\n"
			"\t|O......O.Y..|\n"
			"\t|...OO.......|\n"
			"\t|____________|\n"; //Undead Merchant

		worldState.rooms[5].layout =
			"\t______..______\n"
			"\t|.X.........O|\n"
			"\t|OOOO...O....|\n"
			"\t|...O...X.....\n"
			"\t|.X.....OOOOO|\n"
			"\t|OO.......OOO|\n"
			"\t|_____.._____|\n"; //Crumbling Chamber

		worldState.rooms[6].layout =
			"\t______________\n"
			"\t|............|\n"
			"\t..............\n"
			"\t|............|\n"
			"\t|____________|\n"; //Empty Hallway

		worldState.rooms[7].layout =
			"\t______..______\n"
			"\t|............|\n"
			"\t|.....O.O....|\n"
			"\t.......X.....|\n"
			"\t|.....O.O....|\n"
			"\t|............|\n"
			"\t|_____.._____|\n"; //Torchlit Chamber

		worldState.rooms[8].layout =
			"\t______..______\n"
			"\t|O.X......X..|\n"
			"\t|O...........|\n"
			"\t|O..X.........\n"
			"\t|O...........|\n"
			"\t|O....X..X...|\n"
			"\t|____________|\n"; //Embalming Room

		worldState.rooms[9].layout =
			"\t______________\n"
			"\t|............|\n"
			"\t..............\n"
			"\t|............|\n"
			"\t|____________|\n"; //Empty Hallway

		worldState.rooms[10].layout =
			"\t_____.._____\n"
			"\t|OOOO..OOOO|\n"
			"\t|O.......OO|\n"
			"\t.....OO...O|\n"
			"\t|OO......OO|\n"
			"\t|OOOO..OOOO|\n"
			"\t|____..____|\n"; //Storage Room

		worldState.rooms[11].layout =
			"\t___..___\n"
			"\t|......|\n"
			"\t|......|\n"
			"\t|......|\n"
			"\t|......|\n"
			"\t|......|\n"
			"\t|__..__|\n"; //Empty Hallway

		worldState.rooms[12].layout =
			"\t______..______\n"
			"\t|............|\n"
			"\t|............|\n"
			"\t|.....BB.....|\n"
			"\t|.....BB.....|\n"
			"\t|............|\n"
			"\t|____________|\n"; //Southern Bell Room

		worldState.rooms[13].layout =
			"\t__________\n"
			"\t|..OOOO..|\n"
			"\t|..O.iO..|\n"
			"\t|........|\n"
			"\t|........|\n"
			"\t|___..___|\n"; //Altar Room

		worldState.rooms[14].layout =
			"\t______________\n"
			"\t|XO...X....OX|\n"
			"\t|O..........O|\n"
			"\t|..O..........\n"
			"\t|.OXO........|\n"
			"\t|..O........X|\n"
			"\t|_____.._____|\n"; //Cage Room

		worldState.rooms[15].layout =
			"\t______________\n"
			"\t..............\n"
			"\t|____________|\n"; //Empty Hallway

		worldState.rooms[16].layout =
			"\t__________\n"
			"\t|........|\n"
			"\t|.........\n"
			"\t..........\n"
			"\t|.........\n"
			"\t|.......Y|\n"
			"\t|___..___|\n"; //Gateway Chamber

		worldState.rooms[17].layout =
			"\t______________\n"
			"\t|..XXXXXXXXXX|\n"
			"\t..............\n"
			"\t|..XXXXXXXXXX|\n"
			"\t|____________|\n"; //Undead Army

		worldState.rooms[18].layout =
			"\t______..______\n"
			"\t|X...X..X...X|\n"
			"\t..........X.X|\n"
			"\t|X...X..X...X|\n"
			"\t|_____.._____|\n"; //Undead Barracks

		worldState.rooms[19].layout =
			"\t______________\n"
			"\t|............|\n"
			"\t|.....BB.....|\n"
			"\t|.....BB.....|\n"
			"\t|............|\n"
			"\t|............|\n"
			"\t|_____.._____|\n"; //Northern Bell Room

	}

	//Main function for getting the input and acting accordingly
	void GetInput(PlayerState& playerState, const WorldState& worldState)
	{
		playerState.WantsToExit = false;
		playerState.WantsDescription = false;
		playerState.WantsInventoryListed = false;
		
		printf("What do you do?\n");
		printf("> ");

		//Using W/A/S/D keys to move around instantly
		TextAdventureCommand command = {};
		command.Verb = "";
		while (command.Verb == "") {
			char key = _getch();

			if (key == 'W' || key == 'w') command.Verb = "n";
			else if (key == 'D' || key == 'd') command.Verb = "e";
			else if (key == 'S' || key == 's') command.Verb = "s";
			else if (key == 'A' || key == 'a') command.Verb = "w";
			else if (key == 'C' || key == 'c') command.Verb = "commandMode";
		}

		//Checking if the player wants to manually enter a command
		if (command.Verb == "commandMode") {
			printf("COMMAND MODE : ");
			command = ParseAdventureCommand();
		}

		RoomData current = worldState.rooms[playerState.CurrentRoomIndex];

		//For quitting the game
		if (command.Verb == "quit")
		{
			playerState.WantsToExit = true;
		}

		//Checks for going up/north
		else if (command.Verb == "north" || command.Verb == "n")
		{
			if (playerState.y == 0) {
				playerState.CurrentRoomIndex = current.northID;
				current = worldState.rooms[playerState.CurrentRoomIndex];
				playerState.y = current.length - 1;
				playerState.x = current.width / 2;
			}
			if (current.layout[(playerState.y - 1) * (current.width + 2) + playerState.x + 1] != '_'
				&& current.layout[(playerState.y - 1) * (current.width + 2) + playerState.x + 1] != '~'
				&& current.layout[(playerState.y - 1) * (current.width + 2) + playerState.x + 1] != 'O') {
				playerState.y--;
				if (playerState.y == 0) {
					playerState.CurrentRoomIndex = current.northID;
					current = worldState.rooms[playerState.CurrentRoomIndex];
					playerState.y = current.length - 1;
					playerState.x = current.width / 2;
				}
			}
		}

		//Check for going down/south
		else if (command.Verb == "south" || command.Verb == "s")
		{
			if (playerState.y == current.length - 1) {
				playerState.CurrentRoomIndex = current.southID;
				current = worldState.rooms[playerState.CurrentRoomIndex];
				playerState.y = 0;
				playerState.x = current.width / 2;
			}
			if (current.layout[(playerState.y + 1) * (current.width + 2) + playerState.x + 1] != '_'
				&& current.layout[(playerState.y + 1) * (current.width + 2) + playerState.x + 1] != '~'
				&& current.layout[(playerState.y + 1) * (current.width + 2) + playerState.x + 1] != 'O') {
				playerState.y++;
				if (playerState.y == current.length) {
					playerState.CurrentRoomIndex = current.southID;
					current = worldState.rooms[playerState.CurrentRoomIndex];
					playerState.y = 0;
					playerState.x = current.width / 2;
				}
			}
		}

		//Checks for going left/west
		else if (command.Verb == "west" || command.Verb == "w")
		{
			if (playerState.x == 0) {
				playerState.CurrentRoomIndex = current.westID;
				current = worldState.rooms[playerState.CurrentRoomIndex];
				playerState.y = current.length / 2;
				playerState.x = current.width - 1;
			}
			if (current.layout[playerState.y * (current.width + 2) + playerState.x] != '|'
				&& current.layout[playerState.y * (current.width + 2) + playerState.x] != '~'
				&& current.layout[playerState.y * (current.width + 2) + playerState.x] != 'O') {
				playerState.x--;
				if (playerState.x == 0) {
					playerState.CurrentRoomIndex = current.westID;
					current = worldState.rooms[playerState.CurrentRoomIndex];
					playerState.y = current.length / 2;
					playerState.x = current.width - 1;
				}
			}
		}

		//Checks for going right/east
		else if (command.Verb == "east" || command.Verb == "e")
		{
			if (playerState.x == current.width - 1) {
				playerState.CurrentRoomIndex = current.eastID;
				current = worldState.rooms[playerState.CurrentRoomIndex];
				playerState.y = current.length / 2;
				playerState.x = 0;
			}
			if (current.layout[playerState.y * (current.width + 2) + playerState.x + 2] != '|'
				&& current.layout[playerState.y * (current.width + 2) + playerState.x + 2] != '~'
				&& current.layout[playerState.y * (current.width + 2) + playerState.x + 2] != 'O') {
				playerState.x++;
				if (playerState.x == current.width) {
					playerState.CurrentRoomIndex = current.eastID;
					current = worldState.rooms[playerState.CurrentRoomIndex];
					playerState.y = current.length / 2;
					playerState.x = current.width - 1;
				}
			}
		}

		//For looking around the current room, shows description
		else if (command.Verb == "look")
		{
			playerState.WantsDescription = true;
		}

		//For showing inventory
		else if (command.Verb == "inventory" || command.Verb == "inv")
		{
			playerState.WantsInventoryListed = true;
		}

		//For talking to friendly NPCs
		else if (command.Verb == "talk")
		{
			if (current.layout[playerState.y * (current.width + 2) + playerState.x + 1] == 'Y') {
				if (playerState.CurrentRoomIndex == 0) {
					printf("Hello there! Seems you're trapped, and need to get out. I'll tell you what to do just because I'm so nice!\n"
						"You need to traverse this here dungeon and ring the two bells at the end, this will open the door you came in through.\n"
						"Careful though, there's plenty of undead down here, most of them are asleep and won't give you any trouble\n- "
						"unless you make the mistake of waking them up!\nI see you're unarmed, weird flex but ok.\nThere's also some useful "
						"items you can find to help you complete your quest,\nand there's bound to be more friendly skeletons down here - "
						"we're all naturally cheery due to our funny bone!\nAnyway good luck, and also I have short term memory loss so if "
						"you talk to me again\nI'll just repeat everything I just said word for word...");
				}
				else if (playerState.CurrentRoomIndex == 4) {
					printf("Let me guess, you got stuck here and need to ring the bells like that senile old fool at the entrance told you?\n"
						"Save yourself the trouble and just go die in some corner already, you'll never get past the Undead army up ahead!\n"
						"Help you? HAH! Now why in the world would I do... what is that bone you're holding?\n"
						"OH MY GOODNESS!!! That's one of MY bones! That wishbone you have! Oh won't you part with my lovely wishbone so\n"
						"that I may be complete again? Help? Oh, yes, yes, here is something to help you with the Undead Army.\n\n"
						"The merchant inserts the bone into his skeleton body in a way that makes absolutely no sense, but he's ecstatic all\n"
						"the same, so I guess it all worked out.");
					playerState.bone = false;
					playerState.sneakers = true;
				}
				else if (playerState.CurrentRoomIndex == 16) {
					printf("Hold it! Up ahead is the Undead Army! You best be prepared to either fight your way through all of them,\n"
						"or somehow sneak past them all! Best of luck and hope you have something to help you!\n");
				}
				else { printf("Now is not the time to be talking to yourself!\n"); }
			}
		}

		//For ringing the bells
		else if (command.Verb == "ring") {
			if (current.layout[playerState.y * (current.width + 2) + playerState.x + 1] == 'B') {
				if (playerState.CurrentRoomIndex == 12 || playerState.CurrentRoomIndex == 19) {
					printf("You ring the bell with all your might, and a thunderous echo goes winding down the hallways behind you!\n"
						"You except the Undead Army to be right behind you when you finish, but nobody comes. In fact, it's dead silent after\n"
						"the bell finishes tolling.");
					if (playerState.bell1 == true) { playerState.bell2 = true; }
					playerState.bell1 = true;
				}
			}
		}

		//Prints all available commands and a legend to help player
		else if (command.Verb == "help")
		{
			printf("Command List: look, quit, inventory, get, talk, ring, north, south, west, east\n");
			printf("Key:\n");
			printf("  @ - Player\n");
			printf("  B - Bell\n");
			printf("  i - Item\n");
			printf("  . - Floor\n");
			printf("  Y - Friend\n");
			printf("  X - Enemy\n");
			printf("  | or _ - Wall\n");
			printf("  O - Obstacle / Furniture\n");
			printf("  ~ - Locked Door\n");
		}

		//Unknown command entered
		else
		{
			printf("I don't understand\n");
		}

		//Ending game if player steps onto enemy tile
		if (current.layout[playerState.y * (current.width + 2) + playerState.x + 1] == 'X') {
			printf("You somehow managed to fall over onto one of the undead and woke them all up. Idiot.\n"
				"They swarm you and kill you in a particularly brutal fashion...\n");
			playerState.WantsToExit = true;
		}

		//Ending game if player gets too close to an enemy
		else if (!playerState.sneakers && playerState.y < current.length - 1 && playerState.y > 0 
			&& playerState.x < current.width - 1 && playerState.x > 0) {
			if (current.layout[(playerState.y - 1) * (current.width + 2) + playerState.x + 1] == 'X'
				|| current.layout[(playerState.y + 1) * (current.width + 2) + playerState.x + 1] == 'X'
				|| current.layout[playerState.y * (current.width + 2) + playerState.x] == 'X'
				|| current.layout[playerState.y * (current.width + 2) + playerState.x + 2] == 'X') {
				printf("You were trying to be quiet not to wake any of the undead, but you got a bit too close to one of them!\n"
					"It rises and makes a loud gutteral noise, deafening you in the process. Good thing so at least you\n"
				"didn't have to listen to your own wailing and screams as the rest of the now-awoken undead ripped you to shreds...\n");
				playerState.WantsToExit = true;
			}
		}

		//Auto-pickup for items
		if (current.layout[playerState.y * (current.width + 2) + playerState.x + 1] == 'i') {
			if (playerState.CurrentRoomIndex == 1) {
				playerState.potion = true;
				printf("You pick up the most harmless looking potion you can find. Turns out it's an invisibility potion! "
					"Might come in handy later...\n");
				current.layout[2 * (current.width) + 6] = '.';
			}
			else if (playerState.CurrentRoomIndex == 4) {
				playerState.sneakers = true;
				printf("You grab the sneakers from their box, they're practically new! You put them on and instantly feel much sneakier...\n");
				current.layout[playerState.y * (current.width + 2) + playerState.x + 1] = '.';
			}
			else if (playerState.CurrentRoomIndex == 13) {
				playerState.phone = true;
				printf("In between all the blood and gore around you, you spot a glimmer of something. It's a modern smartphone!"
				"You've been needing a new one for a while now!\n");
				current.layout[playerState.y * (current.width + 2) + playerState.x + 1] = 'O';
			}
		}

		//When both bells are rung
		if (playerState.bell1 && playerState.bell2) {
			printf("\nThe floor and walls around you begin shaking violently, slowly crumbling!\nYou take this as a sign that"
				"the door is now open and you can leave!\nYou prepare yourself and start running back to the exit as fast as you can, "
				"you don't have much time left!\n");
			if (!playerState.potion) {
				printf("Just as you are about to run out of the room, the Undead Army comes pouring in, overwhelming you insantly!\n"
					"If only you had prepared better...");
				playerState.WantsToExit = true;
			}
			else {
				printf("As you prepare to run out, you drink your invisibility potion to aid you in evading the oncoming Undead Army.\n"
					"The potion takes effect just as they start pouring into the room, but you manage to sneak around them in the chaos\n"
					"and make a mad dash for the exit!");
				playerState.potion = false;
			}
			playerState.bell1 = false;
			playerState.bell2 = false;
			playerState.escape = true;
		}

		//Win condition when exiting the dungeon
		if (playerState.CurrentRoomIndex == 0 && playerState.escape) {
			printf("Completely out of breath, you somehow climb through the crumbling debris and into the daylight outside.\n");
			if (playerState.phone) {
				printf("You dust yourself off and look back, happy that you made it out alive,\n"
					"but even happier since you got a new pho - ... \nIt broke. Makes sense, these things aren't exactly built for\n"
					"dungeon crawling. Maybe the real treasure was the crazy skeleton friends we made along the way!\n");
			}
			else {
				printf("You stagger to your feet and look back, surprised how you even survived that.\n"
				"Either way, you dust yourself off and head out, off to some other last-minute improvised adventure!\n");
			}
			playerState.WantsToExit = true;
		}
		printf("\n");
	}

	//Prints out the current state of the game
	void RenderGame(const PlayerState& playerState, const WorldState& worldState)
	{
		RoomData currRoom = worldState.rooms[playerState.CurrentRoomIndex];
		currRoom.layout[playerState.y * (currRoom.width + 2) + playerState.x + 1] = '@';
		printf("%s\n\n", currRoom.layout.c_str());

		if (playerState.WantsDescription)
		{
			printf("================================================\n");
			printf("LOCATION: %s\n", currRoom.Name.c_str());
			printf("%s\n\n", currRoom.Description.c_str());
			printf("%s\n\n", currRoom.layout.c_str());
		}
		else if (playerState.WantsInventoryListed)
		{
			printf("================================================\n");
			printf("INVENTORY:\n");
			if (playerState.bone) { printf("Wishbone\n"); }
			if (playerState.potion) { printf("Invisibility Potion\n"); }
			if (playerState.sneakers) { printf("Sneakers\n"); }
			if (playerState.phone) { printf("Cellphone\n"); }
			printf("\n");
		}
	}

	//Updating the game world after a command
	void UpdateGame(PlayerState& playerState, WorldState& worldState)
	{
		RoomData& currRoom = worldState.rooms[playerState.CurrentRoomIndex];
		if (currRoom.layout[playerState.y * (currRoom.width + 2) + playerState.x + 1] == 'i') {
			currRoom.layout[playerState.y * (currRoom.width + 2) + playerState.x + 1] = '.';
		}

	}

	//*Cleans up the map after the game is over
	void CleanupGame(PlayerState& playerState, WorldState& worldState)
	{
		worldState.rooms.clear();
	}
}