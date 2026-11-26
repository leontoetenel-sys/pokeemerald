Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mijn grote broer is de fossielenfan.\n"
	.string "Hij is aardig en dol op fossielen.\p"
	.string "Hij graaft ook graag gaten.\n"
	.string "Dit gat heeft hij zelf gegraven.\p"
	.string "Neem dit maar mee. Dan kun je\n"
	.string "net als mijn broer DIG gebruiken.$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Gebruik je DIG in een grot?\n"
	.string "Dan kom je weer bij de ingang uit.$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "In de vitrinekast liggen\n"
	.string "stenen met vreemde vormen.$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "DE OPBOUW VAN AARDLAGEN...\n"
	.string "HOE REGEN HET LAND VORMT...\l"
	.string "STENEN, GROND EN GESTEENTE...\p"
	.string "De kast staat vol boeken.$"

