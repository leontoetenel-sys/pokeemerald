Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} schreef de geheime\n"
	.string "code op de deur.\p"
	.string "“Ik hou van TRICK MASTER.”\n"
	.string "... ... ... ... ... ...\p"
	.string "Het slot klikte open!$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Er zijn niet veel TRAINERS\n"
	.string "die zo ver zijn gekomen.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Dan ben jij vast ook sterk...$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Heb jij de CHAMPION van de\n"
	.string "POKéMON LEAGUE verslagen? Wauw!$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Je mag blij zijn dat je\n"
	.string "tegen mij mag vechten!$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Dat kan niet!\n"
	.string "Ik kan niet verliezen!$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "Het is een wonder dat je won.\n"
	.string "Daar mag je over opscheppen.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Jij werkt je ook door het\n"
	.string "TRICK HOUSE heen.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Ik zie het...\n"
	.string "Jij hebt een bijzondere stijl.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "De TRICK MASTER zal blij zijn\n"
	.string "met iemand zoals jij.$"

