Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER_END
	showobjectat LOCALID_TRICK_MASTER_END, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_FacePlayer
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterSpin
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouse_Movement_TrickMasterJumpAway
	removeobject LOCALID_TRICK_MASTER_END
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterDown
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterUp
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterLeft
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_WalkInPlaceFasterRight
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER_END, DIR_WEST
	playse SE_PIN
	applywaitmovement LOCALID_TRICK_MASTER_END, Common_Movement_ExclamationMark
	delay 20
	applywaitmovement LOCALID_TRICK_MASTER_END, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	playse SE_M_EXPLOSION
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	delay 4
	turnobject LOCALID_TRICK_MASTER_END, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aah!\n"
	.string "Heb je me gevonden?\l"
	.string "Hmmm... Je bent scherp!$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Ik was de hele nacht bezig\n"
	.string "met het planten van die bomen...\p"
	.string "Je bent bijna zo goed als ik!\n"
	.string "Nog zes plaatsen te gaan!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Ik maakte de hele nacht\n"
	.string "aan dat doolhof...\p"
	.string "Je bent bijna zo goed als ik!\n"
	.string "Nog vijf plaatsen te gaan!$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Ik maakte de hele nacht\n"
	.string "aan die wandpanelen...\p"
	.string "Je bent bijna zo goed als ik!\n"
	.string "Nog vier plaatsen te gaan!$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Ik duwde de hele nacht\n"
	.string "met die rotsblokken...\p"
	.string "Je bent bijna zo goed als ik!\n"
	.string "Nog drie plaatsen te gaan!$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Ik maakte een nacht MECHADOLLS\n"
	.string "en bedacht daarna de quiz...\p"
	.string "Je bent bijna zo goed als ik!\n"
	.string "Nog twee plaatsen te gaan!$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Ik installeerde de hele nacht\n"
	.string "die deuren...\p"
	.string "Je bent bijna zo goed als ik!$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Ik plaatste de hele nacht pijlen...\p"
	.string "Je bent net zo goed als ik!$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Ik poetste de hele nacht vloeren...\p"
	.string "Je bent beter dan ik!\n"
	.string "Misschien...$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "W-wat nu? Mijn ideeën voor\n"
	.string "nieuwe trucs zijn op...\p"
	.string "Misschien moet ik op reis om\n"
	.string "nieuwe trucs te bedenken...$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Ik geef het niet graag toe,\n"
	.string "maar jij hebt me verslagen!\p"
	.string "Je komt vast steeds terug\n"
	.string "omdat ik zo geweldig ben!\p"
	.string "Maar dat heeft niets met\n"
	.string "mijn verlies te maken!\p"
	.string "Voor onze vriendschap moet\n"
	.string "je een aandenken aannemen!\p"
	.string "Je mag kiezen uit RED TENT\n"
	.string "en BLUE TENT. Welke wil je?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Wat? Je PC zit vol?\p"
	.string "Kom dan later maar terug.\n"
	.string "Ik ben immers heel aardig!$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "... ... ... ... ... ...\p"
	.string "Ik ga op ontdekkingsreis,\n"
	.string "op zoek naar nieuwe trucs.\p"
	.string "Ik hoop dat je me ooit weer\n"
	.string "komt vermaken.\p"
	.string "En nu, vaarwel!$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Goed!\n"
	.string "Je hebt deze beloning verdiend!$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Wat? Heb je geen plek?\n"
	.string "Wat draag jij allemaal mee?\p"
	.string "Goed dan, ik bewaar je\n"
	.string "beloning tot later.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Veeg die grijns van je gezicht!\n"
	.string "Je hebt nog niet gewonnen!\p"
	.string "Ik bedenk nieuwe trucs om\n"
	.string "je in de war te brengen.\p"
	.string "Kom terug voor de volgende\n"
	.string "spannende uitdaging!$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Hé! Negeer je me nu?\n"
	.string "Dat breekt mijn hart!$"

