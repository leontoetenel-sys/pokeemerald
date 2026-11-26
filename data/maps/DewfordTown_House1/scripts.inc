DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Het is fijn om op dit eiland\n"
	.string "met je gezin en POKéMON te wonen.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Ik verhuisde uit SLATEPORT CITY\n"
	.string "toen ik met mijn man trouwde.\p"
	.string "Hier gaat alles rustig.\p"
	.string "Met die mooie zee om ons heen\n"
	.string "ben ik heel gelukkig.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON: Guguuh!$"

