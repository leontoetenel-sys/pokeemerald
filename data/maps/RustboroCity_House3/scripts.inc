RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Ik geef mijn Pokémon altijd\n"
	.string "bijnamen die perfect bij ze passen!\p"
	.string "Dat is mijn manier om, eh...\n"
	.string "origineel te zijn!$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Maar een PIKACHU PEKACHU noemen?\n"
	.string "Dat lijkt me een beetje zinloos.\p"
	.string "Een makkelijke naam is natuurlijk\n"
	.string "wel handig, maar...$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"

