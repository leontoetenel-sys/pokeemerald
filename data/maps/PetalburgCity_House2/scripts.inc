PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "NORMAN is onze nieuwe\n"
	.string "GYM LEADER.\p"
	.string "Zijn gezin is volgens mij\n"
	.string "van ver hierheen verhuisd.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "Ik vocht eens tegen NORMAN.\n"
	.string "Pfoe, hij was veel te sterk!\p"
	.string "Hoe zal ik het zeggen?\p"
	.string "Volgens mij leeft hij echt\n"
	.string "voor Pokémon.$"

