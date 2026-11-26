RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Die vastberaden blik...\n"
	.string "Hoe soepel je beweegt...\l"
	.string "En je goed getrainde Pokémon...\p"
	.string "Jij bent duidelijk een goede trainer!\p"
	.string "Nee, zeg maar niets.\n"
	.string "Ik zie het meteen aan je.\p"
	.string "Jij kunt deze HIDDEN MACHINE\n"
	.string "vast goed gebruiken.\p"
	.string "Wees niet verlegen.\n"
	.string "Neem hem maar aan!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "In deze HIDDEN MACHINE,\n"
	.string "of HM, zit CUT.\p"
	.string "Een HM-aanval kun je ook\n"
	.string "buiten gevechten gebruiken.\p"
	.string "Met CUT kan een Pokémon dunne\n"
	.string "boompjes omhakken als jij\l"
	.string "de STONE BADGE hebt.\p"
	.string "Anders dan een TM kun je\n"
	.string "een HM vaker gebruiken.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Toen RUSTBORO groter werd,\n"
	.string "hielp mijn papa mee.\p"
	.string "Zijn Pokémon gebruikte CUT\n"
	.string "om bomen weg te halen.$"

