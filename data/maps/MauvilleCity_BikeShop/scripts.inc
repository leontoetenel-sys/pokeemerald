MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Zo, wat hebben we hier?\n"
	.string "Een klant vol energie!\p"
	.string "Ik ben RYDEL, de eigenaar\n"
	.string "van deze fietsenwinkel.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL: Je RUNNING SHOES\n"
	.string "zijn helemaal vies.\p"
	.string "Kom je van ver?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL: O, echt?\p"
	.string "Dan heb je vast geen fiets\n"
	.string "van mij nodig.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL: Hm, hm...\p"
	.string "Ben je helemaal uit\n"
	.string "LITTLEROOT gekomen?\p"
	.string "Jeetje! Dat is ontzettend ver!\p"
	.string "Met een fiets kun je makkelijk\n"
	.string "overal naartoe.\p"
	.string "En je voelt de wind!\p"
	.string "Weet je wat?\n"
	.string "Ik geef je een fiets!\p"
	.string "O, wacht even!\p"
	.string "Er zijn twee soorten fietsen!\p"
	.string "De MACH BIKE en de ACRO BIKE!\p"
	.string "De MACH BIKE is voor mensen\n"
	.string "die heel snel willen fietsen.\p"
	.string "De ACRO BIKE is voor mensen\n"
	.string "die graag trucjes doen.\p"
	.string "Ik ben aardig, dus je mag\n"
	.string "zelf kiezen!\p"
	.string "Welke wil je?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} kiest de MACH BIKE.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} kiest de ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL: Wil je van fiets wisselen?\n"
	.string "Kom dan gewoon bij me langs!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL: O? Wil je van fiets\n"
	.string "wisselen?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL: Goed, geen probleem!\n"
	.string "Ik ruil je fiets om!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} ruilt de MACH BIKE\n"
	.string "voor een ACRO BIKE.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} ruilt de ACRO BIKE\n"
	.string "voor een MACH BIKE.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL: Mooi zo!\n"
	.string "Fijn dat je hem leuk vindt!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "O? Waar is de fiets\n"
	.string "die ik je gaf?\p"
	.string "O, je hebt hem op je PC gezet.\p"
	.string "Haal hem daar weer uit,\n"
	.string "dan ruil ik hem graag om!\p"
	.string "Ik wens je altijd wind mee\n"
	.string "op je avontuur!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Ik leer hier alles over fietsen.\p"
	.string "Wil je weten hoe je moet fietsen?\n"
	.string "Achterin liggen handleidingen.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Dit is de handleiding\n"
	.string "van de MACH BIKE.\p"
	.string "Welke bladzijde wil je lezen?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Je fietst in de richting\n"
	.string "waarin je de + knop indrukt.\p"
	.string "Je gaat steeds sneller.\p"
	.string "Laat de + knop los om\n"
	.string "langzaam tot stilstand te komen.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Een MACH BIKE is snel, maar\n"
	.string "kan niet snel stoppen.\p"
	.string "Een bocht nemen is dus lastig.\p"
	.string "Laat de + knop vlak voor\n"
	.string "de bocht los om af te remmen.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Overal in HOENN zijn kleine\n"
	.string "zandhellingen.\p"
	.string "Door het losse zand kun je\n"
	.string "er normaal niet tegenop.\p"
	.string "Met een MACH BIKE kun je\n"
	.string "er wel tegenop fietsen!\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Dit is de handleiding\n"
	.string "van de ACRO BIKE.\p"
	.string "Welke bladzijde wil je lezen?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Druk tijdens het fietsen op B\n"
	.string "om je voorwiel op te tillen.\p"
	.string "Met de + knop kun je zo\n"
	.string "verder fietsen.\p"
	.string "Dit heet een wheelie.\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Houd B ingedrukt om met\n"
	.string "je fiets op de plek te springen.\p"
	.string "Dit heet een bunny hop.\p"
	.string "Je kunt ook springend fietsen!\p"
	.string "Wil je een andere bladzijde lezen?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Druk tegelijk op B en de\n"
	.string "+ knop om te springen.\p"
	.string "Druk opzij om zijwaarts\n"
	.string "te springen.\p"
	.string "Druk naar achteren om tijdens\n"
	.string "de sprong om te draaien.\p"
	.string "Wil je een andere bladzijde lezen?$"

