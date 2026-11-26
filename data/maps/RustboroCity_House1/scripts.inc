RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Huh? Vind je mijn Pokémon lief?\n"
	.string "Dat wist ik natuurlijk al.\p"
	.string "Maar als je echt wilt,\n"
	.string "wil ik hem wel met je ruilen.\p"
	.string "Mijn {STR_VAR_2} voor jouw\n"
	.string "{STR_VAR_1}. Wil je dat?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Hihi...\n"
	.string "Zorg goed voor mijn Pokémon!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Huh? Dat lijkt helemaal niet\n"
	.string "op een {STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "O, als je niet wilt, is dat prima.\n"
	.string "Maar mijn Pokémon is wel lief!$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "Elke Pokémon kan lief zijn\n"
	.string "als je goed voor hem zorgt.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Overal zijn verschillende\n"
	.string "Pokémon en mensen.\p"
	.string "Dat vind ik zo leuk dat ik\n"
	.string "overal naartoe reis.$"

