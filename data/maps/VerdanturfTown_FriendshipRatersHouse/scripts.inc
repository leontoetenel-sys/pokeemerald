VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Laat je Pokémon eens zien.\n"
	.string "Ik kijk hoe lief hij je vindt.\p"
	.string "O...\n"
	.string "Jouw Pokémon...$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Hij is dol op je!\n"
	.string "Hij kan onmogelijk nog meer\l"
	.string "van je houden.\p"
	.string "Ik word er zelf ook blij van!$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Hij lijkt heel gelukkig.\n"
	.string "Hij is duidelijk heel dol op je!$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Hij vindt je erg lief.\n"
	.string "Hij wil graag wat extra aandacht.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Hij begint aan je te wennen.\n"
	.string "Hij lijkt je te vertrouwen.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Hij is nog niet echt aan je gewend.\n"
	.string "Hij vindt je niet lief of vervelend.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Hij vertrouwt je nog niet.\n"
	.string "Hij kijkt zelfs een beetje boos.\p"
	.string "Hij vindt je nog niet zo lief.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Dit vind ik moeilijk om te zeggen...\p"
	.string "Je Pokémon heeft echt een hekel\n"
	.string "aan je. Vind je dat niet naar?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pika pika!$"

