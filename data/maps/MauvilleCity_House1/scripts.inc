MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Joehoe!\p"
	.string "Ze noemen me de ROCK SMASH-man.\n"
	.string "Maar dat klinkt zo gewoon.\p"
	.string "Noem me liever de ROCK SMASH-held!\p"
	.string "Joehoe!\p"
	.string "Jouw Pokémon zien er sterk uit.\n"
	.string "Dat bevalt me!\p"
	.string "Hier, neem deze HIDDEN MACHINE!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Deze HM bevat ROCK SMASH.\p"
	.string "Liggen er grote stenen\n"
	.string "op je pad?\p"
	.string "Gebruik dan deze HM-aanval\n"
	.string "om ze kapot te slaan!\p"
	.string "Weg met die stenen! Joehoe!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "O ja, als je een steen breekt,\n"
	.string "kan er een Pokémon uit springen!\p"
	.string "Joehoe!$"

