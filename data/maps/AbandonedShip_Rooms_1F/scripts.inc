AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Zo'n schip zie je niet vaak.\n"
	.string "Ik kijk eens rustig rond.\p"
	.string "Hmhm... Er lijken nog meer\n"
	.string "kajuiten te zijn...$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Wat brengt jou hier?\n"
	.string "Jij bent vast nieuwsgierig!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Nieuwsgierig én sterk...$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "De man hiernaast...\p"
	.string "Hij zegt dat hij rondkijkt,\n"
	.string "maar ik vertrouw het niet.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Jij bent een sterke TRAINER!\n"
	.string "Mag ik je registreren?$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Wat brengt jou weer hier?\n"
	.string "Jij bent wel erg nieuwsgierig!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Ben jij niet een beetje té sterk?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Die man voert iets in zijn schild!\n"
	.string "Hij doet zo verdacht!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Ik ben gevonden! ...Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "O, jij bent mijn moeder niet.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Ik heb ruzie met mijn moeder en\n"
	.string "ben weggelopen. Niet verklappen!$"

