SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Hallo! Ik ben de NAME RATER!\p"
	.string "Ik weet alles over namen.\p"
	.string "Ik bekijk graag de bijnaam\n"
	.string "van je POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Van welke POKéMON wil je\n"
	.string "de bijnaam laten bekijken?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmm... {STR_VAR_1}, zeg je?\n"
	.string "Dat is een mooie naam.\p"
	.string "Zullen we samen een nog\n"
	.string "mooiere naam bedenken?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Prima! Wat wordt de nieuwe naam?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Klaar! Deze POKéMON heet\n"
	.string "vanaf nu {STR_VAR_1}!\p"
	.string "Dat is een nog mooiere naam!$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Ik begrijp het.\n"
	.string "Kom gerust nog eens langs.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Klaar! Deze POKéMON heet\n"
	.string "vanaf nu {STR_VAR_1}!\p"
	.string "De naam lijkt hetzelfde,\n"
	.string "maar toch is hij veel mooier!$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmm... {STR_VAR_1}!\p"
	.string "Wat een prachtige bijnaam!\n"
	.string "Daar valt niets aan te verbeteren.\p"
	.string "Zorg altijd goed voor je\n"
	.string "{STR_VAR_1}.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Maar dat is nog een ei!$"

