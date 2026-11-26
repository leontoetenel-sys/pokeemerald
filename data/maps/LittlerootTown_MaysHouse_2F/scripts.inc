LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
	call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckShouldUpdateMayPos::
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos
	goto_if_ge VAR_BIRCH_LAB_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos

LittlerootTown_MaysHouse_2F_EventScript_TryUpdateMayPos::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_Ret
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVALS_HOUSE_2F_RIVAL, 8, 2
	setobjectmovementtype LOCALID_RIVALS_HOUSE_2F_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay::
	delay 10
	addobject LOCALID_RIVALS_HOUSE_2F_RIVAL
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, Common_Movement_Delay48
	delay 10
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	applywaitmovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_Brendan
	end

RivalsHouse_2F_EventScript_May::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_Brendan::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	applywaitmovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	checkplayergender
	call_if_eq VAR_RESULT, MALE, RivalsHouse_2F_EventScript_MayPostLilycove
	call_if_eq VAR_RESULT, FEMALE, RivalsHouse_2F_EventScript_BrendanPostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_MayPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "Huh? Wie... Wie ben jij?\p"
	.string "O, jij bent {PLAYER}!\n"
	.string "Je bent vandaag verhuisd.\p"
	.string "Ik ben MAY.\n"
	.string "Leuk je te ontmoeten!\p"
	.string "Ik droom ervan vrienden te worden\n"
	.string "met Pokémon over de hele wereld.\p"
	.string "Mijn vader, PROF. BIRCH,\n"
	.string "heeft me over jou verteld.\p"
	.string "Ik hoopte dat je aardig zou zijn\n"
	.string "en dat we vrienden konden worden.\p"
	.string "Hihi, we kennen elkaar net!\p"
	.string "O nee, vergeten! Ik zou papa\n"
	.string "helpen wilde Pokémon te vangen!\p"
	.string "Tot later, {PLAYER}!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "Pokémon helemaal hersteld!\n"
	.string "Spullen klaar, en...$"

RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "Hé! Wie ben jij?\p"
	.string "O, jij bent {PLAYER}!\n"
	.string "Je woont nu naast ons, toch?\p"
	.string "Ik wist niet dat je een meisje was.\p"
	.string "Papa, PROF. BIRCH, zei dat je\n"
	.string "kind van een GYM LEADER bent.\l"
	.string "Ik dacht dat je een jongen was.\p"
	.string "Ik ben BRENDAN. Hoi, buurmeisje!\p"
	.string "Hé, heb je nog geen Pokémon?\n"
	.string "Zal ik er eentje voor je vangen?\p"
	.string "O nee, vergeten! Ik zou papa\n"
	.string "helpen wilde Pokémon te vangen.\p"
	.string "Een andere keer, goed?$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "Pokémon helemaal hersteld...\n"
	.string "Spullen ingepakt, en...$"

RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "Dat is de POKé BALL van {RIVAL}!\p"
	.string "Laat die maar liggen.$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "MAY: {PLAYER}!\p"
	.string "Ik bekeek net mijn POKéDEX.\p"
	.string "Ik heb nog veel Pokémon gezien\n"
	.string "die ik niet gevangen heb.\p"
	.string "En veel kunnen nog evolueren.\p"
	.string "Waar zal ik nu eens Pokémon\n"
	.string "gaan vangen?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "MAY: Waar zal ik nu eens\n"
	.string "Pokémon gaan vangen?\p"
	.string "Grappig als we elkaar tegenkomen,\n"
	.string "{PLAYER}!$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "BRENDAN: Hé, {PLAYER}.\p"
	.string "Ik bekeek net mijn POKéDEX.\p"
	.string "Ik moet nog veel Pokémon vangen,\n"
	.string "maar het ziet er al goed uit.\p"
	.string "Nu krijg ik weer zin\n"
	.string "om op pad te gaan!$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "BRENDAN: Ik weet nog niet waar\n"
	.string "ik nu Pokémon ga vangen.\p"
	.string "Hé, {PLAYER}, als ik je onderweg\n"
	.string "tegenkom, kunnen we een duel\l"
	.string "houden als je wilt.$"
