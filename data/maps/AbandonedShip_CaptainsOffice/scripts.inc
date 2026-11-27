AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "Ik onderzoek dit schip voor\n"
	.string "CAPT. STERN.\p"
	.string "Hij vroeg me ook een SCANNER\n"
	.string "te zoeken, maar zonder succes...$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "O! Dat is een SCANNER!\p"
	.string "Wil jij die naar CAPT. STERN\n"
	.string "brengen?\p"
	.string "Ik wil dit schip nog wat\n"
	.string "verder onderzoeken.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Dit schip heet de S.S. CACTUS.\n"
	.string "Het lijkt uit een andere tijd te komen.$"

