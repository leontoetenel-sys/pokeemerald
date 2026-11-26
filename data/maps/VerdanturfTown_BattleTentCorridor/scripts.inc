VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_VERDANTURF_TENT_CORRIDOR_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "Aan welke CONTEST doe je mee?\n"
	.string "Wil je een tip?\p"
	.string "Bij een CUTE CONTEST kijken ze\n"
	.string "in de eerste ronde volgens mij\l"
	.string "niet alleen naar schattigheid.\p"
	.string "Bedenk hoe je je Pokémon\n"
	.string "nog beter kunt opvoeden.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "Ik heb mijn Pokémon opgevoed\n"
	.string "om heel schattig te zijn.\p"
	.string "Nu blijkt dat er zelfs een\n"
	.string "CONTEST voor schattigheid is!\p"
	.string "Wat fijn dat ik mijn Pokémon\n"
	.string "met zoveel liefde heb verzorgd!$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mijn Pokémon is geweldig!\p"
	.string "Cool, stoer, mooi, schattig\n"
	.string "en slim. Alles tegelijk!\p"
	.string "Ik kan vast elke CONTEST winnen.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "POKéMON CONTESTS\n"
	.string "NORMAL RANK-PODIUM!$"

