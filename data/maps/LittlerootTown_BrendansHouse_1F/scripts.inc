LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 8, 4
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 4, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 9, 8
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_MAY, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_PLAYERS_HOUSE_1F_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_Delay48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_PLAYERS_HOUSE_1F_MOM
	setvar VAR_0x8005, MALE
	applywaitmovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	delay 30
	playse SE_PIN
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applywaitmovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMA: Kijk, {PLAYER}!\n"
	.string "Mooi hier, hè?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "De Pokémon van de verhuizers\n"
	.string "doen al het zware werk.\p"
	.string "Wat handig!\p"
	.string "Je kamer is boven, {PLAYER}.\n"
	.string "Ga maar kijken!\p"
	.string "Papa heeft een nieuwe klok\n"
	.string "voor je gekocht.\l"
	.string "Vergeet hem niet goed te zetten!$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMA: Nou, {PLAYER}?\p"
	.string "Wil je je eigen kamer niet zien?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMA: {PLAYER}.\p"
	.string "Zet de klok op je kamer goed.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMA: O! {PLAYER}, {PLAYER}!\n"
	.string "Kom snel kijken!$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMA: Kijk! PETALBURG GYM!\n"
	.string "Misschien komt papa op tv!$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMA: O, het is al afgelopen.\p"
	.string "We hebben papa net gemist.\n"
	.string "Wat jammer.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "O ja, een vriend van papa\n"
	.string "woont hier in het dorp.\p"
	.string "Hij heet PROF. BIRCH.\p"
	.string "Hij woont naast ons. Ga maar\n"
	.string "even kennismaken.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMA: Tot straks, lieverd!$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMA: Heb je al kennisgemaakt\n"
	.string "met PROF. BIRCH?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMA: Hoe gaat het, {PLAYER}?\n"
	.string "Je ziet er moe uit.\p"
	.string "Rust maar even uit.$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMA: Doe voorzichtig, lieverd!$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMA: O, kreeg je die BADGE\n"
	.string "van papa?\p"
	.string "Dan krijg je ook iets van mama!$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Doe rustig aan, lieverd.\n"
	.string "Je kunt altijd thuiskomen.\p"
	.string "Veel succes!$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMA: Wat is dat? Een POKéNAV?\n"
	.string "Heb je die van DEVON gekregen?\p"
	.string "Zet mama ook maar in je POKéNAV.\p"
	.string "... ... ...$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MAMA is geregistreerd\n"
	.string "in de POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih!$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo...$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "VERSLAGGEVER: Dit was ons verslag\n"
	.string "bij PETALBURG GYM.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Er is een film op tv.\p"
	.string "Twee mannen dansen op de toetsen\n"
	.string "van een grote piano.\p"
	.string "Tijd om te gaan!$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "De handleiding van de\n"
	.string "RUNNING SHOES.\p"
	.string "Houd B ingedrukt om te rennen\n"
	.string "met je RUNNING SHOES.\p"
	.string "Trek ze aan en ga op pad!$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "PAPA: Hm? Hé, {PLAYER}!\p"
	.string "Ik heb je lang niet gezien.\n"
	.string "Je lijkt sterker geworden!\p"
	.string "Maar je vader geeft nog niet op!\p"
	.string "O ja, ik heb iets voor je.\n"
	.string "Het komt van MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA: Hm, een TICKET voor de boot?\p"
	.string "Er zijn havens in SLATEPORT\n"
	.string "en LILYCOVE, als ik het goed heb.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Ik moet terug naar PETALBURG GYM.\p"
	.string "Bedankt dat je voor het huis\n"
	.string "zorgt als ik weg ben.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMA: Die papa van jou...\p"
	.string "Hij is eindelijk eens thuis,\n"
	.string "maar praat alleen over Pokémon.\p"
	.string "Hij mag best wat langer blijven\n"
	.string "en lekker uitrusten.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMA: Is dat extra nieuws?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We onderbreken de film voor\n"
	.string "een belangrijk nieuwsbericht!\p"
	.string "Op meerdere plekken in HOENN\n"
	.string "is een BZZT...kleurige Pokémon\l"
	.string "in de lucht gezien.\p"
	.string "We weten nog niet welke Pokémon\n"
	.string "het is.\p"
	.string "We gaan nu verder met de film.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMA: {PLAYER}, hoorde je dat?\p"
	.string "Welke kleur had die Pokémon\n"
	.string "volgens de nieuwslezer?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMA: Wat bijzonder!\n"
	.string "Er zijn nog onbekende Pokémon.$"
