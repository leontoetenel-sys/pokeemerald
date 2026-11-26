FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Er is iets aan de hand,\n"
	.string "en het bevalt me niet!\p"
	.string "Ik zag verdachte figuren bij\n"
	.string "het huis van PROF. COZMO\l"
	.string "naar binnen en buiten lopen...$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Deze streek staat al heel lang\n"
	.string "bekend om meteoren.\p"
	.string "METEOR FALLS zou lang geleden\n"
	.string "door een meteoriet zijn ontstaan.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Kijk eens!\n"
	.string "Dit is mijn lieve AZURILL!\p"
	.string "Hij is zo glad, zacht en knuffelig!$"

FallarborTown_Text_Azurill:
	.string "AZURILL: Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Heb je FLANNERY al uitgedaagd?\n"
	.string "Ze is de Gymleider van LAVARIDGE.\p"
	.string "Haar opa was vroeger beroemd.\n"
	.string "Hij zat ooit bij de ELITE FOUR\l"
	.string "van de Pokémon LEAGUE.\p"
	.string "Het zou me niet verbazen als\n"
	.string "FLANNERY zelf ook een geweldige\l"
	.string "trainer wordt.$"

FallarborTown_Text_BattleTentSign:
	.string "BATTLE TENT FALLARBOR\n"
	.string "Hier komen de beste teams samen!$"

FallarborTown_Text_TownSign:
	.string "FALLARBOR TOWN\n"
	.string "Een boerendorp met kleine tuinen.$"

FallarborTown_Text_MoveTutorSign:
	.string "HUIS VAN DE MOVE TUTOR\n"
	.string "Leer je Pokémon aanvallen.$"

