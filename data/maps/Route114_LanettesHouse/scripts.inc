Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: O! {PLAYER}!\p"
	.string "Sorry voor de rommel...\n"
	.string "Als ik druk ben met onderzoek,\l"
	.string "wordt het hier zo'n bende.\p"
	.string "Wat gênant... Hou je dit geheim?\n"
	.string "Dan krijg je dit van mij.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Mag ik je een tip geven over\n"
	.string "mijn Pokémon-opslagsysteem?\p"
	.string "Orden je BOXES zodat je weet\n"
	.string "welke Pokémon erin zitten.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Dit zijn LANETTE's notities.\n"
	.string "Ze gaan over BOXES.\p"
	.string "Elke BOX moet ruimte bieden\n"
	.string "aan 30 Pokémon.\p"
	.string "Elke trainer moet 420 Pokémon\n"
	.string "op de PC kunnen bewaren.\p"
	.string "Verder lezen?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Met markeringen kun je Pokémon\n"
	.string "makkelijker ordenen.\p"
	.string "De naam en achtergrond van\n"
	.string "elke BOX moeten aanpasbaar zijn,\l"
	.string "zodat de Pokémon blij zijn.\p"
	.string "Verder lezen?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Een Pokémon wordt opgeslagen\n"
	.string "in de laatst bekeken BOX.\p"
	.string "Is die BOX vol? Dan gaat de\n"
	.string "Pokémon naar de volgende BOX.\p"
	.string "Dus als je een BOX bekijkt,\n"
	.string "wordt die automatisch gekozen\l"
	.string "voor nieuwe Pokémon.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} sloot het notitieboek.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Er staat een e-mail op de PC.\p"
	.string "... ... ... ... ... ... ...\p"
	.string "Jouw opslagsysteem is handiger\n"
	.string "dan het mijne.\p"
	.string "Het heeft veel handige functies\n"
	.string "die het ook leuk maken.\p"
	.string "Ik ben trots dat ik heb mogen\n"
	.string "helpen bij de ontwikkeling.\p"
	.string "Ik hoop dat je onderzoek naar\n"
	.string "opslagsystemen blijft doen.\p"
	.string "Groetjes, BILL\n"
	.string "... ... ... ... ... ... ...$"

