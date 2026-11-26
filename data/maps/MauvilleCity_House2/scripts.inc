MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applywaitmovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	applywaitmovement VAR_LAST_TALKED, Common_Movement_Delay48
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Met een fiets kon ik makkelijk\n"
	.string "naar SLATEPORT om te winkelen.\p"
	.string "Dan kon ik HARBOR MAIL kopen\n"
	.string "bij de Pokémon Mart daar...$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "O! Heb je HARBOR MAIL?\n"
	.string "Ruilen voor een COIN CASE?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "O, wat ben ik blij!\n"
	.string "Hier is je COIN CASE!$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Je kunt de COIN CASE gebruiken\n"
	.string "in de GAME CORNER.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "O, wat jammer.\p"
	.string "Je hebt een COIN CASE nodig\n"
	.string "voor de GAME CORNER.$"

