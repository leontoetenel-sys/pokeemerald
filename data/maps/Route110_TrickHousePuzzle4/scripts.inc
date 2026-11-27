Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} schreef de geheime\n"
	.string "code op de deur.\p"
	.string "“TRICK MASTER is cool.”\n"
	.string "... ... ... ... ... ...\p"
	.string "Het slot klikte open!$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "Al dat nadenken is lastig.\n"
	.string "Ik wilde alleen maar vechten!$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Ik verloor, maar vechten\n"
	.string "blijft het leukste!$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Jij gaat toch ook overal heen\n"
	.string "waar TRAINERS zijn?$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Ha! Zulke rotsen duw ik\n"
	.string "met één vinger opzij!$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Ik kan rotsen duwen, maar\n"
	.string "de puzzel niet oplossen...$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Sterk zijn is niet genoeg...\n"
	.string "Je moet ook slim zijn!$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "Het TRICK HOUSE wordt steeds\n"
	.string "lastiger, vind je niet?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaah!$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Heeft iemand het einde bereikt?$"

