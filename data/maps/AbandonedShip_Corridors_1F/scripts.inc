AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Wat is er zo grappig aan mijn\n"
	.string "zwemband op dit schip?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Wauw, jij bent sterk!$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "POKé BALLS gooien is lastig\n"
	.string "als je een zwemband vasthoudt!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "Leuk hier, hè?\n"
	.string "Ik vind het zo spannend!$"
