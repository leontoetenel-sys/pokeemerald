PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject LOCALID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_HOUSE_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_CITY_STATE, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Jij bent...\n"
	.string "O, jij bent vast {PLAYER}!\p"
	.string "Bedankt dat je laatst met\n"
	.string "WALLY hebt gespeeld.\p"
	.string "Hij is al sinds zijn geboorte\n"
	.string "vaak ziek en zwak.\p"
	.string "Hij logeert nu bij familie\n"
	.string "in VERDANTURF TOWN.\p"
	.string "Daar is de lucht veel schoner.\p"
	.string "Waar WALLY is?\n"
	.string "Hij is al vertrokken.\p"
	.string "Waar zou hij nu zijn?$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Hoe zou het met WALLY gaan?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}! Sorry dat we je\n"
	.string "zomaar hebben meegenomen.\p"
	.string "WALLY is veel gezonder geworden\n"
	.string "in VERDANTURF TOWN.\p"
	.string "Dat hebben we aan jou te danken!\p"
	.string "Je hielp hem toch een Pokémon\n"
	.string "te vangen voordat hij vertrok?\p"
	.string "Daar werd hij zo blij van.\p"
	.string "En ik als vader ook!\p"
	.string "Ik ben blij dat hij zo'n goede\n"
	.string "vriend als jij heeft gevonden.\p"
	.string "Daarom wil ik je graag\n"
	.string "dit cadeau geven.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Als je Pokémon SURF kan gebruiken,\n"
	.string "kun je overal naartoe!$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY komt binnenkort thuis.\n"
	.string "Ik kijk ernaar uit!$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "O? Je zag WALLY in\n"
	.string "EVER GRANDE CITY?\p"
	.string "Ach, {PLAYER}, doe niet zo gek.\p"
	.string "Hij is wel gezonder geworden,\n"
	.string "maar zo ver kan hij toch niet\l"
	.string "helemaal alleen reizen?$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "WALLY was zo blij toen hij\n"
	.string "vertelde over zijn Pokémon.\p"
	.string "Ik had hem al heel lang\n"
	.string "niet zo zien lachen.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Vertel dit niet aan mijn man...\p"
	.string "WALLY is zonder iets te zeggen\n"
	.string "uit VERDANTURF TOWN vertrokken.\p"
	.string "Hij is misschien kwetsbaar,\n"
	.string "maar hij heeft een sterke wil.\p"
	.string "Ik weet zeker dat hij ooit\n"
	.string "veilig thuiskomt!$"

