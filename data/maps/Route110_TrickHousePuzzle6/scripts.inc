Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} schreef de geheime\n"
	.string "code op de deur.\p"
	.string "“TRICK MASTER is mijn leven.”\n"
	.string "... ... ... ... ... ...\p"
	.string "Het slot klikte open!$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Ik hoorde over een vreemd huis\n"
	.string "en moest het bekijken.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "Ik vond een sterke TRAINER!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Ik vind het leuk om deze plek\n"
	.string "te onderzoeken.\p"
	.string "Deze uitdaging wil ik nog\n"
	.string "wel eens doen!$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Misschien kan mijn vogel-POKéMON\n"
	.string "over de muur vliegen...$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah! Het ging mis!$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe... Ik verloor vast\n"
	.string "omdat ik wilde valsspelen.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "Ik word duizelig van al\n"
	.string "die draaideuren...$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Alles draait maar rond.\n"
	.string "Ik kan niet meer...$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Jij lijkt nergens last van\n"
	.string "te hebben. Of doe je maar alsof?$"

