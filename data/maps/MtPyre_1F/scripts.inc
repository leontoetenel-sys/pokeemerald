MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Op de hellingen van MT. PYRE\n"
	.string "dwalen allerlei wezens rond...\p"
	.string "Je weet nooit wat er gebeurt.\n"
	.string "Neem dit, voor je eigen bestwil.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Laat een POKéMON die\n"
	.string "CLEANSE TAG vasthouden.\p"
	.string "Die helpt wilde POKéMON\n"
	.string "op afstand te houden.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Kom je de geesten van overleden\n"
	.string "POKéMON eer bewijzen?\p"
	.string "Je geeft vast veel om je POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Hier rust mijn ZIGZAGOON.\n"
	.string "Ik hield heel veel van hem...$"

