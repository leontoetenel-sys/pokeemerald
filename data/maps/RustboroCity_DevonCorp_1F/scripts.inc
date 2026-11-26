RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Hallo en welkom bij DEVON\n"
	.string "CORPORATION!\p"
	.string "Wij maken handige items en\n"
	.string "medicijnen die je leven verbeteren.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Een van onze onderzoekers is\n"
	.string "beroofd van een belangrijk pakket.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "He, die RUNNING SHOES!\n"
	.string "Die hebben wij gemaakt!\p"
	.string "Ik word blij als iemand iets\n"
	.string "gebruikt dat wij hebben gemaakt.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Dat gestolen pakket...\p"
	.string "Het is belangrijk, maar niet\n"
	.string "iedereen kan er iets mee.\p"
	.string "Die dief was volgens mij\n"
	.string "niet zo slim.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Ik hoor dat de gestolen\n"
	.string "DEVON GOODS weer terecht zijn.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Sorry, je mag hier alleen naar\n"
	.string "binnen met toestemming.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Hoe konden we ons nou laten\n"
	.string "beroven? Wat stom!$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Hallo!\n"
	.string "Jij bent hier altijd welkom!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "In de glazen kast liggen\n"
	.string "stenen en stukjes metaal.\p"
	.string "Op een bordje staat: DEVON begon\n"
	.string "met het winnen van stenen.\p"
	.string "Het bedrijf haalde ook ijzer\n"
	.string "uit zand.\p"
	.string "Zo groeide DEVON van een klein\n"
	.string "bedrijf tot een grote fabrikant.\p"
	.string "Nu maakt DEVON allerlei\n"
	.string "producten voor de industrie.$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "In de glazen kast staan\n"
	.string "nieuwe uitvindingen.\p"
	.string "Op een bordje staat: DEVON maakt\n"
	.string "ook handige spullen en medicijnen.\p"
	.string "Sinds kort maakt DEVON ook\n"
	.string "spullen voor Pokémon-trainers.\p"
	.string "Zoals POKé BALLS en de POKéNAV.$"

