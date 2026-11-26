GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "He, jij daar!\n"
	.string "Verderop is het heel donker.\p"
	.string "STEVEN kwam hier net langs.\n"
	.string "Hij kan FLASH gebruiken.\p"
	.string "Wij HIKERS helpen graag anderen.\p"
	.string "Hier, dit mag je hebben!$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Leer FLASH aan een POKéMON.\p"
	.string "Daarmee maak je donkere grotten\n"
	.string "weer licht.\p"
	.string "Je hebt wel eerst de BADGE\n"
	.string "van DEWFORD GYM nodig.$"

