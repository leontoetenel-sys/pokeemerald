Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} schreef de geheime\n"
	.string "code op de deur.\p"
	.string "“TRICK MASTER is geweldig.”\n"
	.string "... ... ... ... ... ...\p"
	.string "Het slot klikte open!$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Met de CUT die we net leerden,\n"
	.string "banen we ons een weg!$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Waarom ben je zo serieus?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Ik krijg nooit genoeg van\n"
	.string "hakken en snijden!$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Ik liep per ongeluk dit\n"
	.string "vreemde huis binnen...$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "En nu heb ik verloren...$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Ik ben verdwaald en heb verloren.\n"
	.string "Hoe kom ik hier ooit uit?$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Wie is de TRICK MASTER toch?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "Ik verloor terwijl ik nadacht!$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Jij bent sterk!\n"
	.string "Wie ben jij eigenlijk?$"

