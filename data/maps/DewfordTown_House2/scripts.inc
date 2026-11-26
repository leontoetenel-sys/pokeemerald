DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Kijk eens wat ik heb!\p"
	.string "Een SILK SCARF! Helemaal in de mode!\p"
	.string "O, jij vindt hem ook mooi!\p"
	.string "Wat leuk! Je mag hem hebben!$"

DewfordTown_House2_Text_NoRoom:
	.string "O, je tas is vol?\p"
	.string "Deze SCARF moet je echt hebben!\n"
	.string "Ik zou er alles voor verkopen!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "De SILK SCARF maakt NORMAL-type\n"
	.string "aanvallen sterker.\p"
	.string "Bijna elke POKéMON kan hem dragen!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wauw, je bent helemaal over zee\n"
	.string "naar DEWFORD gekomen!\p"
	.string "Kom je voor BRAWLY?\p"
	.string "Hij is zo cool!\n"
	.string "Iedereen vindt hem geweldig.$"

