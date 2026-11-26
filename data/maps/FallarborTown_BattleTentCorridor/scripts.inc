FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_OnFrame
	.byte 0

FallarborTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, FallarborTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_FALLARBOR_TENT_CORRIDOR_ATTENDANT, FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement LOCALID_PLAYER, FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_FALLARBOR_TOWN_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	releaseall
	end

FallarborTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
	.string "De eerste ronde gaat best goed,\n"
	.string "maar bij de appeals winnen we nooit.\p"
	.string "Misschien moet ik beter kijken\n"
	.string "wat de andere deelnemers doen.$"

@ Unused
FallarborTown_ContestHall_Text_MonAllTheseRibbons:
	.string "Kijk eens! Mijn Pokémon heeft\n"
	.string "al deze RIBBONS gewonnen!\p"
	.string "Hebben jouw Pokémon er ook?\n"
	.string "Je kunt ze op je PokéNav bekijken.$"

@ Unused
FallarborTown_ContestHall_Text_CantWinEverywhere:
	.string "Ik kan geen Gymleiders verslaan...\p"
	.string "Ik win geen enkele CONTEST...\p"
	.string "Ik ben overal geweest,\n"
	.string "maar het helpt helemaal niets.$"

@ Unused
FallarborTown_ContestHall_Text_SuperRankStage:
	.string "POKéMON CONTESTS\n"
	.string "SUPER RANK-PODIUM!$"

