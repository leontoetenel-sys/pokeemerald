Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Ik ben de baas van SEASHORE HOUSE.\n"
	.string "Noem me maar meneer SEA!\p"
	.string "Ik hou van spannende gevechten!\p"
	.string "Versla alle trainers hier.\n"
	.string "Dan krijg je een beloning!$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Laat me spannende gevechten zien!\p"
	.string "Daarom heb ik dit strandhuis!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Wauw, wat een gevechten!\n"
	.string "Ik heb ervan genoten!\p"
	.string "Als beloning krijg je zes\n"
	.string "flesjes SODA POP!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "O, je tas zit vol.\n"
	.string "Ik bewaar ze voor je.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Wil je SODA POP kopen?\n"
	.string "POKéMON zijn er dol op!\p"
	.string "Slechts ¥300 per flesje!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Alsjeblieft!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Je hebt niet genoeg geld.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Nee? Jammer!$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Zoek je een gevecht?\n"
	.string "Ik ben de sterkste trainer hier!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Wat een spannend gevecht!\n"
	.string "Ik kan best tegen mijn verlies!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "In SLATEPORT hou ik van gevechten\n"
	.string "en ijskoude SODA POP!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Saaie gevechten zijn niks!\p"
	.string "Spannende gevechten maken\n"
	.string "trainers en POKéMON sterker!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Wat een gevecht!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Pfff, ik heb dorst.\n"
	.string "Ik neem een SODA POP.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Ik laat zien hoe goed mijn\n"
	.string "POKéMON zijn. Niet huilen hoor!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "Ik verloor, maar ik huil niet!$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Als mijn POKéMON me over water\n"
	.string "kon dragen, had ik deze\l"
	.string "zwemband niet nodig.$"

