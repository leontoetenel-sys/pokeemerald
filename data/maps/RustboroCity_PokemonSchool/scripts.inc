RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applywaitmovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applywaitmovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Op het bord staan statussen\n"
	.string "die Pokémon in een gevecht\l"
	.string "kunnen krijgen.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Waar wil je over lezen?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Een poisoned Pokémon verliest\n"
	.string "steeds een beetje HP.\p"
	.string "Poison blijft ook na het gevecht.\p"
	.string "Tijdens het lopen verliest\n"
	.string "je Pokémon ook HP.\p"
	.string "Gebruik een ANTIDOTE om hem\n"
	.string "te genezen.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Een paralyzed Pokémon heeft\n"
	.string "een lagere SPEED.\p"
	.string "Soms kan hij niet bewegen\n"
	.string "tijdens een gevecht.\p"
	.string "Deze status blijft na het gevecht.\n"
	.string "Gebruik een PARLYZ HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Een Pokémon die asleep is,\n"
	.string "kan niet aanvallen.\p"
	.string "Hij kan vanzelf wakker worden.\p"
	.string "Als hij na het gevecht nog slaapt,\n"
	.string "blijft hij asleep.\p"
	.string "Gebruik een AWAKENING om hem\n"
	.string "wakker te maken.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Een burn verlaagt ATTACK.\n"
	.string "Je Pokémon verliest ook steeds HP.\p"
	.string "Burn blijft na het gevecht.\n"
	.string "Gebruik een BURN HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Een frozen Pokémon kan niet\n"
	.string "bewegen.\p"
	.string "Ook na het gevecht blijft hij frozen.\n"
	.string "Gebruik een ICE HEAL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Leerlingen die niet goed leren,\n"
	.string "krijgen mijn QUICK CLAW!\p"
	.string "Aan hoe jij dit item gebruikt,\n"
	.string "zie ik of je een goede leerling bent.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Een Pokémon met QUICK CLAW\n"
	.string "mag soms als eerste aanvallen.\p"
	.string "Er zijn nog veel meer items\n"
	.string "die Pokémon kunnen vasthouden.\p"
	.string "Genoeg om over te leren dus!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Ik ben nu Pokémon aan het ruilen\n"
	.string "met mijn vriend.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Ik wilde altijd al een SEEDOT.\n"
	.string "Nu krijg ik er eindelijk een!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Pokémon kunnen items vasthouden.\p"
	.string "Maar ze weten niet hoe ze zelf\n"
	.string "een POTION of ANTIDOTE gebruiken.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Sommige aanvallen maken\n"
	.string "een Pokémon confused.\p"
	.string "Dan doet hij soms per ongeluk\n"
	.string "zichzelf pijn.\p"
	.string "Na het gevecht is hij weer normaal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Een Pokémon met een BERRY\n"
	.string "kan zichzelf genezen...\p"
	.string "Er zijn veel items die Pokémon\n"
	.string "kunnen vasthouden...\p"
	.string "Pfff, wat is het lastig om\n"
	.string "dit allemaal op te schrijven!$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Dit is het schrift van een leerling.\p"
	.string "Je vangt Pokémon met POKé BALLS.\p"
	.string "Een trainer kan maximaal zes\n"
	.string "Pokémon meenemen.\p"
	.string "Een trainer vangt Pokémon,\n"
	.string "verzorgt ze en vecht met ze.\p"
	.string "Het doel is om de sterke trainers\n"
	.string "in de Pokémon GYMS te verslaan.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Hallo! Hebben wij elkaar niet\n"
	.string "eerder gezien in PETALBURG CITY?\p"
	.string "Ik zal me voorstellen.\n"
	.string "Ik heet SCOTT.\p"
	.string "Ik reis overal heen om geweldige\n"
	.string "trainers te vinden.\p"
	.string "Vooral trainers die heel goed\n"
	.string "zijn in Pokémon-gevechten.\p"
	.string "Wat doe jij op deze school?\n"
	.string "Ben jij ook een trainer?\p"
	.string "Leer eerst een Pokémon CUT.\p"
	.string "Volgens mij heeft iemand\n"
	.string "in deze stad die aanval.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT: Hmm...\p"
	.string "Ik weet nog niet hoe goed deze\n"
	.string "leerlingen zijn. Ze hebben talent.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT: O, wat is dat?\p"
	.string "Een STONE BADGE, toch?\n"
	.string "Dat is best indrukwekkend!\p"
	.string "Ik had je graag zien vechten.\p"
	.string "Aan alleen een BADGE kan ik\n"
	.string "niet zien hoe jij vecht.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Hallo! Hebben wij elkaar niet\n"
	.string "eerder gezien in PETALBURG CITY?\p"
	.string "Ik zal me voorstellen.\n"
	.string "Ik heet SCOTT.\p"
	.string "Ik reis overal heen om geweldige\n"
	.string "trainers te vinden.\p"
	.string "Vooral trainers die heel goed\n"
	.string "zijn in Pokémon-gevechten.\p"
	.string "O, wat is dat? Een STONE BADGE?\p"
	.string "Best indrukwekkend voor iemand\n"
	.string "die pas trainer is!\p"
	.string "Ik had je graag zien vechten.\p"
	.string "Aan alleen een BADGE kan ik\n"
	.string "niet zien hoe jij vecht.$"

