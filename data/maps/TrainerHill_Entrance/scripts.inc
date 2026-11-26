TrainerHill_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerHill_Entrance_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerHill_Entrance_OnReturn
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Entrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerHill_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Entrance_OnFrame
	.byte 0

TrainerHill_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRAINER_HILL
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

@ Unused
TrainerHill_Entrance_OnWarp:
	end

TrainerHill_Entrance_OnResume:
	trainerhill_resumetimer
	setvar VAR_TEMP_0, 0
	trainerhill_getusingereader
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_TryFaceAttendant  @ VAR_RESULT always FALSE here
	setobjectxy LOCALID_PLAYER, 9, 6
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_TryFaceAttendant::
	trainerhill_getwon
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	end

TrainerHill_Entrance_EventScript_PlayerDontFaceAttendant::
	end

TrainerHill_Entrance_OnReturn:
	addobject LOCALID_TRAINER_HILL_NURSE
	addobject LOCALID_TRAINER_HILL_ATTENDANT
	addobject LOCALID_TRAINER_HILL_MAN
	addobject LOCALID_TRAINER_HILL_GIRL
	end

TrainerHill_Entrance_OnLoad:
	call_if_eq VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_OpenCounterDoor
	end

TrainerHill_Entrance_EventScript_OpenCounterDoor::
	setmetatile 17, 10, METATILE_TrainerHill_GreenFloorTile, FALSE
	return

TrainerHill_Entrance_OnFrame:
	map_script_2 VAR_TEMP_0, 0, TrainerHill_Entrance_EventScript_ExitChallenge
	map_script_2 VAR_TEMP_D, 17, TrainerHill_Entrance_EventScript_ExitElevator
	map_script_2 VAR_TEMP_5, 1, TrainerHill_Entrance_EventScript_EntryTrigger
	map_script_2 VAR_TEMP_1, 1, TrainerHill_EventScript_WarpToEntranceCounter
	.2byte 0

TrainerHill_Entrance_EventScript_ExitElevator::
	lockall
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerExitElevator
	setmetatile 17, 10, METATILE_TrainerHill_CounterDoor, TRUE
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerHill_Entrance_EventScript_ExitChallenge::
	setvar VAR_TEMP_0, 1
	trainerhill_getstatus
	switch VAR_RESULT
	case TRAINER_HILL_PLAYER_STATUS_LOST, TrainerHill_Entrance_EventScript_ExitChallengeLost
	case TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED, TrainerHill_Entrance_EventScript_ExitChallengeECard
	case TRAINER_HILL_PLAYER_STATUS_NORMAL, TrainerHill_Entrance_EventScript_EndExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeLost::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_TooBadTremendousEffort, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_PlayerExitChallenge

TrainerHill_Entrance_EventScript_ExitChallengeECard::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	msgbox TrainerHill_Entrance_Text_MovedReceptionHereForSwitch, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_PlayerExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	special HealPlayerParty
	releaseall
TrainerHill_Entrance_EventScript_EndExitChallenge::
	end

TrainerHill_Entrance_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_TRAINER_HILL_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

TrainerHill_Entrance_EventScript_Attendant::
	lock
	faceplayer
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_ThanksForPlaying
	msgbox TrainerHill_Entrance_Text_HopeYouGiveItYourBest, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AttendantEnd

TrainerHill_Entrance_EventScript_ThanksForPlaying::
	msgbox TrainerHill_Entrance_Text_ThankYouForPlaying, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AttendantEnd::
	release
	end

TrainerHill_Entrance_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PlayerFaceAttendant
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_Closed
	msgbox TrainerHill_Entrance_Text_WelcomeToTrainerHill, MSGBOX_DEFAULT
	trainerhill_getsaved
	call_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveGame
	trainerhill_allfloorsused
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_Entrance_EventScript_AllFloorsUsed
	msgbox TrainerHill_Entrance_Text_TrainersUpToFloorX, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers

TrainerHill_Entrance_EventScript_AllFloorsUsed::
	msgbox TrainerHill_Entrance_Text_TrainersInEveryRoom, MSGBOX_DEFAULT
TrainerHill_Entrance_EventScript_AskChallengeTrainers::
	message TrainerHill_Entrance_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 15, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerHill_Entrance_EventScript_ChooseChallenge
	case 1, TrainerHill_Entrance_EventScript_CancelEntry
	case 2, TrainerHill_Entrance_EventScript_Info
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Info::
	msgbox TrainerHill_Entrance_Text_ExplainTrainerHill, MSGBOX_DEFAULT
	goto TrainerHill_Entrance_EventScript_AskChallengeTrainers
	end

TrainerHill_Entrance_EventScript_ChooseChallenge::
	multichoice 13, 2, MULTI_TAG_MATCH_TYPE, FALSE
	switch VAR_RESULT
	case 4, TrainerHill_Entrance_EventScript_CancelEntry
	case MULTI_B_PRESSED, TrainerHill_Entrance_EventScript_CancelEntry
	trainerhill_setmode VAR_RESULT
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 1
	setvar VAR_TEMP_5, 0
	special HealPlayerParty
	msgbox TrainerHill_Entrance_Text_TimeProgessGetSetGo, MSGBOX_DEFAULT
	trainerhill_start
	releaseall
	end

TrainerHill_Entrance_EventScript_CancelEntry::
	setvar VAR_TEMP_5, 0
	msgbox TrainerHill_Entrance_Text_PleaseVisitUsAgain, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_EventScript_SaveGame::
	msgbox TrainerHill_Entrance_Text_SaveGameBeforeEnter, MSGBOX_DEFAULT
	trainerhill_setsaved
	setvar VAR_TEMP_5, 1
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Entrance_EventScript_SaveFailed
	trainerhill_setsaved
	return

TrainerHill_Entrance_EventScript_SaveFailed::
	trainerhill_clearsaved
	goto TrainerHill_Entrance_EventScript_CancelEntry
	end

TrainerHill_Entrance_EventScript_Closed::
	msgbox TrainerHill_Entrance_Text_StillGettingReady, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_PLAYER, TrainerHill_Entrance_Movement_PushPlayerBackFromCounter
	releaseall
	end

TrainerHill_Entrance_Movement_PlayerFaceAttendant:
	face_right
	step_end

TrainerHill_Entrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

@ Unused
TrainerHill_Entrance_Movement_FaceUp:
	face_up
	step_end

TrainerHill_Entrance_Movement_PlayerExitElevator:
	walk_down
	walk_down
	step_end

TrainerHill_Entrance_EventScript_Records::
	lockall
	fadescreen FADE_TO_BLACK
	special ShowTrainerHillRecords
	releaseall
	end

TrainerHill_Entrance_EventScript_Man::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ManTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_ManTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_CantWaitToTestTheWaters, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Girl::
	goto_if_unset FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_GirlTrainerHillClosed
	msgbox TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_GirlTrainerHillClosed::
	msgbox TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen, MSGBOX_NPC
	end

TrainerHill_Entrance_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, TrainerHill_Entrance_EventScript_ExpandedPokemart
	pokemart TrainerHill_Entrance_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Basic:
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_EventScript_ExpandedPokemart::
	pokemart TrainerHill_Entrance_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
TrainerHill_Entrance_Pokemart_Expanded:
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_X_ACCURACY
	pokemartlistend

TrainerHill_Entrance_Text_StillGettingReady:
	.string "Dit is TRAINER HILL. Hier kun\n"
	.string "je dubbele duels houden tegen\l"
	.string "allerlei trainers.\p"
	.string "Helaas zijn we nog bezig met\n"
	.string "de voorbereidingen.\l"
	.string "Kom later nog eens terug!$"

TrainerHill_Entrance_Text_WelcomeToTrainerHill:
	.string "Welkom!\p"
	.string "Dit is TRAINER HILL. Hier kun\n"
	.string "je dubbele duels houden tegen\l"
	.string "allerlei trainers!$"

TrainerHill_Entrance_Text_SaveGameBeforeEnter:
	.string "Ben je hier voor het eerst?\p"
	.string "Sla je spel op voordat je\n"
	.string "naar binnen gaat.$"

TrainerHill_Entrance_Text_TrainersUpToFloorX:
	.string "Even kijken...\n"
	.string "De trainers staan klaar...\p"
	.string "Tot en met verdieping {STR_VAR_1}.$"

TrainerHill_Entrance_Text_TrainersInEveryRoom:
	.string "Even kijken...\n"
	.string "De trainers staan klaar...\p"
	.string "Er zijn trainers in elke kamer.$"

TrainerHill_Entrance_Text_LikeToChallengeTrainers:
	.string "Wil je de wachtende trainers\n"
	.string "uitdagen?$"

TrainerHill_Entrance_Text_TimeProgessGetSetGo:
	.string "Ik houd je tijd bij.\n"
	.string "Veel succes!\p"
	.string "Op je plaatsen...\p"
	.string "Klaar...\p"
	.string "Start!$"

TrainerHill_Entrance_Text_PleaseVisitUsAgain:
	.string "Kom gerust nog eens terug!$"

TrainerHill_Entrance_Text_TooBadTremendousEffort:
	.string "Wat jammer!\p"
	.string "Je hebt ontzettend goed\n"
	.string "je best gedaan.\p"
	.string "Kom terug en probeer het\n"
	.string "nog eens!$"

TrainerHill_Entrance_Text_HopeYouGiveItYourBest:
	.string "Doe je best!$"

TrainerHill_Entrance_Text_MovedReceptionHereForSwitch:
	.string "Als de trainers van plek\n"
	.string "wisselen, wordt het erg druk.\p"
	.string "Daarom hebben we de balie\n"
	.string "naar deze plek verplaatst.\p"
	.string "Sorry voor het ongemak.$"

TrainerHill_Entrance_Text_ThankYouForPlaying:
	.string "Bedankt voor het spelen!$"

TrainerHill_Entrance_Text_ExplainTrainerHill:
	.string "Hier in TRAINER HILL houden\n"
	.string "we een wedstrijd: Time Attack.\p"
	.string "We meten hoe lang je erover\n"
	.string "doet om vanaf deze balie bij\l"
	.string "de eigenaar op het dak te komen.\p"
	.string "De snelste tijden staan op\n"
	.string "het tijdenbord. Probeer je\l"
	.string "vrienden te verslaan!\p"
	.string "Je krijgt onderweg geen XP\n"
	.string "of geld voor de duels.$"

@ Unused
TrainerHill_Entrance_Text_NeedAtLeastTwoPokemon:
	.string "O, sorry. Je hebt maar één\n"
	.string "Pokémon bij je.\p"
	.string "Je hebt minstens twee Pokémon\n"
	.string "nodig om mee te doen.$"

TrainerHill_Roof_Text_YouFinallyCameBravo:
	.string "Hm! Hm!\p"
	.string "Eindelijk ben je er!\n"
	.string "Ja, je hebt het gehaald!\p"
	.string "Wacht! Zeg maar niets!\n"
	.string "Ik weet waarom je helemaal\l"
	.string "alleen hierheen bent gekomen!\p"
	.string "Je wilde mij, de eigenaar van\n"
	.string "TRAINER HILL, ontmoeten omdat...\p"
	.string "Je samen met mij een team\n"
	.string "wilt vormen! Joepie!\p"
	.string "...Eh?\n"
	.string "Is dat het niet?\p"
	.string "Ik heb je onderweg bekeken.\n"
	.string "Geweldig gevochten! Bravo!$"

TrainerHill_Roof_Text_HaveTheMostMarvelousGift:
	.string "Voor iemand die zo geweldig\n"
	.string "is, heb ik een geweldig cadeau!$"

TrainerHill_Roof_Text_FullUpBeBackLaterForThis:
	.string "O nee, je hebt geen plek meer!\n"
	.string "Kom later terug voor je cadeau!$"

TrainerHill_Roof_Text_GotHereMarvelouslyQuickly:
	.string "O, wacht eens! Ben je hier\n"
	.string "soms ontzettend snel gekomen?\p"
	.string "Wat geweldig! Je hoefde je\n"
	.string "niet zo te haasten voor mij!\p"
	.string "Ik ben zo blij! Ik laat het\n"
	.string "tijdenbord bij de balie aanpassen!$"

TrainerHill_Roof_Text_YouWerentVeryQuick:
	.string "Maar, o...\n"
	.string "Je was niet erg snel.$"

TrainerHill_Roof_Text_ArriveZippierNextTime:
	.string "Misschien maak je me blijer\n"
	.string "als je de volgende keer\l"
	.string "wat sneller bent.\p"
	.string "Dan vorm ik graag een team\n"
	.string "met jou!\p"
	.string "Tot de volgende keer, vriend!$"

@ Unused
TrainerHill_Roof_Text_BuiltTrainerHillToFindPartner:
	.string "Ik heb TRAINER HILL om maar\n"
	.string "één reden laten bouwen!\p"
	.string "Om de allerbeste partner\n"
	.string "te vinden voor dubbele duels!$"

TrainerHill_Entrance_Text_ChallengeTime:
	.string "{STR_VAR_1} min. {STR_VAR_2}.{STR_VAR_3} sec.$"

TrainerHill_Entrance_Text_WhatSortOfTrainersAreAhead:
	.string "Wie weet welke trainers en\n"
	.string "Pokémon ons te wachten staan?\p"
	.string "Ik weet één ding: ik versla\n"
	.string "iedereen die me in de weg staat!$"

TrainerHill_Entrance_Text_CantWaitToTestTheWaters:
	.string "Ik hoorde dat sterke trainers\n"
	.string "van overal naar TRAINER HILL\l"
	.string "komen.\p"
	.string "Ik kan niet wachten om het\n"
	.string "zelf te proberen!\p"
	.string "Ik versla iedereen die me\n"
	.string "in de weg staat!$"

TrainerHill_Entrance_Text_FriendsTryingToReachTimeBoardTop:
	.string "Zie je dat tijdenbord daar?\p"
	.string "Mijn vrienden en ik proberen\n"
	.string "zo snel mogelijk boven te komen.$"

TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen:
	.string "Weet jij wanneer ze opengaan?\p"
	.string "Ik wacht hier om de allereerste\n"
	.string "uitdager te zijn!$"

TrainerHill_Elevator_Text_ReturnToReception:
	.string "Wil je terug naar de balie?$"
