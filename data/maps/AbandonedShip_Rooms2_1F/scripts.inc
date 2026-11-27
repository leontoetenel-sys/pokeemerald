AbandonedShip_Rooms2_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms2_1F_EventScript_Dan::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanIntro, AbandonedShip_Rooms2_1F_Text_DanDefeat, AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterDan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_DanRematch
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterDan::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT  @ Kira speaks for both when registering KiraAndDan
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_DanRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_DanRematchIntro, AbandonedShip_Rooms2_1F_Text_DanRematchDefeat, AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_DanPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Kira::
	trainerbattle_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraIntro, AbandonedShip_Rooms2_1F_Text_KiraDefeat, AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons, AbandonedShip_Rooms2_1F_EventScript_RegisterKira
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms2_1F_EventScript_KiraRematch
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms2_1F_EventScript_RegisterKira::
	msgbox AbandonedShip_Rooms2_1F_Text_KiraRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_KIRA_AND_DAN_1
	release
	end

AbandonedShip_Rooms2_1F_EventScript_KiraRematch::
	trainerbattle_rematch_double TRAINER_KIRA_AND_DAN_1, AbandonedShip_Rooms2_1F_Text_KiraRematchIntro, AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat, AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons
	msgbox AbandonedShip_Rooms2_1F_Text_KiraPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Jani::
	trainerbattle_single TRAINER_JANI, AbandonedShip_Rooms2_1F_Text_JaniIntro, AbandonedShip_Rooms2_1F_Text_JaniDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_JaniPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_EventScript_Garrison::
	trainerbattle_single TRAINER_GARRISON, AbandonedShip_Rooms2_1F_Text_GarrisonIntro, AbandonedShip_Rooms2_1F_Text_GarrisonDefeat
	msgbox AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms2_1F_Text_DanIntro:
	.string "DAN: Tijdens onze zoektocht naar\n"
	.string "schatten vonden we een TRAINER!$"

AbandonedShip_Rooms2_1F_Text_DanDefeat:
	.string "DAN: Zelfs samen konden we\n"
	.string "niet winnen...$"

AbandonedShip_Rooms2_1F_Text_DanPostBattle:
	.string "DAN: We vinden geen schatten...\n"
	.string "Zou iemand ze al hebben gepakt?$"

AbandonedShip_Rooms2_1F_Text_DanNotEnoughMons:
	.string "DAN: Je hebt niet eens twee\n"
	.string "POKéMON. Zo versla je ons niet.$"

AbandonedShip_Rooms2_1F_Text_KiraIntro:
	.string "KIRA: O? We zochten schatten,\n"
	.string "maar vonden een TRAINER!$"

AbandonedShip_Rooms2_1F_Text_KiraDefeat:
	.string "KIRA: Oeh, zo sterk!$"

AbandonedShip_Rooms2_1F_Text_KiraPostBattle:
	.string "KIRA: Waar zijn de schatten toch?\p"
	.string "Ik weet al wat ik wil kopen\n"
	.string "als we ze hebben gevonden!$"

AbandonedShip_Rooms2_1F_Text_KiraNotEnoughMons:
	.string "KIRA: Heb je geen twee POKéMON?\n"
	.string "Dan vechten we een andere keer!$"

AbandonedShip_Rooms2_1F_Text_KiraRegister:
	.string "KIRA: Jij maakt me zo boos!\n"
	.string "Ik ga je registreren!$"

AbandonedShip_Rooms2_1F_Text_DanRematchIntro:
	.string "DAN: We zoeken nog steeds\n"
	.string "naar schatten.\p"
	.string "Onze POKéMON zijn ook sterker.\n"
	.string "Zullen we het laten zien?$"

AbandonedShip_Rooms2_1F_Text_DanRematchDefeat:
	.string "DAN: Je bent sterk, zoals altijd!$"

AbandonedShip_Rooms2_1F_Text_DanPostRematch:
	.string "DAN: We vinden geen schatten\n"
	.string "en verliezen met POKéMON...\p"
	.string "Ik wil naar huis... Maar dan\n"
	.string "wordt zij boos op me...$"

AbandonedShip_Rooms2_1F_Text_DanRematchNotEnoughMons:
	.string "DAN: Je hebt niet eens twee\n"
	.string "POKéMON. Zo versla je ons niet.$"

AbandonedShip_Rooms2_1F_Text_KiraRematchIntro:
	.string "KIRA: O? Daar ben je weer!\p"
	.string "Jij zoekt ook nog steeds\n"
	.string "naar schatten, hè?\p"
	.string "Zullen we afspreken dat de\n"
	.string "verliezer stopt met zoeken?$"

AbandonedShip_Rooms2_1F_Text_KiraRematchDefeat:
	.string "KIRA: O, weer verloren...$"

AbandonedShip_Rooms2_1F_Text_KiraPostRematch:
	.string "KIRA: We gaan pas weg als onze\n"
	.string "POKéMON sterker zijn en we\l"
	.string "de schatten hebben gevonden!$"

AbandonedShip_Rooms2_1F_Text_KiraRematchNotEnoughMons:
	.string "KIRA: Heb je geen twee POKéMON?\n"
	.string "Dan vechten we een andere keer!$"

AbandonedShip_Rooms2_1F_Text_JaniIntro:
	.string "Ik kan niet goed zwemmen,\n"
	.string "maar wel goed vechten!$"

AbandonedShip_Rooms2_1F_Text_JaniDefeat:
	.string "Oeps.\n"
	.string "Dat ging niet zo goed.$"

AbandonedShip_Rooms2_1F_Text_JaniPostBattle:
	.string "Op blote voeten door dit schip\n"
	.string "lopen is best vies.$"

AbandonedShip_Rooms2_1F_Text_GarrisonIntro:
	.string "Kracht en medeleven...\n"
	.string "Dat zijn echte TRAINER-schatten!$"

AbandonedShip_Rooms2_1F_Text_GarrisonDefeat:
	.string "Ah, er is iets aan jou\n"
	.string "dat schittert.$"

AbandonedShip_Rooms2_1F_Text_GarrisonPostBattle:
	.string "Ergens in een kajuit zag ik\n"
	.string "iets schitteren.$"
